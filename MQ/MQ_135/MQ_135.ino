//Delare pins for analog and digital values
int mq_analog_pin = 34;
int mq_digital_pin = 14;

void setup() {
  Serial.begin(115200);
  pinMode(mq_digital_pin, INPUT);  //Setting pin to input mode
}

void loop() {
  //Reading analog and digital values and displaying on Serial monitor
  int analogValue = analogRead(mq_analog_pin);
  int digitalValue = digitalRead(mq_digital_pin);

  Serial.print("Analog Value: ");
  Serial.print(analogValue);

  Serial.print(" | Digital Value: ");
  Serial.println(digitalValue == LOW ? "Gas Detected" : "Clean");

  delay(1000);
}
