#include "storage.h"
#include <bitset>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QStandardPaths>

Q_DECLARE_METATYPE(mavlink_system_status_pack_t);
Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);
Q_DECLARE_METATYPE(mavlink_motor_status_pack_t);
Q_DECLARE_METATYPE(mavlink_storage_status_pack_t);
Q_DECLARE_METATYPE(mavlink_guidance_status_pack_t);
Q_DECLARE_METATYPE(mavlink_radio_link_status_pack_t);

/*!
        \class Storage

        \brief The Storage class is the class used to create log file
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
    QString docFolder= QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString pathName = docFolder + "/agu-logs/";
    std::cout <<"PATH NAME"<< pathName.toStdString() << std::endl;

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
        pathName.append("0");
        pathName.append(QString::number(aa));
    }
    else
    {
        pathName.append(QString::number(aa));
    }

    if (mm < 10)
    {
        pathName.append("0");
        pathName.append(QString::number(mm));
    }
    else
    {
        pathName.append(QString::number(mm));
    }

    if (gg < 10)
    {
        pathName.append("0");
        pathName.append(QString::number(gg));
    }
    else
    {
        pathName.append(QString::number(gg));
    }

    pathName.append("_");

    if (hour < 10)
    {
        pathName.append("0");
        pathName.append(QString::number(hour));
    }
    else
    {
        pathName.append(QString::number(hour));
    }

    if (min < 10)
    {
        pathName.append("0");
        pathName.append(QString::number(min));
    }
    else
    {
        pathName.append(QString::number(min));
    }

    if (sec < 10)
    {
        pathName.append("0");
        pathName.append(QString::number(sec));
    }
    else
    {
        pathName.append(QString::number(sec));
    }

    return pathName;
}

void Storage::TurnOnFixOfTime()
{
    GPS.FixGPSTime = true;
}

void Storage::SetDeltaTime(int deltaTime)
{
    GPS.DeltaGPSTimefromSystemTime=deltaTime;
}

void Storage::storeData(QVariant data)
{
    if (data.canConvert<mavlink_telemetry_data_pack_t>()) {
        storeDataTelemetry(data.value<mavlink_telemetry_data_pack_t>());
    }
    else if (data.canConvert<mavlink_system_status_pack_t>()) {
        storeDataSystemStatus(data.value<mavlink_system_status_pack_t>());
    }
    else if (data.canConvert<mavlink_motor_status_pack_t>()) {
        storeDataMotorStatus(data.value<mavlink_motor_status_pack_t>());
    }

    else if (data.canConvert<mavlink_guidance_status_pack_t>()) {
        storeDataGuidanceStatus(data.value<mavlink_guidance_status_pack_t>());
    }
    else if (data.canConvert<mavlink_storage_status_pack_t>()) {
        storeDataStorageStatus(data.value<mavlink_storage_status_pack_t>());
    }
    else if (data.canConvert<mavlink_radio_link_status_pack_t>()) {
        storeDataRLStatus(data.value<mavlink_radio_link_status_pack_t>());
    }
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

void Storage::storeDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)
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
                 out << msg_telemetry.GNSS_Timestamp << ";";
                 out << msg_telemetry.Log_Timestamp << ";";
                 out << msg_telemetry.Latitude << ";";
                 out << msg_telemetry.Longitude << ";";
                 out << msg_telemetry.GNSS_Altitude << ";";
                 out << msg_telemetry.Velocity_Horizontal << ";";
                 out << msg_telemetry.Velocity_Vertical << ";";
                 out << msg_telemetry.Position_Accuracy  << ";";
                 out << msg_telemetry.Speed_Accuracy << ";";
                 out << msg_telemetry.Acceleration_X << ";";
                 out << msg_telemetry.Acceleration_Y << ";";
                 out << msg_telemetry.Acceleration_Z << ";";
                 out << msg_telemetry.ECEF_Position_X << ";";
                 out << msg_telemetry.ECEF_Position_Y << ";";
                 out << msg_telemetry.ECEF_Position_Z << ";";
                 out << msg_telemetry.ECEF_Velocity_X << ";";
                 out << msg_telemetry.ECEF_Velocity_Y << ";";
                 out << msg_telemetry.ECEF_Velocity_Z << ";";
                 out << msg_telemetry.Roll_Angle << ";";
                 out << msg_telemetry.Pitch_Angle << ";";
                 out << msg_telemetry.Yaw_Angle << ";";
                 out << msg_telemetry.Angular_Rate_Roll << ";";
                 out << msg_telemetry.Angular_Rate_Pitch << ";";
                 out << msg_telemetry.Angular_Rate_Yaw << ";";
                 out << msg_telemetry.Quaternion_0 << ";";
                 out << msg_telemetry.Quaternion_1 << ";";
                 out << msg_telemetry.Quaternion_2 << ";";
                 out << msg_telemetry.Quaternion_3 << ";";
                 out << msg_telemetry.Altitude_Main_Altimeter << ";";
                 out << msg_telemetry.Altitude_Payload_Altimeter << ";";
                 out << msg_telemetry.Air_Speed_U  << ";";
                 out << msg_telemetry.Air_Speed_V << ";";
                 out << msg_telemetry.Air_Speed_W << ";";
                 out << msg_telemetry.Air_Temperature << ";";
                 out << msg_telemetry.Telemetry_Status_Mask << ";";
                 out << msg_telemetry.Satellite_Num << "\r\n";
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
                 out << msg_telemetry.GNSS_Timestamp << ";";
                 out << msg_telemetry.Log_Timestamp << ";";
                 out << msg_telemetry.Latitude << ";";
                 out << msg_telemetry.Longitude << ";";
                 out << msg_telemetry.GNSS_Altitude << ";";
                 out << msg_telemetry.Velocity_Horizontal << ";";
                 out << msg_telemetry.Velocity_Vertical << ";";
                 out << msg_telemetry.Position_Accuracy  << ";";
                 out << msg_telemetry.Speed_Accuracy << ";";
                 out << msg_telemetry.Acceleration_X << ";";
                 out << msg_telemetry.Acceleration_Y << ";";
                 out << msg_telemetry.Acceleration_Z << ";";
                 out << msg_telemetry.ECEF_Position_X << ";";
                 out << msg_telemetry.ECEF_Position_Y << ";";
                 out << msg_telemetry.ECEF_Position_Z << ";";
                 out << msg_telemetry.ECEF_Velocity_X << ";";
                 out << msg_telemetry.ECEF_Velocity_Y << ";";
                 out << msg_telemetry.ECEF_Velocity_Z << ";";
                 out << msg_telemetry.Roll_Angle << ";";
                 out << msg_telemetry.Pitch_Angle << ";";
                 out << msg_telemetry.Yaw_Angle << ";";
                 out << msg_telemetry.Angular_Rate_Roll << ";";
                 out << msg_telemetry.Angular_Rate_Pitch << ";";
                 out << msg_telemetry.Angular_Rate_Yaw << ";";
                 out << msg_telemetry.Quaternion_0 << ";";
                 out << msg_telemetry.Quaternion_1 << ";";
                 out << msg_telemetry.Quaternion_2 << ";";
                 out << msg_telemetry.Quaternion_3 << ";";
                 out << msg_telemetry.Altitude_Main_Altimeter << ";";
                 out << msg_telemetry.Altitude_Payload_Altimeter << ";";
                 out << msg_telemetry.Air_Speed_U  << ";";
                 out << msg_telemetry.Air_Speed_V << ";";
                 out << msg_telemetry.Air_Speed_W << ";";
                 out << msg_telemetry.Air_Temperature << ";";
                 out << msg_telemetry.Telemetry_Status_Mask << ";";
                 out << msg_telemetry.Satellite_Num << "\r\n";
              }

          }

     }

     else

     {
         if (file.open(QIODevice::WriteOnly | QIODevice::Append))
         {
             out << milliseconds_since_epoch << ";";
             out << msg_telemetry.GNSS_Timestamp << ";";
             out << msg_telemetry.Log_Timestamp << ";";
             out << msg_telemetry.Latitude << ";";
             out << msg_telemetry.Longitude << ";";
             out << msg_telemetry.GNSS_Altitude << ";";
             out << msg_telemetry.Velocity_Horizontal << ";";
             out << msg_telemetry.Velocity_Vertical << ";";
             out << msg_telemetry.Position_Accuracy  << ";";
             out << msg_telemetry.Speed_Accuracy << ";";
             out << msg_telemetry.Acceleration_X << ";";
             out << msg_telemetry.Acceleration_Y << ";";
             out << msg_telemetry.Acceleration_Z << ";";
             out << msg_telemetry.ECEF_Position_X << ";";
             out << msg_telemetry.ECEF_Position_Y << ";";
             out << msg_telemetry.ECEF_Position_Z << ";";
             out << msg_telemetry.ECEF_Velocity_X << ";";
             out << msg_telemetry.ECEF_Velocity_Y << ";";
             out << msg_telemetry.ECEF_Velocity_Z << ";";
             out << msg_telemetry.Roll_Angle << ";";
             out << msg_telemetry.Pitch_Angle << ";";
             out << msg_telemetry.Yaw_Angle << ";";
             out << msg_telemetry.Angular_Rate_Roll << ";";
             out << msg_telemetry.Angular_Rate_Pitch << ";";
             out << msg_telemetry.Angular_Rate_Yaw << ";";
             out << msg_telemetry.Quaternion_0 << ";";
             out << msg_telemetry.Quaternion_1 << ";";
             out << msg_telemetry.Quaternion_2 << ";";
             out << msg_telemetry.Quaternion_3 << ";";
             out << msg_telemetry.Altitude_Main_Altimeter << ";";
             out << msg_telemetry.Altitude_Payload_Altimeter << ";";
             out << msg_telemetry.Air_Speed_U  << ";";
             out << msg_telemetry.Air_Speed_V << ";";
             out << msg_telemetry.Air_Speed_W << ";";
             out << msg_telemetry.Air_Temperature << ";";
             out << msg_telemetry.Telemetry_Status_Mask << ";";
             out << msg_telemetry.Satellite_Num << "\r\n";
         }

         CountT = false;
     }

}

void Storage::storeDataSystemStatus(const mavlink_system_status_pack_t msg_system_status)
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
                 out << msg_system_status.Log_Timestamp << ";";
                 out << msg_system_status.Core_Module_Status_Mask << ";";
                 out << msg_system_status.Telemetry_Module_Status_Mask << ";";
                 out << msg_system_status.Storage_Module_Status_Mask << ";";
                 out << msg_system_status.Radio_Link_Module_Status_Mask << ";";
                 out << msg_system_status.Motor_Control_Module_Status_Mask  << ";";
                 out << msg_system_status.Guidance_Module_Status_Mask << ";";

                 if (msg_system_status.Flight_Phase == int(FlightPhase::Initialization))   out << "0;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Trim))        out << "1;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Guidance))    out << "2;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Flare))       out << "3;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Finalization))out << "4;";

                 if (msg_system_status.Flight_Mode == int(FlightMode::EmergencyMode))     out << "0;";
                 else if (msg_system_status.Flight_Mode ==int( FlightMode::RecoveryMode)) out << "1;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::ManualMode))   out << "2;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::OpenLoop))     out << "3;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::ClosedLoop))   out << "4;";

                 out << msg_system_status.Flight_Phase_Time << ";\r\n";
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
                 out << msg_system_status.Log_Timestamp << ";";
                 out << msg_system_status.Core_Module_Status_Mask << ";";
                 out << msg_system_status.Telemetry_Module_Status_Mask << ";";
                 out << msg_system_status.Storage_Module_Status_Mask << ";";
                 out << msg_system_status.Radio_Link_Module_Status_Mask << ";";
                 out << msg_system_status.Motor_Control_Module_Status_Mask  << ";";
                 out << msg_system_status.Guidance_Module_Status_Mask << ";";

                 if (msg_system_status.Flight_Phase == int(FlightPhase::Initialization))   out << "0;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Trim))        out << "1;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Guidance))    out << "2;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Flare))       out << "3;";
                 else if (msg_system_status.Flight_Phase == int(FlightPhase::Finalization))out << "4;";

                 if (msg_system_status.Flight_Mode == int(FlightMode::EmergencyMode))     out << "0;";
                 else if (msg_system_status.Flight_Mode ==int( FlightMode::RecoveryMode)) out << "1;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::ManualMode))   out << "2;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::OpenLoop))     out << "3;";
                 else if (msg_system_status.Flight_Mode == int(FlightMode::ClosedLoop))   out << "4;";

                 out << msg_system_status.Flight_Phase_Time << ";\r\n";
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";   /*stampa ultima riga del file*/
             out << msg_system_status.Log_Timestamp << ";";
             out << msg_system_status.Core_Module_Status_Mask << ";";
             out << msg_system_status.Telemetry_Module_Status_Mask << ";";
             out << msg_system_status.Storage_Module_Status_Mask << ";";
             out << msg_system_status.Radio_Link_Module_Status_Mask << ";";
             out << msg_system_status.Motor_Control_Module_Status_Mask  << ";";
             out << msg_system_status.Guidance_Module_Status_Mask << ";";

             if (msg_system_status.Flight_Phase == int(FlightPhase::Initialization))   out << "0;";
             else if (msg_system_status.Flight_Phase == int(FlightPhase::Trim))        out << "1;";
             else if (msg_system_status.Flight_Phase == int(FlightPhase::Guidance))    out << "2;";
             else if (msg_system_status.Flight_Phase == int(FlightPhase::Flare))       out << "3;";
             else if (msg_system_status.Flight_Phase == int(FlightPhase::Finalization))out << "4;";

             if (msg_system_status.Flight_Mode == int(FlightMode::EmergencyMode))     out << "0;";
             else if (msg_system_status.Flight_Mode ==int( FlightMode::RecoveryMode)) out << "1;";
             else if (msg_system_status.Flight_Mode == int(FlightMode::ManualMode))   out << "2;";
             else if (msg_system_status.Flight_Mode == int(FlightMode::OpenLoop))     out << "3;";
             else if (msg_system_status.Flight_Mode == int(FlightMode::ClosedLoop))   out << "4;";

             out << msg_system_status.Flight_Phase_Time << ";\r\n";
         }

         CountS = false;
     }
}

