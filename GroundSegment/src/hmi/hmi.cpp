#include "hmi.h"
#include <bitset>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iostream>

Q_DECLARE_METATYPE(mavlink_system_status_pack_t);
Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);
Q_DECLARE_METATYPE(mavlink_motor_status_pack_t);
Q_DECLARE_METATYPE(mavlink_storage_status_pack_t);
Q_DECLARE_METATYPE(mavlink_guidance_status_pack_t);
Q_DECLARE_METATYPE(mavlink_radio_link_status_pack_t);


/*!
        \class HMI

        \brief The HMI class is the class used to show the data in GUI
*/
HMI::HMI(QObject *parent)
    : QObject{parent}
{

}

/*!
    \fn void HMI::showData(QVariant msg)

    It call the function for show the data in the GUI
*/
void HMI::showData(QVariant msg) {
    if (msg.canConvert<mavlink_telemetry_data_pack_t>()) {
        showDataTelemetry(msg.value<mavlink_telemetry_data_pack_t>());
    }
    else if (msg.canConvert<mavlink_system_status_pack_t>()) {
        showDataSystemStatus(msg.value<mavlink_system_status_pack_t>());
    }
    else if (msg.canConvert<mavlink_motor_status_pack_t>()) {
        showDataMotorStatus(msg.value<mavlink_motor_status_pack_t>());
    }

    else if (msg.canConvert<mavlink_guidance_status_pack_t>()) {
        showDataGuidanceStatus(msg.value<mavlink_guidance_status_pack_t>());
    }
    else if (msg.canConvert<mavlink_storage_status_pack_t>()) {
        showDataStorageStatus(msg.value<mavlink_storage_status_pack_t>());
    }
    else if (msg.canConvert<mavlink_radio_link_status_pack_t>()) {
        showDataRLStatus(msg.value<mavlink_radio_link_status_pack_t>());
    }
}

