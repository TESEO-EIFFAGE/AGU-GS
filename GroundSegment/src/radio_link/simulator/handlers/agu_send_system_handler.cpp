#include "agu_send_system_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDebug>
#include "QtCore/qdatetime.h"
#include <random>

// Internal
#include "uav_model.h"
#include "../common/mavlink_communicator.h"

using namespace radiolink;

AGUSendSystemHandler::AGUSendSystemHandler(MavLinkCommunicator* communicator,
                                                 UavModel* model):
    AbstractHandler(communicator),
    m_model(model)
{
    this->startTimer(150);
}

void AGUSendSystemHandler::processMessage(const mavlink_message_t& message)
{
    Q_UNUSED(message)
}

void AGUSendSystemHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_system_status_pack_t status;

    static int flightMode = std::rand();

    flightMode = flightMode > 1 ? flightMode - 1: 100;
    status.Flight_Mode = flightMode;
    status.Log_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    mavlink_msg_system_status_pack_encode(m_communicator->systemId(),
                                  m_communicator->componentId(),
                                  &message, &status);

    m_communicator->sendMessageOnLastReceivedLink(message);
}
