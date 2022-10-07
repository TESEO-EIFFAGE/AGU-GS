#ifndef SEND_GPS_RAW_HANDLER_H
#define SEND_GPS_RAW_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class SendGpsRawHandler: public AbstractHandler
    {
    public:
        SendGpsRawHandler(MavLinkCommunicator* communicator,
                          UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent *event) override;

    private:
        UavModel* m_model;
    };
}

#endif // SEND_GPS_RAW_HANDLER_H
