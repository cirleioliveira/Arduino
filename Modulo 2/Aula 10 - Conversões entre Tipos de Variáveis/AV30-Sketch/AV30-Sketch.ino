void setup() {

  int    varInt     = 2020;
  char   varChar    = 'B';
  String varString  = "Ola Mundo!!";
  float  varFloat   = 5.12;
  bool   varBoolean = true;
  
  Serial.begin(9600);
  Serial.println("Aula sobre Tipos de Dados e Conversão");
  Serial.println();

  Serial.print("varInt contem: ");
  Serial.print(varInt);
  Serial.print("(print)  ");
  Serial.write(varInt);
  Serial.println("(write)  ");

  Serial.print("varChar contem: ");
  Serial.print(varChar);
  Serial.print("(print)  ");
  Serial.write(varChar);
  Serial.println("(write)  ");

  Serial.print("varString contem: ");
  Serial.println(varString);

  Serial.print("varFloat contem: ");
  Serial.println(varFloat);

  Serial.print("varBoolean contem: ");
  Serial.println(varBoolean);
}

void loop() {
}
