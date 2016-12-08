#pragma once
// MESSAGE MOUNT_STATUS2 PACKING

#define MAVLINK_MSG_ID_MOUNT_STATUS2 265

MAVPACKED(
typedef struct __mavlink_mount_status2_t {
 uint32_t time_boot_ms; /*< Timestamp (milliseconds since system boot)*/
 float roll; /*< Roll in degrees, set if appropriate mount mode.*/
 float pitch; /*< Pitch in degrees, set if appropriate mount mode.*/
 float yaw; /*< Yaw in degrees, set if appropriate mount mode.*/
 int32_t lat; /*< Latitude, in degrees * 1E7, set if appropriate mount mode.*/
 int32_t lon; /*< Longitude, in degrees * 1E7, set if appropriate mount mode.*/
 float alt; /*< Altitude in meters, set if appropriate mount mode.*/
 uint8_t mode; /*< Mount operation mode (see MAV_MOUNT_MODE enum)*/
}) mavlink_mount_status2_t;

#define MAVLINK_MSG_ID_MOUNT_STATUS2_LEN 29
#define MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN 29
#define MAVLINK_MSG_ID_265_LEN 29
#define MAVLINK_MSG_ID_265_MIN_LEN 29

#define MAVLINK_MSG_ID_MOUNT_STATUS2_CRC 229
#define MAVLINK_MSG_ID_265_CRC 229



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOUNT_STATUS2 { \
    265, \
    "MOUNT_STATUS2", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mount_status2_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mount_status2_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mount_status2_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mount_status2_t, yaw) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mount_status2_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mount_status2_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mount_status2_t, alt) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_mount_status2_t, mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOUNT_STATUS2 { \
    "MOUNT_STATUS2", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mount_status2_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mount_status2_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mount_status2_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mount_status2_t, yaw) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mount_status2_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mount_status2_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mount_status2_t, alt) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_mount_status2_t, mode) }, \
         } \
}
#endif

/**
 * @brief Pack a mount_status2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode Mount operation mode (see MAV_MOUNT_MODE enum)
 * @param roll Roll in degrees, set if appropriate mount mode.
 * @param pitch Pitch in degrees, set if appropriate mount mode.
 * @param yaw Yaw in degrees, set if appropriate mount mode.
 * @param lat Latitude, in degrees * 1E7, set if appropriate mount mode.
 * @param lon Longitude, in degrees * 1E7, set if appropriate mount mode.
 * @param alt Altitude in meters, set if appropriate mount mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mount_status2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t mode, float roll, float pitch, float yaw, int32_t lat, int32_t lon, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOUNT_STATUS2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 28, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN);
#else
    mavlink_mount_status2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOUNT_STATUS2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
}

/**
 * @brief Pack a mount_status2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode Mount operation mode (see MAV_MOUNT_MODE enum)
 * @param roll Roll in degrees, set if appropriate mount mode.
 * @param pitch Pitch in degrees, set if appropriate mount mode.
 * @param yaw Yaw in degrees, set if appropriate mount mode.
 * @param lat Latitude, in degrees * 1E7, set if appropriate mount mode.
 * @param lon Longitude, in degrees * 1E7, set if appropriate mount mode.
 * @param alt Altitude in meters, set if appropriate mount mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mount_status2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t mode,float roll,float pitch,float yaw,int32_t lat,int32_t lon,float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOUNT_STATUS2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 28, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN);
#else
    mavlink_mount_status2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOUNT_STATUS2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
}

/**
 * @brief Encode a mount_status2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mount_status2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mount_status2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mount_status2_t* mount_status2)
{
    return mavlink_msg_mount_status2_pack(system_id, component_id, msg, mount_status2->time_boot_ms, mount_status2->mode, mount_status2->roll, mount_status2->pitch, mount_status2->yaw, mount_status2->lat, mount_status2->lon, mount_status2->alt);
}

/**
 * @brief Encode a mount_status2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mount_status2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mount_status2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mount_status2_t* mount_status2)
{
    return mavlink_msg_mount_status2_pack_chan(system_id, component_id, chan, msg, mount_status2->time_boot_ms, mount_status2->mode, mount_status2->roll, mount_status2->pitch, mount_status2->yaw, mount_status2->lat, mount_status2->lon, mount_status2->alt);
}

/**
 * @brief Send a mount_status2 message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp (milliseconds since system boot)
 * @param mode Mount operation mode (see MAV_MOUNT_MODE enum)
 * @param roll Roll in degrees, set if appropriate mount mode.
 * @param pitch Pitch in degrees, set if appropriate mount mode.
 * @param yaw Yaw in degrees, set if appropriate mount mode.
 * @param lat Latitude, in degrees * 1E7, set if appropriate mount mode.
 * @param lon Longitude, in degrees * 1E7, set if appropriate mount mode.
 * @param alt Altitude in meters, set if appropriate mount mode.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mount_status2_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint8_t mode, float roll, float pitch, float yaw, int32_t lat, int32_t lon, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOUNT_STATUS2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 28, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOUNT_STATUS2, buf, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
#else
    mavlink_mount_status2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOUNT_STATUS2, (const char *)&packet, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
#endif
}

/**
 * @brief Send a mount_status2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mount_status2_send_struct(mavlink_channel_t chan, const mavlink_mount_status2_t* mount_status2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mount_status2_send(chan, mount_status2->time_boot_ms, mount_status2->mode, mount_status2->roll, mount_status2->pitch, mount_status2->yaw, mount_status2->lat, mount_status2->lon, mount_status2->alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOUNT_STATUS2, (const char *)mount_status2, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOUNT_STATUS2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mount_status2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint8_t mode, float roll, float pitch, float yaw, int32_t lat, int32_t lon, float alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, lat);
    _mav_put_int32_t(buf, 20, lon);
    _mav_put_float(buf, 24, alt);
    _mav_put_uint8_t(buf, 28, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOUNT_STATUS2, buf, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
#else
    mavlink_mount_status2_t *packet = (mavlink_mount_status2_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOUNT_STATUS2, (const char *)packet, MAVLINK_MSG_ID_MOUNT_STATUS2_MIN_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN, MAVLINK_MSG_ID_MOUNT_STATUS2_CRC);
#endif
}
#endif

#endif

// MESSAGE MOUNT_STATUS2 UNPACKING


/**
 * @brief Get field time_boot_ms from mount_status2 message
 *
 * @return Timestamp (milliseconds since system boot)
 */
