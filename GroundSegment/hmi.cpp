#include "hmi.h"
#include <bitset>
#include <QString>
#include <iostream>

Q_DECLARE_METATYPE(mavlink_system_status_pack_t);
Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);
Q_DECLARE_METATYPE(mavlink_motor_status_pack_t);

HMI::HMI(QObject *parent)
    : QObject{parent}
{

}

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
}

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
    //m_NumberOfGPSSatellite= msg_telemetry.Satellite_Num; emit NumberOfGPSSatelliteChanged();

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

    printf("SYS STATUS UPDATED \n");
    printf("FLIGHT MODE %d \n",m_FlightMode);
    printf("FLIGHT PHASE %d \n",m_FlightPhase);
}




//    m_MotorARealPosition = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorARealPosition = " << m_MotorARealPosition;
//    m_MotorADemandPosition = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorADemandPosition = " << m_MotorADemandPosition;
//    m_MotorATorque = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorATorque = " << m_MotorATorque;
//    m_MotorATemp = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorATemp = " << m_MotorATemp;

//    m_MotorBRealPosition = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorBRealPosition = " << m_MotorBRealPosition;
//    m_MotorBDemandPosition = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorBDemandPosition = " << m_MotorBDemandPosition;
//    m_MotorBTorque = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorBTorque = " << m_MotorBTorque;
//    m_MotorBTemp = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorBTemp = " << m_MotorBTemp;

//    m_BMS1Voltage = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "BMS1Voltage = " << m_BMS1Voltage;
//    m_BMS1Absorption = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "BMS1Absorption = " << m_BMS1Absorption;
//    m_BMS1Temp = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "BMS1Temp = " << m_BMS1Temp;
//    m_MotorTimestamp = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "MotorTimestamp = " << m_MotorTimestamp;
//    m_ChargeValue = QRandomGenerator::global()->bounded(0, 99);
//    qInfo() << "ChargeValue = " << m_ChargeValue;

//    /* Motor STATUS MASK */


//    m_motor0 = IntBits(t->MotorStatusMask).test(0);  /* BIT 0*/


//    m_motor1 = IntBits(t->MotorStatusMask).test(1);  /* BIT 1*/


//    m_motor2 = IntBits(t->MotorStatusMask).test(2);  /* BIT 2*/


//    m_motor3 = IntBits(t->MotorStatusMask).test(3);  /* BIT 3*/


//    m_motor4 = IntBits(t->MotorStatusMask).test(4);  /* BIT 4*/


//    m_motor5 = IntBits(t->MotorStatusMask).test(5);  /* BIT 5*/


//    m_motor6 = IntBits(t->MotorStatusMask).test(6);  /* BIT 6*/


//    m_motor7 = IntBits(t->MotorStatusMask).test(7);  /* BIT 7*/


//    m_motor8 = IntBits(t->MotorStatusMask).test(8);  /* BIT 8*/


//    m_motor9 = IntBits(t->MotorStatusMask).test(9);  /* BIT 9*/


//    m_motor10 = IntBits(t->MotorStatusMask).test(10); /* BIT 10*/


//    m_motor11 = IntBits(t->MotorStatusMask).test(11); /* BIT 11*/


//    m_motor12 = IntBits(t->MotorStatusMask).test(12); /* BIT 12*/


//    m_motor13 = IntBits(t->MotorStatusMask).test(13); /* BIT 13*/


//    m_motor14 = IntBits(t->MotorStatusMask).test(14); /* BIT 14*/


//    m_motor15 = IntBits(t->MotorStatusMask).test(15); /* BIT 15*/


//    m_motor16 = IntBits(t->MotorStatusMask).test(16); /* BIT 16*/


//    m_motor17 = IntBits(t->MotorStatusMask).test(17); /* BIT 17*/


//    m_motor18 = IntBits(t->MotorStatusMask).test(18); /* BIT 18*/


//    m_motor19 = IntBits(t->MotorStatusMask).test(19); /* BIT 19*/


//    m_motor20 = IntBits(t->MotorStatusMask).test(20); /* BIT 20*/


//    m_motor21 = IntBits(t->MotorStatusMask).test(21); /* BIT 21*/


//    m_motor22 = IntBits(t->MotorStatusMask).test(22); /* BIT 22*/


//    m_motor23 = IntBits(t->MotorStatusMask).test(23); /* BIT 23*/


//    m_motor24 = IntBits(t->MotorStatusMask).test(24); /* BIT 24*/


//    m_motor25 = IntBits(t->MotorStatusMask).test(25); /* BIT 25*/








//    /* BMS STATUS MASK */


//    m_BMS0 = IntBits(t->BMSStatusMask).test(0);  /* BIT 0*/


//    m_BMS1 = IntBits(t->BMSStatusMask).test(1);  /* BIT 1*/


//    m_BMS2 = IntBits(t->BMSStatusMask).test(2);  /* BIT 2*/


//    m_BMS3 = IntBits(t->BMSStatusMask).test(3);  /* BIT 3*/


//    m_BMS4 = IntBits(t->BMSStatusMask).test(4);  /* BIT 4*/


