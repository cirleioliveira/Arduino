#include <PushButton.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//#include <LiquidCrystal.h>


#define pinBotaoEnter 9
#define pinBotaoEsc   10
#define pinBotaoProx  11
#define pinBotaoAnt   12

#define ITENS_MENU 16

struct ItemMenu {
  String name;
  byte upper;
};

ItemMenu menuStruct[ITENS_MENU + 1]; //O array terá um item a mais sendo que o indice zero, será o root (raiz) da estrutura.
byte ponteiroMenu = 1;

PushButton botaoEnter(pinBotaoEnter);
PushButton botaoEsc(pinBotaoEsc);
PushButton botaoProx(pinBotaoProx);
PushButton botaoAnt(pinBotaoAnt);

LiquidCrystal_I2C lcd(0x27, 16, 2);
//LiquidCrystal lcd(8, 7, 6, 5, 4, 3);  //rs, en, d4, d5, d6, d7

void menuRefresh(bool menuLigado = true);

void setup() {
  //Indice 0 identifica o root (raiz) do menu e nao deve ser usado por um item especifico
  menuStruct[1].name = "Estado";
    menuStruct[2].name = "Valvula 1";    menuStruct[2].upper = 1; 
    menuStruct[3].name = "Valvula 2";    menuStruct[3].upper = 1;
  
  menuStruct[4].name = "Controle Manual";
    menuStruct[5].name = "Valvula 1";     menuStruct[5].upper = 4;
        menuStruct[6].name = "Ligar";     menuStruct[6].upper = 5; 
        menuStruct[7].name = "Desligar";  menuStruct[7].upper = 5;
    menuStruct[8].name = "Valvula 2";     menuStruct[8].upper = 4;
        menuStruct[9].name  = "Ligar";    menuStruct[9].upper  = 8;
        menuStruct[10].name = "Desligar"; menuStruct[10].upper = 8; 
  
  menuStruct[11].name = "Configuracao";
    menuStruct[12].name = "Tempo";           menuStruct[12].upper = 11; 
    menuStruct[13].name = "Modo";            menuStruct[13].upper = 11;
        menuStruct[14].name = "Automatico";  menuStruct[14].upper = 13;
        menuStruct[15].name = "Manual";      menuStruct[15].upper = 13;  

  menuStruct[16].name = "Sair";
  
  lcd.begin();
  lcd.backlight();
  
  //lcd.begin(16,2);
  
  menuRefresh();
}

void loop() {
  botaoEnter.button_loop();
  botaoEsc.button_loop();
  botaoProx.button_loop();
  botaoAnt.button_loop();

  if (botaoEnter.pressed()) {
     byte itemSelecionado = menuDown();

     switch (itemSelecionado) {
        case 0: {break;} //Não faz nada, sendo que o item possui um nivel abaixo.
        
        case 2: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 1 ... ");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }
                
        case 3: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 2 ...");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }

       case 6: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 1 ON");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }                

       case 7: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 1 OFF");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }                

       case 9: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 2 ON");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }                

       case 10: {
                  lcd.setCursor(0,1); 
                  lcd.print("Valvula 2 OFF");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }                

      case 12: {
                  lcd.setCursor(0,1); 
                  lcd.print("Configurando ...");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }                

      case 14: {
                  lcd.setCursor(0,1); 
                  lcd.print("Em Automatico!");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }      

      case 15: {
                  lcd.setCursor(0,1); 
                  lcd.print("Em Manual!");                  
                  delay(3000);
                  lcd.setCursor(0,1); 
                  lcd.print("                ");
                  menuRoot();
                  break;
                }          

      case 16: {
                  menuOut();
                  break;
                }                           
    }
  }    

  if (botaoEsc.pressed()) {
     menuUp();
  }    

  if (botaoProx.pressed()) {
     menuNext();
  }    

  if (botaoAnt.pressed()) {
     menuPrevious();
  }    
}

//Refaz a tela do menu
void menuRefresh(bool menuLigado = true) {

  if (!menuLigado) {
     lcd.setCursor(0,0);
     lcd.print("                ");
     lcd.setCursor(0,1); 
     lcd.print("                ");
     return; 
  }

  lcd.setCursor(0,0); 
  lcd.print(menuStruct[ponteiroMenu].name);                  

  //Limpa o restante da linha 
  for (byte nL = menuStruct[ponteiroMenu].name.length() ; nL < 16; nL++) {
      lcd.print(" ");
  }
}

//Entra no Menu
void menuIn() {
  ponteiroMenu = 1;
  menuRefresh(); 
}

//Sai do Menu
void menuOut() {
  ponteiroMenu = 1;
  menuRefresh(false); 
}

//Move o ponteiro do menu para um nível acima
void menuUp() {
  //Ignora comando se o item acima for a raiz 
  if (menuStruct[ponteiroMenu].upper != 0) { 
     ponteiroMenu = menuStruct[ponteiroMenu].upper;
     menuRefresh();
  }
}

//Move o ponteiro do menu para um nível abaixo
byte menuDown() {
  //Procura primeiro item abaixo
  byte actualPointer = ponteiroMenu;
  
  for (byte nL=1; nL <= ITENS_MENU; nL++) {
      if (menuStruct[nL].upper == ponteiroMenu) {
         ponteiroMenu = nL;
         menuRefresh();
         break;
      }
  }

  if (actualPointer == ponteiroMenu) {
     return(ponteiroMenu);
  } else {
     return(0);
  }
}

//Move o ponteiro do menu para o item seguinte
void menuNext() {
  
  //Procura item seguinte do mesmo nivel
  byte actualLevel = menuStruct[ponteiroMenu].upper;
  
  for (byte nL=ponteiroMenu+1; nL <= ITENS_MENU; nL++) {
      if (menuStruct[nL].upper == actualLevel) {
         ponteiroMenu = nL;
         menuRefresh();
         break;
      }
  }
}

//Move o ponteiro do menu para o item anterior
void menuPrevious() {
  
  //Procura item anterior da mesma raiz
  byte actualLevel = menuStruct[ponteiroMenu].upper;
  
  for (byte nL=ponteiroMenu-1; nL >= 1; nL--) {
      if (menuStruct[nL].upper == actualLevel) {
         ponteiroMenu = nL;
         menuRefresh();
         break;
      }
  }
}

void menuRoot() {
  ponteiroMenu = 1;
  menuRefresh(); 
}


