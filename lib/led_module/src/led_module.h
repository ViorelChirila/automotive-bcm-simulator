#ifndef LED_MODULE_H
#define LED_MODULE_H

/**
 * @file led_module.h
 * @author Chirila Viorel
 * @brief This file contains the definitions for the LED module functions.
 * @version 0.1
 * @date 2026-08-06
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <Arduino.h>

/**
 * @fn void led_module_init(uint8_t pin)
 * @brief Initializes the LEDs
 * @param[in] pin
 * @param[out] None
 * @return None
 * @details This function initializes the LEDs by setting the appropriate pins as outputs and turning them off.
 */
extern void led_module_init(uint8_t pin);

extern void led_module_set_state(uint8_t led_pin, uint8_t state);

#endif // LED_MODULE_H