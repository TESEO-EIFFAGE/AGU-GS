#ifndef GS_CORE
#define GS_CORE

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class HMI;

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

signals:
    void DataIsRead (QByteArray data);
    void work_is_down(void);
    //void updateTopDiagLog(void);

public slots:
    void ReadData(void);
    void WriteHartBeat();
private:
    HMI* m_hmi;

};
#endif // GS_CORE
