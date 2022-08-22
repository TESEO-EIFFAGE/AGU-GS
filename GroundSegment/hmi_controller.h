#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class HMIController : public QObject
{
    Q_OBJECT

public:
    HMIController(QWidget *parent = nullptr);
    ~HMIController();

    QSerialPort *Serial1;
    uint64_t TimeStampToHMI;
    qint8 Counter;

signals:
    void DataIsRead (QByteArray data);
    void work_is_down(void);
    void updateTopDiagLog(void);

public slots:
    void ReadData(void);
    void WriteHartBeat();

};
#endif // HMICONTROLLER_H
