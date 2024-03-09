/*
  Author  - Curso De Arduino 2.0
  Link    - https://cursodearduino.net/
  Aula    - Diferenças Pico e Arduino
  Sketch  - Exemplo 03 analogRead
*/

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(analogRead(28));

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(analogRead(28));
}
