#include "agu_telemetry_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <iostream>
#include <QVariant>

#include "../../common/mavlink_communicator.h"
using namespace radiolink;

Q_DECLARE_METATYPE(mavlink_telemetry_data_pack_t);

AGUTelemetryHandler::AGUTelemetryHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AGUTelemetryHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_TELEMETRY_DATA_PACK ||
        message.sysid == 0) return;

    mavlink_telemetry_data_pack_t telemetry_status;
    mavlink_msg_telemetry_data_pack_decode(&message, &telemetry_status);

    std::cout << "TEL " << telemetry_status.Log_Timestamp << std::endl;
    QVariant processedMessage;
    processedMessage.setValue(telemetry_status);
    m_communicator->dispatchReceivedMessage(processedMessage);
}
