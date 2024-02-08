#define pinLEDVermelho 8
#define pinLEDVerde    9
#define pinLEDAmarelo 10

void setup() {
  // put your setup code here, to run once:
   pinMode(pinLEDVermelho, OUTPUT);
   pinMode(pinLEDVerde, OUTPUT);
   pinMode(pinLEDAmarelo, OUTPUT);

   // Força todos os LEDS desligados
   digitalWrite(pinLEDVermelho, LOW); 
   digitalWrite(pinLEDVerde, LOW); 
   digitalWrite(pinLEDAmarelo, LOW);

   // 5 Piscadas de um LED
   piscaLEDUmaVez();
   piscaLEDUmaVez();
   piscaLEDUmaVez();
   piscaLEDUmaVez();
   piscaLEDUmaVez();

   //Espera de um tempo para iniciar o LOOP
   delay(2000); //milisegundos

}

void loop() {
  // put your main code here, to run repeatedly:
  piscaLED(); //chama função

}

void piscaLED() {
  //Primeiro LED acesso
  digitalWrite(pinLEDAmarelo, LOW); // DESLIGADA
  digitalWrite(pinLEDVermelho, HIGH); // LIGADA
  delay(1000); //milisegundos

  //Segundo LED acesso
  digitalWrite(pinLEDVermelho, LOW);
  digitalWrite(pinLEDVerde, HIGH);
  delay(1000); //milisegundos
  
  //Terceiro LED acesso
  digitalWrite(pinLEDVerde, LOW);
  digitalWrite(pinLEDAmarelo, HIGH);
  delay(1000); //milisegundos
}

void piscaLEDUmaVez(){
  digitalWrite(pinLEDVermelho, HIGH);
  delay(300); //milisegundos
  digitalWrite(pinLEDVermelho, LOW);
  delay(300); //milisegundos
}