void Storage::storeDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status)
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
                out << msg_motor_status.Log_Timestamp << ";";
                out << msg_motor_status.Motor_A_Real_Position << ";";
                out << msg_motor_status.Motor_B_Real_Position << ";";
                out << msg_motor_status.Motor_A_Demand_Position << ";";
                out << msg_motor_status.Motor_B_Demand_Position << ";";
                out << msg_motor_status.Motor_A_Torque << ";";
                out << msg_motor_status.Motor_B_Torque << ";";
                out << msg_motor_status.Motor_A_Temperature << ";";
                out << msg_motor_status.Motor_B_Temperature << ";";
                out << msg_motor_status.BMS_Voltage << ";";
                out << msg_motor_status.BMS_Absorption << ";";
                out << msg_motor_status.BMS_Temperature << ";";
                out << msg_motor_status.Motor_Control_Status_Mask << ";";
                out << msg_motor_status.Motor_A_Faults_Mask << ";";
                out << msg_motor_status.Motor_B_Faults_Mask << ";";
                out << msg_motor_status.BMS_Faults_Mask << ";\r\n";
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
                 out << msg_motor_status.Log_Timestamp << ";";
                 out << msg_motor_status.Motor_A_Real_Position << ";";
                 out << msg_motor_status.Motor_B_Real_Position << ";";
                 out << msg_motor_status.Motor_A_Demand_Position << ";";
                 out << msg_motor_status.Motor_B_Demand_Position << ";";
                 out << msg_motor_status.Motor_A_Torque << ";";
                 out << msg_motor_status.Motor_B_Torque << ";";
                 out << msg_motor_status.Motor_A_Temperature << ";";
                 out << msg_motor_status.Motor_B_Temperature << ";";
                 out << msg_motor_status.BMS_Voltage << ";";
                 out << msg_motor_status.BMS_Absorption << ";";
                 out << msg_motor_status.BMS_Temperature << ";";
                 out << msg_motor_status.Motor_Control_Status_Mask << ";";
                 out << msg_motor_status.Motor_A_Faults_Mask << ";";
                 out << msg_motor_status.Motor_B_Faults_Mask << ";";
                 out << msg_motor_status.BMS_Faults_Mask << ";\r\n";
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";  /*Stampo ultima riga del file*/
             out << msg_motor_status.Log_Timestamp << ";";
             out << msg_motor_status.Motor_A_Real_Position << ";";
             out << msg_motor_status.Motor_B_Real_Position << ";";
             out << msg_motor_status.Motor_A_Demand_Position << ";";
             out << msg_motor_status.Motor_B_Demand_Position << ";";
             out << msg_motor_status.Motor_A_Torque << ";";
             out << msg_motor_status.Motor_B_Torque << ";";
             out << msg_motor_status.Motor_A_Temperature << ";";
             out << msg_motor_status.Motor_B_Temperature << ";";
             out << msg_motor_status.BMS_Voltage << ";";
             out << msg_motor_status.BMS_Absorption << ";";
             out << msg_motor_status.BMS_Temperature << ";";
             out << msg_motor_status.Motor_Control_Status_Mask << ";";
             out << msg_motor_status.Motor_A_Faults_Mask << ";";
             out << msg_motor_status.Motor_B_Faults_Mask << ";";
             out << msg_motor_status.BMS_Faults_Mask << ";\r\n";
        }

        CountM = false;
    }
}

