#ifndef MAVLINK_COMMUNICATOR_H
#define MAVLINK_COMMUNICATOR_H

// MAVLink
#include "../3dparty/mavlink_v2/mavlink_types.h"

// Qt
#include <QObject>
#include <QMap>
#include <QVariant>

namespace radiolink
{
    class AbstractLink;

    class MavLinkCommunicator: public QObject
    {
        Q_OBJECT

    public:
        MavLinkCommunicator(uint8_t systemId = 0, uint8_t componentId = 0,
                            QObject* parent = nullptr);

        QList<AbstractLink*> links() const;

        uint8_t systemId() const;
        uint8_t componentId() const;

    public slots:
        void addLink(radiolink::AbstractLink* link, uint8_t channel);
        void removeLink(radiolink::AbstractLink* link);

        void setSystemId(uint8_t systemId);
        void setComponentId(uint8_t componentId);

        void sendMessage(mavlink_message_t& message, radiolink::AbstractLink* link);
        void sendMessageOnLastReceivedLink(mavlink_message_t& message);
        void sendMessageOnAllLinks(mavlink_message_t& message);

    signals:
        void messageReceived(const mavlink_message_t& message);
        void dispatchReceivedMessage(QVariant);

    protected slots:
        void onDataReceived(const QByteArray& data);

    protected:
        QMap<AbstractLink*, uint8_t> m_linkChannels;
        AbstractLink* m_lastReceivedLink;

        uint8_t m_systemId;
        uint8_t m_componentId;
    };
}

#endif // MAVLINK_COMMUNICATOR_H
