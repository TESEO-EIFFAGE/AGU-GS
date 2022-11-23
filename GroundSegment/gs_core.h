#ifndef GS_CORE
#define GS_CORE
#include <QObject>

class HMI;
class RadioLink;
class GNSS;
class Storage;

class GSCore : public QObject
{
    Q_OBJECT
public:
    GSCore(QObject *parent = nullptr);
    ~GSCore();

    HMI* hmi() const;
    void setHmi(HMI*);
    GNSS* gnss() const;
    void setGnss(GNSS*);
    void SetFixOfTime();
    int loadStorageFileSize(QString str);
    void setRadioLink(RadioLink* radioLink);
    RadioLink* radioLink() const;
    void setStorage(Storage*);
    Storage* storage() const;
    void setRLPort(const QString rl);
    void setGNSSPort(const QString gnss);

private:
    bool m_flagDeltaTime = false;
    Storage* m_storage;
    HMI* m_hmi;
    GNSS* m_gnss;
    RadioLink* m_radioLink;
};
#endif // GS_CORE
