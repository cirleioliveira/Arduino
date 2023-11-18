float divisao(float &dividendo, float &divisor); //declarando a função

void setup() {
  Serial.begin(9600);

  float resposta;
  float valor1 = 40;
  float valor2 = 7;

  swap(valor1, valor2);

  resposta = divisao(valor1,valor2);
  Serial.print("O valor recebido e: ");
  Serial.println(resposta);

  Serial.print("O valor1 e: ");
  Serial.println(valor1);
  
}

void loop() {
  
  
}
float divisao(float &dividendo, float &divisor){
  //dividendo = 90; //é uma ref que muda o valor1
  
  float resultado = dividendo / divisor;
  return resultado;
}

void swap(float &valor1, float &valor2){
  float temp = valor1;
  valor1 = valor2;
  valor2 = valor1;
}
