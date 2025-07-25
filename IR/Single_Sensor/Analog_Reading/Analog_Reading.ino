int ir = A0;  //Declaring pin no for ir sensor
int led = 4;  //Declaring pin no for led
int var;      //Global variable

int limit = 200;  //Global variable

void setup() {
  Serial.begin(9600);

  pinMode(A0, INPUT);    //Setting pinmode for ir sensor
  pinMode(led, OUTPUT);  //Setting pinmode for led
}
void loop() {
  var = analogRead(ir);  //Reading analog value from ir sensor

  if (var < limit) {                        //Decision making
    digitalWrite(led, HIGH);                //Led on
    Serial.println("Object detected");      //Printing on serial monitor
  } else {                                  //Decision making
    digitalWrite(led, LOW);                 //Led off
    Serial.println("Object not detected");  //Printing on serial monitor
  }
  delay(500);  //Delay
}