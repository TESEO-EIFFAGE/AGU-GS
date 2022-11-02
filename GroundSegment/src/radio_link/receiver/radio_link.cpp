#include "radio_link.h"

#include <iostream>

#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
#include "../common/links/endpoint.h"

#include "receiver_communicator_factory.h"
#include "../common/mavlink_communicator.h"

/*!
        \class RadioLink

        \brief The RadioLink class used to setup RadioLink
*/
RadioLink::RadioLink(QObject *parent) : QObject(parent)
{
    radiolink::ReceiverCommunicatorFactory factory;
    m_communicator = factory.create();
    m_communicator->setParent(this);

    // Uncomment this block for UDP connection
    m_link = new radiolink::UdpLink(14550);
    auto udpLink = qobject_cast<radiolink::UdpLink*>(m_link);
    udpLink->addEndpoint(radiolink::Endpoint(QHostAddress::LocalHost, 14551));

    // Uncomment this block for UART connection
//    m_link = new radiolink::SerialLink("/dev/ttyUSB0", 115200, this);

    m_communicator->addLink(m_link, MAVLINK_COMM_0);
    this->start();
}

RadioLink::~RadioLink()
{
    this->stop();
}

/*!
    \fn void RadioLink::start()

    Connects the RadioLink
*/
void RadioLink::start()
{
    m_link->connectLink();
    std::cout << "link is " << (m_link->isConnected() ? "up" : "down") << std::endl;
}

/*!
    \fn void RadioLink::stop()

    Disconnects the RadioLink
*/
void RadioLink::stop()
{
    m_link->disconnectLink();
    std::cout << "link is " << (m_link->isConnected() ? "up" : "down") << std::endl;
}

/*!
    \fn radiolink::MavLinkCommunicator *RadioLink::communicator() const

    Returns the communicator object
*/
radiolink::MavLinkCommunicator *RadioLink::communicator() const
{
    return m_communicator;
}
