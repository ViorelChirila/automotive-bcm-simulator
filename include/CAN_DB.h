#ifndef CAN_DB_H
#define CAN_DB_H

/**
 * @file CAN_DB.h
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
  WAKE_UP = 0x01,
  SLEEP = 0x02,
  NODE2_BCM_STATE = 0x03,
  NODE1_DOOR_STATE = 0x04,
  BUTTON_STATE = 0x100,
  LED_STATE = 0x101,
  DOOR_STATE = 0x111
};

/**
 * @brief Structure for the payload of the ButtonState message
 */
struct __attribute__((packed)) ButtonStateData
{
  uint8_t buttonDoorUpState : 1;
  uint8_t buttonDoorDownState : 1;
  uint8_t buttonInteriorLightState : 1;
  uint8_t reserved : 5;
};

union ButtonStatePayload
{
  ButtonStateData buttonState;
  uint8_t bytes[8];
};

/**
 * @brief Structure for the payload of the LedState message
 */
struct __attribute__((packed)) LedStateData
{
  uint8_t ledDoorState : 1;
  uint8_t ledInteriorLightState : 1;
  uint8_t reserved : 6;
};

union LedStatePayload
{
  LedStateData ledState;
  uint8_t bytes[8];
};

#endif // CAN_DB_H