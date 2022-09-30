#ifndef AGU_SEND_SYSTEM_HANDLER_H
#define AGU_SEND_SYSTEM_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendSystemHandler: public AbstractHandler
    {
    public:
        AGUSendSystemHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;
    };
}

#endif // AGU_SEND_SYSTEM_HANDLER_H
