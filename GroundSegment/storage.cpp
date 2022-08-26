#include "storage.h"

Storage::Storage(QObject *parent) : QObject(parent)
{

}

Storage::~Storage()
{

}

QString Storage::CalculatePathName()
{
    QString PathName = "/home/AGU/GroundSegment/";
    QDate date, j;
    int gg, mm, aa;

    date = j.currentDate();
    gg   = date.day();
    mm   = date.month();
    aa   = date.year();

    if (aa < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(aa));
    }
    else
    {
        PathName.append(QString::number(aa));
    }

    if (mm < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(mm));
    }
    else
    {
        PathName.append(QString::number(mm));
    }

    if (gg < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(gg));
    }
    else
    {
        PathName.append(QString::number(gg));
    }

    PathName.append("_");
    PathName.append(CalculateSystemTime());

    qInfo() << "PATH ----------------------------  : " << PathName;

    return PathName;
}

QString Storage::CalculateSystemTime()
{
    QString SystemTime;
    QTime time,i;
    int sec, min, hour;

    time = i.currentTime();
    sec  = time.second();
    min  = time.minute();
    hour = time.hour();

    if (hour < 10)
    {
        SystemTime.append("0");
        SystemTime.append(QString::number(hour));
    }
    else
    {
        SystemTime.append(QString::number(hour));
    }

    if (min < 10)
    {
        SystemTime.append("0");
        SystemTime.append(QString::number(min));
    }
    else
    {
        SystemTime.append(QString::number(min));
    }

    if (sec < 10)
    {
        SystemTime.append("0");
        SystemTime.append(QString::number(sec));
    }
    else
    {
        SystemTime.append(QString::number(sec));
    }

    return SystemTime;
}

void Storage::StoreDataInMemorySystemStatus(SystemStatusPack *s)
{
    QString NewPathName = CalculatePathName();
    QString GlobalTime  = CalculateSystemTime();

    NewPathName.append("_STP_Log.csv");

    if (CountS == false)
    {
        PathSystemStatus = NewPathName.mid(0);  /*esegue la copia*/
        CountS = true;
    }

    QFile file(PathSystemStatus);
    QTextStream out(&file);

    if (file.size() < 10000)
    {
        if (file.size() > 0)
        {
             if (file.open(QIODevice::WriteOnly | QIODevice::Append))
             {
                 out << GlobalTime << ";";
                 out << s->TimeStamp << ";";
                 out << s->CoreModuleStatusMask << ";";
                 out << s->TelemetryStatusMask << ";";
                 out << s->StorageModuleStatusMask << ";";
                 out << s->RadioLinkModuleStatusMask << ";";
                 out << s->MotorControlModuleStatusMask  << ";";
                 out << s->GuidanceModuleStatusMask << ";";

                 if (s->fp == FlightPhase::Initialization)   out << "0;";
                 else if (s->fp == FlightPhase::Trim)        out << "1;";
                 else if (s->fp == FlightPhase::Guidance)    out << "2;";
                 else if (s->fp == FlightPhase::Flare)       out << "3;";
                 else if (s->fp == FlightPhase::Finalization)out << "4;";

                 if (s->fm == FlightMode::EmergencyMode)     out << "0;";
                 else if (s->fm == FlightMode::RecoveryMode) out << "1;";
                 else if (s->fm == FlightMode::ManualMode)   out << "2;";
                 else if (s->fm == FlightMode::OpenLoop)     out << "3;";
                 else if (s->fm == FlightMode::ClosedLoop)   out << "4;";

                 out << s->FlyPhaseExecutionTime << ";\r\n";
              }
         }
         else
         {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "GlobalTime;";
                 out << "TimeStamp;";
                 out << "CoreModuleStatusMask;";
                 out << "TelemetryStatusMask;";
                 out << "StorageModuleStatusMask;";
                 out << "RadioLinkModuleStatusMask;";
                 out << "MotorControlModuleStatusMask;";
                 out << "GuidanceModuleStatusMask;";
                 out << "FlightPhase;";
                 out << "FlightMode;";
                 out << "FlyPhaseExecutionTime;" << "\n";
                 out << GlobalTime << ";";
                 out << s->TimeStamp << ";";
                 out << s->CoreModuleStatusMask << ";";
                 out << s->TelemetryStatusMask << ";";
                 out << s->StorageModuleStatusMask << ";";
                 out << s->RadioLinkModuleStatusMask << ";";
                 out << s->MotorControlModuleStatusMask  << ";";
                 out << s->GuidanceModuleStatusMask << ";";

                 if (s->fp == FlightPhase::Initialization)   out << "0;";
                 else if (s->fp == FlightPhase::Trim)        out << "1;";
                 else if (s->fp == FlightPhase::Guidance)    out << "2;";
                 else if (s->fp == FlightPhase::Flare)       out << "3;";
                 else if (s->fp == FlightPhase::Finalization)out << "4;";

                 if (s->fm == FlightMode::EmergencyMode)     out << "0;";
                 else if (s->fm == FlightMode::RecoveryMode) out << "1;";
                 else if (s->fm == FlightMode::ManualMode)   out << "2;";
                 else if (s->fm == FlightMode::OpenLoop)     out << "3;";
                 else if (s->fm == FlightMode::ClosedLoop)   out << "4;";

                 out << s->FlyPhaseExecutionTime << ";\n";
              }
          }
     }
     else
     {
         CountS = false;
     }

}


