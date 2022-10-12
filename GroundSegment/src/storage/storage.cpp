#include "storage.h"

/*!
        \class Storage

        \brief The Storage class is the class used to create lof file
*/
Storage::Storage(QObject *parent) : QObject(parent)
{
     InitFixGPSTime();
}

Storage::~Storage()
{

}

/*!
    \fn QString Storage::CalculatePathName()

    It calculates the first part of the log file's path name.
    In the first part of the path name there must be the creation time and date.
*/
QString Storage::CalculatePathName()
{
    QString PathName = "/home/AGU/GroundSegment/";
    QDate date, j;
    int gg, mm, aa;

    QTime time,i;
    int sec, min, hour;

    date = j.currentDate();
    gg   = date.day();
    mm   = date.month();
    aa   = date.year();

    time = i.currentTime();
    sec  = time.second();
    min  = time.minute();
    hour = time.hour();

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

    if (hour < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(hour));
    }
    else
    {
        PathName.append(QString::number(hour));
    }

    if (min < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(min));
    }
    else
    {
        PathName.append(QString::number(min));
    }

    if (sec < 10)
    {
        PathName.append("0");
        PathName.append(QString::number(sec));
    }
    else
    {
        PathName.append(QString::number(sec));
    }

    return PathName;
}

/*!
    \fn void Storage::StoreDataInMemorySystemStatus(SystemStatusPack *s)

    It sets the second part of the log file's path name (_CORE_Log.csv) and
    according to SystemStatusPack's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemorySystemStatus(SystemStatusPack *s)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_CORE_Log.csv");

    if (CountS == false)
    {
        PathSystemStatus = NewPathName.mid(0);  /*esegue la copia*/
        CountS = true;
    }

    QFile file(PathSystemStatus);
    QTextStream out(&file);

    if (file.size() < LenSystemStatus)
    {
        if (file.size() > 0)
        {
             if (file.open(QIODevice::WriteOnly | QIODevice::Append))
             {
                 out << milliseconds_since_epoch << ";";
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
                 out << "SystemTime;";
                 out << "Timestamp;";
                 out << "AguCORE_SM;";
                 out << "TLM_SM;";
                 out << "Storage_SM;";
                 out << "RadioL_SM;";
                 out << "MotorCtrl_SM;";
                 out << "Guid_SM;";
                 out << "FlightPhase;";
                 out << "FlightMode;";
                 out << "ExecTime;" << "\r\n";
                 out << milliseconds_since_epoch << ";";
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
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";   /*stampa ultima riga del file*/
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

         CountS = false;
     }

}

/*!
    \fn void Storage::StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *m)

    It sets the second part for the log file's path name (_MSTP_Log.csv) and
    according to MotorStatusPackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *m)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_MSTP_Log.csv");

    if (CountM == false)
    {
        PathMotor = NewPathName.mid(0);  /*esegue la copia*/
        CountM = true;
    }

    QFile file(PathMotor);
    QTextStream out(&file);

    if (file.size() < LenMotor)
    {
        if (file.size() > 0)
        {
            if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                out << milliseconds_since_epoch << ";";
                out << m->TimeStamp << ";";
                out << m->MotorARealPosition << ";";
                out << m->MotorBRealPosition << ";";
                out << m->MotorADemandPosition << ";";
                out << m->MotorBDemandPosition << ";";
                out << m->MotorATorque << ";";
                out << m->MotorBTorque << ";";
                out << m->MotorATemperature << ";";
                out << m->MotorBTemperature << ";";
                out << m->BMS1CurrentVoltage << ";";
                out << m->BMS1CurrentAbsorption << ";";
                out << m->BMS1CurrentTemperature << ";";
                out << m->MotorControlStatusMask << ";";
                out << m->MotorAFaultMask << ";";
                out << m->MotorBFaultMask << ";";
                out << m->BMSFaultMask << ";\r\n";
             }
          }
          else
          {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "SystemTime;";
                 out << "Timestamp;";
                 out << "MotA_RealPos;";
                 out << "MotB_RealPos;";
                 out << "MotA_DemPos;";
                 out << "MotB_DemPos;";
                 out << "MotA_Torque;";
                 out << "MotB_Torque;";
                 out << "MotA_Temp;";
                 out << "MotB_Temp;";
                 out << "BMS_Volt;";
                 out << "BMS_Current;";
                 out << "BMS_Temp;";
                 out << "MotControl_SM;";
                 out << "MotA_faultSM;";
                 out << "MotB_faultSM;"      ;
                 out << "BMS_faultSM;" << "\r\n";
                 out << milliseconds_since_epoch << ";";
                 out << m->TimeStamp << ";";
                 out << m->MotorARealPosition << ";";
                 out << m->MotorBRealPosition << ";";
                 out << m->MotorADemandPosition << ";";
                 out << m->MotorBDemandPosition << ";";
                 out << m->MotorATorque << ";";
                 out << m->MotorBTorque << ";";
                 out << m->MotorATemperature << ";";
                 out << m->MotorBTemperature << ";";
                 out << m->BMS1CurrentVoltage << ";";
                 out << m->BMS1CurrentAbsorption << ";";
                 out << m->BMS1CurrentTemperature << ";";
                 out << m->MotorControlStatusMask << ";";
                 out << m->MotorAFaultMask << ";";
                 out << m->MotorBFaultMask << ";";
                 out << m->BMSFaultMask << ";\r\n";
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";  /*Stampo ultima riga del file*/
             out << m->TimeStamp << ";";
             out << m->MotorARealPosition << ";";
             out << m->MotorBRealPosition << ";";
             out << m->MotorADemandPosition << ";";
             out << m->MotorBDemandPosition << ";";
             out << m->MotorATorque << ";";
             out << m->MotorBTorque << ";";
             out << m->MotorATemperature << ";";
             out << m->MotorBTemperature << ";";
             out << m->BMS1CurrentVoltage << ";";
             out << m->BMS1CurrentAbsorption << ";";
             out << m->BMS1CurrentTemperature << ";";
             out << m->MotorControlStatusMask << ";";
             out << m->MotorAFaultMask << ";";
             out << m->MotorBFaultMask << ";";
             out << m->BMSFaultMask << ";\r\n";
        }

        CountM = false;
    }
}

