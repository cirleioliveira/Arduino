void setup() {
  pinMode(8, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Inicio do Setup..");

  while (digitalRead(8) == HIGH){
    Serial.print(".");
    delay(1000);
    
    if(digitalRead(9) == HIGH) {
      //break;   //parada
      continue;  // volta pra cima
    }
  
    delay(1000);
        
  }
  Serial.println("Fim do Setup!");

  //loop() exemplo
  while(true) {   
    Serial.print("Loop em Execucao ");
    Serial.println(millis());
    delay(1000);
    
  }
  
}

void loop() {

  

}
