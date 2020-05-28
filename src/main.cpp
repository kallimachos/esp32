#include <arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define LEDPin 5

const char* ssid = "...";
const char* password =  "...";

AsyncWebServer server(80);

void setup(){
    Serial.begin(9600);
    pinMode(LEDPin, OUTPUT);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println(WiFi.localIP());
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "<p>Hello World!</p>");
    });
    server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "<p>Some HTML!</p>");
    });
    server.begin();
}

void loop(){
    digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);
    digitalWrite(LEDPin, LOW);    // turn the LED off by making the voltage LOW
    delay(200);
    digitalWrite(LEDPin, HIGH);
    delay(200);
    digitalWrite(LEDPin, LOW);
    delay(1000);
}
