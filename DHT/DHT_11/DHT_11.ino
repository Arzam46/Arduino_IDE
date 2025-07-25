#include <DHT.h>  //Library for DHT11

#define DHTPIN 27      //Defining pin number for DHT
#define DHTTYPE DHT11  //Defining type of DHT

DHT dht(DHTPIN, DHTTYPE);  //Object for class DHT

TaskHandle_t Task;  //Task handler

void setup() {
  Serial.begin(9600);
  dht.begin();  //DHT initialization
}


void loop() {
  float temp = dht.readTemperature();  //Read temperature from DHT11
  Serial.print("Temp:");               //Printing on serial monitor
  Serial.print(temp);                  //Printing on serial monitor
  Serial.println(" C");                //Printing on serial monitor
  float humid = dht.readHumidity();    //Read h8umidity from DHT11
  Serial.print("Humid:");              //Printing on serial monitor
  Serial.print(humid);                 //Printing on serial monitor
  Serial.println(" %");                //Printing on serial monitor
  vTaskDelay(1000);                    //Delay
}
}