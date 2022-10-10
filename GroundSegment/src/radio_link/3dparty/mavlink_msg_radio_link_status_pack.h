#pragma once
// MESSAGE RADIO_LINK_STATUS_PACK PACKING

#define MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK 13004


typedef struct __mavlink_radio_link_status_pack_t {
 uint64_t System_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC.*/
 uint32_t Radio_Link_Module_Status_Mask; /*<  Radio Link Module Status Mask*/
 int16_t RSSI; /*< [dB] RSSI*/
} mavlink_radio_link_status_pack_t;

#define MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN 14
#define MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN 14
#define MAVLINK_MSG_ID_13004_LEN 14
#define MAVLINK_MSG_ID_13004_MIN_LEN 14

#define MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC 169
#define MAVLINK_MSG_ID_13004_CRC 169



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIO_LINK_STATUS_PACK { \
    13004, \
    "RADIO_LINK_STATUS_PACK", \
    3, \
    {  { "System_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_radio_link_status_pack_t, System_Timestamp) }, \
         { "RSSI", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_radio_link_status_pack_t, RSSI) }, \
         { "Radio_Link_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_radio_link_status_pack_t, Radio_Link_Module_Status_Mask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIO_LINK_STATUS_PACK { \
    "RADIO_LINK_STATUS_PACK", \
    3, \
    {  { "System_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_radio_link_status_pack_t, System_Timestamp) }, \
         { "RSSI", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_radio_link_status_pack_t, RSSI) }, \
         { "Radio_Link_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_radio_link_status_pack_t, Radio_Link_Module_Status_Mask) }, \
         } \
}
#endif

/**
 * @brief Pack a radio_link_status_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param RSSI [dB] RSSI
 * @param Radio_Link_Module_Status_Mask  Radio Link Module Status Mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_link_status_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t System_Timestamp, int16_t RSSI, uint32_t Radio_Link_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Radio_Link_Module_Status_Mask);
    _mav_put_int16_t(buf, 12, RSSI);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN);
#else
    mavlink_radio_link_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.RSSI = RSSI;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
}

/**
 * @brief Pack a radio_link_status_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param RSSI [dB] RSSI
 * @param Radio_Link_Module_Status_Mask  Radio Link Module Status Mask
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_link_status_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t System_Timestamp,int16_t RSSI,uint32_t Radio_Link_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Radio_Link_Module_Status_Mask);
    _mav_put_int16_t(buf, 12, RSSI);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN);
#else
    mavlink_radio_link_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.RSSI = RSSI;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
}

/**
 * @brief Encode a radio_link_status_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radio_link_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_link_status_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radio_link_status_pack_t* radio_link_status_pack)
{
    return mavlink_msg_radio_link_status_pack_pack(system_id, component_id, msg, radio_link_status_pack->System_Timestamp, radio_link_status_pack->RSSI, radio_link_status_pack->Radio_Link_Module_Status_Mask);
}

/**
 * @brief Encode a radio_link_status_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radio_link_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_link_status_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radio_link_status_pack_t* radio_link_status_pack)
{
    return mavlink_msg_radio_link_status_pack_pack_chan(system_id, component_id, chan, msg, radio_link_status_pack->System_Timestamp, radio_link_status_pack->RSSI, radio_link_status_pack->Radio_Link_Module_Status_Mask);
}

/**
 * @brief Send a radio_link_status_pack message
 * @param chan MAVLink channel to send the message
 *
 * @param System_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param RSSI [dB] RSSI
 * @param Radio_Link_Module_Status_Mask  Radio Link Module Status Mask
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radio_link_status_pack_send(mavlink_channel_t chan, uint64_t System_Timestamp, int16_t RSSI, uint32_t Radio_Link_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Radio_Link_Module_Status_Mask);
    _mav_put_int16_t(buf, 12, RSSI);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK, buf, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
#else
    mavlink_radio_link_status_pack_t packet;
    packet.System_Timestamp = System_Timestamp;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.RSSI = RSSI;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK, (const char *)&packet, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
#endif
}

/**
 * @brief Send a radio_link_status_pack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radio_link_status_pack_send_struct(mavlink_channel_t chan, const mavlink_radio_link_status_pack_t* radio_link_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radio_link_status_pack_send(chan, radio_link_status_pack->System_Timestamp, radio_link_status_pack->RSSI, radio_link_status_pack->Radio_Link_Module_Status_Mask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK, (const char *)radio_link_status_pack, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radio_link_status_pack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t System_Timestamp, int16_t RSSI, uint32_t Radio_Link_Module_Status_Mask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, System_Timestamp);
    _mav_put_uint32_t(buf, 8, Radio_Link_Module_Status_Mask);
    _mav_put_int16_t(buf, 12, RSSI);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK, buf, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
#else
    mavlink_radio_link_status_pack_t *packet = (mavlink_radio_link_status_pack_t *)msgbuf;
    packet->System_Timestamp = System_Timestamp;
    packet->Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet->RSSI = RSSI;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK, (const char *)packet, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIO_LINK_STATUS_PACK UNPACKING


/**
 * @brief Get field System_Timestamp from radio_link_status_pack message
 *
 * @return [ms] Log timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_radio_link_status_pack_get_System_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field RSSI from radio_link_status_pack message
 *
 * @return [dB] RSSI
 */
static inline int16_t mavlink_msg_radio_link_status_pack_get_RSSI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field Radio_Link_Module_Status_Mask from radio_link_status_pack message
 *
 * @return  Radio Link Module Status Mask
 */
static inline uint32_t mavlink_msg_radio_link_status_pack_get_Radio_Link_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a radio_link_status_pack message into a struct
 *
 * @param msg The message to decode
 * @param radio_link_status_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_radio_link_status_pack_decode(const mavlink_message_t* msg, mavlink_radio_link_status_pack_t* radio_link_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radio_link_status_pack->System_Timestamp = mavlink_msg_radio_link_status_pack_get_System_Timestamp(msg);
    radio_link_status_pack->Radio_Link_Module_Status_Mask = mavlink_msg_radio_link_status_pack_get_Radio_Link_Module_Status_Mask(msg);
    radio_link_status_pack->RSSI = mavlink_msg_radio_link_status_pack_get_RSSI(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN? msg->len : MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN;
        memset(radio_link_status_pack, 0, MAVLINK_MSG_ID_RADIO_LINK_STATUS_PACK_LEN);
    memcpy(radio_link_status_pack, _MAV_PAYLOAD(msg), len);
#endif
}
