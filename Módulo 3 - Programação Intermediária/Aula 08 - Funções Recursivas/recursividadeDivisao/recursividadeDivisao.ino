int divisaoRec(int num, int den);

void setup() {
  Serial.begin(9600);
  Serial.println(divisaoRec(2546, 7));
}

void loop() {
  // put your main code here, to run repeatedly:



}

int divisaoRec(int num, int den) { // recursividade. para a recursividade tem que ter uma condição na função. se não houver uma condição, o arduino trava.

  if (num < den > 0){ 
    return 0;
  }else {
    return (divisaoRec(num - den, den) + 1);
  }
}