/*!
    \fn void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)

    It show in the GUI the data related telemetry
*/
void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry) {
    m_TimeStamp= msg_telemetry.GNSS_Timestamp; emit TimeStampChanged();
    m_Latitude= msg_telemetry.Latitude; emit LatitudeChanged();
    m_Longitude=msg_telemetry.Longitude; emit LongitudeChanged();
    m_GNSSAltitude= msg_telemetry.GNSS_Altitude; emit GNSSAltitudeChanged();
    m_AirSpeed_UVector= msg_telemetry.Air_Speed_U; emit AirSpeed_UVectorChanged();
    m_AirSpeed_VVector= msg_telemetry.Air_Speed_V; emit AirSpeed_VVectorChanged();
    m_AirSpeed_WVector= msg_telemetry.Air_Speed_W; emit AirSpeed_WVectorChanged();
    m_AirTemperature=msg_telemetry.Air_Temperature; emit AirTemperatureChanged();
    m_AltitudeFromPayloadAltimeter= msg_telemetry.Altitude_Payload_Altimeter; emit AltitudeFromPayloadAltimeterChanged();
    m_AltitudeFromRadarAltimeter=msg_telemetry.Altitude_Main_Altimeter; emit AltitudeFromRadarAltimeterChanged();
    m_LinearVelocityHorizontal= msg_telemetry.Velocity_Horizontal; emit LinearVelocityHorizontalChanged();
    m_LinearVelocityVertical= msg_telemetry.Velocity_Vertical; emit LinearVelocityVerticalChanged();
    m_PositionAccuracy= msg_telemetry.Position_Accuracy; emit PositionAccuracyChanged();
    m_SpeedAccuracy= msg_telemetry.Speed_Accuracy; emit SpeedAccuracyChanged();
    m_LinearAccelerationX= msg_telemetry.Acceleration_X; emit LinearAccelerationXChanged();
    m_LinearAccelerationY=msg_telemetry.Acceleration_Y; emit LinearAccelerationYChanged();
    m_LinearAccelerationZ=msg_telemetry.Acceleration_Z; emit LinearAccelerationZChanged();
    m_ECEFVectorPositionX=msg_telemetry.ECEF_Position_X; emit ECEFVectorPositionXChanged();
    m_ECEFVectorPositionY=msg_telemetry.ECEF_Position_Y; emit ECEFVectorPositionYChanged();
    m_ECEFVectorPositionZ=msg_telemetry.ECEF_Position_Z; emit ECEFVectorPositionZChanged();
    m_ECEFVectorVelocityX=msg_telemetry.ECEF_Velocity_X; emit ECEFVectorVelocityXChanged();
    m_ECEFVectorVelocityY=msg_telemetry.ECEF_Velocity_Y; emit ECEFVectorVelocityYChanged();
    m_ECEFVectorVelocityZ=msg_telemetry.ECEF_Velocity_Z; emit ECEFVectorVelocityZChanged();
    m_RollAngle=msg_telemetry.Roll_Angle; emit RollAngleChanged();
    m_YawAngle=msg_telemetry.Yaw_Angle; emit PitchAngleChanged();
    m_PitchAngle=msg_telemetry.Pitch_Angle; emit YawAngleChanged();
    m_AngularRatePitch=msg_telemetry.Angular_Rate_Pitch; emit AngularRatePitchChanged();
    m_AngularRateRoll=msg_telemetry.Angular_Rate_Roll; emit AngularRateRollChanged();
    m_AngularRateYaw=msg_telemetry.Angular_Rate_Yaw; emit AngularRateYawChanged();
    //m_Quaternion0= msg_telemetry.Quaternion_0; emit Quaternion0Changed();
    //m_Quaternion1= msg_telemetry.Quaternion_1; emit Quaternion1Changed();
    //m_Quaternion2= msg_telemetry.Quaternion_2; emit Quaternion2Changed();
    //m_Quaternion3= msg_telemetry.Quaternion_3; emit Quaternion3Changed();
    m_NumberOfGPSSatellite= msg_telemetry.Satellite_Num; emit NumberOfGPSSatelliteChanged();

    /* TELEMETRY STATUS MASK */
    std::bitset<64> bitSet(msg_telemetry.Telemetry_Status_Mask);
    m_telemetry0 = bitSet.test(0); emit telemetry0Changed();
    m_telemetry1 = bitSet.test(1); emit telemetry1Changed();
    m_telemetry2 = bitSet.test(2); emit telemetry2Changed();
    m_telemetry3 = bitSet.test(3); emit telemetry3Changed();
    m_telemetry4 = bitSet.test(4); emit telemetry4Changed();
    m_telemetry5 = bitSet.test(5); emit telemetry5Changed();
    m_telemetry6 = bitSet.test(6); emit telemetry6Changed();
    m_telemetry7 = bitSet.test(7); emit telemetry7Changed();
    m_telemetry8 = bitSet.test(8); emit telemetry8Changed();
    m_telemetry9 = bitSet.test(9); emit telemetry9Changed();
    m_telemetry10 = bitSet.test(10); emit telemetry10Changed();
    m_telemetry11 = bitSet.test(11); emit telemetry11Changed();
    m_telemetry12 = bitSet.test(12); emit telemetry12Changed();
    m_telemetry13 = bitSet.test(13); emit telemetry13Changed();
    m_telemetry14 = bitSet.test(14); emit telemetry14Changed();
    m_telemetry15 = bitSet.test(15); emit telemetry15Changed();
    m_telemetry16 = bitSet.test(16); emit telemetry16Changed();
    m_telemetry17 = bitSet.test(17); emit telemetry17Changed();
    m_telemetry18 = bitSet.test(18); emit telemetry18Changed();
    m_telemetry19 = bitSet.test(19); emit telemetry19Changed();
    m_telemetry20 = bitSet.test(20); emit telemetry20Changed();
    m_telemetry21 = bitSet.test(21); emit telemetry21Changed();
    m_telemetry22 = bitSet.test(22); emit telemetry22Changed();
    m_telemetry23 = bitSet.test(23); emit telemetry23Changed();
    m_telemetry24 = bitSet.test(24); emit telemetry24Changed();
    m_telemetry25 = bitSet.test(25); emit telemetry25Changed();
    m_telemetry26 = bitSet.test(26); emit telemetry26Changed();
    m_telemetry27 = bitSet.test(27); emit telemetry27Changed();
    m_telemetry28 = bitSet.test(28); emit telemetry28Changed();
    m_telemetry29 = bitSet.test(29); emit telemetry29Changed();
    m_telemetry30 = bitSet.test(30); emit telemetry30Changed();
    m_telemetry31 = bitSet.test(31); emit telemetry31Changed();

    m_AnemCommErrorCounter = extractBits64(bitSet,32,40); emit AnemCommErrorCounterChanged();
    m_RDAltCommErrorCounter = extractBits64(bitSet,40,48); emit RDAltCommErrorCounterChanged();
    m_GNSSCommErrorCounter = extractBits64(bitSet,48,56); emit GNSSCommErrorCounterChanged();
    m_PLAltCommErrorCounter = extractBits64(bitSet,56,64); emit PLAltCommErrorCounterChanged();
}

