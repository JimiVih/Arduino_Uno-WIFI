#include <dht.h>

dht DHT;

#define DHT11_PIN 2

unsigned long startTime;
unsigned long duration = 15000;

void setup(){
  Serial.begin(9600);
  startTime = millis();
  
}

void loop(){

   unsigned long currentTime = millis();

   if(currentTime - startTime >= duration) {
     Serial.print("Good Bye");
     delay(3000);
     exit(0);
   }
  //checks if the temp is over 24 celsius
   if(DHT.temperature > 24){
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("Is warm");
   }
  //checks if the temp is between 22 and 24 celsius
   if(DHT.temperature >= 22 && DHT.temperature <= 24){
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("Just good");
   }
  //checks if the temp is below 22 celsius
   if(DHT.temperature < 22){
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("Is cold");
   }

    int chk = DHT.read11(DHT11_PIN);
    
    Serial.println("");
    Serial.println("");
    Serial.println("");
    delay(2000);

}

