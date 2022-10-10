#include "agu_radiolink_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_radio_link_status_pack_t);

AGURadioLinkHandler::AGURadioLinkHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGURadioLinkHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_radio_link_status_pack_t status;
    mavlink_msg_radio_link_status_pack_decode(&message, &status);

    std::cout << "System_Timestamp " << status.System_Timestamp << std::endl;
    std::cout << "RSSI " << status.RSSI << std::endl;
    std::cout << "Radio_Link_Module_Status_Mask " << status.Radio_Link_Module_Status_Mask << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
