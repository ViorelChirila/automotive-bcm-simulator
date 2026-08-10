#ifndef CAN_MODULE_H
#define CAN_MODULE_H

/**
 * @file can_module.h
 * @author Chirila Viorel
 * @brief This file contains the definitions for the CAN bus module functions.
 * @version 0.1
 * @date 2026-08-07
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <Arduino.h>
#include <mcp_can.h>

/** \brief CAN bus bitrate shared by every node on the network */
#define CAN_MODULE_SPEED   CAN_500KBPS

/** \brief Oscillator frequency of the MCP2515 module */
#define CAN_MODULE_CLOCK   MCP_8MHZ

/**
 * @fn uint8_t can_module_init(uint8_t cs_pin)
 * @brief Initializes the CAN controller (MCP2515) on the given Chip Select pin
 * @param[in] cs_pin Chip Select pin connected to the MCP2515 module
 * @param[out] None
 * @return 1 if the initialization succeeded, 0 otherwise
 * @details This function is shared by every node (Uno or ESP32) since both use the same
 *          MCP2515 + mcp_can.h combination, only the CS pin differs per board. It creates
 *          the MCP_CAN driver instance, starts communication in normal mode at
 *          CAN_MODULE_SPEED/CAN_MODULE_CLOCK and leaves it ready to send/receive.
 */
extern uint8_t can_module_init(uint8_t cs_pin);

#endif // CAN_MODULE_H
