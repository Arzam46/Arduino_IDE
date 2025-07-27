//Including library
#include <TinyGPS++.h>

TinyGPSPlus gps;  //Object for class TinyGPSPlus

HardwareSerial gpsSerial(1);  //Using UART 1,as UART 0 is communicating with PC

void setup() {
  Serial.begin(9600);
  //Start GPS Serial on UART 1
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);  //9600 is baudrate,SERIAL_8N1 is8 data bits, No parity, 1 stop bit,16 is RX pin,17 is Tx pin
  Serial.println("GPS Initialized!!!");
}

void loop() {
  // Read characters from GPS module
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    Serial.write(c);  //Print raw GPS NMEA sentences for debugging
    gps.encode(c);    //Feed to TinyGPS++ parse

    // Check if a valid GPS location is available and print data on Serial monitor
    if (gps.location.isUpdated()) {
      Serial.println();
      Serial.println("Location Data Received:");
      Serial.print("  Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("  Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("  Altitude: ");
      Serial.print(gps.altitude.meters());
      Serial.println(" m");
      Serial.print("  Speed: ");
      Serial.print(gps.speed.kmph());
      Serial.println(" km/h");
      Serial.print("  Satellites: ");
      Serial.println(gps.satellites.value());
      Serial.print("  Time: ");
      Serial.print(gps.time.hour());
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());
      Serial.println("-----------------------------");
    }
  }
}