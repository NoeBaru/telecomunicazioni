const int PIN_1 = 13;
const int PIN_0 = 12;
const int PIN_ENB = 3;
const int PIN_SEL = 2;

int Q1 = 0, Q0 = 0;
int ENB, SEL;
int D1, D0;
void setup()
{
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_0, OUTPUT);
  pinMode(PIN_ENB, INPUT);
  pinMode(PIN_SEL, INPUT);
}

void loop()
{
  digitalWrite(PIN_1, !Q1);
  digitalWrite(PIN_0, !Q0);
  ENB = digitalRead(PIN_ENB);
  SEL = digitalRead(PIN_SEL);
  
  D1 = (!Q1*!Q0*ENB*!SEL)+(!Q1*Q0*ENB*SEL)+(Q1*Q0*!SEL)+(Q1*!Q0*SEL)+(Q1*!ENB);
  D0 = (Q0*!ENB)+(!Q0*ENB);
  
  Q1 = D1;
  Q0 = D0;
    
  delay(1000);
}