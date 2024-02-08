#include <LiquidCrystal_I2C.h>

byte pinLED[4] = {11, 10, 9, 8};
byte pinBOTAO[4] = {7, 6, 5, 4};
byte pinLEITURA[4] = {A0, A1, A2, A3};

String descEscala[4] = {"250v dc", "50v dc", "20v dc", "10v dc"};
float escalas[4] = {250, 50, 20, 10};
float calibracao[4] = {4.411, 4.554, 5.019, 4.99};  //divisor de tensão
float divisor[4];

int escala = 0;
unsigned long delayRefresh;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  for (int nL = 0; nL < 4; nL++) {
    pinMode(pinLED[nL], OUTPUT);
    pinMode(pinBOTAO[nL], INPUT_PULLUP);

    divisor[nL] = (1023 * calibracao[nL]) / 5;
  }

  digitalWrite(pinLED[escala], HIGH);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1); //Coluna, Linha
  lcd.print("escala: ");
  lcd.print(descEscala[escala]);
}

void loop()
{
  //Verifica acionamento dos botoes
  for (int nL = 0; nL < 4; nL++) {
    if (!digitalRead(pinBOTAO[nL])) {
      digitalWrite(pinLED[escala], LOW);
      escala = nL;
      digitalWrite(pinLED[escala], HIGH);

      lcd.setCursor(8, 1); //Coluna, Linha
      lcd.print(descEscala[escala]);
      lcd.print(" ");
    }
  }

  //Faz leitura na porta analógica correspondente à escala selecionada
  float leitura  = analogRead(pinLEITURA[escala]);
  float tensao = 0;

  if (leitura > 0) {
    //Calcula a tensão, antes dos divisores de tensão (tensão lida)
    tensao = (leitura * escalas[escala]) / divisor[escala];

    //Se a escala for AC, calcula a tensão de entrada, sendo que a tensão lida é a tensão média com a redução dos diodos da ponte retificadora
    //if (escala == 0) {
    //  tensao = tensao / 0.636; //Constante da formula da tensão média
    //  tensao = tensao + 1.4;   //Tensão reduzida pelos dois diodos da ponte retificadora
    //}

    //Se a escala for DC, soma a tensão reduzida pelo diodo de proteção
    //if (escala != 0) {
      tensao = tensao + 0.45;
    //}
  }

  if ((millis() - delayRefresh) > 200) {
    delayRefresh = millis();

    lcd.setCursor(0, 0); //Coluna, Linha
    lcd.print(tensao);
    lcd.print(" volts   ");

    Serial.print(tensao);
    Serial.println(" volts");
  }
  delay(20);
}
