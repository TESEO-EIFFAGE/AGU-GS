#ifndef STORAGE_H
#define STORAGE_H
#include <QObject>
#include <QTextStream>
#include <QFileInfo>
#include "mavlinkprotocol.h"
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

public slots:
    void StoreDataInMemory(Telemetry *t);
    void StoreDataInMemorySystemStatus(SystemStatusPack *s);
    void StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *m);
    void StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *r);
    void StoreDataInMemoryStorageStatusPack(StorageStatusPack *st);
    void StoreDataInMemoryGuidance(GuidancePackDataset *g);
    void InitFixGPSTime(void);
};

#endif // STORAGE_H