uint8_t HMI::extractBits64(const std::bitset<64> the_bitset, size_t start_bit, size_t end_bit) {
    unsigned long mask = 1;
    unsigned long result = 0;
    for (size_t i = start_bit; i < end_bit; ++ i) {
        if (the_bitset.test(i))
           result |= mask;
        mask <<= 1;
    }
    return result;
}
uint8_t HMI::extractBits32(const std::bitset<32> the_bitset, size_t start_bit, size_t end_bit) {
    unsigned long mask = 1;
    unsigned long result = 0;
    for (size_t i = start_bit; i < end_bit; ++ i) {
        if (the_bitset.test(i))
           result |= mask;
        mask <<= 1;
    }
    return result;
}
uint8_t HMI::extractBits16(const std::bitset<16> the_bitset, size_t start_bit, size_t end_bit) {
    unsigned long mask = 1;
    unsigned long result = 0;
    for (size_t i = start_bit; i < end_bit; ++ i) {
        if (the_bitset.test(i))
           result |= mask;
        mask <<= 1;
    }
    return result;
}
uint8_t HMI::extractBits8(const std::bitset<8> the_bitset, size_t start_bit, size_t end_bit) {
    unsigned long mask = 1;
    unsigned long result = 0;
    for (size_t i = start_bit; i < end_bit; ++ i) {
        if (the_bitset.test(i))
           result |= mask;
        mask <<= 1;
    }
    return result;
}

/*!
    \fn void HMI::showDataSystemStatus(const mavlink_system_status_pack_t msg_status)

    It show in the GUI the data related system status
*/
void HMI::showDataSystemStatus(const mavlink_system_status_pack_t msg_status)
{
    qInfo() << "showDataSystemStatus = CALL" ;

    m_FlightMode = msg_status.Flight_Mode; emit FlightModeChanged();
    m_FlightPhase= msg_status.Flight_Phase; emit FlightPhaseChanged();
    m_FlightPhaseExecutionTime= msg_status.Flight_Phase_Time; emit FlightPhaseExecutionTimeChanged();
    m_TelemetryModuleStatusMask= msg_status.Telemetry_Module_Status_Mask; emit CoreModuleStatusMaskChanged();
    m_StorageModuleStatusMask= msg_status.Storage_Module_Status_Mask; emit TelemetryModuleStatusMaskChanged();
    m_GuidanceModuleStatusMask= msg_status.Guidance_Module_Status_Mask; emit GuidanceModuleStatusMaskChanged();
    m_CoreModuleStatusMask= msg_status.Core_Module_Status_Mask; emit StorageModuleStatusMaskChanged();
    m_RadioLinkModuleStatusMask= msg_status.Radio_Link_Module_Status_Mask; emit RadioLinkModuleStatusMaskChanged();

    std::bitset<32> bitSet(msg_status.Core_Module_Status_Mask);
    m_systemCoreMask0 = bitSet.test(0); emit systemCoreMask0Changed();
    m_systemCoreMask1 = bitSet.test(1); emit systemCoreMask1Changed();
    m_systemCoreMask2 = bitSet.test(2); emit systemCoreMask2Changed();
    m_systemCoreMask3 = bitSet.test(3); emit systemCoreMask3Changed();
    m_systemCoreMask4 = bitSet.test(4); emit systemCoreMask4Changed();
    m_systemCoreMask5 = bitSet.test(5); emit systemCoreMask5Changed();
    m_systemCoreMask6 = bitSet.test(6); emit systemCoreMask6Changed();
    m_systemCoreMask7 = bitSet.test(7); emit systemCoreMask7Changed();
    m_systemCoreMask8 = bitSet.test(8); emit systemCoreMask8Changed();
    m_systemCoreMask9 = bitSet.test(9); emit systemCoreMask9Changed();
    m_systemCoreMask10 = bitSet.test(10); emit systemCoreMask10Changed();
    m_systemCoreMask11 = bitSet.test(11); emit systemCoreMask11Changed();
    m_systemCoreMask12 = bitSet.test(12); emit systemCoreMask12Changed();
    m_systemCoreMask13 = bitSet.test(13); emit systemCoreMask13Changed();
    m_systemCoreMask14 = bitSet.test(14); emit systemCoreMask14Changed();
    m_systemCoreMask15 = bitSet.test(15); emit systemCoreMask15Changed();

    update_communicationErrorCounter(extractBits32(bitSet,16,24)); emit communicationErrorCounterChanged();

    printf("SYS STATUS UPDATED \n");
    printf("FLIGHT MODE %d \n",m_FlightMode);
    printf("FLIGHT PHASE %d \n",m_FlightPhase);
}

