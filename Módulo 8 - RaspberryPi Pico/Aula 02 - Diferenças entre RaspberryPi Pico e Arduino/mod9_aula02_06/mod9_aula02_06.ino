/*
  Author  - Curso De Arduino 2.0
  Link    - https://cursodearduino.net/
  Aula    - Diferenças Pico e Arduino
  Sketch  - Exemplo 06 PWM
*/

void setup() {
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  analogReadResolution(12);
}

void loop() {
  int valPot = analogRead(28);
  int brilho = map(valPot, 0, 4095, 0, 255);
  Serial.println(valPot);

  analogWrite(4, brilho);
  analogWrite(5, LOW);
  delay(200);

  analogWrite(4, LOW);
  analogWrite(5, brilho);
  delay(200);
}
