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

    m_link = new radiolink::UdpLink(14550);
    auto udpLink = qobject_cast<radiolink::UdpLink*>(m_link);
    udpLink->addEndpoint(radiolink::Endpoint(QHostAddress::LocalHost, 14551));

    //m_link = new radiolink::SerialLink("/dev/ttyUSB0", 57600, this);
    //m_link = new radiolink::SerialLink("/dev/tty.usbserial-AH05K5MC", 57600);

    m_communicator->addLink(m_link, MAVLINK_COMM_0);
    this->start();
}

RadioLink::~RadioLink()
{
    this->stop();
}

void RadioLink::start()
{
    m_link->connectLink();
    std::cout << "link is " << (m_link->isConnected() ? "up" : "down") << std::endl;
}

void RadioLink::stop()
{
    m_link->disconnectLink();
    std::cout << "link is " << (m_link->isConnected() ? "up" : "down") << std::endl;
}

radiolink::MavLinkCommunicator *RadioLink::communicator() const
{
    return m_communicator;
}
