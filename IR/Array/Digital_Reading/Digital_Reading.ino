//Declare analog pins
int ir1 = 2;
int ir2 = 3;
int ir3 = 4;
int ir4 = 5;
int ir5 = 6;

void setup() {
  Serial.begin(9600);
  //Set pin mode to read data
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  //Reading digital value and displaying data on serial monitor based on detection
  int a = digitalRead(ir1);
  int b = digitalRead(ir2);
  int c = digitalRead(ir3);
  int d = digitalRead(ir4);
  int e = digitalRead(ir5);

  if (a == LOW) {
    Serial.println("Object detected on First Sensor");
  } else if (a == HIGH) {
    Serial.println("Object not detected on First Sensor");
  }

  if (b == LOW) {
    Serial.println("Object detected on Second Sensor");
  } else if (b == HIGH) {
    Serial.println("Object not detected on Second Sensor");
  }

  if (c == LOW) {
    Serial.println("Object detected on Third Sensor");
  } else if (c == HIGH) {
    Serial.println("Object not detected on Third Sensor");
  }

  if (d == LOW) {
    Serial.println("Object detected on Fourth Sensor");
  } else if (d == HIGH) {
    Serial.println("Object not detected on Fourth Sensor");
  }

  if (e == LOW) {
    Serial.println("Object detected on Fifth Sensor");
  } else if (e == HIGH) {
    Serial.println("Object not detected on Fifth Sensor");
  }

  delay(100);
}
