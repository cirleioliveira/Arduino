#include "PiscaLED.h"

#define pinLEDVm 10
#define pinLEDAm 9
#define pinLEDAz 8

#define pinBotao1 7
#define pinBotao2 6


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
