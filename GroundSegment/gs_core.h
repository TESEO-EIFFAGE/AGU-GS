#ifndef GS_CORE
#define GS_CORE
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class HMI;
class RadioLink;
class GPSData;
class Storage;

class GSCore : public QObject
{
    Q_OBJECT

public:
    GSCore(QObject *parent = nullptr);
    ~GSCore();

    QSerialPort *Serial1;
    uint64_t TimeStampToHMI;
    qint8 Counter;
    bool FlagDeltaTime = false;
    HMI* hmi() const;
    void setHmi(HMI*);
    GPSData* gpsData() const;
    void setGpsData(GPSData*);
    void SetFixOfTime(Storage *s);
    int SetInitParameter(QString str);
    void setRadioLink(RadioLink* radioLink);
    RadioLink* radioLink() const;

signals:
    void DataIsRead (QByteArray data);
    void work_is_down(void);

private:
    HMI* m_hmi;
    GPSData* m_gpsData;
    RadioLink* m_radioLink;
};
#endif // GS_CORE
