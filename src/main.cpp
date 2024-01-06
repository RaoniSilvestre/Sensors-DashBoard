#include "config.h"

void setup() {
  Serial.begin(115200);
  setupSensors();
  setupOLED();
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  readValues();
  updateOLED();
}