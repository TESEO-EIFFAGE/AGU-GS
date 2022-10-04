#ifndef AGU_MOTOR_HANDLER_H
#define AGU_MOTOR_HANDLER_H

#include "../../common/handlers/abstract_handler.h"
#include <AGU_MAVLINK/mavlink.h>
namespace radiolink
{
    class AGUMotorHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUMotorHandler(MavLinkCommunicator* communicator);
    signals:
        void dispatchMessage(mavlink_motor_status_pack_t);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif // AGU_MOTOR_HANDLER_H
