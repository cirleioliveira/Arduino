//display com 3 digitos - CONFIGURADO PARA ANODO COMUM (CATODO COMUM INVERTER)
#define nivelD HIGH  
#define nivelS LOW  

#define qtdDigitos 3

                           // 1  2   3
byte pinosDig[qtdDigitos] = {13, 10, 9};

                   //A  B  C  D  E  F   G  PT
byte pinosSeg[8] = {12, 8, 5, 3, 2, 11, 6, 4};

                      //A  B  C  D  E  F  G
byte digitos[16][7] = {{1, 1, 1, 1, 1, 1, 0},   //0
                       {0, 1, 1, 0, 0, 0, 0},   //1
                       {1, 1, 0, 1, 1, 0, 1},   //2
                       {1, 1, 1, 1, 0, 0, 1},   //3
                       {0, 1, 1, 0, 0, 1, 1},   //4
                       {1, 0, 1, 1, 0, 1, 1},   //5
                       {1, 0, 1, 1, 1, 1, 1},   //6
                       {1, 1, 1, 0, 0, 0, 0},   //7
                       {1, 1, 1, 1, 1, 1, 1},   //8
                       {1, 1, 1, 0, 0, 1, 1},   //9
                       {1, 1, 1, 0, 1, 1, 1},   //a
                       {0, 0, 1, 1, 1, 1, 1},   //b
                       {1, 0, 0, 1, 1, 1, 0},   //c
                       {0, 1, 1, 1, 1, 0, 1},   //d
                       {1, 0, 0, 1, 1, 1, 1},   //e
                       {1, 0, 0, 0, 1, 1, 1}};  //f
                    
void setup() {
  for (byte nL=0; nL<qtdDigitos; nL++) {
      pinMode(pinosDig[nL], OUTPUT);
  }
  for (byte nL=0; nL<8; nL++) {
      pinMode(pinosSeg[nL], OUTPUT);
  }

  //APAGA PONTOS
  digitalWrite( pinosSeg[7], !nivelS);
}

void loop() {

  static byte nDig = 0;
  static unsigned long delayContagem;

  //CONTAGEM
  static int numero = 0;
  if ( (millis() - delayContagem) > 1000 ) {
     numero++;
     delayContagem = millis();
  }

  //APAGA TUDO
  for (byte nS=0; nS<7; nS++) {
      digitalWrite( pinosSeg[nS], !nivelS);
  }
  digitalWrite( pinosDig[nDig], !nivelD ); 

  //INCREMENTA DIGITO
  nDig++;
  if (nDig == qtdDigitos) {
     nDig = 0;
  }  

  //EXTRAI DÍGITO DO NUMERO
  byte digito;
  //if (nDig == 0) { digito = (numero / 1000) % 10; }
  if (nDig == 0) { digito = (numero / 100) % 10; }
  if (nDig == 1) { digito = (numero / 10) % 10; }
  if (nDig == 2) { digito = numero % 10; }  

  //LIGA SEGMENTOS DO DIGITO
  digitalWrite( pinosDig[nDig], nivelD );  
  for (byte nS=0; nS<7; nS++) {
      digitalWrite( pinosSeg[nS], !digitos[digito][nS]);
  }  

  //ESPERA UM TEMPO PARA PROXIMO DIGITO
  int readDelay = map(analogRead(A5), 0, 1023, 0, 400);
  delay(readDelay);  
}
