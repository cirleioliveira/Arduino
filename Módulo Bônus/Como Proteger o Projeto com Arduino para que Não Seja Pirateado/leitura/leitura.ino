#define sda 9   //VERDE
#define scl 10  //AZUL

int sda_read;
int delay_time=1;

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);  
  pinMode(scl, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, false);
  digitalWrite(5, true);
}

int power(int x, unsigned int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}

int read_from_24C16(int Memory_byte_address)
{
  int remainder, i, j, data_read=0;
  int position_in_binary; 
  int binary_of_Memory_byte_address[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  int binary_of_Data[] = {0, 0, 0, 0, 0, 0, 0, 0};
  
  if(Memory_byte_address > 0)
  {
    position_in_binary=10;
    while(Memory_byte_address!=1)
    {
      remainder = Memory_byte_address %2;
      Memory_byte_address= Memory_byte_address / 2;
      binary_of_Memory_byte_address[position_in_binary] = remainder;
      position_in_binary--;
    }    
    binary_of_Memory_byte_address[position_in_binary]=1;
  }

  pinMode(sda, OUTPUT);

  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(sda, LOW);   //   START
  delay(delay_time);        // 
  digitalWrite(scl, LOW);   // 
  delay(delay_time);        //
  
  /*****************  DEVICE ADDRESS STARTS HERE  ******************/
  
  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(sda, HIGH);  // 
  delay(delay_time);        // 
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, binary_of_Memory_byte_address[0]);   //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, binary_of_Memory_byte_address[1]);   //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  digitalWrite(sda, binary_of_Memory_byte_address[2]);   //  
  delay(delay_time);        //  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, LOW);   //  
  delay(delay_time);        //  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //  

  /*****************  DEVICE ADDRESS ENDS HERE  ******************/
  
  pinMode(sda, INPUT);      //
                            
  digitalWrite(scl, HIGH);  //
  sda_read=digitalRead(sda);//  
  delay(delay_time);        //   ACKNOWLEDGEMENT 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  /*****************  WORD ADDRESS STARTS HERE  ******************/

  pinMode(sda, OUTPUT);

  for(i=3;i<11;i++)
  {
    digitalWrite(sda, binary_of_Memory_byte_address[i]);   //  
    delay(delay_time);        //
    digitalWrite(scl, HIGH);  //  
    delay(delay_time);        //   1   MSB
    digitalWrite(scl, LOW);   //
    delay(delay_time);        //
  }
  
  /*****************  WORD ADDRESS ENDS HERE  ******************/

  pinMode(sda, INPUT);
  
  digitalWrite(scl, HIGH);  //
  delay(delay_time);        //
  sda_read=digitalRead(sda);//   ACKNOWLEDGEMENT
  delay(delay_time);        //
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  pinMode(sda, OUTPUT);

  digitalWrite(sda, HIGH);  //                 
  delay(delay_time);        // 
  digitalWrite(scl, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(sda, LOW);   //   START
  delay(delay_time);        //
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  /*****************  DEVICE ADDRESS STARTS HERE  ******************/

  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(sda, HIGH);  // 
  delay(delay_time);        // 
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(sda, binary_of_Memory_byte_address[0]);   //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, binary_of_Memory_byte_address[1]);   //  
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  digitalWrite(sda, binary_of_Memory_byte_address[2]);   //  
  delay(delay_time);        //  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, HIGH);  //  
  delay(delay_time);        //  
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(scl, LOW);   //
  delay(delay_time);        // 

  /*****************  DEVICE ADDRESS ENDS HERE  ******************/

  pinMode(sda, INPUT);      //    
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //
  delay(delay_time);        //
  sda_read=digitalRead(sda);//   ACKNOWLEDGEMENT
  delay(delay_time);        //
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  /***************** DATA STARTS HERE  ******************/

  for(j=0;j<8;j++)
  {
    digitalWrite(scl, HIGH);    //
    delay(delay_time);          //
    for(i=0;i<10;i++)           // 
    {                           //
      sda_read=digitalRead(sda);//   1   MSB
      Serial.print(sda_read);   // 
    }                           //
    
    data_read = data_read + sda_read * power(2,7-j);
    digitalWrite(scl, LOW);     //
    delay(delay_time);          //
  }
  
  /*****************  DATA ENDS HERE  ******************/
  
  pinMode(sda, OUTPUT);       //
  digitalWrite(sda, LOW);     //                
  delay(delay_time);          //
  digitalWrite(scl, HIGH);    //   STOP
  delay(delay_time);          //
  digitalWrite(sda, HIGH);    // 
  delay(delay_time);          //

  //delay(500);

  Serial.println(" ");  
  
  return(data_read);
}

// the loop function runs over and over again forever
void loop() {

  char sn[10];             
  byte snC[10];
  String senhaCripto = "brincandoComIdeias";
  
  int byteOriginal;
  int byteSenha;
  
  int data;

  // Memory Byte Address of the 24C16 from which data to be read
  int Memory_byte_address = 1532;    // In the range 0 - 2047

  for (int nL=0; nL < 10; nL++) {
      // Data read from specified memory of 24C16  
      data = read_from_24C16(Memory_byte_address);

      byteSenha    = byte(senhaCripto.charAt(nL + 1));

      byteOriginal = data + byteSenha;
      if (byteOriginal > 255) {
         byteOriginal = byteOriginal - 255;
      }

      sn[nL] = char(byteOriginal);

      Memory_byte_address--;
  }

  for (int nL=0; nL < 10; nL++) {
      Serial.print(sn[nL]);
  }
  Serial.println();
  Serial.println("Leitura Finalizada");

  while(true);
}
