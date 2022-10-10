#include "agu_send_guidance_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDateTime>
#include <bitset>
#include <iostream>
#include <sstream>

// Internal
#include "uav_model.h"
#include "../common/mavlink_communicator.h"

using namespace radiolink;

AGUSendGuidanceHandler::AGUSendGuidanceHandler(MavLinkCommunicator* communicator,
                                           UavModel* model):
    AbstractHandler(communicator),
    m_model(model)
{
    this->startTimer(150);
}



uint32_t AGUSendGuidanceHandler::generateGuidanceMask()
{
    auto handler = "GUIDANCE";
    std::bitset<32> statusMask;
    typedef std::size_t length_t, position_t;

    for (position_t i=0; i < length_t(32); ++i) {
        bool randBool = m_communicator->randomBool();
        statusMask.set(i, randBool);
    }

    auto statusInt = statusMask.to_ulong();
    std::cout << handler << " STATUS MASK BIN " << statusMask << std::endl;
    std::cout << handler << " STATUS MASK INT " <<statusInt << std::endl;
    std::stringstream hexMask;
    hexMask << std::hex << std::uppercase << statusInt;
    std::cout << handler << " STATUS MASK HEX " << hexMask.str() << std::endl;
    return statusInt;
}




void AGUSendGuidanceHandler::processMessage(const mavlink_message_t& message)
{
    Q_UNUSED(message)
}

void AGUSendGuidanceHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_guidance_status_pack_t status;

    status.Guidance_Module_Status_Mask=this->generateGuidanceMask();
    status.System_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    mavlink_msg_guidance_status_pack_encode(m_communicator->systemId(),
                                          m_communicator->componentId(),
                                          &message, &status);

    m_communicator->sendMessageOnLastReceivedLink(message);
}
