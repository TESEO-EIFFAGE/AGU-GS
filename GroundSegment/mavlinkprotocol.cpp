#include "mavlinkprotocol.h"
#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <string>
#include <iostream>
#include <stdio.h>


MavlinkProtocol::MavlinkProtocol(QObject *parent) : QObject(parent)
{

}

MavlinkProtocol::~MavlinkProtocol()
{

}

void MavlinkProtocol::parseDataTelemetry(QByteArray data)
{
    // Eseguire un test sul header di "data" per essere sicuri che sia un frame di telemetria
    // Spacchettare "data" e scrivere i dati ricevuti al posto sei segnali "_fromMavlink" definiti sotto

    //if (data == PACCHETTO Telemetria)

    uint64_t  TimeStamp_FromMavlink = 1, TimeStampRIO_FromMavlink = 2;
    uint32_t  Latitude_FromMavlink = 3, Longitude_FromMavlink = 4;
    uint32_t  GNSSAltitude_FromMavlink = 5;
    uint16_t  AirSpeed_UVector_FromMavlink = 6, AirSpeed_VVector_FromMavlink = 7, AirSpeed_WVector_FromMavlink = 8;
    uint16_t  AirTemperature_FromMavlink = 9;
    uint32_t  AltitudeFromRadarAltimeter_FromMavlink = 10, AltitudeFromPayloadAltimeter_FromMavlink = 11;
    uint16_t  LinearVelocityHorizontal_FromMavlink = 12;
    uint16_t  LinearVelocityVertical_FromMavlink = 13;
    uint16_t  PositionAccuracy_FromMavlink = 14;
    uint16_t  SpeedAccuracy_FromMavlink = 15;
    uint16_t  LinearAccelerationX_FromMavlink = 16, LinearAccelerationY_FromMavlink = 17, LinearAccelerationZ_FromMavlink = 18;
    uint32_t  ECEFVectorPositionX_FromMavlink = 19, ECEFVectorPositionY_FromMavlink = 20, ECEFVectorPositionZ_FromMavlink = 21;
    uint32_t  ECEFVectorVelocityX_FromMavlink = 22, ECEFVectorVelocityY_FromMavlink = 23, ECEFVectorVelocityZ_FromMavlink = 24;
    uint16_t  RollAngle_FromMavlink = 25, PitchAngle_FromMavlink = 26, YawAngle_FromMavlink = 27;
    uint16_t  AgularRateRoll_FromMavlink = 28, AgularRatePitch_FromMavlink = 29, AgularRateYaw_FromMavlink = 30;
    float     Quaternion0_FromMavlink = 31, Quaternion1_FromMavlink = 32, Quaternion2_FromMavlink = 33, Quaternion3_FromMavlink = 34;
    uint64_t  TelemetryStatusMask_FromMavlink = 2459565876494606882;
    uint8_t   NumberOfGPSSatellite_FromMavlink = 36;

    t.TimeStamp =  TimeStamp_FromMavlink;
    t.TimeStampRIO = TimeStampRIO_FromMavlink;
    t.Latitude = Latitude_FromMavlink;
    t.Longitude = Longitude_FromMavlink;
    t.GNSSAltitude = GNSSAltitude_FromMavlink;
    t.AirSpeed_UVector = AirSpeed_UVector_FromMavlink;
    t.AirSpeed_VVector = AirSpeed_VVector_FromMavlink;
    t.AirSpeed_WVector = AirSpeed_WVector_FromMavlink;
    t.ECEFVectorPositionX = ECEFVectorPositionX_FromMavlink;
    t.ECEFVectorPositionY = ECEFVectorPositionY_FromMavlink;
    t.ECEFVectorPositionZ = ECEFVectorPositionZ_FromMavlink;
    t.ECEFVectorVelocityX = ECEFVectorVelocityX_FromMavlink;
    t.ECEFVectorVelocityY = ECEFVectorVelocityY_FromMavlink;
    t.ECEFVectorVelocityZ = ECEFVectorVelocityZ_FromMavlink;
    t.LinearVelocityHorizontal = LinearVelocityHorizontal_FromMavlink;
    t.LinearVelocityVertical = LinearVelocityVertical_FromMavlink;
    t.AgularRatePitch = AgularRatePitch_FromMavlink;
    t.AgularRateRoll = AgularRateRoll_FromMavlink;
    t.AgularRateYaw = AgularRateYaw_FromMavlink;
    t.RollAngle = RollAngle_FromMavlink;
    t.PitchAngle = PitchAngle_FromMavlink;
    t.YawAngle = YawAngle_FromMavlink;
    t.TelemetryStatusMask = TelemetryStatusMask_FromMavlink;
    t.Quaternion0 = Quaternion0_FromMavlink;
    t.Quaternion1 = Quaternion1_FromMavlink;
    t.Quaternion2 = Quaternion2_FromMavlink;
    t.Quaternion3 = Quaternion3_FromMavlink;
    t.AirTemperature = AirTemperature_FromMavlink;
    t.AltitudeFromPayloadAltimeter = AltitudeFromPayloadAltimeter_FromMavlink;
    t.AltitudeFromRadarAltimeter = AltitudeFromRadarAltimeter_FromMavlink;
    t.PositionAccuracy = PositionAccuracy_FromMavlink;
    t.SpeedAccuracy = SpeedAccuracy_FromMavlink;
    t.LinearAccelerationX = LinearAccelerationX_FromMavlink;
    t.LinearAccelerationY = LinearAccelerationY_FromMavlink;
    t.LinearAccelerationZ = LinearAccelerationZ_FromMavlink;
    t.NumberOfGPSSatellite = NumberOfGPSSatellite_FromMavlink;

    emit toStorage(&t);
    emit toHMI(&t);
}


