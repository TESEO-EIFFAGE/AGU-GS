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

        \brief The HMI class is the class used to show data in the UI
*/
HMI::HMI(QObject *parent)
    : QObject{parent}
{
    update_telemetryMsgCounter(0);
    update_motorMsgCounter(0);
    update_storageMsgCounter(0);
    update_radiolinkMsgCounter(0);
    update_guidanceMsgCounter(0);
    update_systemMsgCounter(0);
    //initValues();
}

/*!
    \fn void HMI::showData(QVariant msg)

    Calls specialized functions to show the data in the UI
*/
void HMI::showData(QVariant msg) {
    if (msg.canConvert<mavlink_telemetry_data_pack_t>()) {
        showDataTelemetry(msg.value<mavlink_telemetry_data_pack_t>());
        update_telemetryMsgCounter(m_telemetryMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_system_status_pack_t>()) {
        showDataSystemStatus(msg.value<mavlink_system_status_pack_t>());
        update_systemMsgCounter(m_systemMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_motor_status_pack_t>()) {
        showDataMotorStatus(msg.value<mavlink_motor_status_pack_t>());
        update_motorMsgCounter(m_motorMsgCounter+1);
    }

    else if (msg.canConvert<mavlink_guidance_status_pack_t>()) {
        showDataGuidanceStatus(msg.value<mavlink_guidance_status_pack_t>());
        update_guidanceMsgCounter(m_guidanceMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_storage_status_pack_t>()) {
        showDataStorageStatus(msg.value<mavlink_storage_status_pack_t>());
        update_storageMsgCounter(m_storageMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_radio_link_status_pack_t>()) {
        showDataRLStatus(msg.value<mavlink_radio_link_status_pack_t>());
        update_radiolinkMsgCounter(m_radiolinkMsgCounter+1);
    }
}

/*!
    \fn void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)

    Sets UI properties for telemetry-related data
*/
void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry) {
    update_TimeStamp( msg_telemetry.GNSS_Timestamp);
    update_Latitude( msg_telemetry.Latitude);
    update_Longitude(msg_telemetry.Longitude);
    update_GNSSAltitude( msg_telemetry.GNSS_Altitude);
    update_AirSpeed_UVector( msg_telemetry.Air_Speed_U);
    update_AirSpeed_VVector( msg_telemetry.Air_Speed_V);
    update_AirSpeed_WVector( msg_telemetry.Air_Speed_W);
    update_AirTemperature(msg_telemetry.Air_Temperature);
    update_AltitudeFromPayloadAltimeter( msg_telemetry.Altitude_Payload_Altimeter);
    update_AltitudeFromRadarAltimeter(msg_telemetry.Altitude_Main_Altimeter);
    update_LinearVelocityHorizontal( msg_telemetry.Velocity_Horizontal);
    update_LinearVelocityVertical( msg_telemetry.Velocity_Vertical);
    update_PositionAccuracy( msg_telemetry.Position_Accuracy);
    update_SpeedAccuracy( msg_telemetry.Speed_Accuracy);
    update_LinearAccelerationX( msg_telemetry.Acceleration_X);
    update_LinearAccelerationY(msg_telemetry.Acceleration_Y);
    update_LinearAccelerationZ(msg_telemetry.Acceleration_Z);
    update_ECEFVectorPositionX(msg_telemetry.ECEF_Position_X);
    update_ECEFVectorPositionY(msg_telemetry.ECEF_Position_Y);
    update_ECEFVectorPositionZ(msg_telemetry.ECEF_Position_Z);
    update_ECEFVectorVelocityX(msg_telemetry.ECEF_Velocity_X);
    update_ECEFVectorVelocityY(msg_telemetry.ECEF_Velocity_Y);
    update_ECEFVectorVelocityZ(msg_telemetry.ECEF_Velocity_Z);
    update_RollAngle(msg_telemetry.Roll_Angle);
    update_YawAngle(msg_telemetry.Yaw_Angle);
    update_PitchAngle(msg_telemetry.Pitch_Angle);
    update_AngularRatePitch(msg_telemetry.Angular_Rate_Pitch);
    update_AngularRateRoll(msg_telemetry.Angular_Rate_Roll);
    update_AngularRateYaw(msg_telemetry.Angular_Rate_Yaw);
    update_Quaternion0( msg_telemetry.Quaternion_0);
    update_Quaternion1( msg_telemetry.Quaternion_1);
    update_Quaternion2( msg_telemetry.Quaternion_2);
    update_Quaternion3( msg_telemetry.Quaternion_3);
    update_NumberOfGPSSatellite( msg_telemetry.Satellite_Num);

    /* TELEMETRY STATUS MASK */
    std::bitset<64> bitSet(msg_telemetry.Telemetry_Status_Mask);

    update_telemetry0(bitSet.test(0));
    update_telemetry1(bitSet.test(1));
    update_telemetry2(bitSet.test(2));
    update_telemetry3(bitSet.test(3));
    update_telemetry4(bitSet.test(4));
    update_telemetry5(bitSet.test(5));
    update_telemetry6(bitSet.test(6));
    update_telemetry7(bitSet.test(7));
    update_telemetry8(bitSet.test(8));
    update_telemetry9(bitSet.test(9));
    update_telemetry10(bitSet.test(10));
    update_telemetry11(bitSet.test(11));
    update_telemetry12(bitSet.test(12));
    update_telemetry13(bitSet.test(13));
    update_telemetry14(bitSet.test(14));
    update_telemetry15(bitSet.test(15));
    update_telemetry16(bitSet.test(16));
    update_telemetry17(bitSet.test(17));
    update_telemetry18(bitSet.test(18));
    update_telemetry19(bitSet.test(19));
    update_telemetry20(bitSet.test(20));
    update_telemetry21(bitSet.test(21));
    update_telemetry22(bitSet.test(22));
    update_telemetry23(bitSet.test(23));
    update_telemetry24(bitSet.test(24));
    update_telemetry25(bitSet.test(25));
    update_telemetry26(bitSet.test(26));
    update_telemetry27(bitSet.test(27));
    update_telemetry28(bitSet.test(28));
    update_telemetry29(bitSet.test(29));
    update_telemetry30(bitSet.test(30));
    update_telemetry31(bitSet.test(31));

    update_AnemCommErrorCounter(extractBits64(bitSet,32,40));
    update_RDAltCommErrorCounter(extractBits64(bitSet,40,48));
    update_GNSSCommErrorCounter(extractBits64(bitSet,48,56));
    update_PLAltCommErrorCounter(extractBits64(bitSet,56,64));
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

    Sets UI properties for system status-related data
*/
void HMI::showDataSystemStatus(const mavlink_system_status_pack_t msg_status)
{
    update_TimeStampRIO ( msg_status.Log_Timestamp);
    update_FlightMode ( msg_status.Flight_Mode);
    update_FlightPhase( msg_status.Flight_Phase);
    update_FlightPhaseExecutionTime( msg_status.Flight_Phase_Time);
    update_TelemetryModuleStatusMask( msg_status.Telemetry_Module_Status_Mask);
    update_StorageModuleStatusMask( msg_status.Storage_Module_Status_Mask);
    update_GuidanceModuleStatusMask( msg_status.Guidance_Module_Status_Mask);
    update_CoreModuleStatusMask( msg_status.Core_Module_Status_Mask);
    update_RadioLinkModuleStatusMask( msg_status.Radio_Link_Module_Status_Mask);

    std::bitset<32> bitSet(msg_status.Core_Module_Status_Mask);

    update_systemCoreMask0(bitSet.test(0));
    update_systemCoreMask1(bitSet.test(1));
    update_systemCoreMask2(bitSet.test(2));
    update_systemCoreMask3(bitSet.test(3));
    update_systemCoreMask4(bitSet.test(4));
    update_systemCoreMask5(bitSet.test(5));
    update_systemCoreMask6(bitSet.test(6));
    update_systemCoreMask7(bitSet.test(7));
    update_systemCoreMask8(bitSet.test(8));
    update_systemCoreMask9(bitSet.test(9));
    update_systemCoreMask10(bitSet.test(10));
    update_systemCoreMask11(bitSet.test(11));
    update_systemCoreMask12(bitSet.test(12));
    update_systemCoreMask13(bitSet.test(13));
    update_systemCoreMask14(bitSet.test(14));
    update_systemCoreMask15(bitSet.test(15));

    update_communicationErrorCounter(extractBits32(bitSet,16,24));



    std::bitset<32> rlBitSet(msg_status.Radio_Link_Module_Status_Mask);
    update_radiolinkMask0(rlBitSet.test(0));
    update_radiolinkMask1(rlBitSet.test(1));
    update_radiolinkMask2(rlBitSet.test(2));
    update_radiolinkMask3(rlBitSet.test(3));
    update_radiolinkMask8(rlBitSet.test(8));
    update_radiolinkMask9(rlBitSet.test(9));
    update_radiolinkErrorCounter(extractBits32(rlBitSet,24,31));


}

/*!
    \fn void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)

    Sets UI properties for motor status-related data
*/
void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)
{
    update_MotorARealPosition(msg_status.Motor_A_Real_Position);
    update_MotorADemandPosition(msg_status.Motor_A_Demand_Position);
    update_MotorATemp(msg_status.Motor_A_Temperature);
    update_MotorATorque(msg_status.Motor_A_Torque);
    update_MotorAFaultsMask(msg_status.Motor_A_Faults_Mask);

    update_MotorBRealPosition(msg_status.Motor_B_Real_Position);
    update_MotorBDemandPosition(msg_status.Motor_B_Demand_Position);
    update_MotorBTemp(msg_status.Motor_B_Temperature);
    update_MotorBTorque(msg_status.Motor_B_Torque);
    update_MotorBFaultsMask(msg_status.Motor_B_Faults_Mask);

    update_BMSVoltage(msg_status.BMS_Voltage);
    update_BMSAbsorption(msg_status.BMS_Absorption);
    update_BMSTemp(msg_status.BMS_Temperature);

    std::bitset<32> bitSet(msg_status.BMS_Faults_Mask);
    update_BMS0(bitSet.test(0));
    update_BMS1(bitSet.test(1));
    update_BMS2(bitSet.test(2));
    update_BMS3(bitSet.test(3));
    update_BMS4(bitSet.test(4));
    update_BMS5(bitSet.test(5));
    update_BMS6(bitSet.test(6));
    update_BMS7(bitSet.test(7));
    update_BMS8(bitSet.test(8));
    update_BMS9(bitSet.test(9));
    update_BMS10(bitSet.test(10));
    update_BMS11(bitSet.test(11));
    update_BMS12(bitSet.test(12));
    update_BMS13(bitSet.test(13));
    update_BMS14(bitSet.test(14));
    update_BMS15(bitSet.test(15));
    update_BMS16(bitSet.test(16));
    update_BMS17(bitSet.test(17));
    update_BMS18(bitSet.test(18));
    update_BMS19(bitSet.test(19));
    update_BMS20(bitSet.test(20));
    update_BMS21(bitSet.test(21));
    update_BMS22(bitSet.test(22));
    update_BMS23(bitSet.test(23));
    update_BMS24(bitSet.test(24));
    update_BMS25(bitSet.test(25));
    update_BMS26(bitSet.test(26));
    update_BMS27(bitSet.test(27));
    update_BMS28(bitSet.test(28));
    update_BMS29(bitSet.test(29));
    update_BMS30(bitSet.test(30));
    update_BMS31(bitSet.test(31));

    std::bitset<32> motorBitSet(msg_status.Motor_Control_Status_Mask);
    update_motor0(motorBitSet.test(0));
    update_motor1(motorBitSet.test(1));
    update_motor2(motorBitSet.test(2));
    update_motor3(motorBitSet.test(3));
    update_motor4(motorBitSet.test(4));
    update_motor5(motorBitSet.test(5));
    update_motor6(motorBitSet.test(6));
    update_motor7(motorBitSet.test(7));
    update_motor8(motorBitSet.test(8));
    update_motor10(motorBitSet.test(10));
    update_motor11(motorBitSet.test(11));
    update_motor12(motorBitSet.test(12));
    update_motor13(motorBitSet.test(13));
    update_motor14(motorBitSet.test(14));
    update_motor15(motorBitSet.test(15));
    update_motor16(motorBitSet.test(16));
    update_motor17(motorBitSet.test(17));
    update_motor18(motorBitSet.test(18));
    update_motor19(motorBitSet.test(19));
    update_motor20(motorBitSet.test(20));
    update_motor21(motorBitSet.test(21));
    update_motor22(motorBitSet.test(22));
    update_motor23(motorBitSet.test(23));


    update_ChargeValue(extractBits32(motorBitSet,24,31));
    update_MotorControlStatusMask(msg_status.Motor_Control_Status_Mask);

}

/*!
    \fn void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)

    Sets UI properties for radiolink-related data

*/
void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)
{

}

/*!
    \fn void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)

    Sets UI properties for storage-related data

*/
void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)
{
    update_storageFreeDataSize(msg_storage_status.Storage_Free_Data_Size);

    std::bitset<64> bitSet(msg_storage_status.Storage_Module_Status_Mask);
    update_storage0(bitSet.test(0));
    update_storage1(bitSet.test(1));
    update_storage2(bitSet.test(2));
    update_storage3(bitSet.test(3));
    update_storage4(bitSet.test(4));
    update_storage5(bitSet.test(5));
    update_storage6(bitSet.test(6));
    update_storage7(bitSet.test(7));
    update_storage8(bitSet.test(8));
    update_storage9(bitSet.test(9));
    update_storage10(bitSet.test(10));
    update_storage11(bitSet.test(11));
    update_storage12(bitSet.test(12));
    update_storage13(bitSet.test(13));
    update_storage14(bitSet.test(14));
    update_storage15(bitSet.test(15));
    update_storage16(bitSet.test(16));
    update_storage17(bitSet.test(17));
    update_storage18(bitSet.test(18));
    update_storage19(bitSet.test(19));
    update_storage20(bitSet.test(20));
    update_storage21(bitSet.test(21));
    update_storage22(bitSet.test(22));
    update_storage23(bitSet.test(23));

}

/*!
    \fn void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)

    It shows in the GUI the guidance related data
*/
void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)
{

}

