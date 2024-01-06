#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 15     // Digital pin connected to the DHT sensor
#define DHTTYPE    DHT11     // DHT 11

extern DHT_Unified dht;
extern sensor_t sensorDHT;

void setupSensors();
void readValues();
float getTemperature();
float getHumidity();
float getMoisture();
#endif // SETUPSENSOR_H_