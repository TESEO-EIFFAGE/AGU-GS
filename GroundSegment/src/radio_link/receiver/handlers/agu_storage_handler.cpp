#include "agu_storage_handler.h"


// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_storage_status_pack_t);

AGUStorageHandler::AGUStorageHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUStorageHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_STORAGE_STATUS_PACK ||
        message.sysid == 0) return;

    mavlink_storage_status_pack_t status;
    mavlink_msg_storage_status_pack_decode(&message, &status);

//    std::cout << "System_Timestamp " << status.System_Timestamp << std::endl;
//    std::cout << "Storage_Free_Data_Size " << status.Storage_Free_Data_Size << std::endl;
//    std::cout << "Storage_Module_Status_Mask " << status.Storage_Module_Status_Mask << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
