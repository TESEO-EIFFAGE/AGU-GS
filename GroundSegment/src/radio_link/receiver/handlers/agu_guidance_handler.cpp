#include "agu_guidance_handler.h"


// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_guidance_status_pack_t);

AGUGuidanceHandler::AGUGuidanceHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUGuidanceHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_GUIDANCE_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_guidance_status_pack_t status;
    mavlink_msg_guidance_status_pack_decode(&message, &status);

    std::cout << "System_Timestamp " << status.System_Timestamp << std::endl;
    std::cout << "Guidance_Module_Status_Mask " << status.Guidance_Module_Status_Mask << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
