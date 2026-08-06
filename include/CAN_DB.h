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

/**
 * @brief Enum for defining message IDs
 */
enum MESSAGE_ID
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
  uint8_t bytes[8];
};

/**
 * @brief Structure for the payload of the LedState message
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
  uint8_t bytes[8];
};

#endif // CAN_DB_H