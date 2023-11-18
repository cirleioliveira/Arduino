/* Curso Arduino por Flávio Guimarães
Aula 3 - Portas digitais de entrada e programação de botões
FORMA DE NAO USAR RESISTOR - LINHAS 21 COM PULLUP*/
#define pinLEDVermelho     8
#define pinLEDVerde        9
#define pinLEDAmarelo     10
#define pinBotaoBranco     5 //Acende LED amarelo
#define pinBotaoAzul       6 //Acende LED verde
#define pinBotaoVermelho   7 //Acende LED vermelho

//Variaveis publicas
   //int valor1;
   //int valor2;

void setup() {
   Serial.begin(9600);
  
  //memoria
   int valor1;
   int valor2;
   valor1 = 10;
   valor2 = 50;
  
  /* Serial.print("valor1 ");
   Serial.println(valor1);
   Serial.print("valor2 ");
   Serial.print(valor2);*/
   
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

   //int valor1; //varivei criada dentro da função é apagada, iniciando novamente
   static int valor1;
   int valor2;
   valor1++;


  
  //Serial.print (digitalRead(pinBotaoVermelho));
  //Serial.print  (digitalRead(pinBotaoAzul));
  //Serial.println(digitalRead(pinBotaoBranco));
  
  digitalWrite(pinLEDVermelho, digitalRead(pinBotaoVermelho)); // liga led vermelho com botao
  digitalWrite(pinLEDVerde,    digitalRead(pinBotaoAzul));     // Liga led Verde com botao
  digitalWrite(pinLEDAmarelo,  digitalRead(pinBotaoBranco));   // liga led Amarelo com botao

   Serial.print("valor1 ");
   Serial.println(valor1);
   Serial.print("valor2 ");
   Serial.println(valor2);
}
