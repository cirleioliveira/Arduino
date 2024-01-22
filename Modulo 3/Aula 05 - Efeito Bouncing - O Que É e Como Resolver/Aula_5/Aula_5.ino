#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDVd 8

#define pinBotao1 7
#define pinBotao2 6
#define pinBotao3 5

#define tempoDebounce 40

byte contador = 0;
bool estadoBotao1Ant = HIGH;
bool estadoBotao2Ant = HIGH;
bool estadoBotao3Ant = HIGH;

unsigned long debounceBotao1;
unsigned long debounceBotao2;

void setup() {
  pinMode(pinLEDVm, OUTPUT);
  pinMode(pinLEDAm, OUTPUT);
  pinMode(pinLEDVd, OUTPUT);

  pinMode(pinBotao1, INPUT_PULLUP);
  pinMode(pinBotao2, INPUT_PULLUP);
  pinMode(pinBotao3, INPUT_PULLUP);
  
}

void loop() {

  bool estadoBotao1 = digitalRead(pinBotao1);
  bool estadoBotao2 = digitalRead(pinBotao2);
  bool estadoBotao3 = digitalRead(pinBotao3);



  //Controle do estado dos botões
  if( (millis() - debounceBotao1) > tempoDebounce) {
    if (!estadoBotao1 && estadoBotao1Ant ) {
      contador++;
      debounceBotao1 = millis();
    }
  }

  if( (millis() - debounceBotao2) > tempoDebounce ) {
    if (!estadoBotao2 && estadoBotao2Ant ) {
      contador--;
      debounceBotao2 = millis();
    }
  }
 
  if (!estadoBotao3 && estadoBotao3Ant) contador = 0;
  
  if (contador >= 5){
    digitalWrite(pinLEDVm, HIGH);
  } else {
    digitalWrite(pinLEDVm, LOW);
  }

  if (contador >= 10){
    digitalWrite(pinLEDAm, HIGH);
  } else {
    digitalWrite(pinLEDAm, LOW);
  }

  if (contador >= 15){
    digitalWrite(pinLEDVd, HIGH);
  } else {
    digitalWrite(pinLEDVd, LOW);
  }

  estadoBotao1Ant = estadoBotao1;
  estadoBotao2Ant = estadoBotao2;
  
}
