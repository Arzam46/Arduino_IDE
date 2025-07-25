#include <RF24.h>      //Library for interfacing with NRF24L01 modules
#include <SPI.h>       //Library for Serial Peripheral Interface communication
#include <nRF24L01.h>  //Library for NRF24L01 module containing specific definitions for NRF24L01 module

RF24 radio(4, 2);                //Object for class RF24 and the parameters are CE(Chip Enable) and CSN(Chip Select Not)
const byte address[] = "node1";  //Address for radio communication
bool buttonCheck = 0;            //Declaring variable that stores current state of button
bool lastButtonState = 0;        //Declaring variable that stores previous state of button
int button = 5;                 //Declaring pin no for button

void setup() {
  Serial.begin(9600);
  radio.begin();                   //RF24 initialization
  radio.openWritingPipe(address);  //Configure module to send data to the specified adress
  radio.setPALevel(RF24_PA_MIN);   //Set amplifier level to minimum
  radio.stopListening();           //Configure the module to send data instead of receiving data,Setting module to tansmitt mode
  pinMode(button, INPUT_PULLUP);   //Setting pinmode for button and using internal pull-up resistor
}

void loop() {
  buttonCheck = !digitalRead(button);                //Reading value from button and inverting it because internal pull-up resistor is used so if button is pressed it will read LOW and if released it will read HIGH
  if (buttonCheck != lastButtonState) {              //Decision making
    radio.write(&buttonCheck, sizeof(buttonCheck));  //Sends the "buttonCheck" value over RF24, Sending button state over RF24
    Serial.print("Button state sent: ");             //Printing on serial monitor
    Serial.println(buttonCheck);                     //Printing on serial monitor
    lastButtonState = buttonCheck;                   //Update the value of "lastButtonState" with the value of "buttonCheck"
  }
  delay(10);  //Delay
}
