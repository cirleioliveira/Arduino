// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int lido = analogRead(A0);
  int tensao = map(lido, 0, 1023, 0, 5);
  Serial.println(tensao);
  
}

//explicação -> map(lido, "valor minimo" 0, 1023 "valor maximo", 0 "converter uma faixa de " 0, "faixa" 500