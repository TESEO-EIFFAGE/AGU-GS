#include "agu_motor_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);

AGUMotorHandler::AGUMotorHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUMotorHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_MOTOR_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_motor_status_pack_t motor_status;
    mavlink_msg_motor_status_pack_decode(&message, &motor_status);

    std::cout << "MOT " << motor_status.Log_Timestamp << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(motor_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
