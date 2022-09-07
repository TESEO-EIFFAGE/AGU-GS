#ifndef GS_CORE
#define GS_CORE
#include "hmi.h"
#include <GPSData.h>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "storage.h"

//class HMI;

class GSCore : public QObject
{
    Q_OBJECT

public:
    GSCore(QObject *parent = nullptr);
    ~GSCore();

    QSerialPort *Serial1;
    uint64_t TimeStampToHMI;
    qint8 Counter;
    HMI* hmi();
    void setHmi(HMI*);
    GPSData* gpsData();
    void setGpsData(GPSData*);
    void SetFixOfTime(Storage *s);

signals:
    void DataIsRead (QByteArray data);
    void work_is_down(void);
    //void updateTopDiagLog(void);

public slots:
    void ReadData(void);
    void WriteHartBeat();
private:
    HMI* m_hmi;
    GPSData* m_gpsData;

};
#endif // GS_CORE
