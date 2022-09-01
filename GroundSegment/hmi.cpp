#include "hmi.h"
#include <bitset>
#include <QString>
#include <cmath>
#include<stdlib.h>

HMI::HMI(QObject *parent)
    : QObject{parent}
{

}

void HMI::showData(/*Telemetry *t*/)
{
    QString s;

    typedef std::bitset<64> IntBits;
    bool is_set0,is_set1,is_set2,is_set3,is_set4,is_set5,is_set6,is_set7,is_set8,is_set9;
    bool is_set10,is_set11,is_set12,is_set13,is_set14,is_set15,is_set16,is_set17,is_set18,is_set19;
    bool is_set20,is_set21,is_set22,is_set23,is_set24,is_set25,is_set26,is_set27,is_set28,is_set29;
    bool is_set30,is_set31;

    int id=0;
    uint8_t DataByte32, DataByte40, DataByte48, DataByte56;
/*
    m_TimeStamp = t->TimeStamp;
    qInfo() << "TimeStamp = " << s;

*/
    m_TimeStampRIO =  QDateTime::currentDateTime().toSecsSinceEpoch();//QRandomGenerator::global()->bounded(999999999, 10000000000);//t->TimeStampRIO;
    qInfo() << "TimeStampRIO = " << m_TimeStampRIO;

    m_Latitude = QRandomGenerator::global()->bounded(999999, 9999999);//t->Latitude;
    qInfo() << "Latitude = " << m_Latitude;

    m_Longitude =  QRandomGenerator::global()->bounded(999999, 9999999);//t->Longitude;
    qInfo() << "Longitude = " << m_Longitude;

    m_GNSSAltitude = QRandomGenerator::global()->bounded(999999, 9999999);// t->GNSSAltitude;
    qInfo() << "GNSSAltitude = " << m_GNSSAltitude;

    m_AirSpeed_UVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_UVector;
    qInfo() << "AirSpeed_UVector = " << m_AirSpeed_UVector;

    m_AirSpeed_VVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_VVector;
    qInfo() << "AirSpeed_VVector = " << m_AirSpeed_VVector;

    m_AirSpeed_WVector = QRandomGenerator::global()->bounded(9, 100);// t->AirSpeed_WVector;
    qInfo() << "AirSpeed_WVector = " << m_AirSpeed_WVector;

    m_AirTemperature = QRandomGenerator::global()->bounded(-100, 100);// t->AirTemperature;
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

    m_RollAngle = QRandomGenerator::global()->bounded(-180, 180);//t->RollAngle;
    qInfo() << "RollAngle = " << m_RollAngle;

    m_PitchAngle = QRandomGenerator::global()->bounded(-180, 180);// t->PitchAngle;
    qInfo() << "PitchAngle = " << m_PitchAngle;

    m_YawAngle = QRandomGenerator::global()->bounded(-180, 180);// t->YawAngle;
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

<<<<<<< HEAD
=======
    m_TelemetryStatusMask = 1;//t->TelemetryStatusMask;
    qInfo() << "TelemetryStatusMask = " << m_TelemetryStatusMask;

>>>>>>> 32548cdd53ca960389b235bad30fcf28c3bffc3b
    m_NumberOfGPSSatellite = QRandomGenerator::global()->bounded(0, 99);// t->NumberOfGPSSatellite;
    qInfo() << "NumberOfGPSSatellite = " << m_NumberOfGPSSatellite;




    /* TELEMETRY STATUS MASK */

<<<<<<< HEAD
    m_telemetry0 = IntBits(t->TelemetryStatusMask).test(0);  /* BIT 0*/


    m_telemetry1 = IntBits(t->TelemetryStatusMask).test(1);  /* BIT 1*/


    m_telemetry2 = IntBits(t->TelemetryStatusMask).test(2);  /* BIT 2*/


    m_telemetry3 = IntBits(t->TelemetryStatusMask).test(3);  /* BIT 3*/


    m_telemetry4 = IntBits(t->TelemetryStatusMask).test(4);  /* BIT 4*/


    m_telemetry5 = IntBits(t->TelemetryStatusMask).test(5);  /* BIT 5*/


    m_telemetry6 = IntBits(t->TelemetryStatusMask).test(6);  /* BIT 6*/


    m_telemetry7 = IntBits(t->TelemetryStatusMask).test(7);  /* BIT 7*/


    m_telemetry8 = IntBits(t->TelemetryStatusMask).test(8);  /* BIT 8*/


    m_telemetry9 = IntBits(t->TelemetryStatusMask).test(9);  /* BIT 9*/


    m_telemetry10 = IntBits(t->TelemetryStatusMask).test(10); /* BIT 10*/


    m_telemetry11 = IntBits(t->TelemetryStatusMask).test(11); /* BIT 11*/


    m_telemetry12 = IntBits(t->TelemetryStatusMask).test(12); /* BIT 12*/


    m_telemetry13 = IntBits(t->TelemetryStatusMask).test(13); /* BIT 13*/


    m_telemetry14 = IntBits(t->TelemetryStatusMask).test(14); /* BIT 14*/


    m_telemetry15 = IntBits(t->TelemetryStatusMask).test(15); /* BIT 15*/


    m_telemetry16 = IntBits(t->TelemetryStatusMask).test(16); /* BIT 16*/


    m_telemetry17 = IntBits(t->TelemetryStatusMask).test(17); /* BIT 17*/


    m_telemetry18 = IntBits(t->TelemetryStatusMask).test(18); /* BIT 18*/


    m_telemetry19 = IntBits(t->TelemetryStatusMask).test(19); /* BIT 19*/


    m_telemetry20 = IntBits(t->TelemetryStatusMask).test(20); /* BIT 20*/


    m_telemetry21 = IntBits(t->TelemetryStatusMask).test(21); /* BIT 21*/


    m_telemetry22 = IntBits(t->TelemetryStatusMask).test(22); /* BIT 22*/


    m_telemetry23 = IntBits(t->TelemetryStatusMask).test(23); /* BIT 23*/


    m_telemetry24 = IntBits(t->TelemetryStatusMask).test(24); /* BIT 24*/


    m_telemetry25 = IntBits(t->TelemetryStatusMask).test(25); /* BIT 25*/


    m_telemetry26 = IntBits(t->TelemetryStatusMask).test(26); /* BIT 26*/


    m_telemetry27 = IntBits(t->TelemetryStatusMask).test(27); /* BIT 27*/


    m_telemetry28 = IntBits(t->TelemetryStatusMask).test(28); /* BIT 28*/


    m_telemetry29 = IntBits(t->TelemetryStatusMask).test(29); /* BIT 29*/


    m_telemetry30 = IntBits(t->TelemetryStatusMask).test(30); /* BIT 30*/


    m_telemetry31 = IntBits(t->TelemetryStatusMask).test(31); /* BIT 31*/


    id=0;
    DataByte32=0;
    do
    {
        if (IntBits(t->TelemetryStatusMask).test(32 + id))
        {
            qInfo() << "id = " << id;
            DataByte32 += pow(2,id);
        }
        id++;
    }
    while (id < 8);
    qInfo() << "DataByte32 = " << DataByte32;  // Da visualizzare su Interfaccia

    id=0;
    DataByte40=0;
    do
    {
        if (IntBits(t->TelemetryStatusMask).test(40 + id))
        {
            qInfo() << "id = " << id;
            DataByte40 += pow(2,id);
        }
        id++;
    }
    while (id < 8);
    qInfo() << "DataByte40 = " << DataByte40;   // Da visualizzare su Interfaccia

    id=0;
    DataByte48=0;
    do
    {
        if (IntBits(t->TelemetryStatusMask).test(48 + id))
        {
            qInfo() << "id = " << id;
            DataByte48 += pow(2,id);
        }
        id++;
    }
    while (id < 8);
    qInfo() << "DataByte48 = " << DataByte48;   // Da visualizzare su Interfaccia

    id=0;
    DataByte56=0;
    do
    {
        if (IntBits(t->TelemetryStatusMask).test(56 + id))
        {
            qInfo() << "id = " << id;
            DataByte56 += pow(2,id);
        }
        id++;
    }
    while (id < 8);
    qInfo() << "DataByte56 = " << DataByte56;   // Da visualizzare su Interfaccia
=======
//    is_set0  = IntBits(t->TelemetryStatusMask).test(0);  /* BIT 0*/
//    if (is_set0)  { /*accensione LED rosso*/ }

//    is_set1  = IntBits(t->TelemetryStatusMask).test(1);  /* BIT 1*/
//    if (is_set1)  { /*accensione LED rosso*/ }

//    is_set2  = IntBits(t->TelemetryStatusMask).test(2);  /* BIT 2*/
//    if (is_set2)  { /*accensione LED rosso*/ }

//    is_set3  = IntBits(t->TelemetryStatusMask).test(3);  /* BIT 3*/
//    if (is_set3)  { /*accensione LED rosso*/ }

//    is_set4  = IntBits(t->TelemetryStatusMask).test(4);  /* BIT 4*/
//    if (is_set4)  { /*accensione LED rosso*/ }

//    is_set5  = IntBits(t->TelemetryStatusMask).test(5);  /* BIT 5*/
//    if (is_set5)  { /*accensione LED rosso*/ }

//    is_set6  = IntBits(t->TelemetryStatusMask).test(6);  /* BIT 6*/
//    if (is_set6)  { /*accensione LED rosso*/ }

//    is_set7  = IntBits(t->TelemetryStatusMask).test(7);  /* BIT 7*/
//    if (is_set7)  { /*accensione LED rosso*/ }

//    is_set8  = IntBits(t->TelemetryStatusMask).test(8);  /* BIT 8*/
//    if (is_set8)  { /*accensione LED rosso*/ }

//    is_set9  = IntBits(t->TelemetryStatusMask).test(9);  /* BIT 9*/
//    if (is_set9)  { /*accensione LED rosso*/ }

//    is_set10 = IntBits(t->TelemetryStatusMask).test(10); /* BIT 10*/
//    if (is_set10) { /*accensione LED rosso*/ }

//    is_set11 = IntBits(t->TelemetryStatusMask).test(11); /* BIT 11*/
//    if (is_set11) { /*accensione LED rosso*/ }

//    is_set12 = IntBits(t->TelemetryStatusMask).test(12); /* BIT 12*/
//    if (is_set12) { /*accensione LED rosso*/ }

//    is_set13 = IntBits(t->TelemetryStatusMask).test(13); /* BIT 13*/
//    if (is_set13) { /*accensione LED rosso*/ }

//    is_set14 = IntBits(t->TelemetryStatusMask).test(14); /* BIT 14*/
//    if (is_set14) { /*accensione LED rosso*/ }

//    is_set15 = IntBits(t->TelemetryStatusMask).test(15); /* BIT 15*/
//    if (is_set15) { /*accensione LED rosso*/ }

//    is_set16 = IntBits(t->TelemetryStatusMask).test(16); /* BIT 16*/
//    if (is_set16) { /*accensione LED rosso*/ }

//    is_set17 = IntBits(t->TelemetryStatusMask).test(17); /* BIT 17*/
//    if (is_set17) { /*accensione LED rosso*/ }

//    is_set18 = IntBits(t->TelemetryStatusMask).test(18); /* BIT 18*/
//    if (is_set18) { /*accensione LED rosso*/ }

//    is_set19 = IntBits(t->TelemetryStatusMask).test(19); /* BIT 19*/
//    if (is_set19) { /*accensione LED rosso*/ }

//    is_set20 = IntBits(t->TelemetryStatusMask).test(20); /* BIT 20*/
//    if (is_set20) { /*accensione LED rosso*/ }

//    is_set21 = IntBits(t->TelemetryStatusMask).test(21); /* BIT 21*/
//    if (is_set21) { /*accensione LED rosso*/ }

//    is_set22 = IntBits(t->TelemetryStatusMask).test(22); /* BIT 22*/
//    if (is_set22) { /*accensione LED rosso*/ }

//    is_set23 = IntBits(t->TelemetryStatusMask).test(23); /* BIT 23*/
//    if (is_set23) { /*accensione LED rosso*/ }

//    is_set24 = IntBits(t->TelemetryStatusMask).test(24); /* BIT 24*/
//    if (is_set24) { /*accensione LED rosso*/ }

//    is_set25 = IntBits(t->TelemetryStatusMask).test(25); /* BIT 25*/
//    if (is_set25) { /*accensione LED rosso*/ }

//    is_set26 = IntBits(t->TelemetryStatusMask).test(26); /* BIT 26*/
//    if (is_set26) { /*accensione LED rosso*/ }

//    is_set27 = IntBits(t->TelemetryStatusMask).test(27); /* BIT 27*/
//    if (is_set27) { /*accensione LED rosso*/ }

//    is_set28 = IntBits(t->TelemetryStatusMask).test(28); /* BIT 28*/
//    if (is_set28) { /*accensione LED rosso*/ }

//    is_set29 = IntBits(t->TelemetryStatusMask).test(29); /* BIT 29*/
//    if (is_set29) { /*accensione LED rosso*/ }

//    is_set30 = IntBits(t->TelemetryStatusMask).test(30); /* BIT 30*/
//    if (is_set30) { /*accensione LED rosso*/ }

//    is_set31 = IntBits(t->TelemetryStatusMask).test(31); /* BIT 31*/
//    if (is_set31) { /*accensione LED rosso*/ }

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
>>>>>>> 32548cdd53ca960389b235bad30fcf28c3bffc3b
}

