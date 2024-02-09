#include <Wire.h>
//SLAVE

const int ledPin = 2;  // Pin del led

void setup() {
  Wire.begin(8);                // Inizia la comunicazione I2C con indirizzo 8
  Wire.onReceive(receiveEvent); // Chiama la funzione receiveEvent quando arrivano dati
  pinMode(ledPin, OUTPUT);      // Imposta il pin del led come output
  Serial.begin(9600);           // Inizia la comunicazione seriale
}

void loop() {
  // Non fare nulla nel loop, la gestione dello stato del led avviene nella funzione receiveEvent
  delay(100);
}

// Funzione chiamata quando arrivano dati sul bus I2C
void receiveEvent(int bytes) {
  while (Wire.available()) {   // Finché ci sono dati disponibili
    int buttonState = Wire.read();  // Leggi lo stato inviato dal master

    // Se il pulsante è premuto (stato LOW), accendi il led, altrimenti spegnilo
    if (buttonState == LOW) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}
