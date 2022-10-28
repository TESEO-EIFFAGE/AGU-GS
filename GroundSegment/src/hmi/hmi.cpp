#include "hmi.h"
#include <bitset>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QStandardPaths>
#include <QDir>
#include<QSettings>


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

    QObject::connect(timerTelemetry,&QTimer::timeout,this, &HMI::checkTelemetry);
    QObject::connect(timerMotor,&QTimer::timeout,this, &HMI::checkMotor);
    QObject::connect(timerGuidance,&QTimer::timeout,this, &HMI::checkGuidance);
    QObject::connect(timerRadioLink,&QTimer::timeout,this, &HMI::checkRadioLink);
    QObject::connect(timerSystem,&QTimer::timeout,this, &HMI::checkSystem);
    QObject::connect(timerStorage,&QTimer::timeout,this, &HMI::checkStorage);

    setTimeStampDesc(initDesc("TimeStamp"));
    setTimeStampRIODesc(initDesc("TimeStampRIO"));
    setLatitudeDesc(initDesc("Latitude"));
    setLongitudeDesc(initDesc("Longitude"));
    setGNSSAltitudeDesc(initDesc("GNSSAltitude"));
    setAirSpeed_UVectorDesc(initDesc("AirSpeed_UVector"));
    setAirSpeed_VVectorDesc(initDesc("AirSpeed_VVector"));
    setAirSpeed_WVectorDesc(initDesc("AirSpeed_WVector"));
    setAirTemperatureDesc(initDesc("AirTemperature"));
    setAltitudeFromRadarAltimeterDesc(initDesc("AltitudeFromRadarAltimeter"));
    setAltitudeFromPayloadAltimeterDesc(initDesc("AltitudeFromPayloadAltimeter"));
    setLinearVelocityHorizontalDesc(initDesc("LinearVelocityHorizontal"));
    setLinearVelocityVerticalDesc(initDesc("LinearVelocityVertical"));
    setPositionAccuracyDesc(initDesc("PositionAccuracy"));
    setSpeedAccuracyDesc(initDesc("SpeedAccuracy"));
    setLinearAccelerationXDesc(initDesc("LinearAccelerationX"));
    setLinearAccelerationYDesc(initDesc("LinearAccelerationY"));
    setLinearAccelerationZDesc(initDesc("LinearAccelerationZ"));
    setECEFVectorPositionXDesc(initDesc("ECEFVectorPositionX"));
    setECEFVectorPositionYDesc(initDesc("ECEFVectorPositionY"));
    setECEFVectorPositionZDesc(initDesc("ECEFVectorPositionZ"));
    setECEFVectorVelocityXDesc(initDesc("ECEFVectorVelocityX"));
    setECEFVectorVelocityYDesc(initDesc("ECEFVectorVelocityY"));
    setECEFVectorVelocityZDesc(initDesc("ECEFVectorVelocityZ"));
    setRollAngleDesc(initDesc("RollAngle"));
    setPitchAngleDesc(initDesc("PitchAngle"));
    setYawAngleDesc(initDesc("YawAngle"));
    setAngularRateRollDesc(initDesc("AngularRateRoll"));
    setAngularRatePitchDesc(initDesc("AngularRatePitch"));
    setAngularRateYawDesc(initDesc("AngularRateYaw"));
    setQuaternion0Desc(initDesc("Quaternion0"));
    setQuaternion1Desc(initDesc("Quaternion1"));
    setQuaternion2Desc(initDesc("Quaternion2"));
    setQuaternion3Desc(initDesc("Quaternion3"));
    setNumberOfGPSSatelliteDesc(initDesc("NumberOfGPSSatellite"));
    setAnemCommErrorCounterDesc(initDesc("AnemCommErrorCounter"));
    setRDAltCommErrorCounterDesc(initDesc("RDAltCommErrorCounter"));
    setGNSSCommErrorCounterDesc(initDesc("GNSSCommErrorCounter"));
    setPLAltCommErrorCounterDesc(initDesc("PLAltCommErrorCounter"));


    setMotorARealPositionDesc(initDesc("MotorARealPosition"));
    setMotorADemandPositionDesc(initDesc("MotorADemandPosition"));
    setMotorATorqueDesc(initDesc("MotorATorque"));
    setMotorATempDesc(initDesc("MotorATemp"));

    setMotorBRealPositionDesc(initDesc("MotorBRealPosition"));
    setMotorBDemandPositionDesc(initDesc("MotorBDemandPosition"));
    setMotorBTorqueDesc(initDesc("MotorBTorque"));
    setMotorBTempDesc(initDesc("MotorBTemp"));

    setBMSVoltageDesc(initDesc("BMSVoltage"));
    setBMSAbsorptionDesc(initDesc("BMSAbsorption"));
    setBMSTempDesc(initDesc("BMSTemp"));

    setChargeValueDesc(initDesc("ChargeValue"));

    setFlightModeDesc(initDesc("FlightMode"));
    setFlightPhaseDesc(initDesc("FlightPhase"));
    setFlightPhaseExecutionTimeDesc(initDesc("FlightPhaseExecutionTime"));

    setcommunicationErrorCounterDesc(initDesc("communicationErrorCounter"));

    setRSSIDesc(initDesc("RSSI"));

    setstorageFreeDataSizeDesc(initDesc("storageFreeDataSize"));

    //initValues();

}

