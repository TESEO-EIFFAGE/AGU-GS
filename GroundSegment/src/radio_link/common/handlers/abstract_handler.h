#ifndef ABSTRACT_HANDLER_H
#define ABSTRACT_HANDLER_H

// MAVLink
#include "../../3dparty/mavlink_v2/mavlink_types.h"

// Qt
#include <QObject>

namespace radiolink
{
    class MavLinkCommunicator;

    class AbstractHandler: public QObject
    {
        Q_OBJECT

    public:
        explicit AbstractHandler(MavLinkCommunicator* communicator);

    protected slots:
        virtual void processMessage(const mavlink_message_t& message) = 0;

    protected:
        MavLinkCommunicator* const m_communicator;
    };
}

#endif // ABSTRACT_HANDLER_H
