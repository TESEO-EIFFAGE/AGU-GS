#include "mavlink_communicator.h"

// MAVLink
#include "../3dparty/mavlink_v2/AGU_MAVLINK/mavlink.h"

// Internal
#include "links/abstract_link.h"

using namespace radiolink;

MavLinkCommunicator::MavLinkCommunicator(uint8_t systemId, uint8_t componentId,
                                         QObject* parent):
    QObject(parent),
    m_lastReceivedLink(nullptr),
    m_systemId(systemId),
    m_componentId(componentId)
{
    qRegisterMetaType<mavlink_message_t>("mavlink_message_t");
}

QList<AbstractLink*> MavLinkCommunicator::links() const
{
    return m_linkChannels.keys();
}

uint8_t MavLinkCommunicator::systemId() const
{
    return m_systemId;
}

uint8_t MavLinkCommunicator::componentId() const
{
    return m_componentId;
}

bool MavLinkCommunicator::randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}

int32_t MavLinkCommunicator::randomLat() {
    static auto gen = std::bind(std::uniform_int_distribution<>(-90,90),std::default_random_engine());
    return gen();
}

int32_t MavLinkCommunicator::randomLon() {
    static auto gen = std::bind(std::uniform_int_distribution<>(-180,180),std::default_random_engine());
    return gen();
}

uint8_t MavLinkCommunicator::random255() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,255),std::default_random_engine());
    return gen();
}

void MavLinkCommunicator::addLink(AbstractLink* link, uint8_t channel)
{
    if (m_linkChannels.contains(link)) return;

    m_linkChannels[link] = channel;
    connect(link, &AbstractLink::dataReceived,
            this, &MavLinkCommunicator::onDataReceived);
}

void MavLinkCommunicator::removeLink(AbstractLink* link)
{
    if (!m_linkChannels.contains(link)) return;

    m_linkChannels.remove(link);
    disconnect(link, &AbstractLink::dataReceived,
            this, &MavLinkCommunicator::onDataReceived);
}

void MavLinkCommunicator::setSystemId(uint8_t systemId)
{
    m_systemId = systemId;
}

void MavLinkCommunicator::setComponentId(uint8_t componentId)
{
    m_componentId = componentId;
}

void MavLinkCommunicator::sendMessage(mavlink_message_t& message, AbstractLink* link)
{
    if (!link ||
            !link->isConnected()) return;

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    int lenght = mavlink_msg_to_send_buffer(buffer, &message);

    if (!lenght) return;
    link->sendData(QByteArray((const char*)buffer, lenght));
}

void MavLinkCommunicator::sendMessageOnLastReceivedLink(mavlink_message_t& message)
{
    this->sendMessage(message, m_lastReceivedLink);
}

void MavLinkCommunicator::sendMessageOnAllLinks(mavlink_message_t& message)
{
    for (AbstractLink* link: m_linkChannels.keys())
        this->sendMessage(message, link);
}

void MavLinkCommunicator::onDataReceived(const QByteArray& data)
{
    mavlink_message_t message;
    mavlink_status_t status;

    m_lastReceivedLink = qobject_cast<AbstractLink*>(this->sender());
    if (!m_lastReceivedLink) return;

    uint8_t channel = m_linkChannels.value(m_lastReceivedLink);
    for (int pos = 0; pos < data.length(); ++pos)
    {
        if (!mavlink_parse_char(channel, (uint8_t)data[pos],
                                &message, &status))
            continue;

        emit messageReceived(message);
    }

    // TODO: Link RX status
}
