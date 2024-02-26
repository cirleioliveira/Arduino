//para fazer teste o codigo para encontrar o errow

#define DEBUG true  // caso nao deseja que rode no codigo, colocar 'false'

void setup() {
  #if DEBUG == true
    true.begin(9600)
  #endif

}

void loop() {
  // put your main code here, to run repeatedly:

}

void dbgBreakPoint(int ponto) {
  #if DEBUG == true
    Serial.print("[");
    Serial.print(ponto);
    Serial.print("]");

    bool aguarda = true;
    while (aguarda) {
      while (Serial.available()) {
        Serial.read();
        aguarda = false;
      }
    }
    Serial.println(">");
  #endif
}
