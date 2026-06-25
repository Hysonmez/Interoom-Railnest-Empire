#include <WiFi.h>

const char* ssid = "SSid";
const char* password = "Password";

unsigned long lastTry = 0;
const long retryInterval = 5000; 

void connectWiFi() {
  Serial.println("WiFi baglaniyor...");
  WiFi.disconnect();
  WiFi.begin(ssid, password);
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  connectWiFi();
}

void loop() {

  if (WiFi.status() != WL_CONNECTED) {

    if (millis() - lastTry > retryInterval) {
      lastTry = millis();
      Serial.println("Trying again...");
      connectWiFi();
    }

  } else {

    static unsigned long lastPrint = 0;

    if (millis() - lastPrint > 3000) {
      lastPrint = millis();
      Serial.print("Connected. IP: ");
      Serial.println(WiFi.localIP());
    }
  }
}