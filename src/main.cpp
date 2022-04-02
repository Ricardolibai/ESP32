
#include "Wire.h"
#include <Adafruit_GFX.h>    
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>

int pin = 2;
int freq=5000 ;
int channel = 0;
int resolution = 9;



void setup()
{
  ledcSetup(channel , freq , resolution);
  ledcAttachPin(pin , channel);
}

void loop()
{
  for(int dutycycle = 0 ; dutycycle<= 2048 ; dutycycle ++)
  {
    ledcWrite(channel , dutycycle);
    delay(15);
  }
    for(int dutycycle = 2048 ; dutycycle>=0 ; dutycycle --)
  {
    ledcWrite(channel , dutycycle);
    digitalWrite(pin , HIGH);
    delay(15);
  }
}