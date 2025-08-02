//Declaring pin
#define TRIG_PIN 16
#define ECHO_PIN 18

void setup() {
  Serial.begin(115200);
  //Setting pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration;
  float distance_cm;

  // Send 10 microsecond pulse to TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo duration
  duration = pulseIn(ECHO_PIN, HIGH, 25000);  // in microseconds

  // If no echo received, pulseIn returns 0
  if (duration == 0) {
    Serial.println("Out of range");
  } else {
    // Distance calculation
    distance_cm = (duration * 0.0343) / 2;
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
  }

  delay(1000);  // Wait 1 second between measurements
}
