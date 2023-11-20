void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Precisão (bytes): ");
  
  Serial.print("int:     ");
  Serial.println(sizeof (int));
  
  Serial.print("long:     ");
  Serial.println(sizeof (long));
  
  Serial.print("float:     ");
  Serial.println(sizeof (float));

  Serial.print("Double:     ");
  Serial.println(sizeof (float));
  
  Serial.println();

  float  variavelFloat;
  double variavelDouble;
  long   variavelBinario;

  //variavelBinario = 0b000110000111000011110000001101;
  //memcpy(&variavelFloat, &variavelBinario, sizeof(variavelFloat));

  variavelFloat = 9999.0123456789;

  Serial.print("variavelFloat: ");
  Serial.println(variavelFloat, 10); //SEGUNDO VALOR PARA MOSTRAR COM PRECISÃO, SER QUER QUE APRESENTE 2 DIGITOS, COLOCAR 2 NO LUGAR DO 10

  memcpy(&variavelBinario, &variavelFloat, 4); 

  Serial.print("variavelBinario: ");
  Serial.println(variavelBinario, BIN); //bin -> para ver o valor binario.
  
  Serial.println();
  Serial.println("--------------------------------------------------------.");

  variavelDouble = 9999.0123456789;

  Serial.print("variavelDouble: ");
  Serial.println(variavelDouble, 10);
}

void loop() {
  // put your main code here, to run repeatedly:

}
