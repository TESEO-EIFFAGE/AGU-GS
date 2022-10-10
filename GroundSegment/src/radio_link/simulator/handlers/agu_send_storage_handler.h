#ifndef AGU_SEND_STORAGE_HANDLER_H
#define AGU_SEND_STORAGE_HANDLER_H


#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendStorageHandler: public AbstractHandler
    {
    public:
        AGUSendStorageHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;

        uint32_t generateStorageMask();

    };
}



#endif // AGU_SEND_STORAGE_HANDLER_H
