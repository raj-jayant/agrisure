#include <DHT.h>

// Define the type of sensor used
#define DHTTYPE DHT11 // DHT11 or DHT22

// Define the pin where the data line is connected
#define DHTPIN 2

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read temperature as Celsius
  float tempC = dht.readTemperature();

  // Check if any reads failed and exit early (to try again)
  if (isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  // Additional logic for monitoring and controlling mushroom plant environment will be added here
}
