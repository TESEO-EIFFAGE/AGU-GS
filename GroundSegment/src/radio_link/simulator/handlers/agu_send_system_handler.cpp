#include "agu_send_system_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDebug>
#include<QBitArray>
#include "QtCore/qdatetime.h"
#include <random>

// Internal
#include "uav_model.h"
#include "../common/mavlink_communicator.h"

using namespace radiolink;

AGUSendSystemHandler::AGUSendSystemHandler(MavLinkCommunicator* communicator,
                                           UavModel* model):
    AbstractHandler(communicator),
    m_model(model)
{
    this->startTimer(150);
}

uint64_t AGUSendSystemHandler::generateTelMask()
{
    auto handler = "TEL";
    std::bitset<64> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(32); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }

    std::string bs56 = std::bitset<8>(m_communicator->random255()).to_string()+"00000000""00000000""00000000""00000000""00000000""00000000""00000000";
    std::cout << bs56 << std::endl;
    std::string bs48 = "00000000"+std::bitset<8>(m_communicator->random255()).to_string()+"00000000""00000000""00000000""00000000""00000000""00000000";
    std::cout << bs48 << std::endl;
    std::string bs40 = "00000000""00000000"+std::bitset<8>(m_communicator->random255()).to_string()+"00000000""00000000""00000000""00000000""00000000";
    std::cout << bs40 << std::endl;
    std::string bs32 = "00000000""00000000""00000000"+std::bitset<8>(m_communicator->random255()).to_string()+"00000000""00000000""00000000""00000000";
    std::cout << bs32 << std::endl;

    statusMask = std::bitset<64>{bs56} | statusMask;
    statusMask = std::bitset<64>{bs48} | statusMask;
    statusMask = std::bitset<64>{bs40} | statusMask;
    statusMask = std::bitset<64>{bs32} | statusMask;
    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
}

uint32_t AGUSendSystemHandler::generateCoreMask()
{
    auto handler = "CORE";
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

uint32_t AGUSendSystemHandler::generateStorageMask()
{
    auto handler = "STORAGE";
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

uint32_t AGUSendSystemHandler::generateRLMask()
{
    auto handler = "RADIOLINK";
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

uint32_t AGUSendSystemHandler::generateMotorMask()
{
    auto handler = "MOTOR";
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

uint32_t AGUSendSystemHandler::generateGuidanceMask()
{
    auto handler = "GUIDANCE";
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

uint16_t AGUSendSystemHandler::generateEmergencyBoardMask()
{
    auto handler = "EMERGENCY BOARD";
    std::bitset<16> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(16); ++i) {
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

uint16_t AGUSendSystemHandler::generatePSUMask()
{
    auto handler = "PSU";
    std::bitset<16> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(16); ++i) {
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

uint8_t AGUSendSystemHandler::generateEmergencyRLMask()
{
    auto handler = "EMERGENCY RL";
    std::bitset<8> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(8); ++i) {
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

void AGUSendSystemHandler::processMessage(const mavlink_message_t& message)
{
    Q_UNUSED(message)
}

void AGUSendSystemHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_system_status_pack_t status;

    static int flightMode = std::rand();

    flightMode = flightMode > 1 ? flightMode - 1: 100;

    int flightPhase = (rand() % 10) + 1;
    int flightPhaseTime = (rand() % 1000) + 1;


    status.Telemetry_Module_Status_Mask=this->generateTelMask();//telemetrybytes.toInt(&telemetryconvcheck);
    status.Motor_Control_Module_Status_Mask=this->generateMotorMask();
    status.Radio_Link_Module_Status_Mask=this->generateRLMask();
    status.Storage_Module_Status_Mask=this->generateStorageMask();
    status.Guidance_Module_Status_Mask=this->generateGuidanceMask();
    status.Core_Module_Status_Mask=this->generateCoreMask();
    status.Flight_Mode = flightMode;
    status.Flight_Phase = flightPhase;
    status.Flight_Phase_Time = flightPhaseTime;
    status.Log_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    mavlink_msg_system_status_pack_encode(m_communicator->systemId(),
                                          m_communicator->componentId(),
                                          &message, &status);

    m_communicator->sendMessageOnLastReceivedLink(message);
}
