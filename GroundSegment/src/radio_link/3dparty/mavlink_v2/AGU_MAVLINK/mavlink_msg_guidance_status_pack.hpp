// MESSAGE GUIDANCE_STATUS_PACK support class

#pragma once

namespace mavlink {
namespace AGU_MAVLINK {
namespace msg {

/**
 * @brief GUIDANCE_STATUS_PACK message
 *
 * Guidance module status message.
 */
struct GUIDANCE_STATUS_PACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13005;
    static constexpr size_t LENGTH = 12;
    static constexpr size_t MIN_LENGTH = 12;
    static constexpr uint8_t CRC_EXTRA = 86;
    static constexpr auto NAME = "GUIDANCE_STATUS_PACK";


    uint64_t System_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC. */
    uint32_t Guidance_Module_Status_Mask; /*<  Guidance Module Status Mask */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  System_Timestamp: " << System_Timestamp << std::endl;
        ss << "  Guidance_Module_Status_Mask: " << Guidance_Module_Status_Mask << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << System_Timestamp;              // offset: 0
        map << Guidance_Module_Status_Mask;   // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> System_Timestamp;              // offset: 0
        map >> Guidance_Module_Status_Mask;   // offset: 8
    }
};

} // namespace msg
} // namespace AGU_MAVLINK
} // namespace mavlink
