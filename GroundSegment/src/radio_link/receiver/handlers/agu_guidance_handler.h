#ifndef AGU_GUIDANCE_HANDLER_H
#define AGU_GUIDANCE_HANDLER_H


#include "../../common/handlers/abstract_handler.h"
#include <AGU_MAVLINK/mavlink.h>
namespace radiolink
{
    class AGUGuidanceHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGUGuidanceHandler(MavLinkCommunicator* communicator);
    signals:
        void dispatchMessage(mavlink_guidance_status_pack_t);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}


#endif // AGU_GUIDANCE_HANDLER_H