void Storage::StoreDataInMemory(Telemetry *t)
{
    QString NewPathName = CalculatePathName();
    QString GlobalTime = CalculateSystemTime();

    NewPathName.append("_TLM_Log.csv");

    if (CountT == false)
    {
        PathTelemetry = NewPathName.mid(0);  /*esegue la copia*/
        CountT = true;
    }

    QFile file(PathTelemetry);
    QTextStream out(&file);

    if (file.size() < 10000)
    {
        if (file.size() > 0)
        {
            if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                 out << GlobalTime << ";";
                 out << t->TimeStamp << ";";                                        /*OCCHIO CHE TELEMETRY LOG FORMAT è DIVERSO*/
                 out << t->TimeStampRIO << ";";
                 out << t->Latitude << ";";
                 out << t->Longitude << ";";
                 out << t->GNSSAltitude << ";";
                 out << t->AirSpeed_UVector  << ";";
                 out << t->AirSpeed_VVector << ";";
                 out << t->AirSpeed_WVector << ";";
                 out << t->AirTemperature << ";";
                 out << t->AltitudeFromRadarAltimeter << ";";
                 out << t->AltitudeFromPayloadAltimeter << ";";
                 out << t->LinearVelocityHorizontal << ";";
                 out << t->LinearVelocityVertical << ";";
                 out << t->PositionAccuracy  << ";";
                 out << t->SpeedAccuracy << ";";
                 out << t->LinearAccelerationX << ";";
                 out << t->LinearAccelerationY << ";";
                 out << t->LinearAccelerationZ << ";";
                 out << t->ECEFVectorPositionX << ";";
                 out << t->ECEFVectorPositionY << ";";
                 out << t->ECEFVectorPositionZ << ";";
                 out << t->ECEFVectorVelocityX << ";";
                 out << t->ECEFVectorVelocityY << ";";
                 out << t->ECEFVectorVelocityZ << ";";
                 out << t->RollAngle << ";";
                 out << t->PitchAngle << ";";
                 out << t->YawAngle << ";";
                 out << t->AngularRateRoll << ";";
                 out << t->AngularRatePitch << ";";
                 out << t->AngularRateYaw << ";";
                 out << t->Quaternion0 << ";";
                 out << t->Quaternion1 << ";";
                 out << t->Quaternion2 << ";";
                 out << t->Quaternion3 << ";";
                 out << t->TelemetryStatusMask << ";";
                 out << t->NumberOfGPSSatellite << ";\n";
             }
          }
          else
          {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "GlobalTime;";
                 out << "TimeStamp;";
                 out << "TimeStampRIO;";
                 out << "Latitude;";
                 out << "Longitude;";
                 out << "GNSSAltitude;";
                 out << "AirSpeed_UVector;";
                 out << "AirSpeed_VVector;";
                 out << "AirSpeed_WVector;";
                 out << "AirTemperature;";
                 out << "AltitudeFromRadarAltimeter;";
                 out << "AltitudeFromPayloadAltimeter;";
                 out << "LinearVelocityHorizontal;";
                 out << "LinearVelocityVertical;";
                 out << "PositionAccuracy;";
                 out << "SpeedAccuracy;";
                 out << "LinearAccelerationX;";
                 out << "LinearAccelerationY;";
                 out << "LinearAccelerationZ;";
                 out << "ECEFVectorPositionX;";
                 out << "ECEFVectorPositionY;";
                 out << "ECEFVectorPositionZ;";
                 out << "ECEFVectorVelocityX;";
                 out << "ECEFVectorVelocityY;";
                 out << "ECEFVectorPositionZ;";
                 out << "RollAngle;";
                 out << "PitchAngle;";
                 out << "YawAngle;";
                 out << "AngularRateRoll;";
                 out << "AngularRatePitch;";
                 out << "AngularRateYaw;";
                 out << "Quaternion0;";
                 out << "Quaternion1;";
                 out << "Quaternion2;";
                 out << "Quaternion3;";
                 out << "TelemetryStatusMask;";
                 out << "NumberOfGPSSatellite;" << "\n";
                 out << GlobalTime << ";";
                 out << t->TimeStamp << ";";
                 out << t->TimeStampRIO << ";";
                 out << t->Latitude << ";";
                 out << t->Longitude << ";";
                 out << t->GNSSAltitude << ";";
                 out << t->AirSpeed_UVector  << ";";
                 out << t->AirSpeed_VVector << ";";
                 out << t->AirSpeed_WVector << ";";
                 out << t->AirTemperature << ";";
                 out << t->AltitudeFromRadarAltimeter << ";";
                 out << t->AltitudeFromPayloadAltimeter << ";";
                 out << t->LinearVelocityHorizontal << ";";
                 out << t->LinearVelocityVertical << ";";
                 out << t->PositionAccuracy  << ";";
                 out << t->SpeedAccuracy << ";";
                 out << t->LinearAccelerationX << ";";
                 out << t->LinearAccelerationY << ";";
                 out << t->LinearAccelerationZ << ";";
                 out << t->ECEFVectorPositionX << ";";
                 out << t->ECEFVectorPositionY << ";";
                 out << t->ECEFVectorPositionZ << ";";
                 out << t->ECEFVectorVelocityX << ";";
                 out << t->ECEFVectorVelocityY << ";";
                 out << t->ECEFVectorVelocityZ << ";";
                 out << t->RollAngle << ";";
                 out << t->PitchAngle << ";";
                 out << t->YawAngle << ";";
                 out << t->AngularRateRoll << ";";
                 out << t->AngularRatePitch << ";";
                 out << t->AngularRateYaw << ";";
                 out << t->Quaternion0 << ";";
                 out << t->Quaternion1 << ";";
                 out << t->Quaternion2 << ";";
                 out << t->Quaternion3 << ";";
                 out << t->TelemetryStatusMask << ";";
                 out << t->NumberOfGPSSatellite << ";\r\n";
              }
          }
     }
     else
     {
         CountT = false;
     }

}

