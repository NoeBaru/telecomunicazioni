int pulSala = 13;
int pinSala = 3;
int sala;
bool statoSala = false;

void setup()
{
  pinMode(pulSala, INPUT);
  pinMode(pinSala, OUTPUT);
}

void loop()
{
  sala = digitalRead(pulSala);
  if(sala == HIGH){
    digitalWrite(pinSala, statoSala);
    statoSala = !statoSala;}
 }
