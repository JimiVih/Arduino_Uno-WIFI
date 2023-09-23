#include <dht.h>

dht DHT;

#define DHT11_PIN 2

unsigned long startTime;
unsigned long duration = 5000;

void setup(){
  Serial.begin(9600);
  startTime = millis();
}

void loop(){

   unsigned long currentTime = millis();

   if(currentTime - startTime >= duration) {
     Serial.print("Good Bye");
     exit(3);
   }

    int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    delay(1000);

}

