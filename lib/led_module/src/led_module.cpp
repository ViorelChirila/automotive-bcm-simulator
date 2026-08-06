#include "led_module.h"

void led_module_init(uint8_t pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void led_module_set_state(uint8_t led_pin, uint8_t state)
{
  digitalWrite(led_pin, state);
}
