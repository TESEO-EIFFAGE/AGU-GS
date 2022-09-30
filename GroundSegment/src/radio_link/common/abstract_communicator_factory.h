#ifndef ABSTRACT_COMMUNICATOR_FACTORY_H
#define ABSTRACT_COMMUNICATOR_FACTORY_H

namespace radiolink
{
    class MavLinkCommunicator;

    class AbstractCommunicatorFactory
    {
    public:
        AbstractCommunicatorFactory();
        virtual ~AbstractCommunicatorFactory();

        virtual MavLinkCommunicator* create() = 0;
    };
}

#endif // ABSTRACT_COMMUNICATOR_FACTORY_H
