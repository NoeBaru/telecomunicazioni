const int PIN_1 = 13;
const int PIN_0 = 12;

int Q1 = 0, Q0 = 0;
int D1, D0;
void setup()
{
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_0, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_1, Q1);
  digitalWrite(PIN_0, Q0);
  
  D1 = (!Q1*Q0)+(Q1*!Q0);
  D0 = !Q0;
  
  Q1 = D1;
  Q0 = D0;
    
  delay(1000);
}