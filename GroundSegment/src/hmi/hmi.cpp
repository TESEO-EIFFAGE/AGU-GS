#include "hmi.h"
#include <bitset>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QStandardPaths>
#include <QDir>
#include <QSettings>

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
void HMI::loadDescriptions()
{
    update_TimeStampDesc(initDesc("TimeStamp"));
    update_TimeStampRIODesc(initDesc("TimeStampRIO"));
    update_LatitudeDesc(initDesc("Latitude"));
    update_LongitudeDesc(initDesc("Longitude"));
    update_GNSSAltitudeDesc(initDesc("GNSSAltitude"));
    update_AirSpeed_UVectorDesc(initDesc("AirSpeed_UVector"));
    update_AirSpeed_VVectorDesc(initDesc("AirSpeed_VVector"));
    update_AirSpeed_WVectorDesc(initDesc("AirSpeed_WVector"));
    update_AirTemperatureDesc(initDesc("AirTemperature"));
    update_AltitudeFromRadarAltimeterDesc(initDesc("AltitudeFromRadarAltimeter"));
    update_AltitudeFromPayloadAltimeterDesc(initDesc("AltitudeFromPayloadAltimeter"));
    update_LinearVelocityHorizontalDesc(initDesc("LinearVelocityHorizontal"));
    update_LinearVelocityVerticalDesc(initDesc("LinearVelocityVertical"));
    update_PositionAccuracyDesc(initDesc("PositionAccuracy"));
    update_SpeedAccuracyDesc(initDesc("SpeedAccuracy"));
    update_LinearAccelerationXDesc(initDesc("LinearAccelerationX"));
    update_LinearAccelerationYDesc(initDesc("LinearAccelerationY"));
    update_LinearAccelerationZDesc(initDesc("LinearAccelerationZ"));
    update_ECEFVectorPositionXDesc(initDesc("ECEFVectorPositionX"));
    update_ECEFVectorPositionYDesc(initDesc("ECEFVectorPositionY"));
    update_ECEFVectorPositionZDesc(initDesc("ECEFVectorPositionZ"));
    update_ECEFVectorVelocityXDesc(initDesc("ECEFVectorVelocityX"));
    update_ECEFVectorVelocityYDesc(initDesc("ECEFVectorVelocityY"));
    update_ECEFVectorVelocityZDesc(initDesc("ECEFVectorVelocityZ"));
    update_RollAngleDesc(initDesc("RollAngle"));
    update_PitchAngleDesc(initDesc("PitchAngle"));
    update_YawAngleDesc(initDesc("YawAngle"));
    update_AngularRateRollDesc(initDesc("AngularRateRoll"));
    update_AngularRatePitchDesc(initDesc("AngularRatePitch"));
    update_AngularRateYawDesc(initDesc("AngularRateYaw"));
    update_Quaternion0Desc(initDesc("Quaternion0"));
    update_Quaternion1Desc(initDesc("Quaternion1"));
    update_Quaternion2Desc(initDesc("Quaternion2"));
    update_Quaternion3Desc(initDesc("Quaternion3"));
    update_NumberOfGPSSatelliteDesc(initDesc("NumberOfGPSSatellite"));
    update_AnemCommErrorCounterDesc(initDesc("AnemCommErrorCounter"));
    update_RDAltCommErrorCounterDesc(initDesc("RDAltCommErrorCounter"));
    update_GNSSCommErrorCounterDesc(initDesc("GNSSCommErrorCounter"));
    update_PLAltCommErrorCounterDesc(initDesc("PLAltCommErrorCounter"));


    update_MotorARealPositionDesc(initDesc("MotorARealPosition"));
    update_MotorADemandPositionDesc(initDesc("MotorADemandPosition"));
    update_MotorATorqueDesc(initDesc("MotorATorque"));
    update_MotorATempDesc(initDesc("MotorATemp"));

    update_MotorBRealPositionDesc(initDesc("MotorBRealPosition"));
    update_MotorBDemandPositionDesc(initDesc("MotorBDemandPosition"));
    update_MotorBTorqueDesc(initDesc("MotorBTorque"));
    update_MotorBTempDesc(initDesc("MotorBTemp"));

    update_BMSVoltageDesc(initDesc("BMSVoltage"));
    update_BMSAbsorptionDesc(initDesc("BMSAbsorption"));
    update_BMSTempDesc(initDesc("BMSTemp"));

    update_ChargeValueDesc(initDesc("ChargeValue"));

    update_FlightModeDesc(initDesc("FlightMode"));
    update_FlightPhaseDesc(initDesc("FlightPhase"));
    update_FlightPhaseExecutionTimeDesc(initDesc("FlightPhaseExecutionTime"));

    update_communicationErrorCounterDesc(initDesc("communicationErrorCounter"));

    update_RSSIDesc(initDesc("RSSI"));

    update_storageFreeDataSizeDesc(initDesc("storageFreeDataSize"));
}

