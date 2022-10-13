#ifndef STORAGE_H
#define STORAGE_H
#include <QObject>
#include <QTextStream>
#include <QFileInfo>
#include "mavlinkprotocol.h"
#include <AGU_MAVLINK/mavlink.h>
#include <bitset>
#include "QQmlAutoPropertyHelpers.h"
#include <gnss.h>

typedef struct
{
    bool FixGPSTime;
    int  DeltaGPSTimefromSystemTime;
}GPSTimePack;
Q_DECLARE_METATYPE(GPSTimePack);

class Storage : public QObject
{
    Q_OBJECT

public:
    explicit Storage(QObject *parent = nullptr);
    ~Storage();
    QString CalculatePathName(void);
    bool CountT = 0;
    bool CountS = 0;
    bool CountM = 0;
    bool CountR = 0;
    bool CountST = 0;
    bool CountG = 0;
    int LenSystemStatus, LenTelemetry, LenMotor, LenRadioLink, LenStorageStatus, LenGuidance;
    QString PathSystemStatus, PathTelemetry, PathMotor, PathRadioLink, PathStorageStatus, PathGuidance;
    GPSTimePack GPS;
    void TurnOnFixOfTime();
    void SetDeltaTime(int deltaTime);
    void storeData(QVariant data);

public slots:
    void StoreDataInMemory(Telemetry *t);
    void StoreDataInMemorySystemStatus(SystemStatusPack *s);
    void StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *m);
    void StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *r);
    void StoreDataInMemoryStorageStatusPack(StorageStatusPack *st);
    void StoreDataInMemoryGuidance(GuidancePackDataset *g);
    void InitFixGPSTime(void);

private:
    void storeDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry);
    void storeDataSystemStatus(const mavlink_system_status_pack_t msg_system_status);
    void storeDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status);
    void storeDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status);
    void storeDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status);
    void storeDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status);

};

#endif // STORAGE_H
