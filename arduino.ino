#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float hum;
float temp;

unsigned long previousMillis = 0UL;
unsigned long interval = 2000UL;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    hum = dht.readHumidity();
    temp = dht.readTemperature();

    Serial.print("{\"temp\":");
    Serial.print(temp);
    Serial.print(",\"hum\":");
    Serial.print(hum);
    Serial.println("}");

    previousMillis = currentMillis;
  }
}