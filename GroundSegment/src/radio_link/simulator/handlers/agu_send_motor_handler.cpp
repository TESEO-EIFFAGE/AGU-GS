#include "agu_send_motor_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDateTime>
#include <bitset>
#include <iostream>
#include <sstream>

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




uint32_t AGUSendMotorHandler::generateBMSMask()
{
    auto handler = "BMS";
    std::bitset<32> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(32); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }

    statusMask.set(0,1);
    statusMask.set(1,1);
    statusMask.set(2,1);
    statusMask.set(3,1);
    statusMask.set(4,1);
    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
}

uint32_t AGUSendMotorHandler::generateMotorAFaultsMask()
{
    auto handler = "MOTOR A";
    std::bitset<32> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(32); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }

    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
}
uint32_t AGUSendMotorHandler::generateMotorBFaultsMask()
{
    auto handler = "MOTOR B";
    std::bitset<32> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(32); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }

    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
}

uint32_t AGUSendMotorHandler::generateMotorControlStatusMask()
{
    auto handler = "MOTOR CONTROL";
    std::bitset<32> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(24); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }
    std::string bs25 = std::bitset<8>(m_communicator->random255()).to_string()+"00000000""00000000""00000000";
    std::cout << bs25 << std::endl;

    statusMask = std::bitset<32>{bs25} | statusMask;

    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
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
    motor.Motor_Control_Status_Mask=this->generateMotorControlStatusMask();
    motor.Motor_A_Faults_Mask=this->generateMotorAFaultsMask();
    motor.Motor_B_Faults_Mask=this->generateMotorBFaultsMask();
    motor.BMS_Faults_Mask=this->generateBMSMask();

    mavlink_msg_motor_status_pack_encode(m_communicator->systemId(),
                                         m_communicator->componentId(),
                                         &message, &motor);

    m_communicator->sendMessageOnLastReceivedLink(message);
}

