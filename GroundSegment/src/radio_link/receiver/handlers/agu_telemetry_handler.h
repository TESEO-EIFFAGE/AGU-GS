#ifndef AGU_TELEMETRY_HANDLER_H
#define AGU_TELEMETRY_HANDLER_H

#include "../../common/handlers/abstract_handler.h"
#include <AGU_MAVLINK/mavlink.h>

namespace radiolink
{
    class AGUTelemetryHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUTelemetryHandler(MavLinkCommunicator* communicator);
    signals:
        void dispatchMessage(mavlink_telemetry_data_pack_t);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif // AGU_TELEMETRY_HANDLER_H
