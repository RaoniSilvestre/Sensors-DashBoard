#include "serverHandler.h"
#include "sensorHandler.h"
#include "OLEDHandler.h"
#include "network.h"

HTTPClient http;

void connectWiFi()
{
  Serial.print("Connecting to WiFi network:");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected!");
}

void sendData()
{
  http.begin("http://192.168.0.200:3000/dados");
  http.addHeader("Content-Type", "application/json");
  http.setTimeout(20000);  

  char jsonBuffer[80]; 
  snprintf(jsonBuffer, sizeof(jsonBuffer), "{\"temperatura\":%f,\"umidade\":%f,\"umidade_solo\":%f}", getTemperature(), getHumidity(), getMoisture());

  int httpResponseCode = http.POST(jsonBuffer);

  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    display.print("HTTP: ");
    display.print(httpResponseCode);
    display.display();
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    
    display.print("HTTP: ");
    display.print(httpResponseCode);
    display.display();
  }

  String s = http.getString();
  Serial.print(s + "\n");
}