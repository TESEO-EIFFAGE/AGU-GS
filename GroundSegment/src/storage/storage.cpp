#include "storage.h"
#include <bitset>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QStandardPaths>
#include <QDir>

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
    initFixGPSTime();
}

Storage::~Storage()
{
}

/*!
    \fn QString Storage::calculatePathName()

    It calculates the first part of the log file's path name.
    In the first part of the path name there must be the creation time and date.
*/
QString Storage::calculatePathName()
{

    QString docFolder= QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString pathName = docFolder + "/agu-logs/";

    if(QDir(pathName).exists()==false){
        QDir().mkdir(pathName);
    }

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

void Storage::turnOnFixOfTime()
{
    GPS.FixGPSTime = true;
}

void Storage::setDeltaTime(int deltaTime)
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
    \fn void Storage::initFixGPSTime()

    Function that initialize the variable FixGPSTime.
    FixGPSTime is set TRUE when GPS is fixed.

*/
void Storage::initFixGPSTime()
{
    GPS.FixGPSTime = false;
}
/*!
    \fn void Storage::storeDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)

    It sets the second part for the log file's path name (_TLM_Log.csv) and
    according to GuidancePackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;


    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_TLM_Log.csv");

    if (m_countT == false)
    {
        m_pathTelemetry = NewPathName.mid(0);  /*esegue la copia*/
        m_countT = true;
    }

    QFile file(m_pathTelemetry);
    QTextStream out(&file);

    if (file.size() < lenTelemetry)
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
                out << msg_telemetry.Log_Timestamp << ";";
                out << msg_telemetry.GNSS_Timestamp << ";";
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
            out << msg_telemetry.Log_Timestamp << ";";
            out << msg_telemetry.GNSS_Timestamp << ";";
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
        m_countT = false;
    }
}
/*!
    \fn void Storage::storeDataSystemStatus(const mavlink_system_status_pack_t msg_system_status)

    It sets the second part of the log file's path name (_CORE_Log.csv) and
    according to SystemStatusPack's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataSystemStatus(const mavlink_system_status_pack_t msg_system_status)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_CORE_Log.csv");

    if (m_countS == false)
    {
        m_pathSystemStatus = NewPathName.mid(0);  /*esegue la copia*/
        m_countS = true;
    }

    QFile file(m_pathSystemStatus);
    QTextStream out(&file);

    if (file.size() < lenSystemStatus)
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

                if (msg_system_status.Flight_Phase == 0) out << "0;";
                else if (msg_system_status.Flight_Phase == 1) out << "1;";
                else if (msg_system_status.Flight_Phase == 2) out << "2;";
                else if (msg_system_status.Flight_Phase == 3) out << "3;";
                else if (msg_system_status.Flight_Phase == 4) out << "4;";

                if (msg_system_status.Flight_Mode == 0) out << "0;";
                else if (msg_system_status.Flight_Mode == 1) out << "1;";
                else if (msg_system_status.Flight_Mode == 2) out << "2;";
                else if (msg_system_status.Flight_Mode == 3) out << "3;";
                else if (msg_system_status.Flight_Mode == 4) out << "4;";

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

                if (msg_system_status.Flight_Phase == 0) out << "0;";
                else if (msg_system_status.Flight_Phase == 1) out << "1;";
                else if (msg_system_status.Flight_Phase == 2) out << "2;";
                else if (msg_system_status.Flight_Phase == 3) out << "3;";
                else if (msg_system_status.Flight_Phase == 4) out << "4;";

                if (msg_system_status.Flight_Mode == 0) out << "0;";
                else if (msg_system_status.Flight_Mode == 1) out << "1;";
                else if (msg_system_status.Flight_Mode == 2) out << "2;";
                else if (msg_system_status.Flight_Mode == 3) out << "3;";
                else if (msg_system_status.Flight_Mode == 4) out << "4;";

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

            if (msg_system_status.Flight_Phase == 0) out << "0;";
            else if (msg_system_status.Flight_Phase == 1) out << "1;";
            else if (msg_system_status.Flight_Phase == 2) out << "2;";
            else if (msg_system_status.Flight_Phase == 3) out << "3;";
            else if (msg_system_status.Flight_Phase == 4) out << "4;";

            if (msg_system_status.Flight_Mode == 0) out << "0;";
            else if (msg_system_status.Flight_Mode == 1) out << "1;";
            else if (msg_system_status.Flight_Mode == 2) out << "2;";
            else if (msg_system_status.Flight_Mode == 3) out << "3;";
            else if (msg_system_status.Flight_Mode == 4) out << "4;";

            out << msg_system_status.Flight_Phase_Time << ";\r\n";
        }

        m_countS = false;
    }
}
/*!
    \fn void Storage::storeDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status)

    It sets the second part for the log file's path name (_MSTP_Log.csv) and
    according to MotorStatusPackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_MSTP_Log.csv");

    if (m_countM == false)
    {
        m_pathMotor = NewPathName.mid(0);  /*esegue la copia*/
        m_countM = true;
    }

    QFile file(m_pathMotor);
    QTextStream out(&file);

    if (file.size() < lenMotor)
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

        m_countM = false;
    }
}
/*!
    \fn void Storage::storeDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)

    It sets the second part for the log file's path name (_RL_Log.csv) and
    according to RadioLinkPackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_RL_Log.csv");

    if (m_countR == false)
    {
        m_pathRadioLink = NewPathName.mid(0);  /*esegue la copia*/
        m_countR = true;
    }

    QFile file(m_pathRadioLink);
    QTextStream out(&file);

    if (file.size() < lenRadioLink)
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

        m_countR = false;
    }
}
/*!
    \fn void Storage::storeDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)

    It sets the second part for the log file's path name (_STR_Log.csv) and
    according to StorageStatusPack's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_STR_Log.csv");

    if (m_countST == false)
    {
        m_pathStorageStatus = NewPathName.mid(0);  /*esegue la copia*/
        m_countST = true;
    }

    QFile file(m_pathStorageStatus);
    QTextStream out(&file);

    if (file.size() < lenStorageStatus)
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

        m_countST = false;
    }
}
/*!
    \fn void Storage::storeDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)

    It sets the second part for the log file's path name (_GUID_Log.csv) and
    according to GuidancePackDataset's struct it fills the file with mavlink data.
    When there is the fix of the GPS the System Time must be aligned to the GPS Time.
*/
void Storage::storeDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status)
{
    QString NewPathName = calculatePathName();
    unsigned long milliseconds_since_epoch;

    milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (GPS.FixGPSTime == true)
    {
        milliseconds_since_epoch -= GPS.DeltaGPSTimefromSystemTime;
    }

    NewPathName.append("_GUID_Log.csv");

    if (m_countG == false)
    {
        m_pathGuidance = NewPathName.mid(0);  /*esegue la copia*/
        m_countG = true;
    }

    QFile file(m_pathGuidance);
    QTextStream out(&file);

    if (file.size() < lenGuidance)
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
        m_countG = false;
    }
}

