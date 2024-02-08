#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDVd 8

#define pinBotao 7

#define tempoDebounce 200

byte estadoLEDs = 1;
bool estadoBotaoAnt = HIGH;
unsigned long debounceBotao;

void setup() {
  pinMode(pinLEDVm, OUTPUT);
  pinMode(pinLEDAm, OUTPUT);
  pinMode(pinLEDVd, OUTPUT);

  pinMode(pinBotao, INPUT_PULLUP);
  
}

void loop() {

  bool estadoBotao = digitalRead(pinBotao);


  //Controle do estado dos botões
  if( (millis() - debounceBotao) > tempoDebounce) {
    if (!estadoBotao && estadoBotaoAnt ) {
      estadoLEDs++;

      if (estadoLEDs > 3 ){
          estadoLEDs = 1;
      }
      debounceBotao = millis();
    }
  }

  switch (estadoLEDs) {
    case 1: {
      //Efeito 1
      digitalWrite(pinLEDVm, HIGH);
      digitalWrite(pinLEDAm, LOW);
      digitalWrite(pinLEDVd, LOW);
      delay(100);
      digitalWrite(pinLEDVm, LOW);
      digitalWrite(pinLEDAm, HIGH);
      digitalWrite(pinLEDVd, LOW);
      delay(100);
      digitalWrite(pinLEDVm, LOW);
      digitalWrite(pinLEDAm, LOW);
      digitalWrite(pinLEDVd, HIGH);
      delay(100);
      break;
      
    }
     case 2: {
      //Efeito 2
      digitalWrite(pinLEDVm, LOW);
      digitalWrite(pinLEDAm, LOW);
      digitalWrite(pinLEDVd, LOW);
      delay(100);
      digitalWrite(pinLEDVm, HIGH);
      digitalWrite(pinLEDAm, HIGH);
      digitalWrite(pinLEDVd, HIGH);
      delay(100);
      break;
      
    }

    default: {
      digitalWrite(pinLEDVm, HIGH);
      digitalWrite(pinLEDAm, HIGH);
      digitalWrite(pinLEDVd, HIGH);
    }
  }
  
  estadoBotaoAnt = estadoBotao;  
}
