#define tamanhoPortas 5 //Tamanho array

byte portas[tamanhoPortas] = {4,9,10,11,12};
byte array3D[10][10][10];

void setup() {
  Serial.begin(9600); 
  
  for (int nL = 0; nL < tamanhoPortas; nL++) {
    pinMode(portas[0], INPUT_PULLUP);
    Serial.println(portas[nL]);
  }

  array3D[1][5][0] = 30;
  array3D[1][6][1] = 28;

  Serial.println(array3D[1][5][0]);
  Serial.println(array3D[1][6][1]);
  

}

void loop() {
  

}
