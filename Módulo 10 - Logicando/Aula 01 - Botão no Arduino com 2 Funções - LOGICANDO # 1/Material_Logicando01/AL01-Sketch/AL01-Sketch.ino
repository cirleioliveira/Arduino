#define pinBotao 2
#define pinLEDAZ 12
#define pinLEDVD 11
#define pinLEDVM 10

#define TEMPO_APERTO_LONGO 1200

byte estadoBotao = 0;  //0=standby  1=contando
byte acaoBotao = 0;    //0=standby  1=aperto  2=apertoLongo

byte estadoLED = 1;    //1=AZUL  2=VERDE  3=VERMELHO
byte estadoPISCA = 1;  //1=ACESO 2=PISCA

unsigned long tempoBotao;
unsigned long tempoDebounce;
byte debounce = 0;

void setup() {
  pinMode(pinLEDAZ, OUTPUT);
  pinMode(pinLEDVD, OUTPUT);
  pinMode(pinLEDVM, OUTPUT);
  pinMode(pinBotao, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinBotao), funcBotao, FALLING);

  Serial.begin(9600);
}

void loop() {

  if (estadoBotao == 0) {  
    if (acaoBotao == 1) { //Aperto Normal
       acaoBotao = 0;
       Serial.println("Aperto Normal");
       estadoLED++;
       if (estadoLED > 3) estadoLED = 1;
    }

    if (acaoBotao == 2) { //Aperto Longo
       acaoBotao = 0;
       Serial.println("Aperto Longo");
       estadoPISCA++;
       if (estadoPISCA > 2) estadoPISCA = 1;
    }
  }  

  //-------- CONTROLE DOS ESTADOS -----------
  bool nivelLEDAceso;
  if (estadoPISCA == 1) {
     nivelLEDAceso = HIGH;
  } else {
     nivelLEDAceso = bitRead(millis(),6);
  }

     
  switch (estadoLED) {
     case 1:   //AZUL
       digitalWrite(pinLEDAZ, nivelLEDAceso);
       digitalWrite(pinLEDVD, LOW);
       digitalWrite(pinLEDVM, LOW);
       break;

     case 2:   //VERDE
       digitalWrite(pinLEDAZ, LOW);
       digitalWrite(pinLEDVD, nivelLEDAceso);
       digitalWrite(pinLEDVM, LOW);
       break;

      case 3:   //VERMELHO
       digitalWrite(pinLEDAZ, LOW);
       digitalWrite(pinLEDVD, LOW);
       digitalWrite(pinLEDVM, nivelLEDAceso);
       break;
  }
  
  //-------- INICIO CONTROLE BOTAO ----------- 
  if (estadoBotao == 1) {  
     if ((millis() - tempoBotao) > TEMPO_APERTO_LONGO) {
        estadoBotao = 0;
        acaoBotao = 2;
        detachInterrupt(digitalPinToInterrupt(pinBotao));
        debounce = 1;
     }
  }

  if ((debounce == 1) && digitalRead(pinBotao)) { //Botao Solto
     tempoBotao = millis();
     debounce = 2;
  }

  if (debounce == 2) { //Após tempo de debounce
     if ((millis() - tempoBotao) > 100) {
        debounce = 0;
        attachInterrupt(digitalPinToInterrupt(pinBotao), funcBotao, CHANGE);
     }
  }
}

void funcBotao() {
  if ((estadoBotao == 0) && !digitalRead(pinBotao)) {  //Botao Apertado
     estadoBotao = 1;
     tempoBotao = millis();
     tempoDebounce = millis();
  }

  if ((estadoBotao == 1) && digitalRead(pinBotao)) {  //Botao Solto
     if ((millis() - tempoDebounce) > 20) {
        estadoBotao = 0;
        acaoBotao = 1;
     }
  }
}
