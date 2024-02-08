struct estruturaDataLog {
  byte umidade;
  int temperatura;
  String data;
  String hora;
};

estruturaDataLog leitura1;
estruturaDataLog leitura2;

void setup() {
  leitura1.umidade = 50;
  leitura1.temperatura = 28;
  leitura1.data = "28/01/2024";
  leitura1.hora = "19:43";

  leitura2.umidade = 40;
  leitura2.temperatura = 30;
  leitura2.data = "30/01/2024";
  leitura2.hora = "09:00";

  Serial.begin(9600);  

}

void loop() {
  Serial.print("umidade1: ");
  Serial.println(leitura1.umidade);

  Serial.print("Temperatura1: ");
  Serial.println(leitura1.temperatura);

  Serial.print("Data1: ");
  Serial.println(leitura1.data);

  Serial.print("Hora1: ");
  Serial.println(leitura1.hora);

  delay(1000);

  Serial.print("umidade2: ");
  Serial.println(leitura2.umidade);

  Serial.print("Temperatura2: ");
  Serial.println(leitura2.temperatura);

  Serial.print("Data2: ");
  Serial.println(leitura2.data);

  Serial.print("Hora2: ");
  Serial.println(leitura2.hora);

  delay(1000);

}
