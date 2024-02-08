String textoRecebido;
String textoInvertido;
int tamanhoTexto = 0;

unsigned long delaySerial;

void setup() {
  Serial.begin(9600);
/*
  for (int x = 1; x <= 127; x--) {
   Serial.print(x);
   Serial.print(" - ");
   Serial.println(char(x));
    
  }
  */

}

void loop() {

  
  while (Serial.available() ) {
    char lido = char(Serial.read() );          //le a informação que vem do computador
    textoRecebido += lido;
    tamanhoTexto++;
    delaySerial = millis();
    
  }

  if ( ((millis() - delaySerial) > 200 ) && (textoRecebido != "")) {
/*
    textoInvertido = "";
    for (int i = tamanhoTexto; i >=0; i--) {
      textoInvertido += textoRecebido.charAt(i);
    }
    */

     textoInvertido = "";
     int i = tamanhoTexto;
     while (i >= 0){
      textoInvertido += textoRecebido.charAt(i);
      i--;
      
     }

    Serial.print("Texto foi recebido: ");
    Serial.println(textoRecebido);

    Serial.print("Texto invertido: ");
    Serial.println(textoInvertido);
    
    textoRecebido = "";
    tamanhoTexto = 0;
  }  
}
