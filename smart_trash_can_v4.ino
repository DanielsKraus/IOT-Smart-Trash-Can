#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"
 
#define WIFI_SSID "yournetwork"
#define WIFI_PASS "youpassword"
#define SERIAL_BAUDRATE 115200

#define open_btn 2
#define close_btn 3
 
fauxmoESP fauxmo;
 
// -----------------------------------------------------------------------------
// Wifi
// -----------------------------------------------------------------------------
void open_trash()
{
  Serial.println("OPEN");
  digitalWrite(open_btn,HIGH);
  delay(500);
  digitalWrite(open_btn,LOW);
}
void close_trash()
{
  Serial.println("CLOSE");
  digitalWrite(close_btn,HIGH);
  delay(500);
  digitalWrite(close_btn,LOW);
}
void wifiSetup() {
 
    // Set WIFI module to STA mode
    WiFi.mode(WIFI_STA);
 
    // Connect
    Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
 
    // Wait
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();
 
    // Connected!
    Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}
 
void setup() {
  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(open_btn, OUTPUT);
  pinMode(close_btn, OUTPUT);
  // Ask Alexa
  Serial.println("ask Alexa, to turn on trash can or off");
 
  // wifi
  wifiSetup();
 
  // Fauxmo
  fauxmo.addDevice("trash can");
  // Gen3 Devices or above
  fauxmo.setPort(80);
 
  // Allow the FauxMo to be discovered
  fauxmo.enable(true);
  
  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    Serial.print("Device: ");Serial.print(device_name);
    Serial.print("  state: ");
    if(state)
      open_trash();
    else
      close_trash();
  }); 
}
 
void loop() {
  fauxmo.handle();
}
