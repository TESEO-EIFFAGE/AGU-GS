#include "receiver_communicator_factory.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Internal
#include "../common/mavlink_communicator.h"

#include "../common/handlers/heartbeat_handler.h"
#include "handlers/agu_system_handler.h"
#include "handlers/agu_motor_handler.h"
#include "handlers/agu_telemetry_handler.h"
#include "handlers/agu_storage_handler.h"
#include "handlers/agu_guidance_handler.h"
#include "handlers/agu_radiolink_handler.h"

using namespace radiolink;

ReceiverCommunicatorFactory::ReceiverCommunicatorFactory()
{}

MavLinkCommunicator* ReceiverCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(2, 200);

    new radiolink::HeartbeatHandler(MAV_TYPE_HELICOPTER, communicator);
    new radiolink::AGUSystemHandler(communicator);
    new radiolink::AGUMotorHandler(communicator);
    new radiolink::AGUTelemetryHandler(communicator);
    new radiolink::AGUGuidanceHandler(communicator);
    new radiolink::AGUStorageHandler(communicator);
    new radiolink::AGURadioLinkHandler(communicator);

    return communicator;
}
