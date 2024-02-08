#define tamanhoPortas 5
byte portas[tamanhoPortas] = {4,9,10,11,12};

struct estruturaDataLog {
  byte umidade;
  int temperatura;
  String data;
  String hora;
};

estruturaDataLog leituras[50];

void setup() {
  Serial.begin(9600); 
  
  for (int nL = 0; nL < tamanhoPortas; nL++) {
    pinMode(portas[0], INPUT_PULLUP);
    Serial.println(portas[nL]);
  }
  
  leituras[0].umidade = 50;
  leituras[0].temperatura = 28;
  leituras[0].data = "28/01/2024";
  leituras[0].hora = "19:43";

  leituras[1].umidade = 40;
  leituras[1].temperatura = 30;
  leituras[1].data = "30/01/2024";
  leituras[1].hora = "09:00"; 

}

void loop() {
  Serial.print("umidade1: ");
  Serial.println(leituras[0].umidade);

  Serial.print("Temperatura1: ");
  Serial.println(leituras[0].temperatura);

  Serial.print("Data1: ");
  Serial.println(leituras[0].data);

  Serial.print("Hora1: ");
  Serial.println(leituras[0].hora);

  delay(1000);

  Serial.print("umidade2: ");
  Serial.println(leituras[1].umidade);

  Serial.print("Temperatura2: ");
  Serial.println(leituras[1].temperatura);

  Serial.print("Data2: ");
  Serial.println(leituras[1].data);

  Serial.print("Hora2: ");
  Serial.println(leituras[1].hora);

  delay(1000);

}
