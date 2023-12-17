#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDVd 8

#define pinBotao1 7
#define pinBotao2 6
#define pinBotao3 5

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
  byte estadoLEDs;
  if (!estadoBotao1) estadoLEDs = 1;
  if (!estadoBotao2) estadoLEDs = 2;
  if (!estadoBotao3) estadoLEDs = 3;
  if ( (estadoBotao1 && estadoBotao2) && estadoBotao3 ) estadoLEDs = 4;
  

  if (estadoLEDs == 1){
      // efeito 1
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
      
  } else if(estadoLEDs == 2){
  // efeito 2
      digitalWrite(pinLEDVm, LOW);
      digitalWrite(pinLEDAm, LOW);
      digitalWrite(pinLEDVd, LOW);
      delay(100);
    
      digitalWrite(pinLEDVm, HIGH);
      digitalWrite(pinLEDAm, HIGH);
      digitalWrite(pinLEDVd, HIGH);
      delay(100);
      
} else if (estadoLEDs == 3){
      // efeito 3
      digitalWrite(pinLEDVm, HIGH);
      digitalWrite(pinLEDAm, HIGH);
      digitalWrite(pinLEDVd, HIGH);
      //delay(100);
      
} else {
  
      digitalWrite(pinLEDVm, LOW);
      digitalWrite(pinLEDAm, LOW);
      digitalWrite(pinLEDVd, LOW);
}
}
