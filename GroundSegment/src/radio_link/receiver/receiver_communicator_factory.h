#ifndef GCS_COMMUNICATOR_FACTORY_H
#define GCS_COMMUNICATOR_FACTORY_H

#include "../common/abstract_communicator_factory.h"

namespace radiolink
{
    class ReceiverCommunicatorFactory: public AbstractCommunicatorFactory
    {
    public:
        ReceiverCommunicatorFactory();

        MavLinkCommunicator* create() override;
    };
}

#endif // GCS_COMMUNICATOR_FACTORY_H