/*!
    \fn void Storage::StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *r)

    It sets the second part for the log file's path name (_RL_Log.csv) and
    according to RadioLinkPackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *r)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_RL_Log.csv");

    if (CountR == false)
    {
        PathRadioLink = NewPathName.mid(0);  /*esegue la copia*/
        CountR = true;
    }

    QFile file(PathRadioLink);
    QTextStream out(&file);

    if (file.size() < LenRadioLink)
    {
        if (file.size() > 0)
        {
             if (file.open(QIODevice::WriteOnly | QIODevice::Append))
             {
                 out << milliseconds_since_epoch << ";";
                 out << r->TimeStamp << ";";
                 out << r->RSSI << ";";
                 out << r->RadioLinkStatusMask << ";\r\n";;
              }
         }
         else
         {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "SystemTime;";
                 out << "Timestamp;";
                 out << "RSSI;";
                 out << "RL_SM;"<< "\r\n";
                 out << milliseconds_since_epoch << ";";
                 out << r->TimeStamp << ";";
                 out << r->RSSI << ";";
                 out << r->RadioLinkStatusMask << ";\r\n";
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";   /*Stampo ultima riga del file*/
             out << r->TimeStamp << ";";
             out << r->RSSI << ";";
             out << r->RadioLinkStatusMask << ";\r\n";
        }

        CountR = false;
    }
}

/*!
    \fn void Storage::StoreDataInMemoryStorageStatusPack(StorageStatusPack *st)

    It sets the second part for the log file's path name (_STR_Log.csv) and
    according to StorageStatusPack's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemoryStorageStatusPack(StorageStatusPack *st)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_STR_Log.csv");

    if (CountST == false)
    {
        PathStorageStatus = NewPathName.mid(0);  /*esegue la copia*/
        CountST = true;
    }

    QFile file(PathStorageStatus);
    QTextStream out(&file);

    if (file.size() < LenStorageStatus)
    {
        if (file.size() > 0)
        {
             if (file.open(QIODevice::WriteOnly | QIODevice::Append))
             {
                 out << milliseconds_since_epoch << ";";
                 out << st->TimeStamp << ";";
                 out << st->StorageFreeDataSize << ";";
                 out << st->StorageLinkStatusMask << ";\r\n";;
              }
         }
         else
         {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "SystemTime;";
                 out << "Timestamp;";
                 out << "FreeSpace;";
                 out << "STR_SM;"<< "\r\n";
                 out << milliseconds_since_epoch << ";";
                 out << st->TimeStamp << ";";
                 out << st->StorageFreeDataSize << ";";
                 out << st->StorageLinkStatusMask << ";\r\n";;
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            out << milliseconds_since_epoch << ";";   /*stampo ultima riga file*/
            out << st->TimeStamp << ";";
            out << st->StorageFreeDataSize << ";";
            out << st->StorageLinkStatusMask << ";\r\n";;
        }

        CountST = false;
    }
}

/*!
    \fn void Storage::StoreDataInMemoryGuidance(GuidancePackDataset *g)

    It sets the second part for the log file's path name (_GUID_Log.csv) and
    according to GuidancePackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemoryGuidance(GuidancePackDataset *g)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_GUID_Log.csv");

    if (CountG == false)
    {
        PathGuidance = NewPathName.mid(0);  /*esegue la copia*/
        CountG = true;
    }

    QFile file(PathGuidance);
    QTextStream out(&file);

    if (file.size() < LenGuidance)
    {
        if (file.size() > 0)
        {
             if (file.open(QIODevice::WriteOnly | QIODevice::Append))
             {
                 out << milliseconds_since_epoch << ";";
                 out << g->TimeStamp << ";";
                 out << g->GuidanceStatusMask << ";\r\n";;
             }
         }
         else
         {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "SystemTime;";
                 out << "Timestamp;";
                 out << "GUID_SM;"<< "\r\n";
                 out << milliseconds_since_epoch << ";";
                 out << g->TimeStamp << ";";
                 out << g->GuidanceStatusMask << ";\r\n";;
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            out << milliseconds_since_epoch << ";";   /*stampo ultima riga file*/
            out << g->TimeStamp << ";";
            out << g->GuidanceStatusMask << ";\r\n";;
        }

        CountG = false;
    }
}
/*!
    \fn void Storage::InitFixGPSTime()

    Function that initialize the variable FixGPSTime.
    FixGPSTime is set TRUE when GPS is fixed.

*/
void Storage::InitFixGPSTime()
{
    GPS.FixGPSTime = false;
}

