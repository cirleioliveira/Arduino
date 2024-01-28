#define pin1 5
#define pin2 6
#define pin3 7
#define pin4 8
#define pin5 9

int pinos[5] = {5,6,7,8,9};
int interacao;

void setup() {
  for (interacao = 0; interacao <= 4; interacao++) {
    pinMode(pinos[interacao], OUTPUT);
        
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
