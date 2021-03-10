#include <Arduino.h>

#include <DallasTemperature.h>

#define ONE_WIRE_BUS 23   //D23
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensor(&oneWire);


void setup() 
{

  sensor.begin();
 
  Serial.begin(115200);
 
}
int timer = 0;


void loop() 
{   
 
  float temperature;
  
  sensor.requestTemperatures();
  
  // считываем данные из регистра датчика
  temperature = sensor.getTempCByIndex(0);

  Serial.println(temperature);
  delay(200);
  
}