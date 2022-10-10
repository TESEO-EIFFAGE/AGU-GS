#ifndef AGU_SEND_RADIOLINK_HANDLER_H
#define AGU_SEND_RADIOLINK_HANDLER_H



#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendRadioLinkHandler: public AbstractHandler
    {
    public:
        AGUSendRadioLinkHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;

        uint32_t generateRLMask();

    };
}

#endif // AGU_SEND_RADIOLINK_HANDLER_H
