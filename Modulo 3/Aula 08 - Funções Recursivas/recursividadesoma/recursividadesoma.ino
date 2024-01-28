int soma(int n);

void setup() {
  Serial.begin(9600);
  int resultado = soma(4);
  Serial.println(resultado);
}

void loop() {
  // put your main code here, to run repeatedly:



}

int soma(int n) { // recursividade. para a recursividade tem que ter uma condição na função. se não houver uma condição, o arduino trava.

  if (n > 0) 
    return n + soma(n - 1);
  else
    return 0;
}
