void setup() {
  pinMode(8, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Inicio do Setup..");

  while (digitalRead(8)){
    Serial.print(".");
    delay(1000);
        
  }
  Serial.println("Fim do Setup!");
  
}

void loop() {
  Serial.print("Loop em Execucao ");
  Serial.println(millis());
  delay(1000);
  

}
