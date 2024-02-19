#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDAz 8

#define pinBotao1 7
#define pinBotao2 6

//int estadoPisca

//******************************************************************************

class PiscaLed {
  public:
    PiscaLed(byte pinLED, int tempoPisca = 1000);
    void play();
    void stop();
    void loop();
  private:
    unsigned long delayPisca;
    bool estadoPisca = HIGH;
    byte pino;
    int tempo;
};

PiscaLed::PiscaLed(byte pinLED, int tempoPisca) {
  pinMode(pinLED, OUTPUT);
  pino = pinLED;
  tempo = tempoPisca;
  estadoPisca = false;
}

void PiscaLed::play() {
  estadoPisca = true;
  delayPisca = millis();
}

void PiscaLed::stop() {
  estadoPisca = false;
  digitalWrite(pino, LOW);
}

void PiscaLed::loop() {
  if (estadoPisca) {
    if ((millis() - delayPisca) < tempo ) {
      digitalWrite(pino, LOW);
    }else if ((millis() - delayPisca) < (tempo * 2) ) {
      digitalWrite(pino, LOW);
    }else {
      delayPisca = millis();
    }
  } else {
    digitalWrite(pino, LOW);
  }
}

//**********************************************************

PiscaLed ledVm( pinLEDVm, 1000);
PiscaLed ledAm( pinLEDAm, 200);
PiscaLed ledAz( pinLEDAz, 3000);

void setup() {
  pinMode(pinBotao1, INPUT_PULLUP);
  pinMode(pinBotao2, INPUT_PULLUP);
}

void loop() {
  ledVm.loop();
  ledAm.loop();
  ledAz.loop();

  if (!digitalRead(pinBotao1)) {
    ledVm.play();
    ledAm.play();
    ledAz.play();
  }

  if (!digitalRead(pinBotao2)) {
    ledVm.play();
    ledAm.play();
    ledAz.play();
  }

}
