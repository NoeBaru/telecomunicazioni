#include <Wire.h>
//MASTER

const int buttonPin = 2;  // Pin del pulsante

void setup() {
  Wire.begin();           // Inizia la comunicazione I2C
  pinMode(buttonPin, INPUT_PULLUP);  // Imposta il pin del pulsante come input con pull-up
  Serial.begin(9600);     // Inizia la comunicazione seriale
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Leggi lo stato del pulsante

  // Invia lo stato del pulsante all'Arduino slave tramite I2C
  Wire.beginTransmission(8); // Indirizzo del dispositivo slave
  Wire.write(buttonState);   // Invia lo stato del pulsante
  Wire.endTransmission();    // Fine della trasmissione

  delay(100);  // Breve ritardo
}
