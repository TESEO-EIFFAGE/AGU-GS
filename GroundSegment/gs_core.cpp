#include "gs_core.h"
#include "storage.h"
#include "hmi.h"
#include <gnss.h>
#include <radio_link.h>
#include <mavlink_communicator.h>
#include <QTimer>
#include <QObject>

GSCore::GSCore(QObject *parent)
    : QObject(parent)
{       
    Counter = 0;
    Serial1 = new QSerialPort(this);
    MavlinkProtocol *Mavlink = new MavlinkProtocol(this);
    Storage *StorageData = new Storage(this);
    setRadioLink(new RadioLink(this));
    setHmi(new HMI(this));
    setGpsData(new GNSS(this));

    StorageData->LenSystemStatus  = SetInitParameter("LenSystemStatus");
    StorageData->LenStorageStatus = SetInitParameter("LenStorageStatus");
    StorageData->LenGuidance      = SetInitParameter("LenGuidance");
    StorageData->LenMotor         = SetInitParameter("LenMotor");
    StorageData->LenRadioLink     = SetInitParameter("LenRadioLink");
    StorageData->LenTelemetry     = SetInitParameter("LenTelemetry");

    QObject::connect(m_radioLink->communicator(),&radiolink::MavLinkCommunicator::dispatchReceivedMessage,
                     m_hmi, &HMI::showData);
    //    QObject::connect(Mavlink, SIGNAL(toStorage(Telemetry *)), StorageData, SLOT(StoreDataInMemory(Telemetry *)));
    QObject::connect(Mavlink, SIGNAL(toStorageSystemStatus(SystemStatusPack *)), StorageData, SLOT(StoreDataInMemorySystemStatus(SystemStatusPack *)));
    QObject::connect(Mavlink, SIGNAL(toStorageMotorStatusPack(MotorStatusPackDataset *)), StorageData, SLOT(StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *)));
    QObject::connect(Mavlink, SIGNAL(toStorageRadioLink(RadioLinkPackDataset *)), StorageData, SLOT(StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *)));
    QObject::connect(Mavlink, SIGNAL(toStorageStorageStatusPack(StorageStatusPack *)), StorageData, SLOT(StoreDataInMemoryStorageStatusPack(StorageStatusPack *)));
    QObject::connect(Mavlink, SIGNAL(toStorageGuidance(GuidancePackDataset *)), StorageData, SLOT(StoreDataInMemoryGuidance(GuidancePackDataset *)));

    QTimer *timer = new QTimer(this);
    //QObject::connect(timer, &QTimer::timeout, this, [this](){ emit work_is_down(); });
    //QObject::connect(this, SIGNAL(work_is_down()), this, SLOT(WriteHartBeat()));
    //timer->start(1000);

    QTimer *timerHasFix = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, [StorageData, this](){SetFixOfTime(StorageData);});
    //timerHasFix->start(1000);
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
    int defaultValue = 50000;
    QSettings settings ("/home/AGU/QtSoftware/Agu/GroundSegment/myInit.ini", QSettings::IniFormat);
    QStringList childKeys = settings.childKeys();
    foreach (const QString &childKey, childKeys)
    {
        qInfo() << str;
        qInfo() << "----- VALUE ------- " << settings.value(childKey).toInt();  /*estraggo il valore numerico*/
        qInfo() << QVariant(childKey).toString();  /*estraggo nome del parametro*/
        if (str.compare(QVariant(childKey).toString()) == 0) return settings.value(childKey).toInt();
    }

    return defaultValue;
}

void GSCore::setRadioLink(RadioLink *radioLink)
{
    m_radioLink = radioLink;
}

RadioLink *GSCore::radioLink() const
{
    return m_radioLink;
}

GSCore::~GSCore()
{
}

HMI *GSCore::hmi() const
{
    return m_hmi;
}

void GSCore::setHmi(HMI* hmi)
{
    m_hmi = hmi;
}

GNSS *GSCore::gpsData() const
{
    return m_gpsData;
}

void GSCore::setGpsData(GNSS* gpsData)
{
    m_gpsData = gpsData;
}

