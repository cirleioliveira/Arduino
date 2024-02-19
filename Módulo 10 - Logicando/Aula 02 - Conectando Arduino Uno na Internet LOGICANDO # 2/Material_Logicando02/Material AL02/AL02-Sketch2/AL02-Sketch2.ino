#define pinAlexaLuz    9
#define pinAlexaTomada 8

#define pinReleLuz    3
#define pinReleTomada 2

bool estadoAlarme = LOW;
bool estadoAlarmeAnt = LOW;

void setup() {
  pinMode(pinAlexaLuz, INPUT);
  pinMode(pinAlexaTomada, INPUT);

  pinMode(pinReleLuz, OUTPUT);
  pinMode(pinReleTomada, OUTPUT);
}

void loop() {

  estadoAlarme = digitalRead(pinAlexaLuz);

  if (estadoAlarme && !estadoAlarmeAnt) {
     digitalWrite(pinReleLuz, HIGH);
     delay(2000);
     digitalWrite(pinReleLuz, LOW);
  } 

  if (!estadoAlarme && estadoAlarmeAnt) {
     digitalWrite(pinReleLuz, HIGH);
     delay(500);
     digitalWrite(pinReleLuz, LOW);
  } 
  
  digitalWrite(pinReleTomada, digitalRead(pinAlexaTomada));

  estadoAlarmeAnt = estadoAlarme;
}
