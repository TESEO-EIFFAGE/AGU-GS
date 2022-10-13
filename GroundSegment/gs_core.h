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
    int SetInitParameter(QString str);
    void setRadioLink(RadioLink* radioLink);
    RadioLink* radioLink() const;
    void setStorage(Storage*);
    Storage* storage() const;

private:
    bool m_flagDeltaTime = false;
    Storage* m_storage;
    HMI* m_hmi;
    GNSS* m_gnss;
    RadioLink* m_radioLink;
};
#endif // GS_CORE
