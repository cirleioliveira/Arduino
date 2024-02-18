#define pinBotao1 7
#define pinBotao2 6
#define pinBotao3 5

#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDAz 8

byte contador = 0;

// ------------- DECLARAÇAO DA CLASSE ------------------------

class PushButton {
  public:
    PushButton(byte pinBotao, int tempoDebounce = 200);
    void button_loop();
    bool pressed();
  private:
    unsigned long debounceBotao;
    bool estadoBotaoAnt = HIGH;
    bool apertado = false;
    byte pino;
    int tempo;
};

// ------------- INICIO DO IMPLEMENTO DA CLASSE ------------------------ 

PushButton::PushButton(byte pinBotao, int tempoDebounce = 200) {
  pinMode(pinBotao, INPUT_PULLUP);
  pino = pinBotao;
  tempo = tempoDebounce;  
}

void PushButton::button_loop() {
  bool estadoBotao = digitalRead(pino);
  apertado = false;
  if ( (millis() - debounceBotao) > tempo ) {
    if(!estadoBotao && estadoBotaoAnt) {
      apertado = true;
      debounceBotao = millis();
    }
  }
  estadoBotaoAnt = estadoBotao;
}

bool PushButton::pressed() {
  return apertado;
}
// ------------- FIM DO IMPLEMENTO DA CLASSE ------------------------ 

PushButton botao1(pinBotao1);
PushButton botao2(pinBotao2);
PushButton botao3(pinBotao3);

void setup() {
  pinMode(pinLEDVm,  OUTPUT);
  pinMode(pinLEDAm,  OUTPUT);
  pinMode(pinLEDAz,  OUTPUT);
  
}

void loop() {
  botao1.button_loop();
  botao2.button_loop();
  botao3.button_loop();

  if (botao1.pressed()) {
    contador++;
  }

  if (botao2.pressed()) {
    contador--;
  }

  if (botao3.pressed()) {
    contador = 0;
  }

  if (contador >= 5) {
    digitalWrite(pinLEDVm, HIGH);
  }else {
    digitalWrite(pinLEDVm, LOW);
  }

  if (contador >= 10) {
    digitalWrite(pinLEDAm, HIGH);
  }else {
    digitalWrite(pinLEDAm, LOW);
  }

  if (contador >= 15) {
    digitalWrite(pinLEDAz, HIGH);
  }else {
    digitalWrite(pinLEDAz, LOW);
  }
}
