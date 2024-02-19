#ifndef PiscaLED_h
#define PiscaLED_h

#include "Arduino.h"

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

#endif