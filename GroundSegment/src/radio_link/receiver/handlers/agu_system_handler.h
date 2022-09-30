#ifndef AGU_SYSTEM_HANDLER_H
#define AGU_SYSTEM_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace domain
{
    class AGUSystemHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUSystemHandler(MavLinkCommunicator* communicator);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif // AGU_SYSTEM_HANDLER_H
