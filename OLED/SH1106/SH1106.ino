#include <Adafruit_GFX.h>     //Library for Graphics
#include <Adafruit_SH110X.h>  //Library for OLED
#include <Wire.h>             //Library for I2C communication

#define SCREEN_WIDTH 128  //Defining screen width
#define SCREEN_HEIGHT 64  //Defining screen height
#define OLED_RESET -1     //Defining reset pin  , Reset pin is used to initialize or reset display
#define i2c_Address 0x3c  //Defining I2C address of an OLED

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  //Object for class Adafruit_SH1106G

void setup() {
  Serial.begin(9600);

  display.begin(i2c_Address, true);    //Initializing OLED,i2c_Address is address,This papmeter is used to inicate whether to use hardware reset which is not here so thats why true is used
  display.setTextColor(SH110X_WHITE);  //Setting colour

  display.clearDisplay();  //Clearing display
}
void loop() {
  display.clearDisplay();  //Clearing display

  display.setCursor(0, 0);        //Setting cursor
  display.setTextSize(1);         //Setting text size
  display.print("Arzam Farooq");  //Displaying text

  delay(400);  //Delay

  display.display();       //Updating OLED,this command takes everything from buffer and send to actual OLED screen
  display.clearDisplay();  //Clearing display

  delay(500);  //Delay

  display.fillCircle(64, 32, 48, SH110X_WHITE);  //Displaying circle

  delay(500);  //Delay

  display.display();       //Updating OLED,this command takes everything from buffer and send to actual OLED screen
  display.clearDisplay();  //Clearing display
  display.display();       //Updating OLED,this command takes everything from buffer and send to actual OLED screen
}