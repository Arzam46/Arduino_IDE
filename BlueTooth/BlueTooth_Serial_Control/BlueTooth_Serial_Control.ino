#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String incomingMessage = "";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");
  Serial.println("Bluetooth started! Pair with 'ESP32_BT'");
}

void loop() {
  // Read incoming string over Bluetooth
  while (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    
    // Check for end of message (newline or carriage return)
    if (incomingChar == '\n' || incomingChar == '\r') {
      if (incomingMessage.length() > 0) {
        Serial.print("Received string: ");
        Serial.println(incomingMessage);

        // You can add logic here, for example:
        if (incomingMessage == "LED ON") {
          Serial.println("Turning LED ON...");
        }

        incomingMessage = "";  // Clear buffer for next message
      }
    } else {
      incomingMessage += incomingChar;  // Build string
    }
  }

  // Optional: Send from Serial Monitor to Bluetooth
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
}
