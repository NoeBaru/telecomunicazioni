int pinArduino = 13;
void setup()
{
  pinMode(pinArduino, OUTPUT);
}

void loop()
{
  digitalWrite(pinArduino, HIGH);
  delay(3000); // Wait for 1000 millisecond(s)
  digitalWrite(pinArduino, LOW);
  delay(3000); // Wait for 1000 millisecond(s)
}
