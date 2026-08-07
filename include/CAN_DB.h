#ifndef CAN_DB_H
#define CAN_DB_H

/**
 * @file can_db.h
 * @author Chirila Viorel
 * @brief This file contains the definitions for the CAN message IDs and their corresponding payload structures.
 * @version 0.1
 * @date 2026-08-06
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>

/** \brief Data length code (payload size in bytes) used for every message on this bus */
#define CAN_DLC 8

/**
 * @brief Enum for defining message IDs
 */
enum MESSAGE_ID : uint16_t
{
  CAN_MSG_WAKE_UP = 0x01,
  CAN_MSG_SLEEP = 0x02,
  CAN_MSG_NODE2_BCM_STATE = 0x03,
  CAN_MSG_NODE1_DOOR_STATE = 0x04,
  CAN_MSG_BUTTON_STATE = 0x100,
  CAN_MSG_LED_STATE = 0x101,
  CAN_MSG_DOOR_STATE = 0x111
};

/**
 * @brief Structure for the payload of the ButtonState message
 * @note Bitfield-to-byte packing order is implementation-defined by the C++ standard.
 *       This relies on both nodes being built with GCC (avr-gcc / xtensa-gcc), which
 *       pack these bitfields identically. Always exchange data via the `bytes` member
 *       of the union, never by copying the struct's raw memory across toolchains.
 */
struct __attribute__((packed)) ButtonStateData
{
  uint8_t button_door_up : 1;
  uint8_t button_door_down : 1;
  uint8_t button_interior_light : 1;
  uint8_t reserved : 5;
};

union ButtonStatePayload
{
  ButtonStateData data;
  uint8_t bytes[CAN_DLC];
};

static_assert(sizeof(ButtonStatePayload) == CAN_DLC, "ButtonStatePayload must match CAN_DLC");

/**
 * @brief Structure for the payload of the LedState message
 * @note See the bitfield packing note on ButtonStateData; the same caveat applies here.
 */
struct __attribute__((packed)) LedStateData
{
  uint8_t led_door : 1;
  uint8_t led_interior_light : 1;
  uint8_t reserved : 6;
};

union LedStatePayload
{
  LedStateData data;
  uint8_t bytes[CAN_DLC];
};

static_assert(sizeof(LedStatePayload) == CAN_DLC, "LedStatePayload must match CAN_DLC");

#endif // CAN_DB_H