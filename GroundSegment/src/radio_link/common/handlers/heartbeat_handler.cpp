#include "heartbeat_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>

// Internal
#include "../mavlink_communicator.h"

using namespace radiolink;

HeartbeatHandler::HeartbeatHandler(uint8_t type, MavLinkCommunicator* communicator):
    AbstractHandler(communicator),
    m_type(type)
{
    this->startTimer(1000); // 1 Hz
}

void HeartbeatHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_heartbeat_t heartbeat;
    heartbeat.type = m_type;
    heartbeat.autopilot=MAV_AUTOPILOT_GENERIC;
    heartbeat.base_mode=MAV_MODE_GUIDED_ARMED;
    heartbeat.custom_mode=0;
    heartbeat.system_status=MAV_STATE_ACTIVE;

    mavlink_msg_heartbeat_encode(m_communicator->systemId(),
                                 m_communicator->componentId(),
                                 &message, &heartbeat);

    m_communicator->sendMessageOnAllLinks(message);
}

void HeartbeatHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_HEARTBEAT) return;

    mavlink_heartbeat_t heartbeat;
    mavlink_msg_heartbeat_decode(&message, &heartbeat);

    std::cout << "Heartbeat received, system type:" << (int)heartbeat.type
             << " System status:" << (int)heartbeat.system_status << std::endl;
}
