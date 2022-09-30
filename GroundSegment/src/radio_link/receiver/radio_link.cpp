#include "radio_link.h"

#include <iostream>

//#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
//#include "../common/links/endpoint.h"

#include "receiver_communicator_factory.h"
#include "../common/mavlink_communicator.h"

RadioLink::RadioLink(QObject *parent) : QObject(parent)
{
    radiolink::ReceiverCommunicatorFactory factory;
    m_communicator = factory.create();
    m_communicator->setParent(this);
    //domain::UdpLink link(14550); link.addEndpoint(domain::Endpoint(QHostAddress::LocalHost, 14551));

    m_link = new radiolink::SerialLink("/dev/ttyUSB0", 57600, this);
    //domain::SerialLink link("/dev/tty.usbserial-AH05K5MC", 57600);

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
