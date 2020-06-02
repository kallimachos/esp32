#include <arduino.h>
// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
#include "DHT.h"

#define LEDPin 5
#define DHTPIN 4
#define DHTTYPE DHT11

const char* ssid = "...";
const char* password = "...";

DHT dht(DHTPIN, DHTTYPE);
// AsyncWebServer server(80);

void setup(){
    Serial.begin(9600);
    pinMode(LEDPin, OUTPUT);
    // WiFi.begin(ssid, password);
    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(1000);
    //     Serial.println("Connecting to WiFi...");
    // }
    // Serial.println(WiFi.localIP());
    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    //     request->send(200, "text/html", "<p>Hello World!</p>");
    // });
    // server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
    //     request->send(200, "text/html", "<p>Some HTML!</p>");
    // });
    // server.begin();
    Serial.println("DHT11 test!");
    pinMode(LEDPin, OUTPUT);
    dht.begin();
}

void loop(){
    // digitalWrite(LEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)
    // delay(200);
    // digitalWrite(LEDPin, LOW);   // turn the LED off by making the voltage LOW
    // delay(200);
    // digitalWrite(LEDPin, HIGH);
    // delay(200);
    // digitalWrite(LEDPin, LOW);
    // delay(1200);
    delay(2000);

    float h = dht.readHumidity();

    float t = dht.readTemperature();  // Read temperature as Celsius (the default)

    if (isnan(h) || isnan(t)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C  Heat index: "));
    Serial.print(hic);
    Serial.println(F("°C"));
}
