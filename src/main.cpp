#include <Arduino.h>
#include <Wire.h>
#include <VL6180X.h>

/*
Arduino   VL6180X board
-------   -------------
     5V - VIN
    GND - GND
    SDA - SDA
    SCL - SCL
*/

VL6180X sensor;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  sensor.init();
  sensor.configureDefault();
  sensor.setTimeout(500);
}

void loop() 
{ 
  Serial.print(sensor.readRangeSingleMillimeters());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
}
