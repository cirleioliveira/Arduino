float divisao(float dividendo, float divisor); //declarando a função

void setup() {
  Serial.begin(9600);

  float resposta;
  resposta = divisao(90, 2);
  Serial.print("O valor recebido e: ");
  Serial.println(resposta);
  
}

void loop() {
  
  
}
float divisao(float dividendo, float divisor){
  float resultado = dividendo/divisor;
  return resultado;
  
}
