#include "agu_send_motor_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDebug>
#include "QtCore/qdatetime.h"
#include <random>

// Internal
#include "uav_model.h"
#include "../common/mavlink_communicator.h"

using namespace radiolink;


AGUSendMotorHandler::AGUSendMotorHandler(MavLinkCommunicator* communicator,
                                         UavModel* model):
    AbstractHandler(communicator),
    m_model(model)
{
    this->startTimer(150);
}

void AGUSendMotorHandler::processMessage(const mavlink_message_t& message)
{
    Q_UNUSED(message)
}

void AGUSendMotorHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_motor_status_pack_t motor;


    int32_t Motor_A_Real_Position=(rand() % 1000) + 1;
    int32_t Motor_B_Real_Position=(rand() % 1000) + 1;
    int32_t Motor_A_Demand_Position=(rand() % 1000) + 1;
    int32_t Motor_B_Demand_Position=(rand() % 1000) + 1;
    int32_t Motor_A_Torque=(rand() % 100) + 1;
    int32_t Motor_B_Torque=(rand() % 100) + 1;
    uint32_t Motor_Control_Status_Mask=(rand() % 100) + 1;
    uint32_t Motor_A_Faults_Mask=(rand() % 100) + 1;
    uint32_t Motor_B_Faults_Mask=(rand() % 100) + 1;
    uint32_t BMS_Faults_Mask=(rand() % 100) + 1;
    int16_t Motor_A_Temperature=(rand() % 100) + 1;
    int16_t Motor_B_Temperature=(rand() % 100) + 1;
    uint16_t BMS_Voltage=(rand() % 100) + 1;
    int16_t BMS_Absorption=(rand() % 100) + 1;
    int16_t BMS_Temperature=(rand() % 100) + 1;

    printf("BMS Voltage %d \n",BMS_Voltage);



    motor.Log_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();
    motor.Motor_A_Real_Position=Motor_A_Real_Position;
    motor.Motor_A_Demand_Position=Motor_A_Demand_Position;
    motor.Motor_B_Demand_Position=Motor_B_Demand_Position;
    motor.Motor_B_Real_Position=Motor_B_Real_Position;
    motor.Motor_A_Torque=Motor_A_Torque;
    motor.Motor_B_Torque=Motor_B_Torque;
    motor.Motor_A_Temperature=Motor_A_Temperature;
    motor.Motor_B_Temperature=Motor_B_Temperature;
    motor.BMS_Voltage=BMS_Voltage;
    motor.BMS_Absorption=BMS_Absorption;
    motor.BMS_Temperature=BMS_Temperature;
    motor.Motor_Control_Status_Mask=Motor_Control_Status_Mask;
    motor.Motor_A_Faults_Mask=Motor_A_Faults_Mask;
    motor.Motor_B_Faults_Mask=Motor_B_Faults_Mask;
    motor.BMS_Faults_Mask=BMS_Faults_Mask;
    mavlink_msg_motor_status_pack_encode(m_communicator->systemId(),
                                         m_communicator->componentId(),
                                         &message, &motor);

    m_communicator->sendMessageOnLastReceivedLink(message);
}

