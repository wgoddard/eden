

#include "Wire.h"

#define I2C_ADDR 0x20

void setup()
{
  Serial.begin(38400);
  Serial.println("RELAY8 starting up");
  
  Wire.begin();
  
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x12);
  Wire.write(0x20);
  Wire.endTransmission();
  
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
  
  Serial.println();
}


void loop()
{
  int sensorValue = analogRead(0); 
  
  Serial.print(sensorValue );
  Serial.print("\n");
  
  if (sensorValue == 0) 
  {
    sendValueToLatch(1);
  }
  else if (sensorValue == 1023)
  {
    sendValueToLatch(2);
  } 
  else 
  {
    sendValueToLatch(0);
  }
  
  
}




void sendValueToLatch(int latchValue)
{
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x12);
  Wire.write(latchValue);
  Wire.endTransmission();
}
