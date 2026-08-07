#include "button_module.h"

void button_module_init(uint8_t pin)
{
  pinMode(pin, INPUT_PULLUP);
}

uint8_t button_module_read_state(uint8_t pin)
{
  return digitalRead(pin);
}

uint8_t button_module_is_pressed(uint8_t pin)
{
  return button_module_read_state(pin) == LOW;
}