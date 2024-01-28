String textoRecebido;
unsigned long delaySerial;

void setup() {
  Serial.begin(9600);

  for (int x = 1; x <= 127; x++) {
   Serial.print(x);
   Serial.print(" - ");
   Serial.println(char(x));
    
  }

}

void loop() {

  
  while (Serial.available() ) {
    char lido = char(Serial.read() ); //le a informação que vem do computador
    textoRecebido = textoRecebido + lido;
    delaySerial = millis();
    
    }

  if ( ((millis() - delaySerial) > 200 ) && (textoRecebido != "")) {
    Serial.print("Texto foi recebido: ");
    Serial.println(textoRecebido);
    textoRecebido = "";
  }
    
}
