#include "agu_telemetry_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);

AGUTelemetryHandler::AGUTelemetryHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUTelemetryHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_TELEMETRY_DATA_PACK ||
        message.sysid == 0) return;

    mavlink_telemetry_data_pack_t telemetry_status;
    mavlink_msg_telemetry_data_pack_decode(&message, &telemetry_status);

    std::cout << "Log_Timestamp " << telemetry_status.Log_Timestamp << std::endl;
    std::cout << "GNSS_Timestamp " << telemetry_status.GNSS_Timestamp << std::endl;
    std::cout << "Telemetry_Status_Mask " << telemetry_status.Telemetry_Status_Mask << std::endl;
    std::cout << "Latitude " << telemetry_status.Latitude << std::endl;
    std::cout << "Longitude " << telemetry_status.Longitude << std::endl;
    std::cout << "GNSS_Altitude " << telemetry_status.GNSS_Altitude << std::endl;
    std::cout << "Altitude_Main_Altimeter " << telemetry_status.Altitude_Main_Altimeter << std::endl;
    std::cout << "Altitude_Payload_Altimeter " << telemetry_status.Altitude_Payload_Altimeter << std::endl;
    std::cout << "ECEF_Position_X " << telemetry_status.ECEF_Position_X << std::endl;
    std::cout << "ECEF_Position_Y " << telemetry_status.ECEF_Position_Y << std::endl;
    std::cout << "ECEF_Position_Z " << telemetry_status.ECEF_Position_Z << std::endl;
    std::cout << "ECEF_Velocity_X " << telemetry_status.ECEF_Velocity_X << std::endl;
    std::cout << "ECEF_Velocity_Y " << telemetry_status.ECEF_Velocity_Y << std::endl;
    std::cout << "ECEF_Velocity_Z " << telemetry_status.ECEF_Velocity_Z << std::endl;
    std::cout << "Quaternion_0 " << telemetry_status.Quaternion_0 << std::endl;
    std::cout << "Quaternion_1 " << telemetry_status.Quaternion_1 << std::endl;
    std::cout << "Quaternion_2 " << telemetry_status.Quaternion_2 << std::endl;
    std::cout << "Quaternion_3 " << telemetry_status.Quaternion_3 << std::endl;
    std::cout << "Air_Speed_U " << telemetry_status.Air_Speed_U << std::endl;
    std::cout << "Air_Speed_V " << telemetry_status.Air_Speed_V << std::endl;
    std::cout << "Air_Speed_W " << telemetry_status.Air_Speed_W << std::endl;
    std::cout << "Air_Temperature " << telemetry_status.Air_Temperature << std::endl;
    std::cout << "Velocity_Horizontal " << telemetry_status.Velocity_Horizontal << std::endl;
    std::cout << "Velocity_Vertical " << telemetry_status.Velocity_Vertical << std::endl;
    std::cout << "Position_Accuracy " << telemetry_status.Position_Accuracy << std::endl;
    std::cout << "Speed_Accuracy " << telemetry_status.Speed_Accuracy << std::endl;
    std::cout << "Acceleration_X " << telemetry_status.Acceleration_X << std::endl;
    std::cout << "Acceleration_Y " << telemetry_status.Acceleration_Y << std::endl;
    std::cout << "Acceleration_Z " << telemetry_status.Acceleration_Z << std::endl;
    std::cout << "Roll_Angle " << telemetry_status.Roll_Angle << std::endl;
    std::cout << "Pitch_Angle " << telemetry_status.Pitch_Angle << std::endl;
    std::cout << "Yaw_Angle " << telemetry_status.Yaw_Angle << std::endl;
    std::cout << "Angular_Rate_Roll " << telemetry_status.Angular_Rate_Roll << std::endl;
    std::cout << "Angular_Rate_Pitch " << telemetry_status.Angular_Rate_Pitch << std::endl;
    std::cout << "Angular_Rate_Yaw " << telemetry_status.Angular_Rate_Yaw << std::endl;
    printf( "Satellite_Num %d \n" ,telemetry_status.Satellite_Num);
    QVariant processedMessage;
    processedMessage.setValue(telemetry_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
