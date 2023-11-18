float divisao(float dividendo, float divisor=3); //declarando a função

void setup() {
  Serial.begin(9600);

  float resposta;
  resposta = divisao(80);
  Serial.print("O valor recebido e: ");
  Serial.println(resposta);
  
}

void loop() {
  
  
}
float divisao(float dividendo, float divisor){// a declaração da função com padrao pode ser colocado só no escopo
  float resultado = dividendo/divisor;
  return resultado;
  
}
