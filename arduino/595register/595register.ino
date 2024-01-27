int SER = 8;
int Rclk = 9;
int SRclk = 10;
byte dato = 0;

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(Rclk, OUTPUT);
  pinMode(SRclk, OUTPUT);
}

void loop()
{
  aggiornamentoShiftRegister();
  delay(500);
  for(int cont = 0; cont < 8; cont++){
    bitSet(dato, cont);
    aggiornamentoShiftRegister();
    delay(500);
  }
}
  
 void aggiornamentoShiftRegister(){
    digitalWrite(Rclk, LOW);
    shiftOut(SER, SRclk, MSBFIRST, dato);
    digitalWrite(Rclk, HIGH);
  }
