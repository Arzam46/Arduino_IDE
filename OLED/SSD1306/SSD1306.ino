#include <Adafruit_GFX.h>      //Library for Graphics
#include <Adafruit_SSD1306.h>  //Library for OLED
#include <Wire.h>              //Library for I2C communication

#define SCREEN_WIDTH 128  //Defining screen width
#define SCREEN_HEIGHT 64  //Defining screen height
#define OLED_RESET -1     //Defining reset pin  , Reset pin is used to initialize or reset display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  //Object for class Adafruit_SSD1306

void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0X3C);  //Initializing OLED,SSD1306_SWITCHCAPVCC is specific power configuration,0x3c is adress

  display.clearDisplay();  //Clearing display
}
void loop() {
  display.clearDisplay();  //Clearing display

  display.setTextColor(SSD1306_WHITE);  //Setting colour
  display.setCursor(0, 0);              //Setting cursor
  display.setTextSize(1);               //Setting text size
  display.print("Arzam Farooq");        //Printing on display

  delay(400);  //Delay

  display.display();       //Updating OLED,this command takes everything from buffer and send to actual OLED screen
  display.clearDisplay();  //Clearing display

  display.drawPixel(5, 20, SSD1306_WHITE);  //Drawing pixel

  delay(500);  //Delay

  display.display();       //Updating OLED,this command takes everything from buffer and send to actual OLED screen
  display.clearDisplay();  //Clearing display

  display.fillCircle(20, 20, 20, SSD1306_WHITE);  //Drawing circle

  display.display();  //Updating OLED,this command takes everything from buffer and send to actual OLED screen
}