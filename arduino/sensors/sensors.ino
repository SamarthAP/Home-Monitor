// use the DHT library from https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>
#define DHTPIN 4     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // DHT11 sensor 
}

void loop() {
  // main loop
  
  delay(2000); // 2 second delay

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11");
    return;
  }

  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  Serial.print(temperature);
  Serial.print(' ');
  Serial.print(humidity);
  Serial.print(' ');
  Serial.print(heatIndex);
  Serial.println();
}
