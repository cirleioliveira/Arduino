//Sketch Teste dos Módulos

#include <LedControl.h>
#include <PushButton.h>


//Definição das portas
#define pinCS 5   //fio roxo
#define pinCLK 6  //fio azul
#define pinDIN 7  //fio verde

#define pinBotaoLoc 2
#define pinBotaoVis 3
#define pinBotaoCorrige 4

//Variaveis de controle
int placar_loc = 0;
int placar_vis = 0;


//Objetos               //DIN, CLK, CS, Qtde_Módulos
LedControl display = LedControl(pinDIN, pinCLK, pinCS, 1);
PushButton botaoLoc(pinBotaoLoc);
PushButton botaoVis(pinBotaoVis);

void setup() {
  //Configura Portas
  pinMode(pinBotaoCorrige, INPUT_PULLUP);

  //Inicia o driver do display
  display.shutdown(0, false);
  //Regula a intensidade do display
  display.setIntensity(0, 3);
  //Limpa o display
  display.clearDisplay(0);

  //Testa Display                         //Endereço do Driver, Digito, Numero, Ponto Decimal
  //for (int nL=0; nL<8; nL++)  display.setDigit(0,nL,8,true);

  atualizaPlacar();
}

void loop() {
  botaoLoc.button_loop();
  botaoVis.button_loop();

  //Controla as variaveis do placar quando um botão for apertado
  if (botaoLoc.pressed()) {
    if (digitalRead(pinBotaoCorrige)) {  
       placar_loc++;
    }
    else {  //Se está ligado o botão para correção
       placar_loc--;
    }
    atualizaPlacar();
  }

  if (botaoVis.pressed()) {
    if (digitalRead(pinBotaoCorrige)) {  
       placar_vis++;
    }
    else {  //Se está ligado o botão para correção
       placar_vis--;
    }
    atualizaPlacar();
  }

  //Garante que os números não sejam negativos
  if (placar_loc < 0) placar_loc = 0;
  if (placar_vis < 0) placar_vis = 0;

  //Controla estouro de valores (máximo = 999)
  if (placar_loc > 999) placar_loc = 0;
  if (placar_vis > 999) placar_vis = 0;
}

void atualizaPlacar() {

  //Controla a posicao do numero no display
  byte posLoc = 6;
  byte posVis = 1;

  if (placar_loc > 99) posLoc = 5;
  if (placar_vis > 9)  posVis = 0;

  //Limpa o display
  display.clearDisplay(0);

  escreveNumero(posLoc, placar_loc);
  escreveNumero(posVis, placar_vis);
}

void escreveNumero(byte posIni, int valor) {
  if (valor < 10) {
    display.setDigit(0, posIni, valor, false);
  } else if (valor < 100) {
    int dezena   = valor / 10;
    int unitario = valor % 10;

    display.setDigit(0, posIni, unitario, false);
    display.setDigit(0, posIni + 1, dezena, false);
  } else {
    int centena  = valor / 100;
    int dezena   = (valor % 100) / 10;
    int unitario = (valor % 100) % 10;

    display.setDigit(0, posIni, unitario, false);
    display.setDigit(0, posIni + 1, dezena, false);
    display.setDigit(0, posIni + 2, centena, false);
  }
}
