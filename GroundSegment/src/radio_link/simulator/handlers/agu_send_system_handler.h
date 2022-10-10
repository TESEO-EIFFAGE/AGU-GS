#ifndef AGU_SEND_SYSTEM_HANDLER_H
#define AGU_SEND_SYSTEM_HANDLER_H

#include "../common/handlers/abstract_handler.h"

namespace radiolink
{
    class UavModel;

    class AGUSendSystemHandler: public AbstractHandler
    {
    public:
        AGUSendSystemHandler(MavLinkCommunicator* communicator,
                                UavModel* model);

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    protected:
        void timerEvent(QTimerEvent* event) override;

    private:
        UavModel* m_model;
        uint32_t generateCoreMask();
        uint64_t generateTelMask();
        uint32_t generateStorageMask();
        uint32_t generateRLMask();
        uint32_t generateMotorMask();
        uint32_t generateGuidanceMask();

        uint16_t generateEmergencyBoardMask();
        uint16_t generatePSUMask();
        uint8_t generateEmergencyRLMask();
    };
}

#endif // AGU_SEND_SYSTEM_HANDLER_H
