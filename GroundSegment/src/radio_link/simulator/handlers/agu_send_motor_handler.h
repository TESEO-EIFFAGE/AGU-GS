#ifndef AGU_SEND_MOTOR_HANDLER_H
#define AGU_SEND_MOTOR_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendMotorHandler: public AbstractHandler
    {
    public:
        AGUSendMotorHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;
    };
}

#endif
