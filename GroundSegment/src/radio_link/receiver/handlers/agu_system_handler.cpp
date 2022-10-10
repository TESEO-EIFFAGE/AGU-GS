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


    std::cout << "Core_Module_Status_Mask " << system_status.Core_Module_Status_Mask << std::endl;
    std::cout << "Flight_Mode " << system_status.Flight_Mode << std::endl;
    std::cout << "Flight_Phase " << system_status.Flight_Phase << std::endl;
    std::cout << "Flight_Phase_Time " << system_status.Flight_Phase_Time << std::endl;
    std::cout << "Guidance_Module_Status_Mask " << system_status.Guidance_Module_Status_Mask << std::endl;
    std::cout << "Log_Timestamp " << system_status.Log_Timestamp << std::endl;
    std::cout << "Motor_Control_Module_Status_Mask " << system_status.Motor_Control_Module_Status_Mask << std::endl;
    std::cout << "Radio_Link_Module_Status_Mask " << system_status.Radio_Link_Module_Status_Mask << std::endl;
    std::cout << "Storage_Module_Status_Mask " << system_status.Storage_Module_Status_Mask << std::endl;
    std::cout << "Telemetry_Module_Status_Mask " << system_status.Telemetry_Module_Status_Mask << std::endl;

    QVariant processedMessage;
    processedMessage.setValue(system_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
