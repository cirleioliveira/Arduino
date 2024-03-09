/*
  Author  - Curso De Arduino 2.0
  Link    - https://cursodearduino.net/
  Aula    - Diferenças Pico e Arduino
  Sketch  - Exemplo 05 analogReadResolution
*/

void setup() {
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  analogReadResolution(12);
}

void loop() {
  int valPot = analogRead(28);
  Serial.println(valPot);

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(valPot);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(valPot);
}
