#include "OLEDHandler.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

void setupOLED()
{
  Serial.println("OLED FeatherWing test");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

  Serial.println("OLED begun");

  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Connecting to SSID\n'adafruit':");
  display.print("connected!");
  display.println("IP: 192.168.0.200");
  display.println("Sending val #0");
  display.setCursor(0, 0);
  display.display();
}

void updateOLED()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Temperature: ");
  display.print(getTemperature());
  display.println(" C");
  display.print("Humidity: ");
  display.print(getHumidity());
  display.println("%");
  display.print("Moisture: ");
  display.println(getMoisture());
  display.display();
}