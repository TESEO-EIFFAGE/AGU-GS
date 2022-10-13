#include "gs_core.h"
#include "storage.h"
#include "hmi.h"
#include <gnss.h>
#include <radio_link.h>
#include <mavlink_communicator.h>
#include <QTimer>
#include <QObject>

/*!
        \class GSCore

        \brief The GSCore class is the logic core of the project.
               It defines the objects and their lines of communication.
*/
GSCore::GSCore(QObject *parent)
    : QObject(parent)
{       
    Counter = 0;
    Serial1 = new QSerialPort(this);
    MavlinkProtocol *Mavlink = new MavlinkProtocol(this);
    //Storage *StorageData = new Storage(this);

    setRadioLink(new RadioLink(this));
    setHmi(new HMI(this));
    setGpsData(new GNSS(this));
    setStorage(new Storage(this));

    m_storage->LenSystemStatus  = SetInitParameter("LenSystemStatus");
    m_storage->LenStorageStatus = SetInitParameter("LenStorageStatus");
    m_storage->LenGuidance      = SetInitParameter("LenGuidance");
    m_storage->LenMotor         = SetInitParameter("LenMotor");
    m_storage->LenRadioLink     = SetInitParameter("LenRadioLink");
    m_storage->LenTelemetry     = SetInitParameter("LenTelemetry");

    QObject::connect(m_radioLink->communicator(),&radiolink::MavLinkCommunicator::dispatchReceivedMessage,
                     m_hmi, &HMI::showData);
    QObject::connect(m_radioLink->communicator(),&radiolink::MavLinkCommunicator::dispatchReceivedMessage,
                     m_storage, &Storage::storeData);
    //    QObject::connect(Mavlink, SIGNAL(toStorage(Telemetry *)), StorageData, SLOT(StoreDataInMemory(Telemetry *)));
//    QObject::connect(Mavlink, SIGNAL(toStorageSystemStatus(SystemStatusPack *)), StorageData, SLOT(StoreDataInMemorySystemStatus(SystemStatusPack *)));
//    QObject::connect(Mavlink, SIGNAL(toStorageMotorStatusPack(MotorStatusPackDataset *)), StorageData, SLOT(StoreDataInMemoryMotorStatusPack(MotorStatusPackDataset *)));
//    QObject::connect(Mavlink, SIGNAL(toStorageRadioLink(RadioLinkPackDataset *)), StorageData, SLOT(StoreDataInMemoryRadioLinkStatusPack(RadioLinkPackDataset *)));
//    QObject::connect(Mavlink, SIGNAL(toStorageStorageStatusPack(StorageStatusPack *)), StorageData, SLOT(StoreDataInMemoryStorageStatusPack(StorageStatusPack *)));
//    QObject::connect(Mavlink, SIGNAL(toStorageGuidance(GuidancePackDataset *)), StorageData, SLOT(StoreDataInMemoryGuidance(GuidancePackDataset *)));

    QTimer *timer = new QTimer(this);
    //QObject::connect(timer, &QTimer::timeout, this, [this](){ emit work_is_down(); });
    //QObject::connect(this, SIGNAL(work_is_down()), this, SLOT(WriteHartBeat()));
    //timer->start(1000);

    QTimer *timerHasFix = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this,&GSCore::SetFixOfTime);
    //timerHasFix->start(1000);
}

/*!
    \fn void GSCore::SetFixOfTime(Storage *s)

    It calculates the delta between System Time and GPS Time.
    The value DeltaGPSTimefromSystemTime is stored in the Storage class.
*/
void GSCore::SetFixOfTime()
{
    if (m_gpsData->hasFix() == true)
    {
        QDate d,j;
        unsigned long milliseconds_since_epoch;

        m_storage->TurnOnFixOfTime();

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
            int deltaTime=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()
                    - milliseconds_since_epoch;
            m_storage->SetDeltaTime(deltaTime);

            FlagDeltaTime = true;
        }

    }
    else
    {
        m_storage->InitFixGPSTime();
        FlagDeltaTime = false;
    }

    qInfo() << "------ sono in  SetFixOfTime "  ;

}

/*!
    \fn int GSCore::SetInitParameter(QString str)

    It extracts from the .ini configuration file the initialization length of the file.
    For each file this returns the length.
*/
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

/*!
    \fn void GSCore::setRadioLink(RadioLink *radioLink)

    It sets the radioLink object.
*/
void GSCore::setRadioLink(RadioLink *radioLink)
{
    m_radioLink = radioLink;
}
/*!
    \fn RadioLink *GSCore::radioLink() const

    It returns the radioLink object.
*/
RadioLink *GSCore::radioLink() const
{
    return m_radioLink;
}

GSCore::~GSCore()
{
}

/*!
    \fn HMI *GSCore::hmi() const

    It returns the hmi object.
*/
HMI *GSCore::hmi() const
{
    return m_hmi;
}

/*!
    \fn void GSCore::setHmi(HMI* hmi)

    It sets the hmi object.
*/
void GSCore::setHmi(HMI* hmi)
{
    m_hmi = hmi;
}

/*!
    \fn void GSCore::setStorage(Storage* storage)

    It sets the storage object.
*/
void GSCore::setStorage(Storage* storage)
{
    m_storage = storage;
}

/*!
    \fn GNSS *GSCore::gpsData() const

    It returns the gpsData object.
*/
GNSS *GSCore::gpsData() const
{
    return m_gpsData;
}

/*!
    \fn void GSCore::setGpsData(GNSS* gpsData)

    It sets the gpsData object.
*/
void GSCore::setGpsData(GNSS* gpsData)
{
    m_gpsData = gpsData;
}

