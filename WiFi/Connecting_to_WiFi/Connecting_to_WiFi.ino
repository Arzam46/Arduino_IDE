#include <WiFi.h>

const char* ssid = "********";       // your mobile hotspot name
const char* password = "********";   // your mobile hotspot password

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  int retry = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retry++;
    if (retry > 20) {
      Serial.println("\nFailed to connect.");
      return;
    }
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // nothing here
}
