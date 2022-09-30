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
    radiolink::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(this);
    //domain::UdpLink link(14550); link.addEndpoint(domain::Endpoint(QHostAddress::LocalHost, 14551));

    radiolink::SerialLink link("/dev/ttyUSB0", 57600);
    //domain::SerialLink link("/dev/tty.usbserial-AH05K5MC", 57600);

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();
    std::cout << "link is " << link.isConnected() << std::endl;
}
