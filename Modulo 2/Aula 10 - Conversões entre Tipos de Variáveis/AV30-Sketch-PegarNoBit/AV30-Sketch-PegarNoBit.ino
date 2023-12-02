#define ledBit0 9
#define ledBit1 8
#define ledBit2 7
#define ledBit3 6
#define ledBit4 5
#define ledBit5 4
#define ledBit6 3
#define ledBit7 2

int varInt = 0;

String comando;

void setup() {  
  Serial.begin(9600);
  Serial.println("Aula sobre Tipos de Dados e Conversão");
  Serial.println();

  Serial.print("varInt contem: ");
  Serial.print(varInt);
  Serial.print("(print)  ");
  Serial.write(varInt);
  Serial.print("(write)  ");
  Serial.print(varInt, BIN);
  Serial.println("(BIN)  ");

  pinMode(ledBit0, OUTPUT);
  pinMode(ledBit1, OUTPUT);
  pinMode(ledBit2, OUTPUT);
  pinMode(ledBit3, OUTPUT);
  pinMode(ledBit4, OUTPUT);
  pinMode(ledBit5, OUTPUT);
  pinMode(ledBit6, OUTPUT);
  pinMode(ledBit7, OUTPUT);
}

void loop() {
  digitalWrite(ledBit0, bitRead(varInt, 0));
  digitalWrite(ledBit1, bitRead(varInt, 1));
  digitalWrite(ledBit2, bitRead(varInt, 2));
  digitalWrite(ledBit3, bitRead(varInt, 3));
  digitalWrite(ledBit4, bitRead(varInt, 4));
  digitalWrite(ledBit5, bitRead(varInt, 5));
  digitalWrite(ledBit6, bitRead(varInt, 6));
  digitalWrite(ledBit7, bitRead(varInt, 7));

  if (Serial.available()) {
     char lido = Serial.read();

     if (lido == ';') {
        varInt = comando.toInt(); 
        comando = "";
      
        Serial.print("varInt contem: ");
        Serial.print(varInt);
        Serial.print("(print)  ");
        Serial.write(varInt);
        Serial.print("(write)  ");
        Serial.print(varInt, BIN);
        Serial.println("(BIN)  ");        
     } else {
        comando += lido;
     }
  }
}