void HMI::initValues()
{
    update_telemetryMsgCounter({});
    update_motorMsgCounter({});
    update_storageMsgCounter({});
    update_radiolinkMsgCounter({});
    update_guidanceMsgCounter({});
    update_systemMsgCounter({});

    update_TimeStamp({});
    update_Latitude({});
    update_Longitude({});
    update_GNSSAltitude({});
    update_AirSpeed_UVector({});
    update_AirSpeed_VVector({});
    update_AirSpeed_WVector({});
    update_AirTemperature({});
    update_AltitudeFromPayloadAltimeter({});
    update_AltitudeFromRadarAltimeter({});
    update_LinearVelocityHorizontal({});
    update_LinearVelocityVertical({});
    update_PositionAccuracy({});
    update_SpeedAccuracy({});
    update_LinearAccelerationX({});
    update_LinearAccelerationY({});
    update_LinearAccelerationZ({});
    update_ECEFVectorPositionX({});
    update_ECEFVectorPositionY({});
    update_ECEFVectorPositionZ({});
    update_ECEFVectorVelocityX({});
    update_ECEFVectorVelocityY({});
    update_ECEFVectorVelocityZ({});
    update_RollAngle({});
    update_YawAngle({});
    update_PitchAngle({});
    update_AngularRatePitch({});
    update_AngularRateRoll({});
    update_AngularRateYaw({});
    update_Quaternion0({});
    update_Quaternion1({});
    update_Quaternion2({});
    update_Quaternion3({});
    update_NumberOfGPSSatellite({});


    update_telemetry0({});
    update_telemetry1({});
    update_telemetry2({});
    update_telemetry3({});
    update_telemetry4({});
    update_telemetry5({});
    update_telemetry6({});
    update_telemetry7({});
    update_telemetry8({});
    update_telemetry9({});
    update_telemetry10({});
    update_telemetry11({});
    update_telemetry12({});
    update_telemetry13({});
    update_telemetry14({});
    update_telemetry15({});
    update_telemetry16({});
    update_telemetry17({});
    update_telemetry18({});
    update_telemetry19({});
    update_telemetry20({});
    update_telemetry21({});
    update_telemetry22({});
    update_telemetry23({});
    update_telemetry24({});
    update_telemetry25({});
    update_telemetry26({});
    update_telemetry27({});
    update_telemetry28({});
    update_telemetry29({});
    update_telemetry30({});
    update_telemetry31({});


    update_AnemCommErrorCounter({});
    update_RDAltCommErrorCounter({});
    update_GNSSCommErrorCounter({});
    update_PLAltCommErrorCounter({});

    update_TimeStampRIO ({});
    update_FlightMode ({});
    update_FlightPhase({});
    update_FlightPhaseExecutionTime({});
    update_TelemetryModuleStatusMask({});
    update_StorageModuleStatusMask({});
    update_GuidanceModuleStatusMask({});
    update_CoreModuleStatusMask({});
    update_RadioLinkModuleStatusMask({});


    update_systemCoreMask0({});
    update_systemCoreMask1({});
    update_systemCoreMask2({});
    update_systemCoreMask3({});
    update_systemCoreMask4({});
    update_systemCoreMask5({});
    update_systemCoreMask6({});
    update_systemCoreMask7({});
    update_systemCoreMask8({});
    update_systemCoreMask9({});
    update_systemCoreMask10({});
    update_systemCoreMask11({});
    update_systemCoreMask12({});
    update_systemCoreMask13({});
    update_systemCoreMask14({});
    update_systemCoreMask15({});

    update_communicationErrorCounter({});



    update_radiolinkMask0({});
    update_radiolinkMask1({});
    update_radiolinkMask2({});
    update_radiolinkMask3({});
    update_radiolinkMask8({});
    update_radiolinkMask9({});
    update_radiolinkErrorCounter({});

    update_MotorARealPosition({});
    update_MotorADemandPosition({});
    update_MotorATemp({});
    update_MotorATorque({});
    update_MotorAFaultsMask({});

    update_MotorBRealPosition({});
    update_MotorBDemandPosition({});
    update_MotorBTemp({});
    update_MotorBTorque({});
    update_MotorBFaultsMask({});

    update_BMSVoltage({});
    update_BMSAbsorption({});
    update_BMSTemp({});

    update_BMS0({});
    update_BMS1({});
    update_BMS2({});
    update_BMS3({});
    update_BMS4({});
    update_BMS5({});
    update_BMS6({});
    update_BMS7({});
    update_BMS8({});
    update_BMS9({});
    update_BMS10({});
    update_BMS11({});
    update_BMS12({});
    update_BMS13({});
    update_BMS14({});
    update_BMS15({});
    update_BMS16({});
    update_BMS17({});
    update_BMS18({});
    update_BMS19({});
    update_BMS20({});
    update_BMS21({});
    update_BMS22({});
    update_BMS23({});
    update_BMS24({});
    update_BMS25({});
    update_BMS26({});
    update_BMS27({});
    update_BMS28({});
    update_BMS29({});
    update_BMS30({});
    update_BMS31({});

    update_motor0({});
    update_motor1({});
    update_motor2({});
    update_motor3({});
    update_motor4({});
    update_motor5({});
    update_motor6({});
    update_motor7({});
    update_motor8({});
    update_motor10({});
    update_motor11({});
    update_motor12({});
    update_motor13({});
    update_motor14({});
    update_motor15({});
    update_motor16({});
    update_motor17({});
    update_motor18({});
    update_motor19({});
    update_motor20({});
    update_motor21({});
    update_motor22({});
    update_motor23({});


    update_ChargeValue({});
    update_MotorControlStatusMask({});

    update_storageFreeDataSize({});

    update_storage0({});
    update_storage1({});
    update_storage2({});
    update_storage3({});
    update_storage4({});
    update_storage5({});
    update_storage6({});
    update_storage7({});
    update_storage8({});
    update_storage9({});
    update_storage10({});
    update_storage11({});
    update_storage12({});
    update_storage13({});
    update_storage14({});
    update_storage15({});
    update_storage16({});
    update_storage17({});
    update_storage18({});
    update_storage19({});
    update_storage20({});
    update_storage21({});
    update_storage22({});
    update_storage23({});
}
