#include "agu_send_telemetry_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDateTime>
#include <bitset>
#include <iostream>
#include <sstream>

// Internal
#include "../common/mavlink_communicator.h"

using namespace radiolink;

AGUSendTelemetryHandler::AGUSendTelemetryHandler(MavLinkCommunicator* communicator,
                                                 UavModel* model):
    AbstractHandler(communicator),
    m_model(model)
{
    this->startTimer(200);
}

void AGUSendTelemetryHandler::processMessage(const mavlink_message_t& message)
{
    Q_UNUSED(message)
}

uint64_t AGUSendTelemetryHandler::generateMask()
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

void AGUSendTelemetryHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_telemetry_data_pack_t telemetry;

    //uint64_t telemetry_Status_Mask = (rand() % 1000) + 1;
    int32_t latitude= (rand() % 10000000) + 1;
    int32_t longitude= (rand() % 10000000) + 1;
    uint32_t gnss_Altitude= (rand() % 1000) + 1;
    int32_t altitude_Main_Altimeter= (rand() % 100) + 1;
    int32_t altitude_Payload_Altimeter= (rand() % 100) + 1;
    float ECEF_Position_X= (rand() % 1000) + 1;
    float ECEF_Position_Y= (rand() % 1000) + 1;
    float ECEF_Position_Z= (rand() % 1000) + 1;
    float ECEF_Velocity_X= (rand() % 1000) + 1;
    float ECEF_Velocity_Y= (rand() % 1000) + 1;
    float ECEF_Velocity_Z= (rand() % 1000) + 1;
    float quaternion_0= (rand() % 1000) + 1;
    float quaternion_1= (rand() % 1000) + 1;
    float quaternion_2= (rand() % 1000) + 1;
    float quaternion_3= (rand() % 1000) + 1;
    int16_t air_Speed_U= (rand() % 100) + 1;
    int16_t air_Speed_V= (rand() % 100) + 1;
    int16_t air_Speed_W= (rand() % 100) + 1;
    int16_t air_Temperature= (rand() % 100) + 1;
    uint16_t velocity_Horizontal= (rand() % 100) + 1;
    int16_t velocity_Vertical= (rand() % 100) + 1;
    uint16_t position_Accuracy= (rand() % 100) + 1;
    uint16_t speed_Accuracy= (rand() % 100) + 1;
    int16_t acceleration_X= (rand() % 100) + 1;
    int16_t acceleration_Y= (rand() % 100) + 1;
    int16_t acceleration_Z= (rand() % 100) + 1;
    int16_t roll_Angle= (rand() % 100) + 1;
    int16_t pitch_Angle= (rand() % 100) + 1;
    int16_t yaw_Angle= (rand() % 100) + 1;
    int16_t angular_Rate_Roll= (rand() % 100) + 1;
    int16_t angular_Rate_Pitch= (rand() % 100) + 1;
    int16_t angular_Rate_Yaw= (rand() % 100) + 1;
    uint8_t satellite_Num= (rand() % 100) + 1;

    printf("ROLL ANGLE %d \n",roll_Angle);

    //telemetry.Telemetry_Status_Mask=telemetry_Status_Mask;
    telemetry.Latitude=latitude;
    telemetry.Longitude=longitude;
    telemetry.GNSS_Altitude=gnss_Altitude;
    telemetry.Altitude_Main_Altimeter=altitude_Main_Altimeter;
    telemetry.Altitude_Payload_Altimeter=altitude_Payload_Altimeter;
    telemetry.ECEF_Position_X=ECEF_Position_X;
    telemetry.ECEF_Position_Y=ECEF_Position_Y;
    telemetry.ECEF_Position_Z=ECEF_Position_Z;
    telemetry.ECEF_Velocity_X=ECEF_Velocity_X;
    telemetry.ECEF_Velocity_Y=ECEF_Velocity_Y;
    telemetry.ECEF_Velocity_Z=ECEF_Velocity_Z;
    telemetry.Quaternion_0=quaternion_0;
    telemetry.Quaternion_1=quaternion_1;
    telemetry.Quaternion_2=quaternion_2;
    telemetry.Quaternion_3=quaternion_3;
    telemetry.Air_Speed_U=air_Speed_U;
    telemetry.Air_Speed_V=air_Speed_V;
    telemetry.Air_Speed_W=air_Speed_W;
    telemetry.Air_Temperature=air_Temperature;
    telemetry.Velocity_Horizontal=velocity_Horizontal;
    telemetry.Velocity_Vertical=velocity_Vertical;
    telemetry.Position_Accuracy=position_Accuracy;
    telemetry.Speed_Accuracy=speed_Accuracy;
    telemetry.Acceleration_X=acceleration_X;
    telemetry.Acceleration_Y=acceleration_Y;
    telemetry.Acceleration_Z=acceleration_Z;
    telemetry.Roll_Angle=roll_Angle;
    telemetry.Pitch_Angle=pitch_Angle;
    telemetry.Yaw_Angle=yaw_Angle;
    telemetry.Angular_Rate_Roll=angular_Rate_Roll;
    telemetry.Angular_Rate_Pitch=angular_Rate_Pitch;
    telemetry.Angular_Rate_Yaw=angular_Rate_Yaw;
    telemetry.Satellite_Num=satellite_Num;
    telemetry.Log_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();
    telemetry.GNSS_Timestamp= QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    telemetry.Telemetry_Status_Mask = this->generateMask();

    mavlink_msg_telemetry_data_pack_encode(m_communicator->systemId(),
                                           m_communicator->componentId(),
                                           &message, &telemetry);

    m_communicator->sendMessageOnLastReceivedLink(message);
}

