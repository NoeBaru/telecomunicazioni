int clockPin = 8;
int latchPin = 9;
int dataPin = 10;

void setup() {
 pinMode(clockPin, OUTPUT);
 pinMode(latchPin, OUTPUT);
 pinMode(dataPin, OUTPUT);

 pinMode(2, OUTPUT);

 randomSeed(analogRead(A0));
}

void setBit(int n){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, n);
  digitalWrite(latchPin, HIGH);
}

void zero(){
  setBit(B00000000);
}

void one(){
  setBit(B01000000);
}

void two(){
  setBit(B00100001);
}

void three(){
  setBit(B01100001);
}

void four(){
  setBit(B00101101);
}

void five(){
  setBit(B01101101);
}

void six(){
  setBit(B00111111);
}

int n = 0;

void loop() {
  if(digitalRead(2)){
    random(1,7);
    displayDice(n);
    delay(10);
  }

}

void displayDice(int n){
  switch(n){
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
  }
}
