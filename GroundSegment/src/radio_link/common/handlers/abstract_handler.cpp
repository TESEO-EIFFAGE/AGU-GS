#include "abstract_handler.h"

// Internal
#include "../common/mavlink_communicator.h"

using namespace domain;

AbstractHandler::AbstractHandler(MavLinkCommunicator* communicator):
    QObject(communicator),
    m_communicator(communicator)
{
    Q_ASSERT(communicator);
    connect(communicator, &MavLinkCommunicator::messageReceived,
            this, &AbstractHandler::processMessage);
}
