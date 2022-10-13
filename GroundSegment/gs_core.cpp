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
               It instantiates application modules and their communication.
*/
GSCore::GSCore(QObject *parent)
    : QObject(parent)
{       
    setRadioLink(new RadioLink(this));
    setHmi(new HMI(this));
    setGnss(new GNSS(this));
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
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this,&GSCore::SetFixOfTime);
}

/*!
    \fn void GSCore::SetFixOfTime(Storage *s)

    Calculates the delta between System Time and GPS Time.
    The value DeltaGPSTimefromSystemTime is stored in the Storage class.
*/
void GSCore::SetFixOfTime()
{
    if (m_gnss->hasFix())
    {
        QDate d,j;
        unsigned long milliseconds_since_epoch;

        m_storage->TurnOnFixOfTime();

        d = j.currentDate();
        int y = d.year();
        int mm = d.month();
        int day = d.day();
        QDate date(y, mm, day);
        QTime time(m_gnss->hour(), m_gnss->minute(), m_gnss->second());
        QDateTime localTime = QDateTime(date, time, Qt::UTC);
        milliseconds_since_epoch = localTime.toUTC().toMSecsSinceEpoch();

        if (m_flagDeltaTime == false)
        {
            int deltaTime=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()
                    - milliseconds_since_epoch;
            m_storage->SetDeltaTime(deltaTime);

            m_flagDeltaTime = true;
        }

    }
    else
    {
        m_storage->InitFixGPSTime();
        m_flagDeltaTime = false;
    }

    qInfo() << "------ sono in  SetFixOfTime "  ;

}

/*!
    \fn int GSCore::SetInitParameter(QString str)

    Extracts from the .ini configuration file the initialization length of the file.
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

    Sets the radioLink module.
*/
void GSCore::setRadioLink(RadioLink *radioLink)
{
    m_radioLink = radioLink;
}
/*!
    \fn RadioLink *GSCore::radioLink() const

    Returns the radioLink module.
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

    Returns the hmi module.
*/
HMI *GSCore::hmi() const
{
    return m_hmi;
}

/*!
    \fn void GSCore::setHmi(HMI* hmi)

    Sets the hmi module.
*/
void GSCore::setHmi(HMI* hmi)
{
    m_hmi = hmi;
}

/*!
    \fn void GSCore::setStorage(Storage* storage)

    Sets the storage module.
*/
void GSCore::setStorage(Storage* storage)
{
    m_storage = storage;
}

Storage *GSCore::storage() const
{
    return m_storage;
}

/*!
    \fn GNSS *GSCore::gnss() const

    Returns the GNSS module.
*/
GNSS *GSCore::gnss() const
{
    return m_gnss;
}

/*!
    \fn void GSCore::setGnss(GNSS* gnss)

    Sets the GNSS module.
*/
void GSCore::setGnss(GNSS* gnss)
{
    m_gnss = gnss;
}

