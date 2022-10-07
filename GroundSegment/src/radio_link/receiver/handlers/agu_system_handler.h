#ifndef AGU_SYSTEM_HANDLER_H
#define AGU_SYSTEM_HANDLER_H

#include "../../common/handlers/abstract_handler.h"

#include <AGU_MAVLINK/mavlink.h>

namespace radiolink
{
    class AGUSystemHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUSystemHandler(MavLinkCommunicator* communicator);
    signals:
        void dispatchMessage(mavlink_system_status_pack_t);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif // AGU_SYSTEM_HANDLER_H
