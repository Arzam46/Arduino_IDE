int led_pin 2 void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    int state = Serial.read();
    if (state == 0) {
      digitalWrite(led_pin, LOW);
      Serial.println("Led LOW");
    } else if (state == 1) {
      digitalWrite(led_pin, HIGH);
      Serial.println("Led HIGH");
    }
    delay(1000);
  }
  delay(1000);
}
