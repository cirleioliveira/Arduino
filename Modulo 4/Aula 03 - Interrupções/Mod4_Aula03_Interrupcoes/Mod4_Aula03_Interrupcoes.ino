#define pinBotao1 2
#define pinBotao2 3

byte portas[] = {4,5,6,7,8,9,10,11,12,13};
int tempo = 500;
unsigned long delayDebounce;

void setup() {
  
  for (byte nL = 0; nL < 10; nL++) {
    pinMode(portas[nL], OUTPUT);
  }

  pinMode(pinBotao1, INPUT_PULLUP);
  pinMode(pinBotao2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pinBotao1), rotina1, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinBotao2), rotina2, FALLING);

  Serial.begin(9600);
}

void loop() {
  
  for (byte nL = 0; nL < 10; nL++) {
    digitalWrite(portas[nL], HIGH);
    delay(tempo);
    digitalWrite(portas[nL], LOW);
    Serial.println(tempo);
  }
}

void rotina1() {
  
  if ( (millis() - delayDebounce) > 100) {
    
    tempo = tempo - 50;
    if (tempo < 1) {
      tempo = 1;
    }

    delayDebounce = millis();
  }
}

void rotina2() {

  if ( (millis() - delayDebounce) > 100) {

    tempo = tempo + 50;

    delayDebounce = millis();
  }
}