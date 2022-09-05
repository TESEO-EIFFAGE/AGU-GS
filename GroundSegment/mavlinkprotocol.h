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
    uint16_t  AngularRateRoll, AngularRatePitch, AngularRateYaw;
    float     Quaternion0, Quaternion1, Quaternion2, Quaternion3;
    uint64_t  TelemetryStatusMask;
    uint8_t   NumberOfGPSSatellite;
}Telemetry;
Q_DECLARE_METATYPE(Telemetry);

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
Q_DECLARE_METATYPE(SystemStatusPack);

typedef struct
{
   /*SYSTEM STATUS PACK DATASET*/
    uint64_t  TimeStamp;
    uint32_t  StorageFreeDataSize;
    uint32_t  StorageLinkStatusMask;
}StorageStatusPack;
Q_DECLARE_METATYPE(StorageStatusPack);

typedef struct
{
   /*MOTOR STATUS PACK*/

    uint64_t  TimeStamp;
    int32_t   MotorARealPosition;
    int32_t   MotorBRealPosition;
    int32_t   MotorADemandPosition;
    int32_t   MotorBDemandPosition;
    int32_t   MotorATorque;
    int32_t   MotorBTorque;
    int16_t   MotorATemperature;
    int16_t   MotorBTemperature;
    uint16_t  BMS1CurrentVoltage;
    int16_t   BMS1CurrentAbsorption;
    int16_t   BMS1CurrentTemperature;
    uint32_t  MotorControlStatusMask;
    uint32_t  MotorAFaultMask;
    uint32_t  MotorBFaultMask;
    uint32_t  BMSFaultMask;
}MotorStatusPackDataset;
Q_DECLARE_METATYPE(MotorStatusPackDataset);

typedef struct
{
   /*RadioLink STATUS PACK*/

    uint64_t  TimeStamp;
    int32_t   RSSI;
    int32_t   RadioLinkStatusMask;

}RadioLinkPackDataset;
Q_DECLARE_METATYPE(RadioLinkPackDataset);

typedef struct
{
   /*Guidance*/

    uint64_t  TimeStamp;
    int32_t   GuidanceStatusMask;

}GuidancePackDataset;
Q_DECLARE_METATYPE(GuidancePackDataset);


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
    MotorStatusPackDataset m;
    RadioLinkPackDataset r;
    StorageStatusPack st;
    GuidancePackDataset g;

public slots:
    void parseDataTelemetry(QByteArray data);
    void parseDataSystemStatus(QByteArray data);
    void parseMotorStatusPack(QByteArray data);
    void parseRadioLink(QByteArray data);
    void parseStorageStatusPack(QByteArray data);
    void parseGuidance(QByteArray data);

signals:
    void toStorage(Telemetry *);
    void toStorageSystemStatus(SystemStatusPack *);
    void toStorageMotorStatusPack(MotorStatusPackDataset *);
    void toStorageRadioLink(RadioLinkPackDataset *);
    void toStorageStorageStatusPack(StorageStatusPack *);
    void toStorageGuidance(GuidancePackDataset *);
    void toHMI(Telemetry *);
    void toHMISystemStatus(SystemStatusPack *);
    void toHMIMotorStatusPack(MotorStatusPackDataset *);
    void toHMIRadioLink(RadioLinkPackDataset *);
    void toHMIStorageStatusPack(StorageStatusPack *);
    void toHMIGuidance(GuidancePackDataset *);
};

#endif // MAVLINKPROTOCOL_H
