#include <QDate>
#include <QTimer>
#include <gnss.h>
#include "gps_driver/drotek_f9p_rover.cpp"

/*!
        \class GNSS

        \brief The GNSS class defines the GNSS object and its lines of communication
*/
GNSS::GNSS(QObject *parent) :
    QObject(parent)
{
    m_latitude = 0.0;
    m_longitude = 0.0;
    m_altitude = 0.0;
    m_hasFix = false;
    m_hour = 0;
    m_minute = 0;
    m_second = 0.0;


    if (m_deviceAddress == "") {
        setDeviceAddress("/dev/ttyACM0");
    }
    m_gnss = new PyHALDrotekF9P();

    if (m_gnss->init(m_deviceAddress.toStdString())) {
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &GNSS::updateData);
        m_timer->start(250);

        std::cout << m_gnss->get_gnss_name() << std::endl;
    } else {
        std::cout << "No GPS Found !" << std::endl;
        std::cout << "Please make sure that the application is running as root and that the GNSS device is properly plugged." << std::endl;
    }
}

GNSS::~GNSS()
{
    delete m_gnss;
}

/*!
    \fn void GNSS::UpdateData()

    Updates the GNSS object's position and time
*/
void GNSS::updateData() {
    double hasFix;

    double *gnss_info = new double[6];
    m_gnss->get_gnss_info(gnss_info);
    hasFix = m_gnss->has_fix();

    // We use the setters because they emit a signal
    // so that the UI gets refreshed
    setLongitude(gnss_info[0]);
    setLatitude(gnss_info[1]);
    setAltitude(gnss_info[2]);
    setHasFix(hasFix == 1);
    setSecond(m_gnss->getTimestamp().sec);
    setMinute(m_gnss->getTimestamp().min);
    setHour(m_gnss->getTimestamp().hour);

    delete [ ] gnss_info;
}

/*!
    \fn double GNSS::latitude() const

    Returns the latitude value
*/
double GNSS::latitude() const
{
    return m_latitude;
}
/*!
    \fn double GNSS::longitude() const

    Returns the longitude value
*/
double GNSS::longitude() const
{
    return m_longitude;
}
/*!
    \fn double GNSS::altitude() const

    Returns the altitude value
*/
double GNSS::altitude() const
{
    return m_altitude;
}
/*!
    \fn bool GNSS::hasFix() const

    Returns the hasFix value
*/
bool GNSS::hasFix() const
{
    return m_hasFix;
}
/*!
    \fn int GNSS::hour() const

    Returns the hour value
*/
int GNSS::hour() const
{
    return m_hour;
}
/*!
    \fn int GNSS::minute() const

    Returns the minute value
*/
int GNSS::minute() const
{
    return m_minute;
}
/*!
    \fn double GNSS::second() const

    Returns the second value
*/
double GNSS::second() const
{
    return m_second;
}

/*!
    \fn void GNSS::setLatitude(const double latitude)

    Sets a new value to latitude
*/
void GNSS::setLatitude(const double latitude)
{
    if (latitude == m_latitude)
        return;

    m_latitude = latitude;
    emit latitudeChanged();
}
/*!
    \fn void GNSS::setLongitude(const double longitude)

    sets a new value to longitude
*/
void GNSS::setLongitude(const double longitude)
{
    if (longitude == m_longitude)
        return;

    m_longitude = longitude;
    emit longitudeChanged();
}
/*!
    \fn void GNSS::setAltitude(const double altitude)

    sets a new value to altitude
*/
void GNSS::setAltitude(const double altitude)
{
    if (altitude == m_altitude)
        return;

    m_altitude = altitude;
    emit altitudeChanged();
}
/*!
    \fn void GNSS::setHasFix(const bool hasFix)

    sets a new value to hasFix
*/
void GNSS::setHasFix(const bool hasFix)
{
    if (hasFix == m_hasFix)
        return;

    m_hasFix = hasFix;
    emit hasFixChanged();
}
/*!
    \fn void GNSS::setHour(const int hour)

    sets a new value to hour
*/
void GNSS::setHour(const int hour)
{
    if (hour == m_hour)
        return;

    m_hour = hour;
    emit hourChanged();
}
/*!
    \fn void GNSS::setMinute(const int minute)

    sets a new value to minute
*/
void GNSS::setMinute(const int minute)
{
    if (minute == m_minute)
        return;

    m_minute = minute;
    emit minuteChanged();
}
/*!
    \fn void GNSS::setSecond(const double second)

    sets a new value to second
*/
void GNSS::setSecond(const double second)
{
    if (second == m_second)
        return;

    m_second = second;
    emit secondChanged();
}
/*!
    \fn void GNSS::setDeviceAddress(const QString &d)

    sets the GNSS serial device address
*/
void GNSS::setDeviceAddress(const QString &d)
{
    m_deviceAddress=d;
    //std::cout << m_port.toStdString() << std::endl;
}
