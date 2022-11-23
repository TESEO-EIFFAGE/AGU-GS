#ifndef RADIO_LINK_H
#define RADIO_LINK_H
#include <QObject>

namespace radiolink {
 class MavLinkCommunicator;
 class AbstractLink;
}

class RadioLink : public QObject {
    Q_OBJECT
public:
    explicit RadioLink(QObject *parent = nullptr);
    ~RadioLink();
    void start();
    void stop();
    radiolink::MavLinkCommunicator* communicator() const;
    void setPort(const QString p);
private:
    radiolink::MavLinkCommunicator* m_communicator{};
    radiolink::AbstractLink* m_link{};
    QString port;

};

#endif // RADIO_LINK_H
