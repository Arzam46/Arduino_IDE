//Declare analog pins
int ir1 = A0;
int ir2 = A1;
int ir3 = A2;
int ir4 = A3;
int ir5 = A5;
void setup() {
  Serial.begin(9600);
  //Set pin mode to read data
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}
void loop() {
  //Reading analog value and displaying data on serial monitor
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  int d = analogRead(A3);
  int e = analogRead(A4);
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  Serial.println(e);
  delay(1000);
}