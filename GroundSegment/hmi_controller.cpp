#include "hmi_controller.h"
#include "storage.h"
#include "hmi.h"
#include <QTimer>
#include <QObject>


HMIController::HMIController(QObject *parent)
    : QObject(parent)
{       
    Counter = 0;
    Serial1 = new QSerialPort(this);
    MavlinkProtocol *Mavlink = new MavlinkProtocol(this);
    Storage *StorageData = new Storage(this);
    HMI *Interface = new HMI(this);


    //Serial1 PORTA CHE RICEVE
    Serial1->setPortName("/dev/ttyUSB1");
    Serial1->setParity(QSerialPort::NoParity);
    Serial1->setDataBits(QSerialPort::Data8);
    Serial1->setBaudRate(QSerialPort::Baud115200);
    Serial1->setStopBits(QSerialPort::OneStop);
    Serial1->setFlowControl(QSerialPort::NoFlowControl);
    Serial1->open(QIODevice::ReadWrite);

    HMIController::connect(Serial1, SIGNAL(readyRead()), this, SLOT(ReadData()));                                   /*segnale emesso dalla porta seriale*/
    HMIController::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseDataTelemetry(QByteArray)));             /*segnale emesso da MainWindow::ReadData()*/
    HMIController::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseDataSystemStatus(QByteArray)));             /*segnale emesso da MainWindow::ReadData()*/
    HMIController::connect(Mavlink, SIGNAL(toStorage(Telemetry *)), StorageData, SLOT(StoreDataInMemory(Telemetry *)));
    HMIController::connect(Mavlink, SIGNAL(toStorageSystemStatus(SystemStatusPack *)), StorageData, SLOT(StoreDataInMemorySystemStatus(SystemStatusPack *)));
    HMIController::connect(Mavlink, SIGNAL(toHMI(Telemetry *)), Interface, SLOT(showData(Telemetry *)));
    HMIController::connect(Mavlink, SIGNAL(toHMISystemStatus(SystemStatusPack *)), Interface, SLOT(showDataSystemStatus(SystemStatusPack *)));
    //HMIController::connect(this, SIGNAL(updateTopDiagLog()), TopDialogWindow, SLOT(UpdateWindow()));  /* Spostare l'UpdateWindow signal dal pushbutton*/

    QTimer *timer = new QTimer(this);
    HMIController::connect(timer, &QTimer::timeout, this, [this](){ emit work_is_down(); });
    HMIController::connect(this, SIGNAL(work_is_down()), this, SLOT(WriteHartBeat()));
    timer->start(1000);
}

HMIController::~HMIController()
{
}

void HMIController::WriteHartBeat()
{
    QByteArray HeartBeatMessage;
  //  qInfo() << "RX Message sono in WriteHartBeat inizio " << data;

  // if (Serial1->isWritable())

    HeartBeatMessage.append("FD");
    HeartBeatMessage.append("01");
    HeartBeatMessage.append("00");
    HeartBeatMessage.append("00");

    if (Counter <= 15)
    {
        HeartBeatMessage.append("0");
        HeartBeatMessage.append(QByteArray::number(Counter,16).toUpper());
    }
    else
    {
        HeartBeatMessage.append(QByteArray::number(Counter,16).toUpper());
    }
    Counter ++;
    qInfo() << Counter;
    HeartBeatMessage.append("01");
    HeartBeatMessage.append("01");
    HeartBeatMessage.append("010101");
    HeartBeatMessage.append("01");

    quint16 CHeckSum = qChecksum(HeartBeatMessage, HeartBeatMessage.size(), Qt::ChecksumIso3309);
    QByteArray q = QByteArray::number(CHeckSum,16).toUpper();

    if (q.size() == 3)
    {
        HeartBeatMessage.append("0");
        HeartBeatMessage.append(q);
    }
    else if (q.size() == 2)
    {
        HeartBeatMessage.append("00");
        HeartBeatMessage.append(q);
    }
    else
    {
        HeartBeatMessage.append(q);
    }
        //QByteArray hexvalue = q.toHex();


    qInfo() << "***************** HeartBeatMessage   = " << HeartBeatMessage;

    Serial1->write(HeartBeatMessage);
}


void HMIController::ReadData()
{
    QByteArray  retData;
    qInfo() << "RX Message sono in ReadData inizio ";

    retData = Serial1->readAll();
    qInfo() << retData;
    if (retData != nullptr)
    {
        emit DataIsRead (retData);
        qInfo() << "RX Message sono in ReadData " << retData;

        /*
         if ( (retData.sliced(0,2)) == "FD")
         {
            qInfo() << retData.length() << " ";
            qInfo() << "RX Message sono in ReadData " << retData;
            emit DataIsRead (retData);
            qInfo() << "Emesso retData" << retData;
         }
         else
         {
             /*verifica se è l'hartbeat e rispedisci*/
             //Serial1->write(retData);*/
      /*   }*/
    }
}


