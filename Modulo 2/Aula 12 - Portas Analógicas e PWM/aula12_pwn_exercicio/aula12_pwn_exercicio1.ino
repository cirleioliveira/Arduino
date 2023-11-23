#define pinPotenciometro A2
#define pinLED1          10
#define pinLED2           9

void setup(){
  //Serial.begin(9600);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  
}

void loop()
{
  int estadoPotenciometro = analogRead(pinPotenciometro);
  analogWrite(pinLED2, map(estadoPotenciometro, 0 , 1023, 0, 255));
  analogWrite(pinLED1, map(estadoPotenciometro, 0 , 1023, 255, 0));
  
}