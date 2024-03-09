#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define pinSW 12
#define pinDT 2   //Sentido anti-horário
#define pinCLK 3  //Sentido horário

#define pinServo       8
#define pinLEDAzul     10
#define pinLEDVermelho 11

int estadoRotary = 0; //0=Parado 1=CLK 2=DT 3=CLK_Centro 4=DT_Centro
void processaCLK();
void processaDT();

/*Diagrama da lógica do rotary
  0 ___ 1 ___ 3 ___ ConfirmaCLK 
     |     |_ 3 ___ Cancela 
     |     |_ Cancela 
     |_ 2 ___ 4 ___ ConfirmaDT 
           |_ 4 ___ Cancela
           |_ Cancela           
*/

int intensidade = 0;
int angulo      = 90;
int anguloAtual = 90;
int modo        = 0;  //0=Volume  1=Servo

unsigned long delayLCD = 0;
unsigned long delayServo = 0;

LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo1;

void setup() {
  pinMode(pinSW, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinCLK, INPUT);
  pinMode(pinLEDAzul, OUTPUT);
  pinMode(pinLEDVermelho, OUTPUT);

  lcd.init();
  lcd.backlight();

  servo1.attach(pinServo);

  attachInterrupt(digitalPinToInterrupt(pinCLK), rotary_loop, CHANGE);   //No Arduino UNO só funciona na porta 2 ou 3
  attachInterrupt(digitalPinToInterrupt(pinDT), rotary_loop, CHANGE);    //No Arduino UNO só funciona na porta 2 ou 3
}

void loop() {
  //Trata Botão do Rotary
  if (!digitalRead(pinSW)) {
     modo = !modo;
     while(!digitalRead(pinSW));
  }

  //Atualiza LEDs
  if (modo == 0) {
     digitalWrite(pinLEDAzul, HIGH);
     digitalWrite(pinLEDVermelho, LOW);
  } else {
     digitalWrite(pinLEDAzul, LOW);
     digitalWrite(pinLEDVermelho, HIGH);
  }

  //Atualiza Display
  if ((millis() - delayLCD) > 200) {
    delayLCD = millis();
    
    lcd.setCursor(0,0);  //coluna, linha
    lcd.print(intensidade);    
    lcd.print(" ");    

    lcd.setCursor(0,1);  //coluna, linha
    for (int nL=0; nL<intensidade; nL++) {
       lcd.write(255);    
    }
    lcd.print("                ");    

    lcd.setCursor(13,0);  //coluna, linha
    lcd.print(angulo);    
    lcd.print("  ");
  }

  //Atualiza Servo
  if ((millis() - delayServo) > 20) {
    delayServo = millis();
    
    //Atualiza Servo Suavemente
    if (anguloAtual < angulo) {
      anguloAtual++;
    }
    if (anguloAtual > angulo) {
      anguloAtual--;
    }
        
    servo1.write(map(anguloAtual,0,180,180,0));    
  }
}

void rotary_loop() {
  
  //Lógica para estado PARADO
  if (estadoRotary == 0) {
    if (!digitalRead(pinCLK)) { //Ao girar, acionando primeiro o CLK
      estadoRotary = 1;   
    }

    if (!digitalRead(pinDT)) { //Ao girar, acionando primeiro o DT
      estadoRotary = 2;   
    }
  }

  //Lógica para estado CLK
  if (estadoRotary == 1) {
    if (!digitalRead(pinDT)) { //Seguir girando, acionando centro
      estadoRotary = 3;   
    }

    if (digitalRead(pinCLK)) { //Não completou o giro. CANCELA
      estadoRotary = 0;   
    }
  }  

  //Lógica para estado DT
  if (estadoRotary == 2) {
    if (!digitalRead(pinCLK)) { //Seguir girando, acionando centro
      estadoRotary = 4;   
    }

    if (digitalRead(pinDT)) { //Não completou o giro. CANCELA
      estadoRotary = 0;   
    }
  }  

  //Lógica para estado CENTRO_CLK
  if (estadoRotary == 3) {
    if (digitalRead(pinCLK)) { //Seguir girando, acionando a confirmacao
      processaCLK();
      estadoRotary = 0;   
    }

    if (digitalRead(pinDT)) { //Não completou o giro. CANCELA
      estadoRotary = 0;   
    }
  }  

  //Lógica para estado CENTRO_DT
  if (estadoRotary == 4) {
    if (digitalRead(pinDT)) { //Seguir girando, acionando a confirmacao
      processaDT();
      estadoRotary = 0;   
    }

    if (digitalRead(pinCLK)) { //Não completou o giro. CANCELA
      estadoRotary = 0;   
    }
  }  
}

//Executa quando o CLK for confirmado
void processaCLK() {
  if (modo == 0) {  //Volume
    intensidade++;
    intensidade = constrain(intensidade, 0, 16);
  } else { //Angulo
    angulo += 5;
    angulo = constrain(angulo, 0, 180);
  }
}

//Executa quando o DT for confirmado
void processaDT() {
  if (modo == 0) {  //Volume
    intensidade--;
    intensidade = constrain(intensidade, 0, 16);
  } else { //Angulo
    angulo -= 5;
    angulo = constrain(angulo, 0, 180);
  }
}