void MavlinkProtocol::parseDataSystemStatus(QByteArray data)
{
    // Eseguire un test sul header di "data" per essere sicuri che sia SystemStatus
    // Spacchettare "data" e scrivere i dati ricevuti al posto sei segnali "_fromMavlink" definiti sotto

    //if (data == PACCHETTO SystemStatus)


    uint64_t  TimeStamp_FromMavlink = 1111;
    uint32_t  CoreModuleStatusMask_FromMavlink = 2222;
    uint64_t  TelemetryStatusMask_FromMavlink = 21232341121212;
    uint32_t  StorageModuleStatusMask_FromMavlink = 12312;
    uint32_t  RadioLinkModuleStatusMask_FromMavlink = 123421;
    uint32_t  MotorControlModuleStatusMask_FromMavlink = 444;
    uint32_t  GuidanceModuleStatusMask_FromMavlink = 12121;
    FlightPhase fp_FromMavlink = FlightPhase::Guidance;
    FlightMode  fm_FromMavlink = FlightMode::EmergencyMode;
    uint32_t  FlyPhaseExecutionTime_FromMavlink = 32131;

    s.TimeStamp = TimeStamp_FromMavlink;
    s.CoreModuleStatusMask = CoreModuleStatusMask_FromMavlink;
    s.TelemetryStatusMask = TelemetryStatusMask_FromMavlink;
    s.StorageModuleStatusMask = StorageModuleStatusMask_FromMavlink;
    s.RadioLinkModuleStatusMask = RadioLinkModuleStatusMask_FromMavlink;
    s.MotorControlModuleStatusMask = MotorControlModuleStatusMask_FromMavlink;
    s.GuidanceModuleStatusMask = GuidanceModuleStatusMask_FromMavlink;
    s.fp = fp_FromMavlink;
    s.fm = fm_FromMavlink;
    s.FlyPhaseExecutionTime = FlyPhaseExecutionTime_FromMavlink;

    emit toStorageSystemStatus(&s);
    emit toHMISystemStatus(&s);
}

quint16 MavlinkProtocol::GetCRC(const QByteArray & data)
{
     return qChecksum(data, data.size(), Qt::ChecksumIso3309);
}

