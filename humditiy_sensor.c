/*
    Project name : ESP8266 Humidity Sensor
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-humidity-sensor
*/

#include <DHT.h>

// Define the type of DHT sensor (DHT11 or DHT22)
#define DHTTYPE DHT11 // Change this to DHT22 if you're using that sensor

// Pin connected to the DHT sensor
const int dhtPin = D2; // GPIO pin D2 on NodeMCU

// Initialize DHT sensor object
DHT dht(dhtPin, DHTTYPE);

void setup() {
  Serial.begin(9600); // Initialize serial communication
  dht.begin(); // Initialize DHT sensor
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read humidity (%)
  float humidity = dht.readHumidity();

  // Check if read failed
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print humidity value to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
