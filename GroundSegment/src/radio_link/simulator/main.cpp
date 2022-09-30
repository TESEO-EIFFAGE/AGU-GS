// Qt
#include <QCoreApplication>
#include <QTimer>

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

    domain::UavModel model;
    domain::UavCommunicatorFactory factory(&model);
    domain::MavLinkCommunicator* communicator = factory.create();
    communicator->setParent(&app);

    domain::SerialLink link("/dev/tty.usbserial-AL01O3PL", 57600);
    //domain::UdpLink link(14551);
    //link.addEndpoint(domain::Endpoint(QHostAddress::LocalHost, 14550));

    communicator->addLink(&link, MAVLINK_COMM_0);
    link.connectLink();

    return app.exec();
}
