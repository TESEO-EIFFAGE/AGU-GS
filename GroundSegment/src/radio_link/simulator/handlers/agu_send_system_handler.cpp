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

    int flightPhase = (rand() % 10) + 1;
    int flightPhaseTime = (rand() % 1000) + 1;
    int guidanceMask = (rand() % 1000) + 1;
    int motorMask = (rand() % 1000) + 1;
    int radioMask = (rand() % 1000) + 1;
    int storageMask = (rand() % 1000) + 1;
    int telemetryMask = (rand() % 1000) + 1;
    int coreMask = (rand() % 1000) + 1;

    status.Telemetry_Module_Status_Mask=telemetryMask;
    status.Guidance_Module_Status_Mask=guidanceMask;
    status.Motor_Control_Module_Status_Mask=motorMask;
    status.Radio_Link_Module_Status_Mask=radioMask;
    status.Storage_Module_Status_Mask=storageMask;
    status.Core_Module_Status_Mask=coreMask;
    status.Flight_Mode = flightMode;
    status.Flight_Phase = flightPhase;
    status.Flight_Phase_Time = flightPhaseTime;
    status.Log_Timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

    mavlink_msg_system_status_pack_encode(m_communicator->systemId(),
                                  m_communicator->componentId(),
                                  &message, &status);

    m_communicator->sendMessageOnLastReceivedLink(message);
}
