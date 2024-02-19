#define pinAlexaLuz    9
#define pinAlexaTomada 8

#define pinReleLuz    3
#define pinReleTomada 2


void setup() {
  pinMode(pinAlexaLuz, INPUT);
  pinMode(pinAlexaTomada, INPUT);

  pinMode(pinReleLuz, OUTPUT);
  pinMode(pinReleTomada, OUTPUT);
}

void loop() {
  digitalWrite(pinReleLuz,    digitalRead(pinAlexaLuz));
  digitalWrite(pinReleTomada, digitalRead(pinAlexaTomada));
}
