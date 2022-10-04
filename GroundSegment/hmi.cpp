#include "hmi.h"
#include <bitset>
#include <QString>
#include <cmath>
#include<stdlib.h>
#include <AGU_MAVLINK/mavlink.h>

Q_DECLARE_METATYPE(mavlink_system_status_pack_t);
Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);

HMI::HMI(QObject *parent)
    : QObject{parent}
{
    m_RollAngle=0;
    emit RollAngleChanged();
}

void HMI::showData(QVariant telemetry)
{
    if (telemetry.canConvert<mavlink_telemetry_data_pack_t>()) {


    printf("TELEMETRY QVARIANT \n");
    //printf(telemetry.toString());

    auto msg_telemetry = telemetry.value<mavlink_telemetry_data_pack_t>();
    m_TimeStamp= msg_telemetry.GNSS_Timestamp;
    m_Latitude= msg_telemetry.Latitude;
    m_Longitude=msg_telemetry.Longitude;
    m_GNSSAltitude= msg_telemetry.GNSS_Altitude;
    m_AirSpeed_UVector= msg_telemetry.Air_Speed_U;
    m_AirSpeed_VVector= msg_telemetry.Air_Speed_V;
    m_AirSpeed_WVector= msg_telemetry.Air_Speed_W;
    m_AirTemperature=msg_telemetry.Air_Temperature;
    m_AltitudeFromPayloadAltimeter= msg_telemetry.Altitude_Payload_Altimeter;
    m_AltitudeFromRadarAltimeter=msg_telemetry.Altitude_Main_Altimeter;
    m_LinearVelocityHorizontal= msg_telemetry.Velocity_Horizontal;
    m_LinearVelocityVertical= msg_telemetry.Velocity_Vertical;
    m_PositionAccuracy= msg_telemetry.Position_Accuracy;
    m_SpeedAccuracy= msg_telemetry.Speed_Accuracy;
    m_LinearAccelerationX= msg_telemetry.Acceleration_X;
    m_LinearAccelerationY=msg_telemetry.Acceleration_Y;
    m_LinearAccelerationZ=msg_telemetry.Acceleration_Z;
    m_ECEFVectorPositionX=msg_telemetry.ECEF_Position_X;
    m_ECEFVectorPositionY=msg_telemetry.ECEF_Position_Y;
    m_ECEFVectorPositionZ=msg_telemetry.ECEF_Position_Z;
    m_ECEFVectorVelocityX=msg_telemetry.ECEF_Velocity_X;
    m_ECEFVectorVelocityY=msg_telemetry.ECEF_Velocity_Y;
    m_ECEFVectorVelocityZ=msg_telemetry.ECEF_Velocity_Z;
    m_RollAngle=msg_telemetry.Roll_Angle;
    m_YawAngle=msg_telemetry.Yaw_Angle;
    m_PitchAngle=msg_telemetry.Pitch_Angle;
    m_AngularRatePitch=msg_telemetry.Angular_Rate_Pitch;
    m_AngularRateRoll=msg_telemetry.Angular_Rate_Roll;
    m_AngularRateYaw=msg_telemetry.Angular_Rate_Yaw;
    m_Quaternion0= msg_telemetry.Quaternion_0;
    m_Quaternion1= msg_telemetry.Quaternion_1;
    m_Quaternion2= msg_telemetry.Quaternion_2;
    m_Quaternion3= msg_telemetry.Quaternion_3;
    //QString s;

    emit TimeStampChanged();
    emit LatitudeChanged();
    emit LongitudeChanged();
    emit GNSSAltitudeChanged();
    emit AirSpeed_UVectorChanged();
    emit AirSpeed_VVectorChanged();
    emit AirSpeed_WVectorChanged();
    emit AirTemperatureChanged();
    emit AltitudeFromPayloadAltimeterChanged();
    emit AltitudeFromRadarAltimeterChanged();
    emit LinearVelocityHorizontalChanged();
    emit LinearVelocityVerticalChanged();
    emit PositionAccuracyChanged();
    emit SpeedAccuracyChanged();
    emit LinearAccelerationXChanged();
    emit LinearAccelerationYChanged();
    emit LinearAccelerationZChanged();
    emit ECEFVectorPositionXChanged();
    emit ECEFVectorPositionYChanged();
    emit ECEFVectorPositionZChanged();
    emit ECEFVectorVelocityXChanged();
    emit ECEFVectorVelocityYChanged();
    emit ECEFVectorVelocityZChanged();
    emit RollAngleChanged();
    emit PitchAngleChanged();
    emit YawAngleChanged();
    emit AngularRatePitchChanged();
    emit AngularRateRollChanged();
    emit AngularRateYawChanged();
    emit Quaternion0Changed();
    emit Quaternion1Changed();
    emit Quaternion2Changed();
    emit Quaternion3Changed();
    emit NumberOfGPSSatelliteChanged();

    printf("TELEMETRY UPDATED \n");
    printf("ROLL ANGLE %d \n",m_RollAngle);
    printf("AIR TEMP %d \n",m_AirTemperature);
    }
    //typedef std::bitset<64> IntBits;
    //    bool is_set0,is_set1,is_set2,is_set3,is_set4,is_set5,is_set6,is_set7,is_set8,is_set9;
    //    bool is_set10,is_set11,is_set12,is_set13,is_set14,is_set15,is_set16,is_set17,is_set18,is_set19;
    //    bool is_set20,is_set21,is_set22,is_set23,is_set24,is_set25,is_set26,is_set27,is_set28,is_set29;
    //    bool is_set30,is_set31;

    //int id=0;
    //uint8_t DataByte32, DataByte40, DataByte48, DataByte56;
    /*
    m_TimeStamp = t->TimeStamp;
    qInfo() << "TimeStamp = " << s;


    m_TimeStampRIO =  QDateTime::currentDateTime().toSecsSinceEpoch();//QRandomGenerator::global()->bounded(999999999, 10000000000);//t->TimeStampRIO;
    qInfo() << "TimeStampRIO = " << m_TimeStampRIO;

    m_Latitude = QRandomGenerator::global()->bounded(-90, 90);//t->Latitude;
    qInfo() << "Latitude = " << m_Latitude;

    m_Longitude =  QRandomGenerator::global()->bounded(-180, 180);//t->Longitude;
    qInfo() << "Longitude = " << m_Longitude;

    m_GNSSAltitude = QRandomGenerator::global()->bounded(999999, 9999999);// t->GNSSAltitude;
    qInfo() << "GNSSAltitude = " << m_GNSSAltitude;

    m_AirSpeed_UVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_UVector;
    qInfo() << "AirSpeed_UVector = " << m_AirSpeed_UVector;

    m_AirSpeed_VVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_VVector;
    qInfo() << "AirSpeed_VVector = " << m_AirSpeed_VVector;

    m_AirSpeed_WVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_WVector;
    qInfo() << "AirSpeed_WVector = " << m_AirSpeed_WVector;

    m_AirTemperature = QRandomGenerator::global()->bounded(-30, 50);// t->AirTemperature;
    qInfo() << "AirTemperature = " << m_AirTemperature;

    m_AltitudeFromRadarAltimeter= QRandomGenerator::global()->bounded(999999, 9999999);// t->AltitudeFromRadarAltimeter;
    qInfo() << "AltitudeFromRadarAltimeter = " << m_AltitudeFromRadarAltimeter;

    m_AltitudeFromPayloadAltimeter = QRandomGenerator::global()->bounded(999999, 9999999);//t->AltitudeFromPayloadAltimeter;
    qInfo() << "AltitudeFromPayloadAltimeter = " << m_AltitudeFromPayloadAltimeter;

    m_LinearVelocityHorizontal = QRandomGenerator::global()->bounded(9, 100);// t->LinearVelocityHorizontal;
    qInfo() << "LinearVelocityHorizontal = " << m_LinearVelocityHorizontal;

    m_LinearVelocityVertical = QRandomGenerator::global()->bounded(9, 100);// t->LinearVelocityVertical;
    qInfo() << "LinearVelocityVertical = " << m_LinearVelocityVertical;

    m_PositionAccuracy = QRandomGenerator::global()->bounded(0, 9999);// t->PositionAccuracy;
    qInfo() << "PositionAccuracy = " << m_PositionAccuracy;

    m_SpeedAccuracy = QRandomGenerator::global()->bounded(0, 9999);// t->SpeedAccuracy;
    qInfo() << "SpeedAccuracy   = " << m_SpeedAccuracy;

    m_LinearAccelerationX = QRandomGenerator::global()->bounded(9, 100);// t->LinearAccelerationX;
    qInfo() << "LinearAccelerationX = " << m_LinearAccelerationX;

    m_LinearAccelerationY = QRandomGenerator::global()->bounded(9, 100);// t->LinearAccelerationY;
    qInfo() << "LinearAccelerationY = " << m_LinearAccelerationY;

    m_LinearAccelerationZ = QRandomGenerator::global()->bounded(9, 100);// t->LinearAccelerationZ;
    qInfo() << "LinearAccelerationZ = " << m_LinearAccelerationZ;

    m_ECEFVectorPositionX = QRandomGenerator::global()->bounded(999999, 9999999);// t->ECEFVectorPositionX;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorPositionX;

    m_ECEFVectorPositionY = QRandomGenerator::global()->bounded(999999, 9999999);// t->ECEFVectorPositionY;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorPositionY;

    m_ECEFVectorPositionZ = QRandomGenerator::global()->bounded(999999, 9999999);// t->ECEFVectorPositionZ;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorPositionZ;

    m_ECEFVectorVelocityX = QRandomGenerator::global()->bounded(9, 100);// t->ECEFVectorVelocityX;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorVelocityX;

    m_ECEFVectorVelocityY = QRandomGenerator::global()->bounded(9, 100);// t->ECEFVectorVelocityY;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorVelocityY;

    m_ECEFVectorVelocityZ = QRandomGenerator::global()->bounded(9, 100);// t->ECEFVectorVelocityZ;
    qInfo() << "PositionAccuracy = " << m_ECEFVectorVelocityZ;

    m_RollAngle = QRandomGenerator::global()->bounded(0, 360);//t->RollAngle;
    qInfo() << "RollAngle = " << m_RollAngle;

    m_PitchAngle = QRandomGenerator::global()->bounded(0, 360);// t->PitchAngle;
    qInfo() << "PitchAngle = " << m_PitchAngle;

    m_YawAngle = QRandomGenerator::global()->bounded(0, 360);// t->YawAngle;
    qInfo() << "YawAngle = " << m_YawAngle;

    m_AngularRateRoll = QRandomGenerator::global()->bounded(99, 999);// t->AngularRateRoll;
    qInfo() << "AngularRateRoll = " << m_AngularRateRoll;

    m_AngularRatePitch = QRandomGenerator::global()->bounded(99, 999);// t->AngularRatePitch;
    qInfo() << "AngularRatePitch = " << m_AngularRatePitch;

    m_AngularRateYaw = QRandomGenerator::global()->bounded(99, 999);// t->AngularRateYaw;
    qInfo() << "AngularRateYaw = " << m_AngularRateYaw;

    m_Quaternion0 = QRandomGenerator::global()->bounded(999999, 9999999);//  t->Quaternion0;
    qInfo() << "Quaternion0 = " << m_Quaternion0;

    m_Quaternion1 = QRandomGenerator::global()->bounded(999999, 9999999);//  t->Quaternion1;
    qInfo() << "Quaternion1 = " << m_Quaternion1;

    m_Quaternion2 = QRandomGenerator::global()->bounded(999999, 9999999);//  t->Quaternion2;
    qInfo() << "Quaternion2 = " << m_Quaternion2;

    m_Quaternion3 = QRandomGenerator::global()->bounded(999999, 9999999);//  t->Quaternion3;
    qInfo() << "Quaternion3 = " << m_Quaternion3;

    m_NumberOfGPSSatellite = QRandomGenerator::global()->bounded(0, 99);// t->NumberOfGPSSatellite;
    qInfo() << "NumberOfGPSSatellite = " << m_NumberOfGPSSatellite;


    m_AnemCommErrorCounter = QRandomGenerator::global()->bounded(0, 100);//  t->AnemCommErrorCounter;
    qInfo() << "Anemometer Communication error counter = " << m_AnemCommErrorCounter;

    m_RDAltCommErrorCounter = QRandomGenerator::global()->bounded(0, 100);//  t->RDAltCommErrorCounter;
    qInfo() << "Radar Altimeter Communication error counter = " << m_RDAltCommErrorCounter;

    m_GNSSCommErrorCounter = QRandomGenerator::global()->bounded(0, 100);//  t->GNSSCommErrorCounter;
    qInfo() << "GNSS Communication error counter = " << m_GNSSCommErrorCounter;

    m_PLAltCommErrorCounter = QRandomGenerator::global()->bounded(0, 100);//  t->PLAltCommErrorCounter;
    qInfo() << "Payload Altimeter Communication error counter = " << m_PLAltCommErrorCounter;
*/


    //    /* TELEMETRY STATUS MASK */


    //    m_telemetry0 = IntBits(t->TelemetryStatusMask).test(0);  /* BIT 0*/


    //    m_telemetry1 = IntBits(t->TelemetryStatusMask).test(1);  /* BIT 1*/


    //    m_telemetry2 = IntBits(t->TelemetryStatusMask).test(2);  /* BIT 2*/


    //    m_telemetry3 = IntBits(t->TelemetryStatusMask).test(3);  /* BIT 3*/


    //    m_telemetry4 = IntBits(t->TelemetryStatusMask).test(4);  /* BIT 4*/


    //    m_telemetry5 = IntBits(t->TelemetryStatusMask).test(5);  /* BIT 5*/


    //    m_telemetry6 = IntBits(t->TelemetryStatusMask).test(6);  /* BIT 6*/


    //    m_telemetry7 = IntBits(t->TelemetryStatusMask).test(7);  /* BIT 7*/


    //    m_telemetry8 = IntBits(t->TelemetryStatusMask).test(8);  /* BIT 8*/


    //    m_telemetry9 = IntBits(t->TelemetryStatusMask).test(9);  /* BIT 9*/


    //    m_telemetry10 = IntBits(t->TelemetryStatusMask).test(10); /* BIT 10*/


    //    m_telemetry11 = IntBits(t->TelemetryStatusMask).test(11); /* BIT 11*/


    //    m_telemetry12 = IntBits(t->TelemetryStatusMask).test(12); /* BIT 12*/


    //    m_telemetry13 = IntBits(t->TelemetryStatusMask).test(13); /* BIT 13*/


    //    m_telemetry14 = IntBits(t->TelemetryStatusMask).test(14); /* BIT 14*/


    //    m_telemetry15 = IntBits(t->TelemetryStatusMask).test(15); /* BIT 15*/


    //    m_telemetry16 = IntBits(t->TelemetryStatusMask).test(16); /* BIT 16*/


    //    m_telemetry17 = IntBits(t->TelemetryStatusMask).test(17); /* BIT 17*/


    //    m_telemetry18 = IntBits(t->TelemetryStatusMask).test(18); /* BIT 18*/


    //    m_telemetry19 = IntBits(t->TelemetryStatusMask).test(19); /* BIT 19*/


    //    m_telemetry20 = IntBits(t->TelemetryStatusMask).test(20); /* BIT 20*/


    //    m_telemetry21 = IntBits(t->TelemetryStatusMask).test(21); /* BIT 21*/


    //    m_telemetry22 = IntBits(t->TelemetryStatusMask).test(22); /* BIT 22*/


    //    m_telemetry23 = IntBits(t->TelemetryStatusMask).test(23); /* BIT 23*/


    //    m_telemetry24 = IntBits(t->TelemetryStatusMask).test(24); /* BIT 24*/


    //    m_telemetry25 = IntBits(t->TelemetryStatusMask).test(25); /* BIT 25*/


    //    m_telemetry26 = IntBits(t->TelemetryStatusMask).test(26); /* BIT 26*/


    //    m_telemetry27 = IntBits(t->TelemetryStatusMask).test(27); /* BIT 27*/


    //    m_telemetry28 = IntBits(t->TelemetryStatusMask).test(28); /* BIT 28*/


    //    m_telemetry29 = IntBits(t->TelemetryStatusMask).test(29); /* BIT 29*/


    //    m_telemetry30 = IntBits(t->TelemetryStatusMask).test(30); /* BIT 30*/


    //    m_telemetry31 = IntBits(t->TelemetryStatusMask).test(31); /* BIT 31*/


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

}

