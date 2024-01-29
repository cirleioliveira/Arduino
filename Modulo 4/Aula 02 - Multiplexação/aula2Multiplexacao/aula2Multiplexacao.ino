byte pinRow[8] = {0, 1, 2, 3, 4, 5, 6, 7};
byte pinCol[8] = {A0, A1, A2, A3, A4, 9, 10, 11};

bool emogi[8][8] = {{0,0,1,1,1,1,0,0},
                    {0,1,0,0,0,0,1,0},
                    {1,0,1,0,0,1,0,1},
                    {1,0,0,0,0,0,0,1},
                    {1,0,1,0,0,1,0,1},
                    {1,0,0,1,1,0,0,1},
                    {0,1,0,0,0,0,1,0},
                    {0,0,1,1,1,1,0,0}};

void setup() {

  for (byte nL=0; nL <8; nL++) {
      pinMode(pinRow[nL], OUTPUT);
      pinMode(pinCol[nL], OUTPUT);
  }
}

void loop() {
  static byte nRow = 0;

  for (byte nC=0; nC <8; nC++) {
      digitalWrite( pinCol[nC], LOW);
  }
  digitalWrite( pinRow[nRow], HIGH );
  
  
  nRow++;
  if (nRow == 8) {
     nRow = 0;
  }

  digitalWrite( pinRow[nRow], LOW );

  for (byte nC=0; nC <8; nC++) {
      digitalWrite( pinCol[nC], emogi[nRow][nC]);
  }

  int readDelay = map(analogRead(A5), 0, 1023, 0, 400);
  delay(readDelay);
}
