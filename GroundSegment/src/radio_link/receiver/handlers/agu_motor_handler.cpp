#include "agu_motor_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_motor_status_pack_t);

AGUMotorHandler::AGUMotorHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUMotorHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_MOTOR_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_motor_status_pack_t motor_status;
    mavlink_msg_motor_status_pack_decode(&message, &motor_status);

//    std::cout << "BMS_Absorption " << motor_status.BMS_Absorption << std::endl;
//    std::cout << "BMS_Faults_Mask " << motor_status.BMS_Faults_Mask << std::endl;
//    std::cout << "BMS_Temperature " << motor_status.BMS_Temperature << std::endl;
//    std::cout << "BMS_Voltage " << motor_status.BMS_Voltage << std::endl;

//    std::cout << "Log_Timestamp " << motor_status.Log_Timestamp << std::endl;
//    std::cout << "Motor_A_Demand_Position " << motor_status.Motor_A_Demand_Position << std::endl;
//    std::cout << "Motor_A_Faults_Mask " << motor_status.Motor_A_Faults_Mask << std::endl;
//    std::cout << "Motor_A_Real_Position " << motor_status.Motor_A_Real_Position << std::endl;
//    std::cout << "Motor_A_Temperature " << motor_status.Motor_A_Temperature << std::endl;
//    std::cout << "Motor_A_Torque " << motor_status.Motor_A_Torque << std::endl;

//    std::cout << "Motor_B_Demand_Position " << motor_status.Motor_B_Demand_Position << std::endl;
//    std::cout << "Motor_B_Faults_Mask " << motor_status.Motor_B_Faults_Mask << std::endl;
//    std::cout << "Motor_B_Real_Position " << motor_status.Motor_B_Real_Position << std::endl;
//    std::cout << "Motor_B_Temperature " << motor_status.Motor_B_Temperature << std::endl;
//    std::cout << "Motor_B_Torque " << motor_status.Motor_B_Torque << std::endl;

//    std::cout << "Motor_Control_Status_Mask " << motor_status.Motor_Control_Status_Mask << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(motor_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
