#pragma once
// MESSAGE SYSTEM_STATUS_PACK PACKING

#define MAVLINK_MSG_ID_SYSTEM_STATUS_PACK 13000


typedef struct __mavlink_system_status_pack_t {
 uint64_t Log_Timestamp; /*< [ms] Log timestamp since 1.1.1970 UTC.*/
 uint64_t Telemetry_Module_Status_Mask; /*<  Telemetry module status mask*/
 uint32_t Core_Module_Status_Mask; /*<  Core module status mask*/
 uint32_t Storage_Module_Status_Mask; /*<  Storage module status mask*/
 uint32_t Radio_Link_Module_Status_Mask; /*<  Radio link module status mask*/
 uint32_t Motor_Control_Module_Status_Mask; /*<  Motor control module status mask*/
 uint32_t Guidance_Module_Status_Mask; /*<  Guidance module status mask*/
 uint32_t Flight_Phase_Time; /*< [ms] Flight phase execution time*/
 uint16_t Emergency_Board_Status; /*<  Emergency Board Status*/
 uint16_t PSU_Status; /*<  PSU Status*/
 int16_t Channel_4_PWM; /*<  Channel 4 PWM*/
 int16_t Channel_5_PWM; /*<  Channel 5 PWM*/
 uint8_t Flight_Phase; /*<  Flight phase id*/
 uint8_t Flight_Mode; /*<  Flight mode id*/
 uint8_t Emergency_Radio_Link_Status; /*<  Emergency Radio Link Status*/
} mavlink_system_status_pack_t;

#define MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN 51
#define MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN 51
#define MAVLINK_MSG_ID_13000_LEN 51
#define MAVLINK_MSG_ID_13000_MIN_LEN 51