/*!
    \fn void HMI::showData(QVariant msg)

    Calls specialized functions to show the data in the UI
*/
void HMI::showData(QVariant msg) {
    timerTelemetry->start();
    timerMotor->start();
    timerGuidance->start();
    timerRadioLink->start();
    timerStorage->start();
    timerSystem->start();

    setmsgGuidanceOld(false);
    setmsgSystemOld(false);
    setmsgRadioLinkOld(false);
    setmsgStorageOld(false);
    setmsgMotorOld(false);
    setmsgTelemetryOld(false);

    if (msg.canConvert<mavlink_telemetry_data_pack_t>()) {
        showDataTelemetry(msg.value<mavlink_telemetry_data_pack_t>());
        settelemetryMsgCounter(m_telemetryMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_system_status_pack_t>()) {
        showDataSystemStatus(msg.value<mavlink_system_status_pack_t>());
        setsystemMsgCounter(m_systemMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_motor_status_pack_t>()) {
        showDataMotorStatus(msg.value<mavlink_motor_status_pack_t>());
        setmotorMsgCounter(m_motorMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_guidance_status_pack_t>()) {
        showDataGuidanceStatus(msg.value<mavlink_guidance_status_pack_t>());
        setguidanceMsgCounter(m_guidanceMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_storage_status_pack_t>()) {
        showDataStorageStatus(msg.value<mavlink_storage_status_pack_t>());
        setstorageMsgCounter(m_storageMsgCounter+1);
    }
    else if (msg.canConvert<mavlink_radio_link_status_pack_t>()) {
        showDataRLStatus(msg.value<mavlink_radio_link_status_pack_t>());
        setradiolinkMsgCounter(m_radiolinkMsgCounter+1);
    }
}

/*!
    \fn void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)

    Sets UI properties for telemetry-related data
*/
void HMI::showDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry) {
    setTimeStamp( msg_telemetry.GNSS_Timestamp);
    setLatitude( msg_telemetry.Latitude);
    setLongitude(msg_telemetry.Longitude);
    setGNSSAltitude( msg_telemetry.GNSS_Altitude);
    setAirSpeed_UVector( msg_telemetry.Air_Speed_U);
    setAirSpeed_VVector( msg_telemetry.Air_Speed_V);
    setAirSpeed_WVector( msg_telemetry.Air_Speed_W);
    setAirTemperature(msg_telemetry.Air_Temperature);
    setAltitudeFromPayloadAltimeter( msg_telemetry.Altitude_Payload_Altimeter);
    setAltitudeFromRadarAltimeter(msg_telemetry.Altitude_Main_Altimeter);
    setLinearVelocityHorizontal( msg_telemetry.Velocity_Horizontal);
    setLinearVelocityVertical( msg_telemetry.Velocity_Vertical);
    setPositionAccuracy( msg_telemetry.Position_Accuracy);
    setSpeedAccuracy( msg_telemetry.Speed_Accuracy);
    setLinearAccelerationX( msg_telemetry.Acceleration_X);
    setLinearAccelerationY(msg_telemetry.Acceleration_Y);
    setLinearAccelerationZ(msg_telemetry.Acceleration_Z);
    setECEFVectorPositionX(msg_telemetry.ECEF_Position_X);
    setECEFVectorPositionY(msg_telemetry.ECEF_Position_Y);
    setECEFVectorPositionZ(msg_telemetry.ECEF_Position_Z);
    setECEFVectorVelocityX(msg_telemetry.ECEF_Velocity_X);
    setECEFVectorVelocityY(msg_telemetry.ECEF_Velocity_Y);
    setECEFVectorVelocityZ(msg_telemetry.ECEF_Velocity_Z);
    setRollAngle(msg_telemetry.Roll_Angle);
    setYawAngle(msg_telemetry.Yaw_Angle);
    setPitchAngle(msg_telemetry.Pitch_Angle);
    setAngularRatePitch(msg_telemetry.Angular_Rate_Pitch);
    setAngularRateRoll(msg_telemetry.Angular_Rate_Roll);
    setAngularRateYaw(msg_telemetry.Angular_Rate_Yaw);
    setQuaternion0( msg_telemetry.Quaternion_0);
    setQuaternion1( msg_telemetry.Quaternion_1);
    setQuaternion2( msg_telemetry.Quaternion_2);
    setQuaternion3( msg_telemetry.Quaternion_3);
    setNumberOfGPSSatellite( msg_telemetry.Satellite_Num);

    /* TELEMETRY STATUS MASK */
    std::bitset<64> bitSet(msg_telemetry.Telemetry_Status_Mask);

    settelemetry0(bitSet.test(0));
    settelemetry1(bitSet.test(1));
    settelemetry2(bitSet.test(2));
    settelemetry3(bitSet.test(3));
    settelemetry4(bitSet.test(4));
    settelemetry5(bitSet.test(5));
    settelemetry6(bitSet.test(6));
    settelemetry7(bitSet.test(7));
    settelemetry8(bitSet.test(8));
    settelemetry9(bitSet.test(9));
    settelemetry10(bitSet.test(10));
    settelemetry11(bitSet.test(11));
    settelemetry12(bitSet.test(12));
    settelemetry13(bitSet.test(13));
    settelemetry14(bitSet.test(14));
    settelemetry15(bitSet.test(15));
    settelemetry16(bitSet.test(16));
    settelemetry17(bitSet.test(17));
    settelemetry18(bitSet.test(18));
    settelemetry19(bitSet.test(19));
    settelemetry20(bitSet.test(20));
    settelemetry21(bitSet.test(21));
    settelemetry22(bitSet.test(22));
    settelemetry23(bitSet.test(23));
    settelemetry24(bitSet.test(24));
    settelemetry25(bitSet.test(25));
    settelemetry26(bitSet.test(26));
    settelemetry27(bitSet.test(27));
    settelemetry28(bitSet.test(28));
    settelemetry29(bitSet.test(29));
    settelemetry30(bitSet.test(30));
    settelemetry31(bitSet.test(31));

    setAnemCommErrorCounter(extractBits64(bitSet,32,40));
    setRDAltCommErrorCounter(extractBits64(bitSet,40,48));
    setGNSSCommErrorCounter(extractBits64(bitSet,48,56));
    setPLAltCommErrorCounter(extractBits64(bitSet,56,64));
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
    setTimeStampRIO ( msg_status.Log_Timestamp);
    setFlightMode ( msg_status.Flight_Mode);
    setFlightPhase( msg_status.Flight_Phase);
    setFlightPhaseExecutionTime( msg_status.Flight_Phase_Time);
    setTelemetryModuleStatusMask( msg_status.Telemetry_Module_Status_Mask);
    setStorageModuleStatusMask( msg_status.Storage_Module_Status_Mask);
    setGuidanceModuleStatusMask( msg_status.Guidance_Module_Status_Mask);
    setCoreModuleStatusMask( msg_status.Core_Module_Status_Mask);
    setRadioLinkModuleStatusMask( msg_status.Radio_Link_Module_Status_Mask);

    std::bitset<32> bitSet(msg_status.Core_Module_Status_Mask);

    setsystemCoreMask0(bitSet.test(0));
    setsystemCoreMask1(bitSet.test(1));
    setsystemCoreMask2(bitSet.test(2));
    setsystemCoreMask3(bitSet.test(3));
    setsystemCoreMask4(bitSet.test(4));
    setsystemCoreMask5(bitSet.test(5));
    setsystemCoreMask6(bitSet.test(6));
    setsystemCoreMask7(bitSet.test(7));
    setsystemCoreMask8(bitSet.test(8));
    setsystemCoreMask9(bitSet.test(9));
    setsystemCoreMask10(bitSet.test(10));
    setsystemCoreMask11(bitSet.test(11));
    setsystemCoreMask12(bitSet.test(12));
    setsystemCoreMask13(bitSet.test(13));
    setsystemCoreMask14(bitSet.test(14));
    setsystemCoreMask15(bitSet.test(15));

    setcommunicationErrorCounter(extractBits32(bitSet,16,24));



    std::bitset<32> rlBitSet(msg_status.Radio_Link_Module_Status_Mask);
    setradiolinkMask0(rlBitSet.test(0));
    setradiolinkMask1(rlBitSet.test(1));
    setradiolinkMask2(rlBitSet.test(2));
    setradiolinkMask3(rlBitSet.test(3));
    setradiolinkMask8(rlBitSet.test(8));
    setradiolinkMask9(rlBitSet.test(9));
    setradiolinkErrorCounter(extractBits32(rlBitSet,24,31));


}

/*!
    \fn void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)

    Sets UI properties for motor status-related data
*/
void HMI::showDataMotorStatus(const mavlink_motor_status_pack_t msg_status)
{
    setMotorARealPosition(msg_status.Motor_A_Real_Position);
    setMotorADemandPosition(msg_status.Motor_A_Demand_Position);
    setMotorATemp(msg_status.Motor_A_Temperature);
    setMotorATorque(msg_status.Motor_A_Torque);
    setMotorAFaultsMask(msg_status.Motor_A_Faults_Mask);

    setMotorBRealPosition(msg_status.Motor_B_Real_Position);
    setMotorBDemandPosition(msg_status.Motor_B_Demand_Position);
    setMotorBTemp(msg_status.Motor_B_Temperature);
    setMotorBTorque(msg_status.Motor_B_Torque);
    setMotorBFaultsMask(msg_status.Motor_B_Faults_Mask);

    setBMSVoltage(msg_status.BMS_Voltage);
    setBMSAbsorption(msg_status.BMS_Absorption);
    setBMSTemp(msg_status.BMS_Temperature);

    std::bitset<32> bitSet(msg_status.BMS_Faults_Mask);
    setBMS0(bitSet.test(0));
    setBMS1(bitSet.test(1));
    setBMS2(bitSet.test(2));
    setBMS3(bitSet.test(3));
    setBMS4(bitSet.test(4));
    setBMS5(bitSet.test(5));
    setBMS6(bitSet.test(6));
    setBMS7(bitSet.test(7));
    setBMS8(bitSet.test(8));
    setBMS9(bitSet.test(9));
    setBMS10(bitSet.test(10));
    setBMS11(bitSet.test(11));
    setBMS12(bitSet.test(12));
    setBMS13(bitSet.test(13));
    setBMS14(bitSet.test(14));
    setBMS15(bitSet.test(15));
    setBMS16(bitSet.test(16));
    setBMS17(bitSet.test(17));
    setBMS18(bitSet.test(18));
    setBMS19(bitSet.test(19));
    setBMS20(bitSet.test(20));
    setBMS21(bitSet.test(21));
    setBMS22(bitSet.test(22));
    setBMS23(bitSet.test(23));
    setBMS24(bitSet.test(24));
    setBMS25(bitSet.test(25));
    setBMS26(bitSet.test(26));
    setBMS27(bitSet.test(27));
    setBMS28(bitSet.test(28));
    setBMS29(bitSet.test(29));
    setBMS30(bitSet.test(30));
    setBMS31(bitSet.test(31));

    std::bitset<32> motorBitSet(msg_status.Motor_Control_Status_Mask);
    setmotor0(motorBitSet.test(0));
    setmotor1(motorBitSet.test(1));
    setmotor2(motorBitSet.test(2));
    setmotor3(motorBitSet.test(3));
    setmotor4(motorBitSet.test(4));
    setmotor5(motorBitSet.test(5));
    setmotor6(motorBitSet.test(6));
    setmotor7(motorBitSet.test(7));
    setmotor8(motorBitSet.test(8));
    setmotor10(motorBitSet.test(10));
    setmotor11(motorBitSet.test(11));
    setmotor12(motorBitSet.test(12));
    setmotor13(motorBitSet.test(13));
    setmotor14(motorBitSet.test(14));
    setmotor15(motorBitSet.test(15));
    setmotor16(motorBitSet.test(16));
    setmotor17(motorBitSet.test(17));
    setmotor18(motorBitSet.test(18));
    setmotor19(motorBitSet.test(19));
    setmotor20(motorBitSet.test(20));
    setmotor21(motorBitSet.test(21));
    setmotor22(motorBitSet.test(22));
    setmotor23(motorBitSet.test(23));


    setChargeValue(extractBits32(motorBitSet,24,31));
    setMotorControlStatusMask(msg_status.Motor_Control_Status_Mask);

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
    setstorageFreeDataSize(msg_storage_status.Storage_Free_Data_Size);

    std::bitset<64> bitSet(msg_storage_status.Storage_Module_Status_Mask);
    setstorage0(bitSet.test(0));
    setstorage1(bitSet.test(1));
    setstorage2(bitSet.test(2));
    setstorage3(bitSet.test(3));
    setstorage4(bitSet.test(4));
    setstorage5(bitSet.test(5));
    setstorage6(bitSet.test(6));
    setstorage7(bitSet.test(7));
    setstorage8(bitSet.test(8));
    setstorage9(bitSet.test(9));
    setstorage10(bitSet.test(10));
    setstorage11(bitSet.test(11));
    setstorage12(bitSet.test(12));
    setstorage13(bitSet.test(13));
    setstorage14(bitSet.test(14));
    setstorage15(bitSet.test(15));
    setstorage16(bitSet.test(16));
    setstorage17(bitSet.test(17));
    setstorage18(bitSet.test(18));
    setstorage19(bitSet.test(19));
    setstorage20(bitSet.test(20));
    setstorage21(bitSet.test(21));
    setstorage22(bitSet.test(22));
    setstorage23(bitSet.test(23));

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
    settelemetryMsgCounter(0);
    setmotorMsgCounter(0);
    setstorageMsgCounter(0);
    setradiolinkMsgCounter(0);
    setguidanceMsgCounter(0);
    setsystemMsgCounter(0);

    setTimeStamp(0);
    setLatitude(0);
    setLongitude(0);
    setGNSSAltitude(0);
    setAirSpeed_UVector(0);
    setAirSpeed_VVector(0);
    setAirSpeed_WVector(0);
    setAirTemperature(0);
    setAltitudeFromPayloadAltimeter(0);
    setAltitudeFromRadarAltimeter(0);
    setLinearVelocityHorizontal(0);
    setLinearVelocityVertical(0);
    setPositionAccuracy(0);
    setSpeedAccuracy(0);
    setLinearAccelerationX(0);
    setLinearAccelerationY(0);
    setLinearAccelerationZ(0);
    setECEFVectorPositionX(0);
    setECEFVectorPositionY(0);
    setECEFVectorPositionZ(0);
    setECEFVectorVelocityX(0);
    setECEFVectorVelocityY(0);
    setECEFVectorVelocityZ(0);
    setRollAngle(0);
    setYawAngle(0);
    setPitchAngle(0);
    setAngularRatePitch(0);
    setAngularRateRoll(0);
    setAngularRateYaw(0);
    setQuaternion0(0);
    setQuaternion1(0);
    setQuaternion2(0);
    setQuaternion3(0);
    setNumberOfGPSSatellite(0);


    settelemetry0(0);
    settelemetry1(0);
    settelemetry2(0);
    settelemetry3(0);
    settelemetry4(0);
    settelemetry5(0);
    settelemetry6(0);
    settelemetry7(0);
    settelemetry8(0);
    settelemetry9(0);
    settelemetry10(0);
    settelemetry11(0);
    settelemetry12(0);
    settelemetry13(0);
    settelemetry14(0);
    settelemetry15(0);
    settelemetry16(0);
    settelemetry17(0);
    settelemetry18(0);
    settelemetry19(0);
    settelemetry20(0);
    settelemetry21(0);
    settelemetry22(0);
    settelemetry23(0);
    settelemetry24(0);
    settelemetry25(0);
    settelemetry26(0);
    settelemetry27(0);
    settelemetry28(0);
    settelemetry29(0);
    settelemetry30(0);
    settelemetry31(0);


    setAnemCommErrorCounter(0);
    setRDAltCommErrorCounter(0);
    setGNSSCommErrorCounter(0);
    setPLAltCommErrorCounter(0);

    setTimeStampRIO (0);
    setFlightMode (0);
    setFlightPhase(0);
    setFlightPhaseExecutionTime(0);
    setTelemetryModuleStatusMask(0);
    setStorageModuleStatusMask(0);
    setGuidanceModuleStatusMask(0);
    setCoreModuleStatusMask(0);
    setRadioLinkModuleStatusMask(0);


    setsystemCoreMask0(0);
    setsystemCoreMask1(0);
    setsystemCoreMask2(0);
    setsystemCoreMask3(0);
    setsystemCoreMask4(0);
    setsystemCoreMask5(0);
    setsystemCoreMask6(0);
    setsystemCoreMask7(0);
    setsystemCoreMask8(0);
    setsystemCoreMask9(0);
    setsystemCoreMask10(0);
    setsystemCoreMask11(0);
    setsystemCoreMask12(0);
    setsystemCoreMask13(0);
    setsystemCoreMask14(0);
    setsystemCoreMask15(0);

    setcommunicationErrorCounter(0);



    setradiolinkMask0(0);
    setradiolinkMask1(0);
    setradiolinkMask2(0);
    setradiolinkMask3(0);
    setradiolinkMask8(0);
    setradiolinkMask9(0);
    setradiolinkErrorCounter(0);

    setMotorARealPosition(0);
    setMotorADemandPosition(0);
    setMotorATemp(0);
    setMotorATorque(0);
    setMotorAFaultsMask(0);

    setMotorBRealPosition(0);
    setMotorBDemandPosition(0);
    setMotorBTemp(0);
    setMotorBTorque(0);
    setMotorBFaultsMask(0);

    setBMSVoltage(0);
    setBMSAbsorption(0);
    setBMSTemp(0);

    setBMS0(0);
    setBMS1(0);
    setBMS2(0);
    setBMS3(0);
    setBMS4(0);
    setBMS5(0);
    setBMS6(0);
    setBMS7(0);
    setBMS8(0);
    setBMS9(0);
    setBMS10(0);
    setBMS11(0);
    setBMS12(0);
    setBMS13(0);
    setBMS14(0);
    setBMS15(0);
    setBMS16(0);
    setBMS17(0);
    setBMS18(0);
    setBMS19(0);
    setBMS20(0);
    setBMS21(0);
    setBMS22(0);
    setBMS23(0);
    setBMS24(0);
    setBMS25(0);
    setBMS26(0);
    setBMS27(0);
    setBMS28(0);
    setBMS29(0);
    setBMS30(0);
    setBMS31(0);

    setmotor0(0);
    setmotor1(0);
    setmotor2(0);
    setmotor3(0);
    setmotor4(0);
    setmotor5(0);
    setmotor6(0);
    setmotor7(0);
    setmotor8(0);
    setmotor10(0);
    setmotor11(0);
    setmotor12(0);
    setmotor13(0);
    setmotor14(0);
    setmotor15(0);
    setmotor16(0);
    setmotor17(0);
    setmotor18(0);
    setmotor19(0);
    setmotor20(0);
    setmotor21(0);
    setmotor22(0);
    setmotor23(0);


    setChargeValue(0);
    setMotorControlStatusMask(0);

    setstorageFreeDataSize(0);

    setstorage0(0);
    setstorage1(0);
    setstorage2(0);
    setstorage3(0);
    setstorage4(0);
    setstorage5(0);
    setstorage6(0);
    setstorage7(0);
    setstorage8(0);
    setstorage9(0);
    setstorage10(0);
    setstorage11(0);
    setstorage12(0);
    setstorage13(0);
    setstorage14(0);
    setstorage15(0);
    setstorage16(0);
    setstorage17(0);
    setstorage18(0);
    setstorage19(0);
    setstorage20(0);
    setstorage21(0);
    setstorage22(0);
    setstorage23(0);
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

void HMI::checkTelemetry()
{
    setmsgTelemetryOld(true);
}

void HMI::checkGuidance()
{
    setmsgGuidanceOld(true);
}

void HMI::checkSystem()
{
    setmsgSystemOld(true);
}

void HMI::checkStorage()
{
    setmsgStorageOld(true);
}

void HMI::checkMotor()
{
    setmsgMotorOld(true);
}

void HMI::checkRadioLink()
{
    setmsgRadioLinkOld(true);
}


quint64 HMI::TimeStamp() const
{
    return m_TimeStamp;
}

void HMI::setTimeStamp(quint64 newTimeStamp)
{
    if (m_TimeStamp == newTimeStamp)
        return;
    m_TimeStamp = newTimeStamp;
    emit TimeStampChanged();
}

quint64 HMI::TimeStampRIO() const
{
    return m_TimeStampRIO;
}

void HMI::setTimeStampRIO(quint64 newTimeStampRIO)
{
    if (m_TimeStampRIO == newTimeStampRIO)
        return;
    m_TimeStampRIO = newTimeStampRIO;
    emit TimeStampRIOChanged();
}

qint32 HMI::Latitude() const
{
    return m_Latitude;
}

void HMI::setLatitude(qint32 newLatitude)
{
    if (m_Latitude == newLatitude)
        return;
    m_Latitude = newLatitude;
    emit LatitudeChanged();
}
