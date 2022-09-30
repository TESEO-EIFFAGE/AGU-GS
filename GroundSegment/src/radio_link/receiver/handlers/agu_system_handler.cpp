#include "agu_system_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"

using namespace radiolink;


Q_DECLARE_METATYPE(mavlink_system_status_pack_t);

AGUSystemHandler::AGUSystemHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUSystemHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_SYSTEM_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_system_status_pack_t system_status;
    mavlink_msg_system_status_pack_decode(&message, &system_status);

    std::cout << "SYS " << system_status.Log_Timestamp << std::endl;
    QVariant processedMessage;
    processedMessage.setValue(system_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