void HMI::showDataSystemStatus(QVariant status)
{
    qInfo() << "showDataSystemStatus = CALL" ;

    if (status.canConvert<mavlink_system_status_pack_t>()) {

    auto msg_status = status.value<mavlink_system_status_pack_t>();
    m_FlightMode = msg_status.Flight_Mode;
    m_FlightPhase= msg_status.Flight_Phase;
    m_FlightPhaseExecutionTime= msg_status.Flight_Phase_Time;
    m_TelemetryModuleStatusMask= msg_status.Telemetry_Module_Status_Mask;
    m_StorageModuleStatusMask= msg_status.Storage_Module_Status_Mask;
    m_GuidanceModuleStatusMask= msg_status.Guidance_Module_Status_Mask;
    m_CoreModuleStatusMask= msg_status.Core_Module_Status_Mask;
    m_RadioLinkModuleStatusMask= msg_status.Radio_Link_Module_Status_Mask;

    emit FlightModeChanged();
    emit FlightPhaseChanged();
    emit FlightPhaseExecutionTimeChanged();
    emit CoreModuleStatusMaskChanged();
    emit TelemetryModuleStatusMaskChanged();
    emit GuidanceModuleStatusMaskChanged();
    emit StorageModuleStatusMaskChanged();
    emit RadioLinkModuleStatusMaskChanged();
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
}

void HMI::showDataMotorStatus(QVariant status)
{
    if (status.canConvert<mavlink_motor_status_pack_t>()) {

    auto msg_status = status.value<mavlink_motor_status_pack_t>();
    m_MotorARealPosition = msg_status.Motor_A_Real_Position;
    m_MotorADemandPosition= msg_status.Motor_A_Demand_Position;
    m_MotorATemp=msg_status.Motor_A_Temperature;
    m_MotorATorque= msg_status.Motor_A_Torque;
    m_MotorAFaultsMask=msg_status.Motor_A_Faults_Mask;

    m_MotorBRealPosition = msg_status.Motor_B_Real_Position;
    m_MotorBDemandPosition= msg_status.Motor_B_Demand_Position;
    m_MotorBTemp=msg_status.Motor_B_Temperature;
    m_MotorBTorque= msg_status.Motor_B_Torque;
    m_MotorBFaultsMask=msg_status.Motor_B_Faults_Mask;

    m_BMSVoltage= msg_status.BMS_Voltage;
    m_BMSAbsorption=msg_status.BMS_Absorption;
    m_BMSVoltage= msg_status.BMS_Voltage;
    m_BMSFaultsMask= msg_status.BMS_Faults_Mask;

    m_MotorControlStatusMask= msg_status.Motor_Control_Status_Mask;


    emit MotorADemandPositionChanged();
    emit MotorAFaultsMaskChanged();
    emit MotorARealPositionChanged();
    emit MotorATempChanged();
    emit MotorATorqueChanged();

    emit MotorBDemandPositionChanged();
    emit MotorBFaultsMaskChanged();
    emit MotorBRealPositionChanged();
    emit MotorBTempChanged();
    emit MotorBTorqueChanged();

    emit BMSVoltageChanged();
    emit BMSAbsorptionChanged();
    emit BMSTempChanged();
    emit BMSFaultsMaskChanged();

    emit MotorControlStatusMaskChanged();

    printf("MOTOR STATUS UPDATED \n");
    printf("BMS VOLTAGE %d \n",m_BMSVoltage);


}
}

void HMI::showDataRLStatus(QVariant status)
{

}

void HMI::showDataStorageStatus(QVariant status)
{

}

void HMI::showDataGuidance(QVariant guidance)
{

}
