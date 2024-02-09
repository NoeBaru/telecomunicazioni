#include <Wire.h>
//MASTER
//master che comunica con lo slave. Due Arduini insieme

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.requestFrom(7, 2); //indirizzo associato allo Slave
  while(Wire.available()){
    char c = Wire.read();
    Serial.begin(c);
  }
  Serial.println();
}
