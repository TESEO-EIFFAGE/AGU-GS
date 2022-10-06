#ifndef AGU_SEND_TELEMETRY_HANDLER_H
#define AGU_SEND_TELEMETRY_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendTelemetryHandler: public AbstractHandler
    {
    public:
        AGUSendTelemetryHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;
        uint64_t generateMask();
    };
}

#endif // AGU_SEND_TELEMETRY_HANDLER_H
