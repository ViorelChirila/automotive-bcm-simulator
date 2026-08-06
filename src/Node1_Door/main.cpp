#include <Arduino.h>
#include "pinout_door.h"
#include "led_module.h"

void setup()
{
  led_module_init(DOOR_LED_PIN);
}

void loop()
{
  delay(1000);
  led_module_set_state(DOOR_LED_PIN, HIGH);
  
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/