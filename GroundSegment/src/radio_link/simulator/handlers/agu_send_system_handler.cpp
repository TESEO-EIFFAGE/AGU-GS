#include "agu_send_system_handler.h"

// MAVLink
#include <AGU_MAVLINK/mavlink.h>

// Qt
#include <QDebug>
#include<QBitArray>
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
    //int telemetryMask = (rand() % 1000) + 1;
    int coreMask = (rand() % 1000) + 1;

    QBitArray telemetryba(32);
    for(int i=0;i++;i<32){
        telemetryba.setBit(i,false);
    }
    //int telemetryMask = telemetryba
    QByteArray telemetrybytes;
    telemetrybytes.resize(telemetryba.count()/8+1);
    telemetrybytes.fill(0);
    for(int b=0; b<telemetryba.count(); ++b)
        telemetrybytes[b/8] = ( telemetrybytes.at(b/8) | ((telemetryba[b]?1:0)<<(b%8)));

    bool telemetryconvcheck;
    status.Telemetry_Module_Status_Mask=telemetrybytes.toInt(&telemetryconvcheck);

    printf("Conversion Telemetry %d", telemetryconvcheck);


    QBitArray motorba(32);
    for(int i=0;i++;i<32){
        motorba.setBit(i,false);
    }
    QByteArray motorbytes;
    motorbytes.resize(motorba.count()/8+1);
    motorbytes.fill(0);
    for(int b=0; b<motorba.count(); ++b)
        motorbytes[b/8] = ( motorbytes.at(b/8) | ((motorba[b]?1:0)<<(b%8)));

    bool motorconvcheck;
    status.Motor_Control_Module_Status_Mask=motorbytes.toInt(&motorconvcheck);
    printf("Conversion Motor %d", motorconvcheck);


    QBitArray radioba(32);
    for(int i=0;i++;i<32){
        radioba.setBit(i,false);
    }
    QByteArray radiobytes;
    radiobytes.resize(radioba.count()/8+1);
    radiobytes.fill(0);
    for(int b=0; b<radioba.count(); ++b)
        radiobytes[b/8] = ( radiobytes.at(b/8) | ((radioba[b]?1:0)<<(b%8)));

    bool radioconvcheck;
    status.Radio_Link_Module_Status_Mask=radiobytes.toInt(&radioconvcheck);
    printf("Conversion Radio %d", radioconvcheck);


    QBitArray storageba(32);
    for(int i=0;i++;i<32){
        storageba.setBit(i,false);
    }
    QByteArray storagebytes;
    storagebytes.resize(storageba.count()/8+1);
    storagebytes.fill(0);
    for(int b=0; b<storageba.count(); ++b)
        storagebytes[b/8] = ( storagebytes.at(b/8) | ((storageba[b]?1:0)<<(b%8)));

    bool storageconvcheck;
    status.Storage_Module_Status_Mask=storagebytes.toInt(&storageconvcheck);
    printf("Conversion Storage %d", radioconvcheck);


    status.Guidance_Module_Status_Mask=guidanceMask;
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
