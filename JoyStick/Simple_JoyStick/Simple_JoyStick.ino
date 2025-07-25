// Define joystick input pin
int joyXPin = 25;   // Joystick X-axis pin
int joyXValue = 0;  // Variable to store X-axis value
int joyYPin = 27;   // Joystick X-axis pin
int joyYValue = 0;  // Variable to store X-axis value



void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read joystick X-axis value
  joyXValue = analogRead(joyXPin);
  Serial.println(joyXValue);
  // Read joystick X-axis value
  joyYValue = analogRead(joyYPin);
  Serial.println(joyYValue);
  delay(400);
}