void HMI::showDataSystemStatus(SystemStatusPack *s)
{
     qInfo() << "showDataSystemStatus = CALL" ;

     /* STORAGE STATUS MASK */

     typedef std::bitset<32> IntBitsStorage;
     bool is_setStorage0,is_setStorage1,is_setStorage2,is_setStorage3,is_setStorage4;
     bool is_setStorage5,is_setStorage6,is_setStorage7,is_setStorage8/*,is_setStorage9*/;
     bool is_setStorage10,is_setStorage11,is_setStorage12,is_setStorage13,is_setStorage14;
     bool is_setStorage15,is_setStorage16,is_setStorage17,is_setStorage18,is_setStorage19;
     bool is_setStorage20,is_setStorage21,is_setStorage22,is_setStorage23;

     is_setStorage0  = IntBitsStorage(s->StorageModuleStatusMask).test(0);  /* BIT 0*/
     if (is_setStorage0)  { /*accensione LED rosso*/ }

     is_setStorage1  = IntBitsStorage(s->StorageModuleStatusMask).test(1);  /* BIT 1*/
     if (is_setStorage1)  { /*accensione LED rosso*/ }

     is_setStorage2  = IntBitsStorage(s->StorageModuleStatusMask).test(2);  /* BIT 2*/
     if (is_setStorage2)  { /*accensione LED rosso*/ }

     is_setStorage3  = IntBitsStorage(s->StorageModuleStatusMask).test(3);  /* BIT 3*/
     if (is_setStorage3)  { /*accensione LED rosso*/ }

     is_setStorage4  = IntBitsStorage(s->StorageModuleStatusMask).test(4);  /* BIT 4*/
     if (is_setStorage4)  { /*accensione LED rosso*/ }

     is_setStorage5  = IntBitsStorage(s->StorageModuleStatusMask).test(5);  /* BIT 5*/
     if (is_setStorage5)  { /*accensione LED rosso*/ }

     is_setStorage6  = IntBitsStorage(s->StorageModuleStatusMask).test(6);  /* BIT 6*/
     if (is_setStorage6)  { /*accensione LED rosso*/ }

     is_setStorage7  = IntBitsStorage(s->StorageModuleStatusMask).test(7);  /* BIT 7*/
     if (is_setStorage7)  { /*accensione LED rosso*/ }

     is_setStorage8  = IntBitsStorage(s->StorageModuleStatusMask).test(8);  /* BIT 8*/
     if (is_setStorage8)  { /*accensione LED rosso*/ }

//     is_setStorage9  = IntBits(s->StorageModuleStatusMask).test(9);  /* BIT 9*/
//     if (is_setStorage9)  { /*accensione LED rosso*/ }

     is_setStorage10 = IntBitsStorage(s->StorageModuleStatusMask).test(10); /* BIT 10*/
     if (is_setStorage10) { /*accensione LED rosso*/ }

     is_setStorage11 = IntBitsStorage(s->StorageModuleStatusMask).test(11); /* BIT 11*/
     if (is_setStorage11) { /*accensione LED rosso*/ }

     is_setStorage12 = IntBitsStorage(s->StorageModuleStatusMask).test(12); /* BIT 12*/
     if (is_setStorage12) { /*accensione LED rosso*/ }

     is_setStorage13 = IntBitsStorage(s->StorageModuleStatusMask).test(13); /* BIT 13*/
     if (is_setStorage13) { /*accensione LED rosso*/ }

     is_setStorage14 = IntBitsStorage(s->StorageModuleStatusMask).test(14); /* BIT 14*/
     if (is_setStorage14) { /*accensione LED rosso*/ }

     is_setStorage15 = IntBitsStorage(s->StorageModuleStatusMask).test(15); /* BIT 15*/
     if (is_setStorage15) { /*accensione LED rosso*/ }

     is_setStorage16 = IntBitsStorage(s->StorageModuleStatusMask).test(16); /* BIT 16*/
     if (is_setStorage16) { /*accensione LED rosso*/ }

     is_setStorage17 = IntBitsStorage(s->StorageModuleStatusMask).test(17); /* BIT 17*/
     if (is_setStorage17) { /*accensione LED rosso*/ }

     is_setStorage18 = IntBitsStorage(s->StorageModuleStatusMask).test(18); /* BIT 18*/
     if (is_setStorage18) { /*accensione LED rosso*/ }

     is_setStorage19 = IntBitsStorage(s->StorageModuleStatusMask).test(19); /* BIT 19*/
     if (is_setStorage19) { /*accensione LED rosso*/ }

     is_setStorage20 = IntBitsStorage(s->StorageModuleStatusMask).test(20); /* BIT 20*/
     if (is_setStorage20) { /*accensione LED rosso*/ }

     is_setStorage21 = IntBitsStorage(s->StorageModuleStatusMask).test(21); /* BIT 21*/
     if (is_setStorage21) { /*accensione LED rosso*/ }

     is_setStorage22 = IntBitsStorage(s->StorageModuleStatusMask).test(22); /* BIT 22*/
     if (is_setStorage22) { /*accensione LED rosso*/ }

     is_setStorage23 = IntBitsStorage(s->StorageModuleStatusMask).test(23); /* BIT 23*/
     if (is_setStorage23) { /*accensione LED rosso*/ }


     /* RADIOLINK STATUS MASK */

     typedef std::bitset<32> IntBitsRadioLink;
     bool is_setRadioLink0,is_setRadioLink1,is_setRadioLink2,is_setRadioLink3/*,is_setRadioLink4,is_setRadioLink5*/;
     bool /*is_setRadioLink6,is_setRadioLink7,*/is_setRadioLink8,is_setRadioLink9, is_setRadioLink24;


     is_setRadioLink0  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(0);  /* BIT 0*/
     if (is_setRadioLink0)  { /*accensione LED rosso*/ }

     is_setRadioLink1  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(1);  /* BIT 1*/
     if (is_setRadioLink1)  { /*accensione LED rosso*/ }

     is_setRadioLink2  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(2);  /* BIT 2*/
     if (is_setRadioLink2)  { /*accensione LED rosso*/ }

     is_setRadioLink3  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(3);  /* BIT 3*/
     if (is_setRadioLink3)  { /*accensione LED rosso*/ }

//     is_setRadioLink4  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(4);  /* BIT 4*/
//     if (is_setRadioLink4)  { /*accensione LED rosso*/ }

//     is_setRadioLink5  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(5);  /* BIT 5*/
//     if (is_setRadioLink5)  { /*accensione LED rosso*/ }

//     is_setRadioLink6  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(6);  /* BIT 6*/
//     if (is_setRadioLink6)  { /*accensione LED rosso*/ }

//     is_setRadioLink7  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(7);  /* BIT 7*/
//     if (is_setRadioLink7)  { /*accensione LED rosso*/ }

     is_setRadioLink8  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(8);  /* BIT 8*/
     if (is_setRadioLink8)  { /*accensione LED rosso*/ }

     is_setRadioLink9  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(9);  /* BIT 9*/
     if (is_setRadioLink9)  { /*accensione LED rosso*/ }

     is_setRadioLink24  = IntBitsRadioLink(s->RadioLinkModuleStatusMask).test(24);  /* BIT 9*/
     if (is_setRadioLink24)  { /*accensione LED rosso*/ }
}
