#include "Senha.h" // biblioteca para acessar o arquivo(aba) senha.h
//String lerSensorTemp();

void loop() {
  // put your setup code here, to run once:
  //int tempo = 200;  // Variavel local
  Serial.println( lerSensorTemp() ); // impressão aba2
  Serial.println( Senha );

  delay(tempo);

}
