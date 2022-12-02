#ifndef GNSS_H
#define GNSS_H

#include <QTimer>
#include <QObject>
#include <QString>
#include <QtQml>

class PyHALDrotekF9P;

class GNSS : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(double altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged)
    Q_PROPERTY(bool hasFix READ hasFix WRITE setHasFix NOTIFY hasFixChanged)
    Q_PROPERTY(int hour READ hour WRITE setHour NOTIFY hourChanged)
    Q_PROPERTY(int minute READ minute WRITE setMinute NOTIFY minuteChanged)
    Q_PROPERTY(double second READ second WRITE setSecond NOTIFY secondChanged)

public:
    explicit GNSS(QObject *parent = nullptr);
    ~GNSS();


    double latitude() const;
    double longitude() const;
    double altitude() const;
    bool hasFix() const;
    int hour() const;
    int minute() const;
    double second() const;

    void setLatitude(const double latitude);
    void setLongitude(const double longitude);
    void setAltitude(const double altitude);
    void setHasFix(const bool status);
    void setHour(const int hour);
    void setMinute(const int minute);
    void setSecond(const double sec);
    void setDeviceAddress(const QString& d);

signals:
    void latitudeChanged();
    void longitudeChanged();
    void altitudeChanged();
    void hasFixChanged();
    void hourChanged();
    void minuteChanged();
    void secondChanged();

public slots:
    void updateData();

private:
    double m_latitude;
    double m_longitude;
    double m_altitude;
    bool m_hasFix;
    double m_hour;
    double m_minute;
    double m_second;
    QTimer* m_timer;
    PyHALDrotekF9P* m_gnss;
    QString m_deviceAddress;
};

#endif // GNSS_H
