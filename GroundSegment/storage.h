#ifndef STORAGE_H
#define STORAGE_H
#include <QObject>
#include <QTextStream>
#include <QFileInfo>
#include "mavlinkprotocol.h"

class Storage : public QObject
{
    Q_OBJECT

public:
    explicit Storage(QObject *parent = nullptr);
    ~Storage();
    QString CalculatePathName(void);
    QString CalculateSystemTime(void);
    bool CountT = 0;
    bool CountS = 0;
    QString PathSystemStatus, PathTelemetry;

public slots:
    void StoreDataInMemory(Telemetry *t);
    void StoreDataInMemorySystemStatus(SystemStatusPack *s);

};

#endif // STORAGE_H