/*!
    \fn void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)

    It show in the GUI the data related motor status
*/
void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)
{
    m_MotorARealPosition = msg_status.Motor_A_Real_Position;emit MotorADemandPositionChanged();
    m_MotorADemandPosition= msg_status.Motor_A_Demand_Position;emit MotorAFaultsMaskChanged();
    m_MotorATemp=msg_status.Motor_A_Temperature;emit MotorARealPositionChanged();
    m_MotorATorque= msg_status.Motor_A_Torque;emit MotorATempChanged();
    m_MotorAFaultsMask=msg_status.Motor_A_Faults_Mask;emit MotorATorqueChanged();

    m_MotorBRealPosition = msg_status.Motor_B_Real_Position;emit MotorBDemandPositionChanged();
    m_MotorBDemandPosition= msg_status.Motor_B_Demand_Position;emit MotorBFaultsMaskChanged();
    m_MotorBTemp=msg_status.Motor_B_Temperature;emit MotorBRealPositionChanged();
    m_MotorBTorque= msg_status.Motor_B_Torque;emit MotorBTempChanged();
    m_MotorBFaultsMask=msg_status.Motor_B_Faults_Mask;emit MotorBTorqueChanged();

    m_BMSVoltage= msg_status.BMS_Voltage;emit BMSVoltageChanged();
    m_BMSAbsorption=msg_status.BMS_Absorption;emit BMSAbsorptionChanged();
    m_BMSTemp= msg_status.BMS_Temperature;emit BMSTempChanged();





    std::bitset<32> bitSet(msg_status.BMS_Faults_Mask);
    m_BMS0 = bitSet.test(0); emit BMS0Changed();
    m_BMS1 = bitSet.test(1); emit BMS1Changed();
    m_BMS2 = bitSet.test(2); emit BMS2Changed();
    m_BMS3 = bitSet.test(3); emit BMS3Changed();
    m_BMS4 = bitSet.test(4); emit BMS4Changed();
    m_BMS5 = bitSet.test(5); emit BMS5Changed();
    m_BMS6 = bitSet.test(6); emit BMS6Changed();
    m_BMS7 = bitSet.test(7); emit BMS7Changed();
    m_BMS8 = bitSet.test(8); emit BMS8Changed();
    m_BMS9 = bitSet.test(9); emit BMS9Changed();
    m_BMS10 = bitSet.test(10); emit BMS10Changed();
    m_BMS11 = bitSet.test(11); emit BMS11Changed();
    m_BMS12 = bitSet.test(12); emit BMS12Changed();
    m_BMS13 = bitSet.test(13); emit BMS13Changed();
    m_BMS14 = bitSet.test(14); emit BMS14Changed();
    m_BMS15 = bitSet.test(15); emit BMS15Changed();
    m_BMS16 = bitSet.test(16); emit BMS16Changed();
    m_BMS17 = bitSet.test(17); emit BMS17Changed();
    m_BMS18 = bitSet.test(18); emit BMS18Changed();
    m_BMS19 = bitSet.test(19); emit BMS19Changed();
    m_BMS20 = bitSet.test(20); emit BMS20Changed();
    m_BMS21 = bitSet.test(21); emit BMS21Changed();
    m_BMS22 = bitSet.test(22); emit BMS22Changed();
    m_BMS23 = bitSet.test(23); emit BMS23Changed();
    m_BMS24 = bitSet.test(24); emit BMS24Changed();
    m_BMS25 = bitSet.test(25); emit BMS25Changed();
    m_BMS26 = bitSet.test(26); emit BMS26Changed();
    m_BMS27 = bitSet.test(27); emit BMS27Changed();
    m_BMS28 = bitSet.test(28); emit BMS28Changed();
    m_BMS29 = bitSet.test(29); emit BMS29Changed();
    m_BMS30 = bitSet.test(30); emit BMS30Changed();
    m_BMS31 = bitSet.test(31); emit BMS31Changed();


    std::bitset<32> motorBitSet(msg_status.Motor_Control_Status_Mask);
    m_motor0 = motorBitSet.test(0); emit motor0Changed();
    m_motor1 = motorBitSet.test(1); emit motor1Changed();
    m_motor2 = motorBitSet.test(2); emit motor2Changed();
    m_motor3 = motorBitSet.test(3); emit motor3Changed();
    m_motor4 = motorBitSet.test(4); emit motor4Changed();
    m_motor5 = motorBitSet.test(5); emit motor5Changed();
    m_motor6 = motorBitSet.test(6); emit motor6Changed();
    m_motor7 = motorBitSet.test(7); emit motor7Changed();
    m_motor8 = motorBitSet.test(8); emit motor8Changed();
    m_motor10 = motorBitSet.test(10); emit motor10Changed();
    m_motor11 = motorBitSet.test(11); emit motor11Changed();
    m_motor12 = motorBitSet.test(12); emit motor12Changed();
    m_motor13 = motorBitSet.test(13); emit motor13Changed();
    m_motor14 = motorBitSet.test(14); emit motor14Changed();
    m_motor15 = motorBitSet.test(15); emit motor15Changed();
    m_motor16 = motorBitSet.test(16); emit motor16Changed();
    m_motor17 = motorBitSet.test(17); emit motor17Changed();
    m_motor18 = motorBitSet.test(18); emit motor18Changed();
    m_motor19 = motorBitSet.test(19); emit motor19Changed();
    m_motor20 = motorBitSet.test(20); emit motor20Changed();
    m_motor21 = motorBitSet.test(21); emit motor21Changed();
    m_motor22 = motorBitSet.test(22); emit motor22Changed();
    m_motor23 = motorBitSet.test(23); emit motor23Changed();
    m_motor24 = motorBitSet.test(24); emit motor24Changed();


    m_ChargeValue = extractBits32(motorBitSet,25,31); emit ChargeValueChanged();

    m_MotorControlStatusMask= msg_status.Motor_Control_Status_Mask;emit MotorControlStatusMaskChanged();

    printf("MOTOR STATUS UPDATED \n");
    printf("BMS VOLTAGE %d \n",m_BMSVoltage);
}

