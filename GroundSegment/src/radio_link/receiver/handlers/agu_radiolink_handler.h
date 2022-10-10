#ifndef AGU_RADIOLINK_HANDLER_H
#define AGU_RADIOLINK_HANDLER_H

#include "../../common/handlers/abstract_handler.h"
#include <AGU_MAVLINK/mavlink.h>
namespace radiolink
{
    class AGURadioLinkHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        AGURadioLinkHandler(MavLinkCommunicator* communicator);
    signals:
        void dispatchMessage(mavlink_radio_link_status_pack_t);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}

#endif