#define MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC 217
#define MAVLINK_MSG_ID_13000_CRC 217



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_STATUS_PACK { \
    13000, \
    "SYSTEM_STATUS_PACK", \
    15, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_status_pack_t, Log_Timestamp) }, \
         { "Core_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_system_status_pack_t, Core_Module_Status_Mask) }, \
         { "Telemetry_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_system_status_pack_t, Telemetry_Module_Status_Mask) }, \
         { "Storage_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_system_status_pack_t, Storage_Module_Status_Mask) }, \
         { "Radio_Link_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_system_status_pack_t, Radio_Link_Module_Status_Mask) }, \
         { "Motor_Control_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_system_status_pack_t, Motor_Control_Module_Status_Mask) }, \
         { "Guidance_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_system_status_pack_t, Guidance_Module_Status_Mask) }, \
         { "Flight_Phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_system_status_pack_t, Flight_Phase) }, \
         { "Flight_Mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_system_status_pack_t, Flight_Mode) }, \
         { "Flight_Phase_Time", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_system_status_pack_t, Flight_Phase_Time) }, \
         { "Emergency_Board_Status", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_system_status_pack_t, Emergency_Board_Status) }, \
         { "PSU_Status", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_system_status_pack_t, PSU_Status) }, \
         { "Emergency_Radio_Link_Status", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_system_status_pack_t, Emergency_Radio_Link_Status) }, \
         { "Channel_4_PWM", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_system_status_pack_t, Channel_4_PWM) }, \
         { "Channel_5_PWM", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_system_status_pack_t, Channel_5_PWM) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_STATUS_PACK { \
    "SYSTEM_STATUS_PACK", \
    15, \
    {  { "Log_Timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_status_pack_t, Log_Timestamp) }, \
         { "Core_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_system_status_pack_t, Core_Module_Status_Mask) }, \
         { "Telemetry_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_system_status_pack_t, Telemetry_Module_Status_Mask) }, \
         { "Storage_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_system_status_pack_t, Storage_Module_Status_Mask) }, \
         { "Radio_Link_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_system_status_pack_t, Radio_Link_Module_Status_Mask) }, \
         { "Motor_Control_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_system_status_pack_t, Motor_Control_Module_Status_Mask) }, \
         { "Guidance_Module_Status_Mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_system_status_pack_t, Guidance_Module_Status_Mask) }, \
         { "Flight_Phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_system_status_pack_t, Flight_Phase) }, \
         { "Flight_Mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_system_status_pack_t, Flight_Mode) }, \
         { "Flight_Phase_Time", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_system_status_pack_t, Flight_Phase_Time) }, \
         { "Emergency_Board_Status", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_system_status_pack_t, Emergency_Board_Status) }, \
         { "PSU_Status", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_system_status_pack_t, PSU_Status) }, \
         { "Emergency_Radio_Link_Status", NULL, MAVLINK_TYPE_UINT8_T, 0, 50, offsetof(mavlink_system_status_pack_t, Emergency_Radio_Link_Status) }, \
         { "Channel_4_PWM", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_system_status_pack_t, Channel_4_PWM) }, \
         { "Channel_5_PWM", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_system_status_pack_t, Channel_5_PWM) }, \
         } \
}
#endif

/**
 * @brief Pack a system_status_pack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Core_Module_Status_Mask  Core module status mask
 * @param Telemetry_Module_Status_Mask  Telemetry module status mask
 * @param Storage_Module_Status_Mask  Storage module status mask
 * @param Radio_Link_Module_Status_Mask  Radio link module status mask
 * @param Motor_Control_Module_Status_Mask  Motor control module status mask
 * @param Guidance_Module_Status_Mask  Guidance module status mask
 * @param Flight_Phase  Flight phase id
 * @param Flight_Mode  Flight mode id
 * @param Flight_Phase_Time [ms] Flight phase execution time
 * @param Emergency_Board_Status  Emergency Board Status
 * @param PSU_Status  PSU Status
 * @param Emergency_Radio_Link_Status  Emergency Radio Link Status
 * @param Channel_4_PWM  Channel 4 PWM
 * @param Channel_5_PWM  Channel 5 PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_status_pack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t Log_Timestamp, uint32_t Core_Module_Status_Mask, uint64_t Telemetry_Module_Status_Mask, uint32_t Storage_Module_Status_Mask, uint32_t Radio_Link_Module_Status_Mask, uint32_t Motor_Control_Module_Status_Mask, uint32_t Guidance_Module_Status_Mask, uint8_t Flight_Phase, uint8_t Flight_Mode, uint32_t Flight_Phase_Time, uint16_t Emergency_Board_Status, uint16_t PSU_Status, uint8_t Emergency_Radio_Link_Status, int16_t Channel_4_PWM, int16_t Channel_5_PWM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, Telemetry_Module_Status_Mask);
    _mav_put_uint32_t(buf, 16, Core_Module_Status_Mask);
    _mav_put_uint32_t(buf, 20, Storage_Module_Status_Mask);
    _mav_put_uint32_t(buf, 24, Radio_Link_Module_Status_Mask);
    _mav_put_uint32_t(buf, 28, Motor_Control_Module_Status_Mask);
    _mav_put_uint32_t(buf, 32, Guidance_Module_Status_Mask);
    _mav_put_uint32_t(buf, 36, Flight_Phase_Time);
    _mav_put_uint16_t(buf, 40, Emergency_Board_Status);
    _mav_put_uint16_t(buf, 42, PSU_Status);
    _mav_put_int16_t(buf, 44, Channel_4_PWM);
    _mav_put_int16_t(buf, 46, Channel_5_PWM);
    _mav_put_uint8_t(buf, 48, Flight_Phase);
    _mav_put_uint8_t(buf, 49, Flight_Mode);
    _mav_put_uint8_t(buf, 50, Emergency_Radio_Link_Status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN);
#else
    mavlink_system_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Telemetry_Module_Status_Mask = Telemetry_Module_Status_Mask;
    packet.Core_Module_Status_Mask = Core_Module_Status_Mask;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.Motor_Control_Module_Status_Mask = Motor_Control_Module_Status_Mask;
    packet.Guidance_Module_Status_Mask = Guidance_Module_Status_Mask;
    packet.Flight_Phase_Time = Flight_Phase_Time;
    packet.Emergency_Board_Status = Emergency_Board_Status;
    packet.PSU_Status = PSU_Status;
    packet.Channel_4_PWM = Channel_4_PWM;
    packet.Channel_5_PWM = Channel_5_PWM;
    packet.Flight_Phase = Flight_Phase;
    packet.Flight_Mode = Flight_Mode;
    packet.Emergency_Radio_Link_Status = Emergency_Radio_Link_Status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_STATUS_PACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
}

/**
 * @brief Pack a system_status_pack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Core_Module_Status_Mask  Core module status mask
 * @param Telemetry_Module_Status_Mask  Telemetry module status mask
 * @param Storage_Module_Status_Mask  Storage module status mask
 * @param Radio_Link_Module_Status_Mask  Radio link module status mask
 * @param Motor_Control_Module_Status_Mask  Motor control module status mask
 * @param Guidance_Module_Status_Mask  Guidance module status mask
 * @param Flight_Phase  Flight phase id
 * @param Flight_Mode  Flight mode id
 * @param Flight_Phase_Time [ms] Flight phase execution time
 * @param Emergency_Board_Status  Emergency Board Status
 * @param PSU_Status  PSU Status
 * @param Emergency_Radio_Link_Status  Emergency Radio Link Status
 * @param Channel_4_PWM  Channel 4 PWM
 * @param Channel_5_PWM  Channel 5 PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_status_pack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t Log_Timestamp,uint32_t Core_Module_Status_Mask,uint64_t Telemetry_Module_Status_Mask,uint32_t Storage_Module_Status_Mask,uint32_t Radio_Link_Module_Status_Mask,uint32_t Motor_Control_Module_Status_Mask,uint32_t Guidance_Module_Status_Mask,uint8_t Flight_Phase,uint8_t Flight_Mode,uint32_t Flight_Phase_Time,uint16_t Emergency_Board_Status,uint16_t PSU_Status,uint8_t Emergency_Radio_Link_Status,int16_t Channel_4_PWM,int16_t Channel_5_PWM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, Telemetry_Module_Status_Mask);
    _mav_put_uint32_t(buf, 16, Core_Module_Status_Mask);
    _mav_put_uint32_t(buf, 20, Storage_Module_Status_Mask);
    _mav_put_uint32_t(buf, 24, Radio_Link_Module_Status_Mask);
    _mav_put_uint32_t(buf, 28, Motor_Control_Module_Status_Mask);
    _mav_put_uint32_t(buf, 32, Guidance_Module_Status_Mask);
    _mav_put_uint32_t(buf, 36, Flight_Phase_Time);
    _mav_put_uint16_t(buf, 40, Emergency_Board_Status);
    _mav_put_uint16_t(buf, 42, PSU_Status);
    _mav_put_int16_t(buf, 44, Channel_4_PWM);
    _mav_put_int16_t(buf, 46, Channel_5_PWM);
    _mav_put_uint8_t(buf, 48, Flight_Phase);
    _mav_put_uint8_t(buf, 49, Flight_Mode);
    _mav_put_uint8_t(buf, 50, Emergency_Radio_Link_Status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN);
#else
    mavlink_system_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Telemetry_Module_Status_Mask = Telemetry_Module_Status_Mask;
    packet.Core_Module_Status_Mask = Core_Module_Status_Mask;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.Motor_Control_Module_Status_Mask = Motor_Control_Module_Status_Mask;
    packet.Guidance_Module_Status_Mask = Guidance_Module_Status_Mask;
    packet.Flight_Phase_Time = Flight_Phase_Time;
    packet.Emergency_Board_Status = Emergency_Board_Status;
    packet.PSU_Status = PSU_Status;
    packet.Channel_4_PWM = Channel_4_PWM;
    packet.Channel_5_PWM = Channel_5_PWM;
    packet.Flight_Phase = Flight_Phase;
    packet.Flight_Mode = Flight_Mode;
    packet.Emergency_Radio_Link_Status = Emergency_Radio_Link_Status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_STATUS_PACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
}

/**
 * @brief Encode a system_status_pack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_status_pack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_status_pack_t* system_status_pack)
{
    return mavlink_msg_system_status_pack_pack(system_id, component_id, msg, system_status_pack->Log_Timestamp, system_status_pack->Core_Module_Status_Mask, system_status_pack->Telemetry_Module_Status_Mask, system_status_pack->Storage_Module_Status_Mask, system_status_pack->Radio_Link_Module_Status_Mask, system_status_pack->Motor_Control_Module_Status_Mask, system_status_pack->Guidance_Module_Status_Mask, system_status_pack->Flight_Phase, system_status_pack->Flight_Mode, system_status_pack->Flight_Phase_Time, system_status_pack->Emergency_Board_Status, system_status_pack->PSU_Status, system_status_pack->Emergency_Radio_Link_Status, system_status_pack->Channel_4_PWM, system_status_pack->Channel_5_PWM);
}

/**
 * @brief Encode a system_status_pack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_status_pack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_status_pack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_status_pack_t* system_status_pack)
{
    return mavlink_msg_system_status_pack_pack_chan(system_id, component_id, chan, msg, system_status_pack->Log_Timestamp, system_status_pack->Core_Module_Status_Mask, system_status_pack->Telemetry_Module_Status_Mask, system_status_pack->Storage_Module_Status_Mask, system_status_pack->Radio_Link_Module_Status_Mask, system_status_pack->Motor_Control_Module_Status_Mask, system_status_pack->Guidance_Module_Status_Mask, system_status_pack->Flight_Phase, system_status_pack->Flight_Mode, system_status_pack->Flight_Phase_Time, system_status_pack->Emergency_Board_Status, system_status_pack->PSU_Status, system_status_pack->Emergency_Radio_Link_Status, system_status_pack->Channel_4_PWM, system_status_pack->Channel_5_PWM);
}

/**
 * @brief Send a system_status_pack message
 * @param chan MAVLink channel to send the message
 *
 * @param Log_Timestamp [ms] Log timestamp since 1.1.1970 UTC.
 * @param Core_Module_Status_Mask  Core module status mask
 * @param Telemetry_Module_Status_Mask  Telemetry module status mask
 * @param Storage_Module_Status_Mask  Storage module status mask
 * @param Radio_Link_Module_Status_Mask  Radio link module status mask
 * @param Motor_Control_Module_Status_Mask  Motor control module status mask
 * @param Guidance_Module_Status_Mask  Guidance module status mask
 * @param Flight_Phase  Flight phase id
 * @param Flight_Mode  Flight mode id
 * @param Flight_Phase_Time [ms] Flight phase execution time
 * @param Emergency_Board_Status  Emergency Board Status
 * @param PSU_Status  PSU Status
 * @param Emergency_Radio_Link_Status  Emergency Radio Link Status
 * @param Channel_4_PWM  Channel 4 PWM
 * @param Channel_5_PWM  Channel 5 PWM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_status_pack_send(mavlink_channel_t chan, uint64_t Log_Timestamp, uint32_t Core_Module_Status_Mask, uint64_t Telemetry_Module_Status_Mask, uint32_t Storage_Module_Status_Mask, uint32_t Radio_Link_Module_Status_Mask, uint32_t Motor_Control_Module_Status_Mask, uint32_t Guidance_Module_Status_Mask, uint8_t Flight_Phase, uint8_t Flight_Mode, uint32_t Flight_Phase_Time, uint16_t Emergency_Board_Status, uint16_t PSU_Status, uint8_t Emergency_Radio_Link_Status, int16_t Channel_4_PWM, int16_t Channel_5_PWM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN];
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, Telemetry_Module_Status_Mask);
    _mav_put_uint32_t(buf, 16, Core_Module_Status_Mask);
    _mav_put_uint32_t(buf, 20, Storage_Module_Status_Mask);
    _mav_put_uint32_t(buf, 24, Radio_Link_Module_Status_Mask);
    _mav_put_uint32_t(buf, 28, Motor_Control_Module_Status_Mask);
    _mav_put_uint32_t(buf, 32, Guidance_Module_Status_Mask);
    _mav_put_uint32_t(buf, 36, Flight_Phase_Time);
    _mav_put_uint16_t(buf, 40, Emergency_Board_Status);
    _mav_put_uint16_t(buf, 42, PSU_Status);
    _mav_put_int16_t(buf, 44, Channel_4_PWM);
    _mav_put_int16_t(buf, 46, Channel_5_PWM);
    _mav_put_uint8_t(buf, 48, Flight_Phase);
    _mav_put_uint8_t(buf, 49, Flight_Mode);
    _mav_put_uint8_t(buf, 50, Emergency_Radio_Link_Status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK, buf, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
#else
    mavlink_system_status_pack_t packet;
    packet.Log_Timestamp = Log_Timestamp;
    packet.Telemetry_Module_Status_Mask = Telemetry_Module_Status_Mask;
    packet.Core_Module_Status_Mask = Core_Module_Status_Mask;
    packet.Storage_Module_Status_Mask = Storage_Module_Status_Mask;
    packet.Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet.Motor_Control_Module_Status_Mask = Motor_Control_Module_Status_Mask;
    packet.Guidance_Module_Status_Mask = Guidance_Module_Status_Mask;
    packet.Flight_Phase_Time = Flight_Phase_Time;
    packet.Emergency_Board_Status = Emergency_Board_Status;
    packet.PSU_Status = PSU_Status;
    packet.Channel_4_PWM = Channel_4_PWM;
    packet.Channel_5_PWM = Channel_5_PWM;
    packet.Flight_Phase = Flight_Phase;
    packet.Flight_Mode = Flight_Mode;
    packet.Emergency_Radio_Link_Status = Emergency_Radio_Link_Status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
#endif
}

/**
 * @brief Send a system_status_pack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_status_pack_send_struct(mavlink_channel_t chan, const mavlink_system_status_pack_t* system_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_status_pack_send(chan, system_status_pack->Log_Timestamp, system_status_pack->Core_Module_Status_Mask, system_status_pack->Telemetry_Module_Status_Mask, system_status_pack->Storage_Module_Status_Mask, system_status_pack->Radio_Link_Module_Status_Mask, system_status_pack->Motor_Control_Module_Status_Mask, system_status_pack->Guidance_Module_Status_Mask, system_status_pack->Flight_Phase, system_status_pack->Flight_Mode, system_status_pack->Flight_Phase_Time, system_status_pack->Emergency_Board_Status, system_status_pack->PSU_Status, system_status_pack->Emergency_Radio_Link_Status, system_status_pack->Channel_4_PWM, system_status_pack->Channel_5_PWM);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK, (const char *)system_status_pack, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_status_pack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t Log_Timestamp, uint32_t Core_Module_Status_Mask, uint64_t Telemetry_Module_Status_Mask, uint32_t Storage_Module_Status_Mask, uint32_t Radio_Link_Module_Status_Mask, uint32_t Motor_Control_Module_Status_Mask, uint32_t Guidance_Module_Status_Mask, uint8_t Flight_Phase, uint8_t Flight_Mode, uint32_t Flight_Phase_Time, uint16_t Emergency_Board_Status, uint16_t PSU_Status, uint8_t Emergency_Radio_Link_Status, int16_t Channel_4_PWM, int16_t Channel_5_PWM)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, Log_Timestamp);
    _mav_put_uint64_t(buf, 8, Telemetry_Module_Status_Mask);
    _mav_put_uint32_t(buf, 16, Core_Module_Status_Mask);
    _mav_put_uint32_t(buf, 20, Storage_Module_Status_Mask);
    _mav_put_uint32_t(buf, 24, Radio_Link_Module_Status_Mask);
    _mav_put_uint32_t(buf, 28, Motor_Control_Module_Status_Mask);
    _mav_put_uint32_t(buf, 32, Guidance_Module_Status_Mask);
    _mav_put_uint32_t(buf, 36, Flight_Phase_Time);
    _mav_put_uint16_t(buf, 40, Emergency_Board_Status);
    _mav_put_uint16_t(buf, 42, PSU_Status);
    _mav_put_int16_t(buf, 44, Channel_4_PWM);
    _mav_put_int16_t(buf, 46, Channel_5_PWM);
    _mav_put_uint8_t(buf, 48, Flight_Phase);
    _mav_put_uint8_t(buf, 49, Flight_Mode);
    _mav_put_uint8_t(buf, 50, Emergency_Radio_Link_Status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK, buf, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
#else
    mavlink_system_status_pack_t *packet = (mavlink_system_status_pack_t *)msgbuf;
    packet->Log_Timestamp = Log_Timestamp;
    packet->Telemetry_Module_Status_Mask = Telemetry_Module_Status_Mask;
    packet->Core_Module_Status_Mask = Core_Module_Status_Mask;
    packet->Storage_Module_Status_Mask = Storage_Module_Status_Mask;
    packet->Radio_Link_Module_Status_Mask = Radio_Link_Module_Status_Mask;
    packet->Motor_Control_Module_Status_Mask = Motor_Control_Module_Status_Mask;
    packet->Guidance_Module_Status_Mask = Guidance_Module_Status_Mask;
    packet->Flight_Phase_Time = Flight_Phase_Time;
    packet->Emergency_Board_Status = Emergency_Board_Status;
    packet->PSU_Status = PSU_Status;
    packet->Channel_4_PWM = Channel_4_PWM;
    packet->Channel_5_PWM = Channel_5_PWM;
    packet->Flight_Phase = Flight_Phase;
    packet->Flight_Mode = Flight_Mode;
    packet->Emergency_Radio_Link_Status = Emergency_Radio_Link_Status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_STATUS_PACK UNPACKING


/**
 * @brief Get field Log_Timestamp from system_status_pack message
 *
 * @return [ms] Log timestamp since 1.1.1970 UTC.
 */
static inline uint64_t mavlink_msg_system_status_pack_get_Log_Timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Core_Module_Status_Mask from system_status_pack message
 *
 * @return  Core module status mask
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Core_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field Telemetry_Module_Status_Mask from system_status_pack message
 *
 * @return  Telemetry module status mask
 */
static inline uint64_t mavlink_msg_system_status_pack_get_Telemetry_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field Storage_Module_Status_Mask from system_status_pack message
 *
 * @return  Storage module status mask
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Storage_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field Radio_Link_Module_Status_Mask from system_status_pack message
 *
 * @return  Radio link module status mask
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Radio_Link_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field Motor_Control_Module_Status_Mask from system_status_pack message
 *
 * @return  Motor control module status mask
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Motor_Control_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Get field Guidance_Module_Status_Mask from system_status_pack message
 *
 * @return  Guidance module status mask
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Guidance_Module_Status_Mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field Flight_Phase from system_status_pack message
 *
 * @return  Flight phase id
 */
static inline uint8_t mavlink_msg_system_status_pack_get_Flight_Phase(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field Flight_Mode from system_status_pack message
 *
 * @return  Flight mode id
 */
static inline uint8_t mavlink_msg_system_status_pack_get_Flight_Mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field Flight_Phase_Time from system_status_pack message
 *
 * @return [ms] Flight phase execution time
 */
static inline uint32_t mavlink_msg_system_status_pack_get_Flight_Phase_Time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field Emergency_Board_Status from system_status_pack message
 *
 * @return  Emergency Board Status
 */
static inline uint16_t mavlink_msg_system_status_pack_get_Emergency_Board_Status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field PSU_Status from system_status_pack message
 *
 * @return  PSU Status
 */
static inline uint16_t mavlink_msg_system_status_pack_get_PSU_Status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field Emergency_Radio_Link_Status from system_status_pack message
 *
 * @return  Emergency Radio Link Status
 */
static inline uint8_t mavlink_msg_system_status_pack_get_Emergency_Radio_Link_Status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  50);
}

