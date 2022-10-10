#pragma once
// MESSAGE STORAGE_STATUS_PACK PACKING

#define MAVLINK_MSG_ID_STORAGE_STATUS_PACK 13003


typedef struct __mavlink_storage_status_pack_t {
 uint64_t System_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC.*/
 uint32_t Storage_Free_Data_Size; /*<  Storage Free Data Size*/
 uint32_t Storage_Module_Status_Mask; /*<  Storage Module Status Mask*/
} mavlink_storage_status_pack_t;

#define MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN 16
#define MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN 16
#define MAVLINK_MSG_ID_13003_LEN 16
#define MAVLINK_MSG_ID_13003_MIN_LEN 16

#define MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC 178
#define MAVLINK_MSG_ID_13003_CRC 178



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STORAGE_STATUS_PACK { \
    13003, \
    "STORAGE_STATUS_PACK", \
    3, \
    {  { "System_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_storage_status_pack_t, System_Timestamp) }, \
         { "Storage_Free_Data_Size", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_storage_status_pack_t, Storage_Free_Data_Size) }, \
         { "Storage_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_storage_status_pack_t, Storage_Module_Status_Mask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STORAGE_STATUS_PACK { \
    "STORAGE_STATUS_PACK", \
    3, \
    {  { "System_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_storage_status_pack_t, System_Timestamp) }, \
         { "Storage_Free_Data_Size", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_storage_status_pack_t, Storage_Free_Data_Size) }, \
         { "Storage_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_storage_status_pack_t, Storage_Module_Status_Mask) }, \
         } \
}
#endif

/**
 * @brief Pack a storage_status_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Storage_Free_Data_Size  Storage Free Data Size
 * @param Storage_Module_Status_Mask  Storage Module Status Mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_storage_status_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t System_Timestamp, uint32_t Storage_Free_Data_Size, uint32_t Storage_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Storage_Free_Data_Size);
    _mav_put_uint32_t(buf, 12, Storage_Module_Status_Mask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN);
#else
    mavlink_storage_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Storage_Free_Data_Size = Storage_Free_Data_Size;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STORAGE_STATUS_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
}

/**
 * @brief Pack a storage_status_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Storage_Free_Data_Size  Storage Free Data Size
 * @param Storage_Module_Status_Mask  Storage Module Status Mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_storage_status_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t System_Timestamp,uint32_t Storage_Free_Data_Size,uint32_t Storage_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Storage_Free_Data_Size);
    _mav_put_uint32_t(buf, 12, Storage_Module_Status_Mask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN);
#else
    mavlink_storage_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Storage_Free_Data_Size = Storage_Free_Data_Size;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STORAGE_STATUS_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
}

/**
 * @brief Encode a storage_status_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param storage_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_storage_status_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_storage_status_pack_t* storage_status_pack)
{
    return mavlink_msg_storage_status_pack_pack(system_id, component_id, msg, storage_status_pack->System_Timestamp, storage_status_pack->Storage_Free_Data_Size, storage_status_pack->Storage_Module_Status_Mask);
}

/**
 * @brief Encode a storage_status_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param storage_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_storage_status_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_storage_status_pack_t* storage_status_pack)
{
    return mavlink_msg_storage_status_pack_pack_chan(system_id, component_id, chan, msg, storage_status_pack->System_Timestamp, storage_status_pack->Storage_Free_Data_Size, storage_status_pack->Storage_Module_Status_Mask);
}

/**
 * @brief Send a storage_status_pack message
 * @param chan MAVLink channel to send the message
 *
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Storage_Free_Data_Size  Storage Free Data Size
 * @param Storage_Module_Status_Mask  Storage Module Status Mask
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_storage_status_pack_send(mavlink_channel_t chan, uint64_t System_Timestamp, uint32_t Storage_Free_Data_Size, uint32_t Storage_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Storage_Free_Data_Size);
    _mav_put_uint32_t(buf, 12, Storage_Module_Status_Mask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK, buf, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
#else
    mavlink_storage_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Storage_Free_Data_Size = Storage_Free_Data_Size;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK, (const char *)&packet, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
#endif
}

/**
 * @brief Send a storage_status_pack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_storage_status_pack_send_struct(mavlink_channel_t chan, const mavlink_storage_status_pack_t* storage_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_storage_status_pack_send(chan, storage_status_pack->System_Timestamp, storage_status_pack->Storage_Free_Data_Size, storage_status_pack->Storage_Module_Status_Mask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK, (const char *)storage_status_pack, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_storage_status_pack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t System_Timestamp, uint32_t Storage_Free_Data_Size, uint32_t Storage_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Storage_Free_Data_Size);
    _mav_put_uint32_t(buf, 12, Storage_Module_Status_Mask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK, buf, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
#else
    mavlink_storage_status_pack_t *packet = (mavlink_storage_status_pack_t *)msgbuf;
    packet->System_Timestamp = System_Timestamp;
    packet->Storage_Free_Data_Size = Storage_Free_Data_Size;
    packet->Storage_Module_Status_Mask = Storage_Module_Status_Mask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STORAGE_STATUS_PACK, (const char *)packet, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_CRC);
#endif
}
#endif

#endif

// MESSAGE STORAGE_STATUS_PACK UNPACKING


/**
 * @brief Get field System_Timestamp from storage_status_pack message
 *
 * @return [ms] Log timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_storage_status_pack_get_System_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Storage_Free_Data_Size from storage_status_pack message
 *
 * @return  Storage Free Data Size
 */
static inline uint32_t mavlink_msg_storage_status_pack_get_Storage_Free_Data_Size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field Storage_Module_Status_Mask from storage_status_pack message
 *
 * @return  Storage Module Status Mask
 */
static inline uint32_t mavlink_msg_storage_status_pack_get_Storage_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a storage_status_pack message into a struct
 *
 * @param msg The message to decode
 * @param storage_status_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_storage_status_pack_decode(const mavlink_message_t* msg, mavlink_storage_status_pack_t* storage_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    storage_status_pack->System_Timestamp = mavlink_msg_storage_status_pack_get_System_Timestamp(msg);
    storage_status_pack->Storage_Free_Data_Size = mavlink_msg_storage_status_pack_get_Storage_Free_Data_Size(msg);
    storage_status_pack->Storage_Module_Status_Mask = mavlink_msg_storage_status_pack_get_Storage_Module_Status_Mask(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN? msg->len : MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN;
        memset(storage_status_pack, 0, MAVLINK_MSG_ID_STORAGE_STATUS_PACK_LEN);
    memcpy(storage_status_pack, _MAV_PAYLOAD(msg), len);
#endif
}
