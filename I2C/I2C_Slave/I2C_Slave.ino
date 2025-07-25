#include <Wire.h>

#define I2C_SLAVE_ADDR  0x08  // I2C address of the slave
#define IR_SENSOR_PIN   4     // IR sensor connected to GPIO 4
#define MQ135_SENSOR_PIN 34   // MQ135 sensor connected to ADC pin GPIO 34

void setup() {
    Wire.begin(I2C_SLAVE_ADDR);  // Start I2C as a slave
    Wire.onRequest(sendData);    // Set function to send data to master
    pinMode(IR_SENSOR_PIN, INPUT);
}

void loop() {
    // Nothing here, only responding to master requests
}

void sendData() {
    int irState = digitalRead(IR_SENSOR_PIN);   // Read IR sensor (0 = object detected, 1 = no object)
    int mq135Value = analogRead(MQ135_SENSOR_PIN); // Read MQ135 sensor (0-4095 for ESP32 ADC)

    Wire.write(irState);                     // Send 1 byte for IR sensor
    Wire.write(highByte(mq135Value));        // Send high byte of MQ135 sensor value
    Wire.write(lowByte(mq135Value));         // Send low byte of MQ135 sensor value
}
