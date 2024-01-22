void setup() {
  Serial.begin(9600);

  Serial.println("Tabela NAO: ");
  Serial.print(!0);
  Serial.println(!1);
  Serial.print(!false);
  Serial.println(!true);
  Serial.print(!LOW);
  Serial.println(!HIGH);
  
  Serial.println("Tabela E: ");
  Serial.print(0 && 0);
  Serial.print(1 && 0);
  Serial.print(0 && 1);
  Serial.println(1 && 1);

  Serial.print(false && false);
  Serial.print(true && false);
  Serial.print(false && true);
  Serial.println(true && true);

  Serial.print(LOW && LOW);
  Serial.print(HIGH && LOW);
  Serial.print(LOW && HIGH);
  Serial.println(HIGH && HIGH);

  Serial.println("Tabela OU: ");
  Serial.print(0 || 0);
  Serial.print(1 || 0);
  Serial.print(0 || 1);
  Serial.println(1 || 1);

  Serial.print(false || false);
  Serial.print(true || false);
  Serial.print(false || true);
  Serial.println(true || true);

  Serial.print(LOW || LOW);
  Serial.print(HIGH || LOW);
  Serial.print(LOW || HIGH);
  Serial.println(HIGH || HIGH);

  Serial.println("Tabela IGUAL ");
  Serial.print(30 == 20);
  Serial.print(true == 1);
  Serial.print(30 == 30);
  Serial.print("ABC" == "CDE");
  Serial.println("del" == "del");

  Serial.println("Tabela DIFERENTE ");
  Serial.print(30 != 20);
  Serial.print(true != 1);
  Serial.print(30 != 30);
  Serial.print("ABC" != "CDE");
  Serial.println("del" != "del");

  Serial.println("Tabela MAIOR ");
  Serial.print(30 > 20);
  Serial.print(true > 1);
  Serial.print(30 > 30);
  Serial.print("ABC" > "def");
  Serial.println("xyz" > "def");

  Serial.println("Tabela MENOR ");
  Serial.print(30 < 20);
  Serial.print(true < 1);
  Serial.print(30 < 30);
  Serial.print("ABC" < "def");
  Serial.println("xyz" < "def");

  Serial.println("Tabela MAIOR OU IGUAL ");
  Serial.print(30 >= 20);
  Serial.print(true >= 1);
  Serial.print(30 >= 30);
  Serial.print("ABC" >= "CDE");
  Serial.println("det" >= "del");
  
  Serial.println("Tabela MENOR OU IGUAL ");
  Serial.print(30 <= 20);
  Serial.print(true <= 1);
  Serial.print(30 <= 30);
  Serial.print("ABC" <= "CDE");
  Serial.println("det" <= "del");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
