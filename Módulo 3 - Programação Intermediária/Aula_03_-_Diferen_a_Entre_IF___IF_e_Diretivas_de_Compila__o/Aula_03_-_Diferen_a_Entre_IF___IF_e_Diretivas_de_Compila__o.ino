#define modoDebug 1
#define pinBotao  8
#define pinLED    10

void setup() {
  #if modoDebug == 1
    Serial.begin(9600);
    Serial.println("Sketch Iniciado");
  #endif

  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  if (!digitalRead(pinBotao));
    digitalWrite(pinLED, bitRead(millis(),8));

}
