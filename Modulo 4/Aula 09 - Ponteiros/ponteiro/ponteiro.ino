String msg;

void setup() {
  
  int *p;
  int i = 5;
  int result = 0;

  result = i;
  p = &i;
  result = *p;

  Serial.begin(9600);
  Serial.print(result);

  msg = "Isso e um teste de texto";

}

void loop() {
 
  msg = millis();

  mostraValor(&msg);

}

void mostraValor(String *texto){
  Serial.println(*texto);
}
