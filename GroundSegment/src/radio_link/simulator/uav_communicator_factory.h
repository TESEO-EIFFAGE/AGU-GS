#ifndef UAV_COMMUNICATOR_FACTORY_H
#define UAV_COMMUNICATOR_FACTORY_H

#include "../common/abstract_communicator_factory.h"

namespace radiolink
{
    class UavModel;

    class UavCommunicatorFactory: public AbstractCommunicatorFactory
    {
    public:
        UavCommunicatorFactory(radiolink::UavModel* model);

        MavLinkCommunicator* create() override;

    private:
        radiolink::UavModel* m_model;
    };
}

#endif // UAV_COMMUNICATOR_FACTORY_H
