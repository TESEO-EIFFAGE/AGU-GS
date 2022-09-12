#include "gs_core.h"
#include "storage.h"
#include "hmi.h"
#include <QTimer>
#include <QObject>

GSCore::GSCore(QObject *parent)
    : QObject(parent)
{       
    Counter = 0;
    Serial1 = new QSerialPort(this);
    MavlinkProtocol *Mavlink = new MavlinkProtocol(this);
    Storage *StorageData = new Storage(this);
    setHmi(new HMI(this));
    setGpsData(new GPSData(this));

    StorageData->LenSystemStatus  = SetInitParameter("LenSystemStatus");
    StorageData->LenStorageStatus = SetInitParameter("LenStorageStatus");
    StorageData->LenGuidance      = SetInitParameter("LenGuidance");
    StorageData->LenMotor         = SetInitParameter("LenMotor");
    StorageData->LenRadioLink     = SetInitParameter("LenRadioLink");
    StorageData->LenTelemetry     = SetInitParameter("LenTelemetry");

    //Serial1 PORTA CHE RICEVE
    Serial1->setPortName("/dev/ttyUSB1");
    Serial1->setParity(QSerialPort::NoParity);
    Serial1->setDataBits(QSerialPort::Data8);
    Serial1->setBaudRate(QSerialPort::Baud57600);
    Serial1->setStopBits(QSerialPort::OneStop);
    Serial1->setFlowControl(QSerialPort::NoFlowControl);
    Serial1->open(QIODevice::ReadWrite);

    m_hmi->showData();

    GSCore::connect(Serial1, SIGNAL(readyRead()), this, SLOT(ReadData()));                                   /*segnale emesso dalla porta seriale*/
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseDataTelemetry(QByteArray)));          /*segnale emesso da MainWindow::ReadData()*/
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseDataSystemStatus(QByteArray)));       /*segnale emesso da MainWindow::ReadData()*/
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseMotorStatusPack(QByteArray)));    /*segnale emesso da MainWindow::ReadData()*/
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseRadioLink(QByteArray)));    /*segnale emesso da MainWindow::ReadData()*/
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseStorageStatusPack(QByteArray)));
    GSCore::connect(this, SIGNAL(DataIsRead(QByteArray)), Mavlink, SLOT(parseGuidance(QByteArray)));
    GSCore::connect(Mavlink, SIGNAL(toStorage(Telemetry *)), StorageData, SLOT(StoreDataInMemory(Telemetry *)));
    GSCore::connect(Mavlink, SIGNAL(toStorageSystemStatus(SystemStatusPack *)), StorageData, SLOT(StoreDataInMemorySystemStatus(SystemStatusPack *)));
    GSCore::connect(Mavlink, SIGNAL(toStorageMotorStatusPack(MotorStatusPackDataset *)), StorageData, SLOT(StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *)));
    GSCore::connect(Mavlink, SIGNAL(toStorageRadioLink(RadioLinkPackDataset *)), StorageData, SLOT(StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *)));
    GSCore::connect(Mavlink, SIGNAL(toStorageStorageStatusPack(StorageStatusPack *)), StorageData, SLOT(StoreDataInMemoryStorageStatusPack(StorageStatusPack *)));
    GSCore::connect(Mavlink, SIGNAL(toStorageGuidance(GuidancePackDataset *)), StorageData, SLOT(StoreDataInMemoryGuidance(GuidancePackDataset *)));

    GSCore::connect(Mavlink, SIGNAL(toHMI(Telemetry *)), m_hmi, SLOT(showData(Telemetry *)));
    GSCore::connect(Mavlink, SIGNAL(toHMISystemStatus(SystemStatusPack *)), m_hmi, SLOT(showDataSystemStatus(SystemStatusPack *)));
    //HMIController::connect(this, SIGNAL(updateTopDiagLog()), TopDialogWindow, SLOT(UpdateWindow()));  /* Spostare l'UpdateWindow signal dal pushbutton*/

    QTimer *timer = new QTimer(this);
    GSCore::connect(timer, &QTimer::timeout, this, [this](){ emit work_is_down(); });
    GSCore::connect(this, SIGNAL(work_is_down()), this, SLOT(WriteHartBeat()));
    timer->start(1000);

    QTimer *timerHasFix = new QTimer(this);
    GSCore::connect(timer, &QTimer::timeout, this, [StorageData, this](){SetFixOfTime(StorageData);});
    timerHasFix->start(1000);
}


void GSCore::SetFixOfTime(Storage *s)
{
    if (m_gpsData->hasFix() == true)
    {
       QDate d,j;
       unsigned long milliseconds_since_epoch;

       s->GPS.FixGPSTime = true;

       d = j.currentDate();
       int y = d.year();
       int mm = d.month();
       int day = d.day();
       QDate date(y, mm, day);
       QTime time(m_gpsData->hour(), m_gpsData->minute(), m_gpsData->second());
       QDateTime localTime = QDateTime(date, time, Qt::UTC);
       milliseconds_since_epoch = localTime.toUTC().toMSecsSinceEpoch();


       if (FlagDeltaTime == false)
       {
           s->GPS.DeltaGPSTimefromSystemTime =   std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()
                                               - milliseconds_since_epoch;

           qInfo () << " --------- DELTA = " << s->GPS.DeltaGPSTimefromSystemTime;

           FlagDeltaTime = true;
       }

    }
    else
    {
       s->GPS.FixGPSTime = false;
       FlagDeltaTime = false;
    }

    qInfo() << "------ sono in  SetFixOfTime "  ;

}

int GSCore::SetInitParameter(QString str)
{
     QSettings settings ("/home/AGU/QtSoftware/Agu/GroundSegment/myInit.ini", QSettings::IniFormat);
     QStringList childKeys = settings.childKeys();
     foreach (const QString &childKey, childKeys)
     {
         //qInfo() << "----- VALUE ------- " << settings.value(childKey).toInt();  /*estraggo il valore numerico*/
         //qInfo() << QVariant(childKey).toString();  /*estraggo nome del parametro*/
         if (str.compare(QVariant(childKey).toString()) != 0) return settings.value(childKey).toInt();
     }
}

GSCore::~GSCore()
{
}

HMI *GSCore::hmi()
{
    return m_hmi;
}

void GSCore::setHmi(HMI* hmi)
{
    m_hmi = hmi;
}

GPSData *GSCore::gpsData()
{
    return m_gpsData;
}

void GSCore::setGpsData(GPSData* gpsData)
{
    m_gpsData = gpsData;
}

void GSCore::WriteHartBeat()
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


void GSCore::ReadData()
{
    QByteArray  retData;
    //qInfo() << "RX Message sono in ReadData inizio ";

    retData = Serial1->readAll();
    retData = retData.toHex(0);
    qInfo() << "RX MESSAGE retData" << "\n" << retData;
    if (retData != nullptr)
    {
        emit DataIsRead (retData);
        //qInfo() << "RX Message sono in ReadData " << retData;

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


