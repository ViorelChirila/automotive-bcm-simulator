#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128]; // Array to store serial string

MCP_CAN CAN0(10); // Set CS to pin 10

void setup()
{
  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL); // Set operation mode to normal so the MCP2515 sends acks to received data.

  Serial.println("MCP2515 Library Receive Example...");
}

void loop()
{
  if (CAN0.checkReceive() == CAN_MSGAVAIL)
  {
    CAN0.readMsgBuf(&rxId, &len, rxBuf);

    if ((rxId & 0x80000000) == 0x80000000)
      sprintf(msgString,
              "Extended ID: 0x%.8lX DLC: %d Data:",
              (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString,
              "Standard ID: 0x%.3lX DLC: %d Data:",
              rxId, len);

    Serial.print(msgString);

    if ((rxId & 0x40000000) == 0x40000000)
    {
      Serial.print(" REMOTE REQUEST FRAME");
    }
    else
    {
      for (byte i = 0; i < len; i++)
      {
        sprintf(msgString, " %02X", rxBuf[i]);
        Serial.print(msgString);
      }
    }

    Serial.println();
  }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/