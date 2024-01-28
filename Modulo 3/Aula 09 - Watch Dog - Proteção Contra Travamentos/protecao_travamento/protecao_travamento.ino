#include <avr/wdt.h> // ver no documento da bibliote 'wdt.h' para ver o tempo permitido, na linha5 foi colocado 500MS

void setup() {
  delay(5000); //da um tempo de carregamento do arduino.
  wdt_enable(WDTO_500MS); //comando que inicia o comando

  Serial.begin(9600);
  Serial.println("Sketch Iniciado");

}

void loop() {
  wdt_reset();

  Serial.println("Este ponto foi processado");

  while(1);

  Serial.println("Este ponto nunca sera atingido");
  



}