/*!
    \fn void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)

    It show in the GUI the data related radio link
*/
void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)
{

}

/*!
    \fn void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)

    It show in the GUI the data related storage
*/
void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)
{
    m_storageFreeDataSize=msg_storage_status.Storage_Free_Data_Size; emit storageFreeDataSizeChanged();

    std::bitset<64> bitSet(msg_storage_status.Storage_Module_Status_Mask);
    m_storage0 = bitSet.test(0); emit storage0Changed();
    m_storage1 = bitSet.test(1); emit storage1Changed();
    m_storage2 = bitSet.test(2); emit storage2Changed();
    m_storage3 = bitSet.test(3); emit storage3Changed();
    m_storage4 = bitSet.test(4); emit storage4Changed();
    m_storage5 = bitSet.test(5); emit storage5Changed();
    m_storage6 = bitSet.test(6); emit storage6Changed();
    m_storage7 = bitSet.test(7); emit storage7Changed();
    m_storage8 = bitSet.test(8); emit storage8Changed();
    m_storage9 = bitSet.test(9); emit storage9Changed();
    m_storage10 = bitSet.test(10); emit storage10Changed();
    m_storage11 = bitSet.test(11); emit storage11Changed();
    m_storage12 = bitSet.test(12); emit storage12Changed();
    m_storage13 = bitSet.test(13); emit storage13Changed();
    m_storage14 = bitSet.test(14); emit storage14Changed();
    m_storage15 = bitSet.test(15); emit storage15Changed();
    m_storage16 = bitSet.test(16); emit storage16Changed();
    m_storage17 = bitSet.test(17); emit storage17Changed();
    m_storage18 = bitSet.test(18); emit storage18Changed();
    m_storage19 = bitSet.test(19); emit storage19Changed();
    m_storage20 = bitSet.test(20); emit storage20Changed();
    m_storage21 = bitSet.test(21); emit storage21Changed();
    m_storage22 = bitSet.test(22); emit storage22Changed();
    m_storage23 = bitSet.test(23); emit storage23Changed();

}

/*!
    \fn void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)

    It show in the GUI the data related guidance
*/
void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)
{

}
