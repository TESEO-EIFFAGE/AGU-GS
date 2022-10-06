// Qt
#include <QCoreApplication>
#include <iostream>

// Internal
#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
#include "../common/links/endpoint.h"

#include "uav_model.h"
#include "uav_communicator_factory.h"
#include "../common/mavlink_communicator.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    radiolink::UavModel model;
    radiolink::UavCommunicatorFactory factory(&model);
    radiolink::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(&app);

    radiolink::UdpLink link(14551);
    link.addEndpoint(radiolink::Endpoint(QHostAddress::LocalHost, 14550));

    //radiolink::SerialLink link("/dev/tty.usbserial-AL01O3PL", 57600);

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();
    std::cout << "simulator link is " << link.isConnected() << std::endl;

    return app.exec();
}