//    m_BMS5 = IntBits(t->BMSStatusMask).test(5);  /* BIT 5*/


//    m_BMS6 = IntBits(t->BMSStatusMask).test(6);  /* BIT 6*/


//    m_BMS7 = IntBits(t->BMSStatusMask).test(7);  /* BIT 7*/


//    m_BMS8 = IntBits(t->BMSStatusMask).test(8);  /* BIT 8*/


//    m_BMS9 = IntBits(t->BMSStatusMask).test(9);  /* BIT 9*/


//    m_BMS10 = IntBits(t->BMSStatusMask).test(10); /* BIT 10*/


//    m_BMS11 = IntBits(t->BMSStatusMask).test(11); /* BIT 11*/


//    m_BMS12 = IntBits(t->BMSStatusMask).test(12); /* BIT 12*/


//    m_BMS13 = IntBits(t->BMSStatusMask).test(13); /* BIT 13*/


//    m_BMS14 = IntBits(t->BMSStatusMask).test(14); /* BIT 14*/


//    m_BMS15 = IntBits(t->BMSStatusMask).test(15); /* BIT 15*/


//    m_BMS16 = IntBits(t->BMSStatusMask).test(16); /* BIT 16*/


//    m_BMS17 = IntBits(t->BMSStatusMask).test(17); /* BIT 17*/


//    m_BMS18 = IntBits(t->BMSStatusMask).test(18); /* BIT 18*/


//    m_BMS19 = IntBits(t->BMSStatusMask).test(19); /* BIT 19*/


//    m_BMS20 = IntBits(t->BMSStatusMask).test(20); /* BIT 20*/


//    m_BMS21 = IntBits(t->BMSStatusMask).test(21); /* BIT 21*/


//    m_BMS22 = IntBits(t->BMSStatusMask).test(22); /* BIT 22*/


//    m_BMS23 = IntBits(t->BMSStatusMask).test(23); /* BIT 23*/


//    m_BMS24 = IntBits(t->BMSStatusMask).test(24); /* BIT 24*/


//    m_BMS25 = IntBits(t->BMSStatusMask).test(25); /* BIT 25*/


//    m_BMS26 = IntBits(t->BMSStatusMask).test(26); /* BIT 26*/


//    m_BMS27 = IntBits(t->BMSStatusMask).test(27); /* BIT 27*/


//    m_BMS28 = IntBits(t->BMSStatusMask).test(28); /* BIT 28*/


//    m_BMS29 = IntBits(t->BMSStatusMask).test(29); /* BIT 29*/


//    m_BMS30 = IntBits(t->BMSStatusMask).test(30); /* BIT 30*/


//    m_BMS31 = IntBits(t->BMSStatusMask).test(31); /* BIT 31*/


/* RADIOLINK STATUS MASK */

//     typedef std::bitset<32> IntBitsRadioLink;
//     bool is_setRadioLink0,is_setRadioLink1,is_setRadioLink2,is_setRadioLink3/*,is_setRadioLink4,is_setRadioLink5*/;
//     bool /*is_setRadioLink6,is_setRadioLink7,*/is_setRadioLink8,is_setRadioLink9, is_setRadioLink24;


//     is_setRadioLink0  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(0);  /* BIT 0*/
//     if (is_setRadioLink0)  { /*accensione LED rosso*/ }

//     is_setRadioLink1  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(1);  /* BIT 1*/
//     if (is_setRadioLink1)  { /*accensione LED rosso*/ }

//     is_setRadioLink2  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(2);  /* BIT 2*/
//     if (is_setRadioLink2)  { /*accensione LED rosso*/ }

//     is_setRadioLink3  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(3);  /* BIT 3*/
//     if (is_setRadioLink3)  { /*accensione LED rosso*/ }

////     is_setRadioLink4  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(4);  /* BIT 4*/
////     if (is_setRadioLink4)  { /*accensione LED rosso*/ }

////     is_setRadioLink5  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(5);  /* BIT 5*/
////     if (is_setRadioLink5)  { /*accensione LED rosso*/ }

////     is_setRadioLink6  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(6);  /* BIT 6*/
////     if (is_setRadioLink6)  { /*accensione LED rosso*/ }

////     is_setRadioLink7  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(7);  /* BIT 7*/
////     if (is_setRadioLink7)  { /*accensione LED rosso*/ }

//     is_setRadioLink8  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(8);  /* BIT 8*/
//     if (is_setRadioLink8)  { /*accensione LED rosso*/ }

//     is_setRadioLink9  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(9);  /* BIT 9*/
//     if (is_setRadioLink9)  { /*accensione LED rosso*/ }

//     is_setRadioLink24  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(24);  /* BIT 9*/
//     if (is_setRadioLink24)  { /*accensione LED rosso*/ }
//}

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
    m_BMSFaultsMask= msg_status.BMS_Faults_Mask;emit BMSFaultsMaskChanged();

    m_MotorControlStatusMask= msg_status.Motor_Control_Status_Mask;emit MotorControlStatusMaskChanged();

    printf("MOTOR STATUS UPDATED \n");
    printf("BMS VOLTAGE %d \n",m_BMSVoltage);
}