void HMI::loadBoundingBox()
{
    update_LatTopLeft(initMap("LatTopLeft"));
    update_LongTopLeft(initMap("LongTopLeft"));
    update_LatBotRight(initMap("LatBotRight"));
    update_LongBotRight(initMap("LongBotRight"));
}

HMI::HMI(QObject *parent)
    : QObject{parent}
{
    timerTelemetry= new QTimer(this);
    timerSystem= new QTimer(this);
    timerGuidance= new QTimer(this);
    timerMotor= new QTimer(this);
    timerRadioLink= new QTimer(this);
    timerStorage= new QTimer(this);

    timerTelemetry->setInterval(1000);
    timerMotor->setInterval(1000);
    timerGuidance->setInterval(1000);
    timerRadioLink->setInterval(1000);
    timerStorage->setInterval(6000);
    timerSystem->setInterval(1000);

    update_msgTelemetryOld(true);
    update_msgMotorOld(true);
    update_msgGuidanceOld(true);
    update_msgRadioLinkOld(true);
    update_msgSystemOld(true);
    update_msgStorageOld(true);

    QObject::connect(timerTelemetry,&QTimer::timeout,this, [this](){update_msgTelemetryOld(true);});
    QObject::connect(timerMotor,&QTimer::timeout,this,  [this](){update_msgMotorOld(true);});
    QObject::connect(timerGuidance,&QTimer::timeout,this,  [this](){update_msgGuidanceOld(true);});
    QObject::connect(timerRadioLink,&QTimer::timeout,this,  [this](){update_msgRadioLinkOld(true);});
    QObject::connect(timerSystem,&QTimer::timeout,this,  [this](){update_msgSystemOld(true);});
    QObject::connect(timerStorage,&QTimer::timeout,this,  [this](){update_msgStorageOld(true);});

    loadBoundingBox();
    loadDescriptions();
    //initValues();
}

