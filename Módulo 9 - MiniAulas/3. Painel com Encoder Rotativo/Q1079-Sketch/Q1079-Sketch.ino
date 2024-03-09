//#include <TimerOne.h>

#define pinSW 8
#define pinDT 2   //Sentido anti-horário
#define pinCLK 3  //Sentido horário

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

int contador = 0;

void setup() {
  pinMode(pinSW, INPUT);
  pinMode(pinDT, INPUT);
  pinMode(pinCLK, INPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pinCLK), rotary_loop, CHANGE);   //No Arduino UNO só funciona na porta 2 ou 3
  attachInterrupt(digitalPinToInterrupt(pinDT), rotary_loop, CHANGE);    //No Arduino UNO só funciona na porta 2 ou 3

  //Timer1.initialize(100);
  //Timer1.attachInterrupt(rotary_loop);
}

void loop() {
  //rotary_loop();
  Serial.print("SW: ");
  Serial.print(digitalRead(pinSW));

  Serial.print(" DT: ");
  Serial.print(digitalRead(pinDT));

  Serial.print(" CLK: ");
  Serial.print(digitalRead(pinCLK));

  Serial.print(" Contador: ");
  Serial.println(contador);  
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
  contador++;
}

//Executa quando o DT for confirmado
void processaDT() {
  contador--;
}