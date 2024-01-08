#include "sensorHandler.h"

#define DHTPIN 15     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
#define HIGRO_PIN 35  // Analog pin connected to the Higrometer
DHT_Unified dht(DHTPIN, DHTTYPE);
sensor_t sensorDHT;

void setupDHT()
{
  dht.begin();
  // Initialize device.
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  dht.temperature().getSensor(&sensorDHT);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print(F("Sensor Type: "));
  Serial.println(sensorDHT.name);
  Serial.print(F("Driver Ver:  "));
  Serial.println(sensorDHT.version);
  Serial.print(F("Unique ID:   "));
  Serial.println(sensorDHT.sensor_id);
  Serial.print(F("Max Value:   "));
  Serial.print(sensorDHT.max_value);
  Serial.println(F("°C"));
  Serial.print(F("Min Value:   "));
  Serial.print(sensorDHT.min_value);
  Serial.println(F("°C"));
  Serial.print(F("Resolution:  "));
  Serial.print(sensorDHT.resolution);
  Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensorDHT);
  Serial.println(F("Humidity Sensor"));
  Serial.print(F("Sensor Type: "));
  Serial.println(sensorDHT.name);
  Serial.print(F("Driver Ver:  "));
  Serial.println(sensorDHT.version);
  Serial.print(F("Unique ID:   "));
  Serial.println(sensorDHT.sensor_id);
  Serial.print(F("Max Value:   "));
  Serial.print(sensorDHT.max_value);
  Serial.println(F("%"));
  Serial.print(F("Min Value:   "));
  Serial.print(sensorDHT.min_value);
  Serial.println(F("%"));
  Serial.print(F("Resolution:  "));
  Serial.print(sensorDHT.resolution);
  Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
}

float getMoisture()
{
  float data = map(analogRead(HIGRO_PIN), 2600, 1100, 0, 100);
  if (data < 0)
    data = 0;
  else if (data > 100)
    data = 100;
  return data;
}

float getTemperature()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  return event.temperature;
}

float getHumidity()
{
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  return event.relative_humidity;
}

void readValues()
{
  sensors_event_t event;

  // Get temperature event and print its value.
  Serial.print(F("Temperature: "));
  Serial.print(getTemperature());
  Serial.println(F("°C"));

  // Get humidity event and print its value.
  Serial.print(F("Humidity: "));
  Serial.print(getHumidity());
  Serial.println(F("%"));

  // Get moisture event and print its value.
  Serial.print(F("Moisture: "));
  Serial.print(getMoisture());
  Serial.println(F("%"));
}

void setupSensors()
{
  setupDHT();
  pinMode(HIGRO_PIN, INPUT);
}