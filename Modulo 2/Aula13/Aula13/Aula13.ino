/* Curso Arduino por Flávio Guimarães
Aula 3 - Portas digitais de entrada e programação de botões
FORMA DE NAO USAR RESISTOR - LINHAS 21 COM PULLUP*/
#define pinLEDVermelho     8
#define pinLEDVerde        9
#define pinLEDAmarelo     10
#define pinBotaoBranco     5 //Acende LED amarelo
#define pinBotaoAzul       6 //Acende LED verde
#define pinBotaoVermelho   7 //Acende LED vermelho


void setup() {
   Serial.begin(9600);

   //Configura as portas
   pinMode(pinLEDVermelho, OUTPUT);
   pinMode(pinLEDVerde,    OUTPUT);
   pinMode(pinLEDAmarelo,  OUTPUT);

   
   pinMode (pinBotaoVermelho, INPUT_PULLUP); // Acende LED vermelho
   pinMode(pinBotaoAzul,      INPUT_PULLUP); // Acende LED verde
   pinMode(pinBotaoBranco,    INPUT_PULLUP); // acende LED amarelo

   // Força todos os LEDS desligados
   digitalWrite(pinLEDVermelho, LOW); 
   digitalWrite(pinLEDVerde,    LOW); 
   digitalWrite(pinLEDAmarelo,  LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print (digitalRead(pinBotaoVermelho));
  Serial.print  (digitalRead(pinBotaoAzul));
  Serial.println(digitalRead(pinBotaoBranco));
  
  digitalWrite(pinLEDVermelho, digitalRead(pinBotaoVermelho)); // liga led vermelho com botao
  digitalWrite(pinLEDVerde,    digitalRead(pinBotaoAzul));     // Liga led Verde com botao
  digitalWrite(pinLEDAmarelo,  digitalRead(pinBotaoBranco));   // liga led Amarelo com botao
}
