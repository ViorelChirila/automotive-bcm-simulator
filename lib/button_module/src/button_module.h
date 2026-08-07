#ifndef BUTTON_MODULE_H
#define BUTTON_MODULE_H

/**
 * @file button_module.h
 * @author Chirila Viorel
 * @brief This file contains the definitions for the button module functions.
 * @version 0.1
 * @date 2026-08-07
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <Arduino.h>

/**
 * @fn void button_module_init(uint8_t pin)
 * @brief Initializes a button
 * @param[in] pin
 * @param[out] None
 * @return None
 * @details This function initializes a button by setting the corresponding pin as an input
 *          with the internal pull-up resistor enabled. Buttons are wired active-low
 *          (pressed = pin pulled to GND).
 */
extern void button_module_init(uint8_t pin);

/**
 * @fn uint8_t button_module_read_state(uint8_t pin)
 * @brief Reads the raw electrical state of a button pin
 * @param[in] pin
 * @param[out] None
 * @return The raw pin state (HIGH or LOW)
 */
extern uint8_t button_module_read_state(uint8_t pin);

/**
 * @fn uint8_t button_module_is_pressed(uint8_t pin)
 * @brief Reads the logical state of a button
 * @param[in] pin
 * @param[out] None
 * @return 1 if the button is pressed, 0 otherwise
 * @details Since buttons are wired active-low, this function inverts the raw pin
 *          state so callers can reason in terms of "pressed"/"not pressed".
 */
extern uint8_t button_module_is_pressed(uint8_t pin);

#endif // BUTTON_MODULE_H