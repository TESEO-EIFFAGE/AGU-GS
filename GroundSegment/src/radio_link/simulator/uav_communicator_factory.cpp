#include "uav_communicator_factory.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Internal
#include "../common/mavlink_communicator.h"

#include "../common/handlers/heartbeat_handler.h"
#include "handlers/agu_send_system_handler.h"
#include "handlers/agu_send_telemetry_handler.h"
#include "handlers/agu_send_motor_handler.h"
using namespace radiolink;

UavCommunicatorFactory::UavCommunicatorFactory(radiolink::UavModel* model):
    m_model(model)
{}

MavLinkCommunicator* UavCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(1, 0);

    new radiolink::HeartbeatHandler(MAV_TYPE_HELICOPTER, communicator);
    new radiolink::AGUSendSystemHandler(communicator, m_model);
    new radiolink::AGUSendTelemetryHandler(communicator, m_model);
    new radiolink::AGUSendMotorHandler(communicator, m_model);


    /* add handler instances here */

    return communicator;
}
