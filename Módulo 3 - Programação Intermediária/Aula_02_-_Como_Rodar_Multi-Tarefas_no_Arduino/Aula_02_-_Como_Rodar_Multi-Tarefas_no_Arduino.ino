void setup() {
  pinMode( 9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  loop1();
  loop2();
}

void loop1() {
  static unsigned long inicioCiclo;
  unsigned long tempoDecorrido = millis() - inicioCiclo;  

  if ( tempoDecorrido < 300) {
    digitalWrite(9, HIGH);
  }
  if ( tempoDecorrido >= 300) {
    digitalWrite(9, LOW);
  }
  if ( tempoDecorrido > 700) {
    inicioCiclo = millis();
  }
  
}

void loop2(){
  static unsigned long inicioCiclo;
  unsigned long tempoDecorrido = millis() - inicioCiclo;
  
  if ( tempoDecorrido < 1000) {
    digitalWrite(10, HIGH);
  }
  if ( tempoDecorrido >= 1000) {
    digitalWrite(10, LOW);
  }
  if ( tempoDecorrido > 3500) {
    inicioCiclo = millis();
  }
}
