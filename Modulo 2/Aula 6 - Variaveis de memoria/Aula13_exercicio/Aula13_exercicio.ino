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
   int estadoBotaoVemelho;
   int estadoBotaoVerde;
   int estadoBotaoAmarelo;

  estadoBotaoVemelho = digitalRead(pinBotaoVermelho);
  estadoBotaoVerde   =  digitalRead(pinBotaoAzul);
  estadoBotaoAmarelo = digitalRead(pinBotaoBranco);
  
  Serial.print (estadoBotaoVemelho);
  Serial.print  (estadoBotaoVerde);
  Serial.println(estadoBotaoAmarelo);
  
  digitalWrite(pinLEDVermelho, estadoBotaoVemelho); // liga led vermelho com botao
  digitalWrite(pinLEDVerde,   estadoBotaoVerde);     // Liga led Verde com botao
  digitalWrite(pinLEDAmarelo,  estadoBotaoAmarelo);   // liga led Amarelo com botao

}