/**
 * @brief Get field Channel_4_PWM from system_status_pack message
 *
 * @return  Channel 4 PWM
 */
static inline int16_t mavlink_msg_system_status_pack_get_Channel_4_PWM(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field Channel_5_PWM from system_status_pack message
 *
 * @return  Channel 5 PWM
 */
static inline int16_t mavlink_msg_system_status_pack_get_Channel_5_PWM(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Decode a system_status_pack message into a struct
 *
 * @param msg The message to decode
 * @param system_status_pack C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_status_pack_decode(const mavlink_message_t* msg, mavlink_system_status_pack_t* system_status_pack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    system_status_pack->Log_Timestamp = mavlink_msg_system_status_pack_get_Log_Timestamp(msg);
    system_status_pack->Telemetry_Module_Status_Mask = mavlink_msg_system_status_pack_get_Telemetry_Module_Status_Mask(msg);
    system_status_pack->Core_Module_Status_Mask = mavlink_msg_system_status_pack_get_Core_Module_Status_Mask(msg);
    system_status_pack->Storage_Module_Status_Mask = mavlink_msg_system_status_pack_get_Storage_Module_Status_Mask(msg);
    system_status_pack->Radio_Link_Module_Status_Mask = mavlink_msg_system_status_pack_get_Radio_Link_Module_Status_Mask(msg);
    system_status_pack->Motor_Control_Module_Status_Mask = mavlink_msg_system_status_pack_get_Motor_Control_Module_Status_Mask(msg);
    system_status_pack->Guidance_Module_Status_Mask = mavlink_msg_system_status_pack_get_Guidance_Module_Status_Mask(msg);
    system_status_pack->Flight_Phase_Time = mavlink_msg_system_status_pack_get_Flight_Phase_Time(msg);
    system_status_pack->Emergency_Board_Status = mavlink_msg_system_status_pack_get_Emergency_Board_Status(msg);
    system_status_pack->PSU_Status = mavlink_msg_system_status_pack_get_PSU_Status(msg);
    system_status_pack->Channel_4_PWM = mavlink_msg_system_status_pack_get_Channel_4_PWM(msg);
    system_status_pack->Channel_5_PWM = mavlink_msg_system_status_pack_get_Channel_5_PWM(msg);
    system_status_pack->Flight_Phase = mavlink_msg_system_status_pack_get_Flight_Phase(msg);
    system_status_pack->Flight_Mode = mavlink_msg_system_status_pack_get_Flight_Mode(msg);
    system_status_pack->Emergency_Radio_Link_Status = mavlink_msg_system_status_pack_get_Emergency_Radio_Link_Status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN;
        memset(system_status_pack, 0, MAVLINK_MSG_ID_SYSTEM_STATUS_PACK_LEN);
    memcpy(system_status_pack, _MAV_PAYLOAD(msg), len);
#endif
}
