#include "can_module.h"

static MCP_CAN *can_controller = nullptr;

uint8_t can_module_init(uint8_t cs_pin)
{
  can_controller = new MCP_CAN(cs_pin);

  if (can_controller->begin(MCP_ANY, CAN_MODULE_SPEED, CAN_MODULE_CLOCK) != CAN_OK)
  {
    return 0;
  }

  can_controller->setMode(MCP_NORMAL);
  return 1;
}
