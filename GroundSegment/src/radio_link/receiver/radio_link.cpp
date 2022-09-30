// Qt
#include <QGuiApplication>
#include <iostream>

// Internal
#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
#include "../common/links/endpoint.h"

#include "gcs_communicator_factory.h"
#include "radio_link.h"
#include "../common/mavlink_communicator.h"

RadioLink::RadioLink(QObject *parent) : QObject(parent)
{
    domain::GcsCommunicatorFactory factory;
    domain::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(this);
    //domain::UdpLink link(14550); link.addEndpoint(domain::Endpoint(QHostAddress::LocalHost, 14551));

    domain::SerialLink link("/dev/ttyUSB0", 57600);
    //domain::SerialLink link("/dev/tty.usbserial-AH05K5MC", 57600);

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();
    std::cout << "link is " << link.isConnected() << std::endl;
}
