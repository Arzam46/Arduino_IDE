#include <ESP32Servo.h>  //Library for servo motor
Servo servo;             //Object for class Servo
const int joyXPin = 2;   // Joystick X-axis pin
int joyXValue = 0;       // Variable to store X-axis value



void setup() {
  // Start serial communication
  Serial.begin(9600);

  servo.attach(5);  //Connecting servo to pin 5
  servo.write(90);  //Moving servo to an angle given in argument
}

void loop() {
  // Read joystick X-axis value
  joyXValue = analogRead(joyXPin);
  int a = map(joyXValue, 0, 4095, 0, 180);
  servo.write(a);
  delay(400);
}