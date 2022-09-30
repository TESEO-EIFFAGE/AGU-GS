// Qt
#include <QCoreApplication>
#include <iostream>

// Internal
#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
#include "../common/links/endpoint.h"

#include "receiver_communicator_factory.h"
#include "../common/mavlink_communicator.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    radiolink::ReceiverCommunicatorFactory factory;
    radiolink::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(&app);
    radiolink::UdpLink link(14550); link.addEndpoint(radiolink::Endpoint(QHostAddress::LocalHost, 14551));

    //radiolink::SerialLink link("/dev/ttyUSB0", 57600);
    //radiolink::SerialLink link("/dev/tty.usbserial-AH05K5MC", 57600);

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();
    std::cout << "receiver link is " << link.isConnected() << std::endl;

    return app.exec();
}
