// Dichiarazione delle costanti per i pin utilizzati
int SER = 8;     // Pin del pin di serie per il shift register
int Rclk = 9;    // Pin del clock del registro di spostamento
int SRclk = 10;  // Pin del clock di serie del registro di spostamento
byte dato = 0;   // Variabile per memorizzare il dato da inviare al registro di spostamento

void setup()
{
  // Impostazione dei pin come output
  pinMode(SER, OUTPUT);
  pinMode(Rclk, OUTPUT);
  pinMode(SRclk, OUTPUT);
}

void loop()
{
  // Chiamata alla funzione per aggiornare il registro di spostamento
  aggiornamentoShiftRegister();
  
  // Attendi 500 millisecondi
  delay(500);
  
  // Ciclo per impostare bit uno alla volta e aggiornare il registro di spostamento
  for(int cont = 0; cont < 8; cont++){
    bitSet(dato, cont);  // Imposta il bit corrente nella variabile "dato"
    aggiornamentoShiftRegister();  // Chiamata alla funzione per aggiornare il registro di spostamento
    delay(500);  // Attendi 500 millisecondi
  }
}

// Funzione per aggiornare il registro di spostamento
void aggiornamentoShiftRegister(){
  digitalWrite(Rclk, LOW);  // Imposta il pin di clock del registro di spostamento a basso
  shiftOut(SER, SRclk, LSBFIRST, dato);  // Invia il dato al registro di spostamento
  digitalWrite(Rclk, HIGH);  // Imposta il pin di clock del registro di spostamento ad alto per memorizzare il dato
}
