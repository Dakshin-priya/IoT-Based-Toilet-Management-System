#include <Adafruit_Sensor.h>
#include <Arduino.h>

#include <WiFi.h>
#include <ThingSpeak.h>

#include <DHT.h>
#include <DHT_U.h>

#define dhtPin 22
#define DHTTYPE DHT22

const int heaterPin = 2;
const int gasPin = 33; 

const char* ssid = "Dakshin priya TS";
const char* password = "dakshinrithi";

// ThingSpeak credentials
const char* thingSpeakApiKey = "77V65WF4C66N6DE4";
const unsigned long channelNumber = 2586693;

DHT dht(dhtPin, DHTTYPE);
WiFiClient client;

void setup() {
  Serial.begin(115200);

dht.begin();
// Initialize heater pin as output

  pinMode(heaterPin, OUTPUT);
digitalWrite(heaterPin, HIGH);  // Turn heater on
  
// Initialize ADC pin for sensor reading
analogReadResolution(12);

 // Connect to WiFi
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop(){
delay(2000);
float h = dht.readHumidity(); //reads humidity
float t = dht.readTemperature(); //reads temperature in celcius
float f = dht.readTemperature(true); //read temperature in fahrenheit

Serial.print("Moisture:");
Serial.println(h);

if (isnan(h) || isnan(t) || isnan(f))
 {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 

    if (3.5 >= h <= 6.0) {
        Serial.println("Normal moisture content");
    } else if (h >= 7) {
        Serial.println("High moisture content-CLEANING NEEDED");
    }
  delay(500);

int gasValue = analogRead(gasPin);//reads analog voltage from sensor

float voltage = gasValue * (3.3 / 4095.0);// Convert ADC value to voltage (assuming 0-4095 corresponds to 0-3.3V)

    // Print the raw sensor value to the serial monitor
    Serial.print("Raw gas Value: ");
    Serial.println(gasValue);

    // Check the range of sensor values and print corresponding indication
    if (gasValue < 2000) {
        Serial.println("Low gas concentration");
    } else if (gasValue >= 2500 ) {
        Serial.println("Very high gas concentration-CLEANING NEEDED");
    }

   ThingSpeak.writeField(channelNumber, 1, h, thingSpeakApiKey);
   
    Serial.println("Data sent to ThingSpeak");
     delay(15000);  // Wait for 15 seconds (ThingSpeak API limit is 15 seconds between updates)

ThingSpeak.writeField(channelNumber, 2, gasValue, thingSpeakApiKey);
Serial.println("Data sent to ThingSpeak");
    delay(15000);  // Wait for 15 seconds (ThingSpeak API limit is 15 seconds between updates)
}

