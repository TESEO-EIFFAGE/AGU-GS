#include "hmi.h"
#include <bitset>
#include <QString>
#include <cmath>
#include<stdlib.h>

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
    m_Quaternion0= msg_telemetry.Quaternion_0; emit Quaternion0Changed();
    m_Quaternion1= msg_telemetry.Quaternion_1; emit Quaternion1Changed();
    m_Quaternion2= msg_telemetry.Quaternion_2; emit Quaternion2Changed();
    m_Quaternion3= msg_telemetry.Quaternion_3; emit Quaternion3Changed();
    //m_NumberOfGPSSatellite= msg_telemetry.Satellite_Num; emit NumberOfGPSSatelliteChanged();

    /* TELEMETRY STATUS MASK */
    std::bitset<64> telemetryBitset(msg_telemetry.Telemetry_Status_Mask);
    m_telemetry0 = telemetryBitset.test(0);
    m_telemetry1 = telemetryBitset.test(1);
    m_telemetry2 = telemetryBitset.test(2);
    m_telemetry3 = telemetryBitset.test(3);
    m_telemetry4 = telemetryBitset.test(4);
    m_telemetry5 = telemetryBitset.test(5);
    m_telemetry6 = telemetryBitset.test(6);
    m_telemetry7 = telemetryBitset.test(7);
    m_telemetry8 = telemetryBitset.test(8);
    m_telemetry9 = telemetryBitset.test(9);
    m_telemetry10 = telemetryBitset.test(10);
    m_telemetry11 = telemetryBitset.test(11);
    m_telemetry12 = telemetryBitset.test(12);
    m_telemetry13 = telemetryBitset.test(13);
    m_telemetry14 = telemetryBitset.test(14);
    m_telemetry15 = telemetryBitset.test(15);
    m_telemetry16 = telemetryBitset.test(16);
    m_telemetry17 = telemetryBitset.test(17);
    m_telemetry18 = telemetryBitset.test(18);
    m_telemetry19 = telemetryBitset.test(19);
    m_telemetry20 = telemetryBitset.test(20);
    m_telemetry21 = telemetryBitset.test(21);
    m_telemetry22 = telemetryBitset.test(22);
    m_telemetry23 = telemetryBitset.test(23);
    m_telemetry24 = telemetryBitset.test(24);
    m_telemetry25 = telemetryBitset.test(25);
    m_telemetry26 = telemetryBitset.test(26);
    m_telemetry27 = telemetryBitset.test(27);
    m_telemetry28 = telemetryBitset.test(28);
    m_telemetry29 = telemetryBitset.test(29);
    m_telemetry30 = telemetryBitset.test(30);
    m_telemetry31 = telemetryBitset.test(31);

    printf("TELEMETRY UPDATED \n");
    printf("ROLL ANGLE %d \n",m_RollAngle);
}

//int id=0;
//uint8_t DataByte32, DataByte40, DataByte48, DataByte56;
/*




    //    id=0;
    //    DataByte32=0;
    //    do
    //    {
    //        if (IntBits(t->TelemetryStatusMask).test(32 + id))
    //        {
    //            qInfo() << "id = " << id;
    //            DataByte32 += pow(2,id);
    //        }
    //        id++;
    //    }
    //    while (id < 8);
    //    qInfo() << "DataByte32 = " << DataByte32;  // Da visualizzare su Interfaccia

    //    id=0;
    //    DataByte40=0;
    //    do
    //    {
    //        if (IntBits(t->TelemetryStatusMask).test(40 + id))
    //        {
    //            qInfo() << "id = " << id;
    //            DataByte40 += pow(2,id);
    //        }
    //        id++;
    //    }
    //    while (id < 8);
    //    qInfo() << "DataByte40 = " << DataByte40;   // Da visualizzare su Interfaccia

    //    id=0;
    //    DataByte48=0;
    //    do
    //    {
    //        if (IntBits(t->TelemetryStatusMask).test(48 + id))
    //        {
    //            qInfo() << "id = " << id;
    //            DataByte48 += pow(2,id);
    //        }
    //        id++;
    //    }
    //    while (id < 8);
    //    qInfo() << "DataByte48 = " << DataByte48;   // Da visualizzare su Interfaccia

    //    id=0;
    //    DataByte56=0;
    //    do
    //    {
    //        if (IntBits(t->TelemetryStatusMask).test(56 + id))
    //        {
    //            qInfo() << "id = " << id;
    //            DataByte56 += pow(2,id);
    //        }
    //        id++;
    //    }
    //    while (id < 8);
    //    qInfo() << "DataByte56 = " << DataByte56;   // Da visualizzare su Interfaccia

}*/

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

/* STORAGE STATUS MASK */    /* STORAGE STATUS MASK */


//         m_storage0 = IntBits(s->StorageModuleStatusMask).test(0);  /* BIT 0*/


//         m_storage1 = IntBits(s->StorageModuleStatusMask).test(1);  /* BIT 1*/


//         m_storage2 = IntBits(s->StorageModuleStatusMask).test(2);  /* BIT 2*/


//         m_storage3 = IntBits(s->StorageModuleStatusMask).test(3);  /* BIT 3*/


//         m_storage4 = IntBits(s->StorageModuleStatusMask).test(4);  /* BIT 4*/


//         m_storage5 = IntBits(s->StorageModuleStatusMask).test(5);  /* BIT 5*/


//         m_storage6 = IntBits(s->StorageModuleStatusMask).test(6);  /* BIT 6*/


//         m_storage7 = IntBits(s->StorageModuleStatusMask).test(7);  /* BIT 7*/


//         m_storage8 = IntBits(s->StorageModuleStatusMask).test(8);  /* BIT 8*/




//         m_storage10 = IntBits(s->StorageModuleStatusMask).test(10); /* BIT 10*/


//         m_storage11 = IntBits(s->StorageModuleStatusMask).test(11); /* BIT 11*/


//         m_storage12 = IntBits(s->StorageModuleStatusMask).test(12); /* BIT 12*/


//         m_storage13 = IntBits(s->StorageModuleStatusMask).test(13); /* BIT 13*/


//         m_storage14 = IntBits(s->StorageModuleStatusMask).test(14); /* BIT 14*/


//         m_storage15 = IntBits(s->StorageModuleStatusMask).test(15); /* BIT 15*/


//         m_storage16 = IntBits(s->StorageModuleStatusMask).test(16); /* BIT 16*/


//         m_storage17 = IntBits(s->StorageModuleStatusMask).test(17); /* BIT 17*/


//         m_storage18 = IntBits(s->StorageModuleStatusMask).test(18); /* BIT 18*/


//         m_storage19 = IntBits(s->StorageModuleStatusMask).test(19); /* BIT 19*/


//         m_storage20 = IntBits(s->StorageModuleStatusMask).test(20); /* BIT 20*/


//         m_storage21 = IntBits(s->StorageModuleStatusMask).test(21); /* BIT 21*/


//         m_storage22 = IntBits(s->StorageModuleStatusMask).test(22); /* BIT 22*/


//         m_storage23 = IntBits(s->StorageModuleStatusMask).test(23); /* BIT 23*/

//typedef std::bitset<32> IntBitsStorage;


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