static inline uint32_t mavlink_msg_mount_status2_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mode from mount_status2 message
 *
 * @return Mount operation mode (see MAV_MOUNT_MODE enum)
 */
static inline uint8_t mavlink_msg_mount_status2_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field roll from mount_status2 message
 *
 * @return Roll in degrees, set if appropriate mount mode.
 */
static inline float mavlink_msg_mount_status2_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch from mount_status2 message
 *
 * @return Pitch in degrees, set if appropriate mount mode.
 */
static inline float mavlink_msg_mount_status2_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw from mount_status2 message
 *
 * @return Yaw in degrees, set if appropriate mount mode.
 */
static inline float mavlink_msg_mount_status2_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field lat from mount_status2 message
 *
 * @return Latitude, in degrees * 1E7, set if appropriate mount mode.
 */
static inline int32_t mavlink_msg_mount_status2_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field lon from mount_status2 message
 *
 * @return Longitude, in degrees * 1E7, set if appropriate mount mode.
 */
static inline int32_t mavlink_msg_mount_status2_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field alt from mount_status2 message
 *
 * @return Altitude in meters, set if appropriate mount mode.
 */
static inline float mavlink_msg_mount_status2_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a mount_status2 message into a struct
 *
 * @param msg The message to decode
 * @param mount_status2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_mount_status2_decode(const mavlink_message_t* msg, mavlink_mount_status2_t* mount_status2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mount_status2->time_boot_ms = mavlink_msg_mount_status2_get_time_boot_ms(msg);
    mount_status2->roll = mavlink_msg_mount_status2_get_roll(msg);
    mount_status2->pitch = mavlink_msg_mount_status2_get_pitch(msg);
    mount_status2->yaw = mavlink_msg_mount_status2_get_yaw(msg);
    mount_status2->lat = mavlink_msg_mount_status2_get_lat(msg);
    mount_status2->lon = mavlink_msg_mount_status2_get_lon(msg);
    mount_status2->alt = mavlink_msg_mount_status2_get_alt(msg);
    mount_status2->mode = mavlink_msg_mount_status2_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOUNT_STATUS2_LEN? msg->len : MAVLINK_MSG_ID_MOUNT_STATUS2_LEN;
        memset(mount_status2, 0, MAVLINK_MSG_ID_MOUNT_STATUS2_LEN);
    memcpy(mount_status2, _MAV_PAYLOAD(msg), len);
#endif
}