/*!
    \fn void HMI::showData(QVariant msg)

    Calls specialized functions to show the data in the UI
*/
void HMI::showData(QVariant msg) {
    if (msg.canConvert<mavlink_telemetry_data_pack_t>()) {
        update_msgTelemetryOld(false);
        timerTelemetry->start();
        showDataTelemetry(msg.value<mavlink_telemetry_data_pack_t>());
        update_telemetryMsgCounter(m_telemetryMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_system_status_pack_t>()) {
        update_msgSystemOld(false);
        timerSystem->start();
        showDataSystemStatus(msg.value<mavlink_system_status_pack_t>());
        update_systemMsgCounter(m_systemMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_motor_status_pack_t>()) {
        update_msgMotorOld(false);
        timerMotor->start();
        showDataMotorStatus(msg.value<mavlink_motor_status_pack_t>());
        update_motorMsgCounter(m_motorMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_guidance_status_pack_t>()) {
        update_msgGuidanceOld(false);
        timerGuidance->start();
        showDataGuidanceStatus(msg.value<mavlink_guidance_status_pack_t>());
        update_guidanceMsgCounter(m_guidanceMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_storage_status_pack_t>()) {
        update_msgStorageOld(false);
        timerStorage->start();
        showDataStorageStatus(msg.value<mavlink_storage_status_pack_t>());
        update_storageMsgCounter(m_storageMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_radio_link_status_pack_t>()) {
        update_msgRadioLinkOld(false);
        timerRadioLink->start();
        showDataRLStatus(msg.value<mavlink_radio_link_status_pack_t>());
        update_radiolinkMsgCounter(m_radiolinkMsgCounter+1);
    }
}

/*!
    \fn void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)

    update_s UI properties for telemetry-related data
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
    std::bitset<64> bitset(msg_telemetry.Telemetry_Status_Mask);

    update_telemetry0(bitset.test(0));
    update_telemetry1(bitset.test(1));
    update_telemetry2(bitset.test(2));
    update_telemetry3(bitset.test(3));
    update_telemetry4(bitset.test(4));
    update_telemetry5(bitset.test(5));
    update_telemetry6(bitset.test(6));
    update_telemetry7(bitset.test(7));
    update_telemetry8(bitset.test(8));
    update_telemetry9(bitset.test(9));
    update_telemetry10(bitset.test(10));
    update_telemetry11(bitset.test(11));
    update_telemetry12(bitset.test(12));
    update_telemetry13(bitset.test(13));
    update_telemetry14(bitset.test(14));
    update_telemetry15(bitset.test(15));
    update_telemetry16(bitset.test(16));
    update_telemetry17(bitset.test(17));
    update_telemetry18(bitset.test(18));
    update_telemetry19(bitset.test(19));
    update_telemetry20(bitset.test(20));
    update_telemetry21(bitset.test(21));
    update_telemetry22(bitset.test(22));
    update_telemetry23(bitset.test(23));
    update_telemetry24(bitset.test(24));
    update_telemetry25(bitset.test(25));
    update_telemetry26(bitset.test(26));
    update_telemetry27(bitset.test(27));
    update_telemetry28(bitset.test(28));
    update_telemetry29(bitset.test(29));
    update_telemetry30(bitset.test(30));
    update_telemetry31(bitset.test(31));

    update_AnemCommErrorCounter(extractBits64(bitset,32,40));
    update_RDAltCommErrorCounter(extractBits64(bitset,40,48));
    update_GNSSCommErrorCounter(extractBits64(bitset,48,56));
    update_PLAltCommErrorCounter(extractBits64(bitset,56,64));
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

    update_s UI properties for system status-related data
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

    std::bitset<32> bitset(msg_status.Core_Module_Status_Mask);

    update_systemCoreMask0(bitset.test(0));
    update_systemCoreMask1(bitset.test(1));
    update_systemCoreMask2(bitset.test(2));
    update_systemCoreMask3(bitset.test(3));
    update_systemCoreMask4(bitset.test(4));
    update_systemCoreMask5(bitset.test(5));
    update_systemCoreMask6(bitset.test(6));
    update_systemCoreMask7(bitset.test(7));
    update_systemCoreMask8(bitset.test(8));
    update_systemCoreMask9(bitset.test(9));
    update_systemCoreMask10(bitset.test(10));
    update_systemCoreMask11(bitset.test(11));
    update_systemCoreMask12(bitset.test(12));
    update_systemCoreMask13(bitset.test(13));
    update_systemCoreMask14(bitset.test(14));
    update_systemCoreMask15(bitset.test(15));

    update_communicationErrorCounter(extractBits32(bitset,16,24));



    std::bitset<32> rlBitset(msg_status.Radio_Link_Module_Status_Mask);
    update_radiolinkMask0(rlBitset.test(0));
    update_radiolinkMask1(rlBitset.test(1));
    update_radiolinkMask2(rlBitset.test(2));
    update_radiolinkMask3(rlBitset.test(3));
    update_radiolinkMask8(rlBitset.test(8));
    update_radiolinkMask9(rlBitset.test(9));
    update_radiolinkErrorCounter(extractBits32(rlBitset,24,31));


}

/*!
    \fn void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)

    update_s UI properties for motor status-related data
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

    std::bitset<32> bitset(msg_status.BMS_Faults_Mask);
    update_BMS0(bitset.test(0));
    update_BMS1(bitset.test(1));
    update_BMS2(bitset.test(2));
    update_BMS3(bitset.test(3));
    update_BMS4(bitset.test(4));
    update_BMS5(bitset.test(5));
    update_BMS6(bitset.test(6));
    update_BMS7(bitset.test(7));
    update_BMS8(bitset.test(8));
    update_BMS9(bitset.test(9));
    update_BMS10(bitset.test(10));
    update_BMS11(bitset.test(11));
    update_BMS12(bitset.test(12));
    update_BMS13(bitset.test(13));
    update_BMS14(bitset.test(14));
    update_BMS15(bitset.test(15));
    update_BMS16(bitset.test(16));
    update_BMS17(bitset.test(17));
    update_BMS18(bitset.test(18));
    update_BMS19(bitset.test(19));
    update_BMS20(bitset.test(20));
    update_BMS21(bitset.test(21));
    update_BMS22(bitset.test(22));
    update_BMS23(bitset.test(23));
    update_BMS24(bitset.test(24));
    update_BMS25(bitset.test(25));
    update_BMS26(bitset.test(26));
    update_BMS27(bitset.test(27));
    update_BMS28(bitset.test(28));
    update_BMS29(bitset.test(29));
    update_BMS30(bitset.test(30));
    update_BMS31(bitset.test(31));

    std::bitset<32> motorBitset(msg_status.Motor_Control_Status_Mask);
    update_motor0(motorBitset.test(0));
    update_motor1(motorBitset.test(1));
    update_motor2(motorBitset.test(2));
    update_motor3(motorBitset.test(3));
    update_motor4(motorBitset.test(4));
    update_motor5(motorBitset.test(5));
    update_motor6(motorBitset.test(6));
    update_motor7(motorBitset.test(7));
    update_motor8(motorBitset.test(8));
    update_motor10(motorBitset.test(10));
    update_motor11(motorBitset.test(11));
    update_motor12(motorBitset.test(12));
    update_motor13(motorBitset.test(13));
    update_motor14(motorBitset.test(14));
    update_motor15(motorBitset.test(15));
    update_motor16(motorBitset.test(16));
    update_motor17(motorBitset.test(17));
    update_motor18(motorBitset.test(18));
    update_motor19(motorBitset.test(19));
    update_motor20(motorBitset.test(20));
    update_motor21(motorBitset.test(21));
    update_motor22(motorBitset.test(22));
    update_motor23(motorBitset.test(23));


    update_ChargeValue(extractBits32(motorBitset,24,31));
    update_MotorControlStatusMask(msg_status.Motor_Control_Status_Mask);

}

/*!
    \fn void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)

    update_s UI properties for radiolink-related data

*/
void HMI::showDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)
{
    Q_UNUSED(msg_radio_status)
}

/*!
    \fn void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)

    update_s UI properties for storage-related data

*/
void HMI::showDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)
{
    update_storageFreeDataSize(msg_storage_status.Storage_Free_Data_Size);

    std::bitset<64> bitset(msg_storage_status.Storage_Module_Status_Mask);
    update_storage0(bitset.test(0));
    update_storage1(bitset.test(1));
    update_storage2(bitset.test(2));
    update_storage3(bitset.test(3));
    update_storage4(bitset.test(4));
    update_storage5(bitset.test(5));
    update_storage6(bitset.test(6));
    update_storage7(bitset.test(7));
    update_storage8(bitset.test(8));
    update_storage9(bitset.test(9));
    update_storage10(bitset.test(10));
    update_storage11(bitset.test(11));
    update_storage12(bitset.test(12));
    update_storage13(bitset.test(13));
    update_storage14(bitset.test(14));
    update_storage15(bitset.test(15));
    update_storage16(bitset.test(16));
    update_storage17(bitset.test(17));
    update_storage18(bitset.test(18));
    update_storage19(bitset.test(19));
    update_storage20(bitset.test(20));
    update_storage21(bitset.test(21));
    update_storage22(bitset.test(22));
    update_storage23(bitset.test(23));

}

/*!
    \fn void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)

    It shows in the GUI the guidance related data
*/
void HMI::showDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)
{
    Q_UNUSED(msg_guidance_status)
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

QString HMI::initDesc(const QString &str)
{
    QString defaultValue{str};
    QString docFolder(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    const QString settingsFileName(docFolder + "/agu-settings/params-descriptions.ini");
    const QString settingsTplName(docFolder + "/agu-settings/params-descriptions-template.ini");
    if (!QFileInfo(settingsFileName).exists()) {
        QFile::copy(settingsTplName, settingsFileName);
    }
    if (QFileInfo(settingsFileName).exists()) {
        QSettings settings (settingsFileName, QSettings::IniFormat);
        QStringList childKeys = settings.childKeys();
        for (const QString& childKey : settings.childKeys())
        {
            if (str.compare(QVariant(childKey).toString()) == 0)
            {
                //printf("Found TimeStamp desc");
                defaultValue = settings.value(childKey).toString();
                break;
            }
        }
    }
    return defaultValue;
}

qint32 HMI::initMap(QString str)
{
    int defaultValue = 0;
    QString docFolder= QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString settingsFileName = docFolder + "/agu-settings/map-parameters.ini";

    if (QFileInfo(settingsFileName).exists()) {
        QSettings settings (settingsFileName, QSettings::IniFormat);
        QStringList childKeys = settings.childKeys();
        foreach (const QString &childKey, childKeys)
        {
            if (str.compare(QVariant(childKey).toString()) == 0)
                defaultValue = settings.value(childKey).toInt();
        }
    }
    return defaultValue;
}
