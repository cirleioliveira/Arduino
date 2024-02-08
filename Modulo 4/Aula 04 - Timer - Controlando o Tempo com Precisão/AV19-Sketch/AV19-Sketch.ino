#define pinBotao1 3
#define pinBotao2 2

byte pinLED[] = {12,11,10,9,8,7,6,5,4,3};

#define tempoDebounce 100

int tempo = 200;
int ledAceso = 0;

unsigned long delayDebounce1;
bool estadoBotao1;
bool estadoBotao1Ant;

unsigned long delayDebounce2;
bool estadoBotao2;
bool estadoBotao2Ant;


//VARIAVEIS PARA CONTROLE DE PULSO
int tempoPulso = 50;
int intervaloPulso = 950;
unsigned long delayPulso;
 

void setup() {
  for (byte nL=0; nL<10; nL++) {
      pinMode(pinLED[nL], OUTPUT);
  }

  pinMode(pinBotao1, INPUT_PULLUP);
  pinMode(pinBotao2, INPUT_PULLUP);

  attachInterrupt( digitalPinToInterrupt(pinBotao1), funcBotao1, CHANGE);
  attachInterrupt( digitalPinToInterrupt(pinBotao2), funcBotao2, CHANGE);

  Serial.begin(9600);
}

void funcBotao1() {
  if (digitalRead(pinBotao1)) {
     delayDebounce1 = millis();
     return;
  }
  
  //CONTROLE BOTAO 1
  if ((millis() - delayDebounce1) > tempoDebounce) {
     tempo = tempo - 50;
     if (tempo < 0) {
        tempo = 0;
     }
  }
  delayDebounce1 = millis();
}

void funcBotao2() {

  if (digitalRead(pinBotao2)) {
     delayDebounce2 = millis();
     return;
  }
   
  if ((millis() - delayDebounce2) > tempoDebounce) {
     tempo = tempo + 50;
  }
  delayDebounce2 = millis();
}

void loop() {

  //CONTROLE LEDs
  digitalWrite(pinLED[ledAceso], HIGH);
  delay(tempo);
  digitalWrite(pinLED[ledAceso], LOW);

  ledAceso++;
  if (ledAceso > 4) {
     ledAceso = 0;    
  }


  //DEBUG
  Serial.println(tempo);


  //CONTROLE PULSO
  if ((millis() - delayPulso) > intervaloPulso) {
     digitalWrite(pinLED[8], HIGH);
  }
 
  if ((millis() - delayPulso) > (intervaloPulso + tempoPulso)) {
     digitalWrite(pinLED[8], LOW);
     delayPulso = millis();
  }
    
  
}