/*!
    \fn void Storage::StoreDataInMemory(Telemetry *t)

    It sets the second part for the log file's path name (_TLM_Log.csv) and
    according to GuidancePackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::StoreDataInMemory(Telemetry *t)
{
    QString NewPathName = CalculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_TLM_Log.csv");

    if (CountT == false)
    {
        PathTelemetry = NewPathName.mid(0);  /*esegue la copia*/
        CountT = true;
    }   

    QFile file(PathTelemetry);
    QTextStream out(&file);

    if (file.size() < LenTelemetry)
    {
        if (file.size() > 0)
        {
            if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                 out << milliseconds_since_epoch << ";";
                 out << t->TimeStamp << ";";
                 out << t->TimeStampRIO << ";";
                 out << t->Latitude << ";";
                 out << t->Longitude << ";";
                 out << t->GNSSAltitude << ";";
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
                 out << t->AltitudeFromRadarAltimeter << ";";
                 out << t->AltitudeFromPayloadAltimeter << ";";
                 out << t->AirSpeed_UVector  << ";";
                 out << t->AirSpeed_VVector << ";";
                 out << t->AirSpeed_WVector << ";";
                 out << t->AirTemperature << ";";
                 out << t->TelemetryStatusMask << ";";
                 out << t->NumberOfGPSSatellite << "\r\n";
             }
          }
          else
          {
              if (file.open(QIODevice::WriteOnly))
              {
                 out << "SystemTime;";
                 out << "TimeStamp;";
                 out << "GNSS_TimeStamp;";
                 out << "GNSS_Latitude;";
                 out << "GNSS_Longitude;";
                 out << "GNSS_Altitude;";
                 out << "GNSS_LinVelH;";
                 out << "GNSS_LinVelV;";
                 out << "GNSS_PosAcc;";
                 out << "GNSS_SpeedAcc;";
                 out << "GNSS_LinAccX;";
                 out << "GNSS_LinAccY;";
                 out << "GNSS_LinAccZ;";
                 out << "GNSS_VecPosX;";
                 out << "GNSS_VecPosY;";
                 out << "GNSS_VecPosZ;";
                 out << "GNSS_VecVelX;";
                 out << "GNSS_VecVelY;";
                 out << "GNSS_VecVelZ;";
                 out << "GNSS_RollAng;";
                 out << "GNSS_PitchAng;";
                 out << "GNSS_YawAng;";
                 out << "GNSS_RollAngRate;";
                 out << "GNSS_PitchAngRate;";
                 out << "GNSS_YawAngRate;";
                 out << "GNSS_Quat0;";
                 out << "GNSS_Quat1;";
                 out << "GNSS_Quat2;";
                 out << "GNSS_Quat3;";
                 out << "RDaltitude;";
                 out << "PLaltitude;";
                 out << "Anem_U;";
                 out << "Anem_V;";
                 out << "Anem_W;";
                 out << "Anem_Temp;";
                 out << "StatusMask;";
                 out << "GPSnum;" << "\r\n";
                 out << milliseconds_since_epoch << ";";
                 out << t->TimeStamp << ";";
                 out << t->TimeStampRIO << ";";
                 out << t->Latitude << ";";
                 out << t->Longitude << ";";
                 out << t->GNSSAltitude << ";";
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
                 out << t->AltitudeFromRadarAltimeter << ";";
                 out << t->AltitudeFromPayloadAltimeter << ";";
                 out << t->AirSpeed_UVector  << ";";
                 out << t->AirSpeed_VVector << ";";
                 out << t->AirSpeed_WVector << ";";
                 out << t->AirTemperature << ";";
                 out << t->TelemetryStatusMask << ";";
                 out << t->NumberOfGPSSatellite << ";\r\n";
              }
          }
     }
     else
     {
         if (file.open(QIODevice::WriteOnly | QIODevice::Append))
         {
             out << milliseconds_since_epoch << ";";
             out << t->TimeStamp << ";";
             out << t->TimeStampRIO << ";";
             out << t->Latitude << ";";
             out << t->Longitude << ";";
             out << t->GNSSAltitude << ";";
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
             out << t->AltitudeFromRadarAltimeter << ";";
             out << t->AltitudeFromPayloadAltimeter << ";";
             out << t->AirSpeed_UVector  << ";";
             out << t->AirSpeed_VVector << ";";
             out << t->AirSpeed_WVector << ";";
             out << t->AirTemperature << ";";
             out << t->TelemetryStatusMask << ";";
             out << t->NumberOfGPSSatellite << ";\r\n";
         }

         CountT = false;
     }

}

