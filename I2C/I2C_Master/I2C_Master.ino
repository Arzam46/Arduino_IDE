#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED width, in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels
#define OLED_RESET    -1  // Reset pin
#define I2C_SLAVE_ADDR 0x08  // I2C address of the slave

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(115200);
    Wire.begin();  // Initialize I2C as master

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println("SSD1306 allocation failed");
        for (;;); // Loop forever if OLED is not found
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("I2C Master Ready");
    display.display();
    delay(2000);
}

void loop() {
    Wire.requestFrom(I2C_SLAVE_ADDR, 3);  // Request 3 bytes from slave

    if (Wire.available() >= 3) {
        int irState = Wire.read();  // Read IR sensor state
        int highByteVal = Wire.read();  // Read high byte of MQ135
        int lowByteVal = Wire.read();   // Read low byte of MQ135

        int mq135Value = (highByteVal << 8) | lowByteVal;  // Reconstruct MQ135 value

        // Serial Monitor Debugging
        Serial.print("IR Sensor: ");
        Serial.println(irState ? "No Object" : "Object Detected");

        Serial.print("MQ135 Sensor Value: ");
        Serial.println(mq135Value);

        // Update OLED Display
        display.clearDisplay();
        display.setCursor(0, 10);
        display.setTextSize(1);
        display.print("IR: ");
        display.println(irState ? "No Obj" : "Detected");

        display.setCursor(0, 40);
        display.setTextSize(1);
        display.print("MQ135: ");
        display.println(mq135Value);

        display.display();
    }

    delay(500);  // Request data every 500ms
}
