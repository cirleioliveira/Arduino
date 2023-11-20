void setup() {
  Serial.begin(9600);

  byte varByte = 250;
  int varInt = -150000;
  long varLong = 10000000000;
  float varFloat = 1124545.478456;
  unsigned int varUnsigInt = 64004245244522300;

  Serial.print("varByte: ");
  Serial.println(varByte);

   Serial.print("varInt: ");
  Serial.println(varInt);

    Serial.print("varLong: ");
  Serial.println(varLong);

   Serial.print("varFloat: ");
  Serial.println(varFloat);

   Serial.print("varUnsigInt: ");
  Serial.println(varUnsigInt);
}

void loop() {


}
