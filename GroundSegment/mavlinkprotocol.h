#ifndef MAVLINKPROTOCOL_H
#define MAVLINKPROTOCOL_H
#include <QObject>
#include <QVector>
#include <QTime>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>

typedef struct
{
   /*TELEMETRIA*/
    uint64_t  TimeStamp, TimeStampRIO;
    uint32_t  Latitude, Longitude;
    uint32_t  GNSSAltitude;
    uint16_t  AirSpeed_UVector, AirSpeed_VVector, AirSpeed_WVector;
    uint16_t  AirTemperature;
    uint32_t  AltitudeFromRadarAltimeter, AltitudeFromPayloadAltimeter;
    uint16_t  LinearVelocityHorizontal;
    uint16_t  LinearVelocityVertical;
    uint16_t  PositionAccuracy;
    uint16_t  SpeedAccuracy;
    uint16_t  LinearAccelerationX, LinearAccelerationY, LinearAccelerationZ;
    uint32_t  ECEFVectorPositionX, ECEFVectorPositionY, ECEFVectorPositionZ;
    uint32_t  ECEFVectorVelocityX, ECEFVectorVelocityY, ECEFVectorVelocityZ;
    uint16_t  RollAngle, PitchAngle, YawAngle;
    uint16_t  AgularRateRoll, AgularRatePitch, AgularRateYaw;
    float     Quaternion0, Quaternion1, Quaternion2, Quaternion3;
    uint64_t  TelemetryStatusMask;
    uint8_t   NumberOfGPSSatellite;
}Telemetry;
Q_DECLARE_METATYPE(Telemetry);  /*MESSAGGIO MAVLINK*/

enum class FlightMode
{
   EmergencyMode,
   RecoveryMode,
   ManualMode,
   OpenLoop,
   ClosedLoop
};

enum class FlightPhase
{
   Initialization,
   Trim,
   Guidance,
   Flare,
   Finalization
};

typedef struct
{
   /*SYSTEM STATUS PACK DATASET*/
    uint64_t  TimeStamp;
    uint32_t  CoreModuleStatusMask;
    uint64_t  TelemetryStatusMask;
    uint32_t  StorageModuleStatusMask;
    uint32_t  RadioLinkModuleStatusMask;
    uint32_t  MotorControlModuleStatusMask;
    uint32_t  GuidanceModuleStatusMask;
    FlightPhase fp;
    FlightMode  fm;
    uint32_t  FlyPhaseExecutionTime;
}SystemStatusPack;
Q_DECLARE_METATYPE(SystemStatusPack);  /*MESSAGGIO MAVLINK*/

class MavlinkProtocol : public QObject
{
    Q_OBJECT
public:
    explicit MavlinkProtocol(QObject *parent = nullptr);
    ~MavlinkProtocol();
    quint16 GetCRC(const QByteArray & data);
    void printDataInFile(void);

    QString STX, LEN, INC_FLAGS, CMP_FLAGS, SEQ, SYS_ID, COMP_ID, MSG_ID, PAYLOAD, CRC;
    QByteArray data;
    qint8 Counter;
    int Index = 0;
    Telemetry t;
    SystemStatusPack s;

public slots:
    void parseDataTelemetry(QByteArray data);
    void parseDataSystemStatus(QByteArray data);

signals:
    void toStorage(Telemetry *);
    void toStorageSystemStatus(SystemStatusPack *);
    void toHMI(Telemetry *);
    void toHMISystemStatus(SystemStatusPack *);

};

#endif // MAVLINKPROTOCOL_H
