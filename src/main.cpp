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

#define PIN_FREQ 4
#define DIST_MIN 0
#define DIST_MAX 200
#define FREQ_MIN 33
#define FREQ_MAX 1023

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
  uint16_t sensorValue = sensor.readRangeSingleMillimeters();
  uint16_t freq = map(sensorValue, DIST_MIN, DIST_MAX, FREQ_MIN, FREQ_MAX);
  tone(PIN_FREQ, freq);
  Serial.print(sensorValue);
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
}
