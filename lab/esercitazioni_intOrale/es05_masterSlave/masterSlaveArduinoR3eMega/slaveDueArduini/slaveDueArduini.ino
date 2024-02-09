#include <Wire.h>
//SLAVE
// slave che comunica con il master. Due Arduini isnieme

int buttonPin = 2;

void setup() {
  Wire.begin(7); //indirizzo dello Slave riportato dal Master
  Wire.onRequest(rispondi);
  pinMode(buttonPin, INPUT);
}

void loop() {
  delay(1000);
}

void rispondi(){
  if(digitalRead(buttonPin) == HIGH){
    Wire.write("si");
  } else{
    Wire.write("no");
  }
}
