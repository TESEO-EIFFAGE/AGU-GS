#include "gcs_communicator_factory.h"

// MAVLink
#include "../3dparty/mavlink_v2/AGU_MAVLINK/mavlink.h"

// Internal
#include "../common/mavlink_communicator.h"

#include "../common/handlers/heartbeat_handler.h"
#include "handlers/agu_system_handler.h"
#include "handlers/agu_motor_handler.h"
#include "handlers/agu_telemetry_handler.h"

using namespace domain;

GcsCommunicatorFactory::GcsCommunicatorFactory()
{}

MavLinkCommunicator* GcsCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(2, 200);

    new domain::HeartbeatHandler(MAV_TYPE_HELICOPTER, communicator);
    new domain::AGUSystemHandler(communicator);
    new domain::AGUMotorHandler(communicator);
    new domain::AGUTelemetryHandler(communicator);

    return communicator;
}
