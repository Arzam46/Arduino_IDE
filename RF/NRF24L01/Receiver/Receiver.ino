#include <RF24.h>      //Library for interfacing with NRF24L01 modules
#include <SPI.h>       //Library for Serial Peripheral Interface communication
#include <nRF24L01.h>  //Library for NRF24L01 module containing specific definitions for NRF24L01 module

RF24 radio(4, 2);                //Object for class RF24 and the parameters are CE(Chip Enable) and CSN(Chip Select Not)
const byte address[] = "node1";  //Address for radio communication
bool buttonState = 0;            //Declaring variable that stores state of button which will received via radio
int led = 5;                     //Setting pinmode for led

void setup() {
  Serial.begin(9600);
  radio.begin();                      //RF24 initialization
  radio.openReadingPipe(0, address);  //Configure module to receive data on pipe 0 on the address
  radio.setPALevel(RF24_PA_MIN);      //Set amplifier level to minimum
  radio.startListening();             //Configure the module to receive data instead of sending data,Setting module to receiver mode
  pinMode(led, OUTPUT);               //Setting pinmode for Led
}

void loop() {
  if (radio.available()) {                          //Decision making
    radio.read(&buttonState, sizeof(buttonState));  //Receives the "buttonState" value over RF24,Receive button state over RF24
    digitalWrite(led, buttonState);                 //Set the Led state according to the value of "buttonState"
    Serial.print("LED state: ");                    //Printing on serial monitor
    Serial.println(buttonState);                    //Printing on serial monitor
  }
  delay(10);  //Delay
}
