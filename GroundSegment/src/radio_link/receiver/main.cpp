// Qt
#include <QGuiApplication>
#include <iostream>

// Internal
#include "../common/links/udp_link.h"
#include "../common/links/serial_link.h"
#include "../common/links/endpoint.h"

#include "gcs_communicator_factory.h"
#include "../common/mavlink_communicator.h"

int main(int argc, char* argv[])
{
    using namespace std;
    QGuiApplication app(argc, argv);
    domain::GcsCommunicatorFactory factory;
    domain::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(&app);
    //domain::UdpLink link(14550); link.addEndpoint(domain::Endpoint(QHostAddress::LocalHost, 14551));

    //domain::SerialLink link("/dev/ttyUSB0", 57600);
    domain::SerialLink link("/dev/tty.usbserial-AH05K5MC", 57600);

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();
    cout << "link is " << link.isConnected() << endl;

    return app.exec();
}