void Storage::storeDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)
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
                 out << msg_radio_status.System_Timestamp << ";";
                 out << msg_radio_status.RSSI << ";";
                 out << msg_radio_status.Radio_Link_Module_Status_Mask << ";\r\n";;
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
                 out << msg_radio_status.System_Timestamp << ";";
                 out << msg_radio_status.RSSI << ";";
                 out << msg_radio_status.Radio_Link_Module_Status_Mask << ";\r\n";
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
             out << milliseconds_since_epoch << ";";   /*Stampo ultima riga del file*/
             out << msg_radio_status.System_Timestamp << ";";
             out << msg_radio_status.RSSI << ";";
             out << msg_radio_status.Radio_Link_Module_Status_Mask << ";\r\n";
        }

        CountR = false;
    }
}

void Storage::storeDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)
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
                 out << msg_storage_status.System_Timestamp << ";";
                 out << msg_storage_status.Storage_Free_Data_Size << ";";
                 out << msg_storage_status.Storage_Module_Status_Mask << ";\r\n";;
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
                 out << msg_storage_status.System_Timestamp << ";";
                 out << msg_storage_status.Storage_Free_Data_Size << ";";
                 out << msg_storage_status.Storage_Module_Status_Mask << ";\r\n";;
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            out << milliseconds_since_epoch << ";";   /*stampo ultima riga file*/
            out << msg_storage_status.System_Timestamp << ";";
            out << msg_storage_status.Storage_Free_Data_Size << ";";
            out << msg_storage_status.Storage_Module_Status_Mask << ";\r\n";;
        }

        CountST = false;
    }
}

void Storage::storeDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)
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
                 out << msg_guidance_status.System_Timestamp << ";";
                 out << msg_guidance_status.Guidance_Module_Status_Mask << ";\r\n";;
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
                 out << msg_guidance_status.System_Timestamp << ";";
                 out << msg_guidance_status.Guidance_Module_Status_Mask << ";\r\n";;
              }
          }
     }
     else
     {
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            out << milliseconds_since_epoch << ";";   /*stampo ultima riga file*/
            out << msg_guidance_status.System_Timestamp << ";";
            out << msg_guidance_status.Guidance_Module_Status_Mask << ";\r\n";;
        }

        CountG = false;
    }
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

