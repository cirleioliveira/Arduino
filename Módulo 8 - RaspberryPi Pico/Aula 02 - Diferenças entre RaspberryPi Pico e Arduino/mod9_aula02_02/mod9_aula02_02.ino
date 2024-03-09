/*
  Author  - Curso De Arduino 2.0
  Link    - https://cursodearduino.net/
  Aula    - Diferenças Pico e Arduino
  Sketch  - Exemplo 02 PullDown
*/

void setup() {
  pinMode(2, INPUT_PULLDOWN);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (digitalRead(2)) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(200);

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(200);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
