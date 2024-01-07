#ifndef OLEDHANDLER_H
#define OLEDHANDLER_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "sensorHandler.h"

#define WIRE Wire

extern Adafruit_SSD1306 display;

void setupOLED();
void updateOLED();

#endif // OLEDHANDLER_H_