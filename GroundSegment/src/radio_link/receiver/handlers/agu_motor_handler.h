#ifndef AGU_MOTOR_HANDLER_H
#define AGU_MOTOR_HANDLER_H

#include "../../common/handlers/abstract_handler.h"

namespace radiolink
{
    class AGUMotorHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUMotorHandler(MavLinkCommunicator* communicator);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif // AGU_MOTOR_HANDLER_H
