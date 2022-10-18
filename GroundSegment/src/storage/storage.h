#ifndef STORAGE_H
#define STORAGE_H
#include <QObject>
#include <QTextStream>
#include <QFileInfo>
#include <AGU_MAVLINK/mavlink.h>
#include <bitset>
#include <gnss.h>

typedef struct
{
    bool FixGPSTime;
    int  DeltaGPSTimefromSystemTime;
}GPSTimePack;
Q_DECLARE_METATYPE(GPSTimePack);

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = nullptr);
    ~Storage();
    void initFixGPSTime(void);
    void turnOnFixOfTime();
    void setDeltaTime(int deltaTime);
    void storeData(QVariant data);
    int lenSystemStatus;
    int lenTelemetry;
    int lenMotor;
    int lenRadioLink;
    int lenStorageStatus;
    int lenGuidance;
private:
    void storeDataTelemetry(const mavlink_telemetry_data_pack_t msg_telemetry);
    void storeDataSystemStatus(const mavlink_system_status_pack_t msg_system_status);
    void storeDataMotorStatus(const mavlink_motor_status_pack_t msg_motor_status);
    void storeDataRLStatus(const mavlink_radio_link_status_pack_t msg_radio_status);
    void storeDataStorageStatus(const mavlink_storage_status_pack_t msg_storage_status);
    void storeDataGuidanceStatus(const mavlink_guidance_status_pack_t msg_guidance_status);
    QString calculatePathName(void);
    bool m_countT{};
    bool m_countS{};
    bool m_countM{};
    bool m_countR{};
    bool m_countST{};
    bool m_countG{};
    QString m_pathSystemStatus;
    QString m_pathTelemetry;
    QString m_pathMotor;
    QString m_pathRadioLink;
    QString m_pathStorageStatus;
    QString m_pathGuidance;
    GPSTimePack GPS;

};

#endif // STORAGE_H
