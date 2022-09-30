#include "uav_communicator_factory.h"

// MAVLink
#include "../3dparty/mavlink_v2/ardupilotmega/mavlink.h"

// Internal
#include "../common/mavlink_communicator.h"

#include "../common/handlers/heartbeat_handler.h"
#include "handlers/send_system_status_handler.h"
#include "handlers/send_position_handler.h"
#include "handlers/send_attitude_handler.h"
#include "handlers/send_vfr_hud_handler.h"
#include "handlers/send_home_position_handler.h"
#include "handlers/send_gps_raw_handler.h"

using namespace domain;

UavCommunicatorFactory::UavCommunicatorFactory(domain::UavModel* model):
    m_model(model)
{}

MavLinkCommunicator* UavCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(1, 0);

    new domain::HeartbeatHandler(MAV_TYPE_HELICOPTER, communicator);
    new domain::SendSystemStatusHandler(communicator, m_model);
    new domain::SendPositionHandler(communicator, m_model);
    new domain::SendAttitudeHandler(communicator, m_model);
    new domain::SendVfrHudHandler(communicator, m_model);
    new domain::SendHomePositionHandler(communicator, m_model);
    new domain::SendGpsRawHandler(communicator, m_model);

    return communicator;
}
