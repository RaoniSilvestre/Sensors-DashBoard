#include "config.h"

int cont = 0;

void setup()
{
  Serial.begin(115200);
  setupSensors();
  setupOLED();
  connectWiFi();
}

void loop()
{
  delay(delayMS);
  readValues();
  updateOLED();
  
  cont++;
  if(cont == 60) {
    cont = 0;
    sendData();
  }
}