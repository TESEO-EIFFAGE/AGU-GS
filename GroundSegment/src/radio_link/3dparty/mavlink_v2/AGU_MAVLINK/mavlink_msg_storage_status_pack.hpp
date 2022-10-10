// MESSAGE STORAGE_STATUS_PACK support class

#pragma once

namespace mavlink {
namespace AGU_MAVLINK {
namespace msg {

/**
 * @brief STORAGE_STATUS_PACK message
 *
 * Storage module status message.
 */
struct STORAGE_STATUS_PACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13003;
    static constexpr size_t LENGTH = 16;
    static constexpr size_t MIN_LENGTH = 16;
    static constexpr uint8_t CRC_EXTRA = 178;
    static constexpr auto NAME = "STORAGE_STATUS_PACK";


    uint64_t System_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC. */
    uint32_t Storage_Free_Data_Size; /*<  Storage Free Data Size */
    uint32_t Storage_Module_Status_Mask; /*<  Storage Module Status Mask */


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
        ss << "  Storage_Free_Data_Size: " << Storage_Free_Data_Size << std::endl;
        ss << "  Storage_Module_Status_Mask: " << Storage_Module_Status_Mask << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << System_Timestamp;              // offset: 0
        map << Storage_Free_Data_Size;        // offset: 8
        map << Storage_Module_Status_Mask;    // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> System_Timestamp;              // offset: 0
        map >> Storage_Free_Data_Size;        // offset: 8
        map >> Storage_Module_Status_Mask;    // offset: 12
    }
};

} // namespace msg
} // namespace AGU_MAVLINK
} // namespace mavlink
