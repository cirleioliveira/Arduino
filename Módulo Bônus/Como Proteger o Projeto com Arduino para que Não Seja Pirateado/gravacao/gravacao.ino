#define sda  9    //VERDE
#define scl  10   //AZUL

int sda_read;
int delay_time=1;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);

  pinMode(scl, OUTPUT);
}

void write_to_24C16(int Memory_byte_address, int Data)
{
  int remainder, i;
  int position_in_binary;
  int binary_of_Memory_byte_address[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  int binary_of_Data[] = {0, 0, 0, 0, 0, 0, 0, 0};
  
  if(Memory_byte_address > 0)
  {
    position_in_binary=10;
    while(Memory_byte_address!=1)
    {
      remainder= Memory_byte_address %2;
      Memory_byte_address= Memory_byte_address / 2;
      binary_of_Memory_byte_address[position_in_binary] = remainder;
      position_in_binary--;
    }
    
    binary_of_Memory_byte_address[position_in_binary]=1;
  }
  
  if(Data > 0)
  {
    position_in_binary=7;
    while(Data!=1)
    {
      remainder= Data %2;
      Data= Data / 2;
      binary_of_Data[position_in_binary] = remainder;
      position_in_binary--;
    }
    
    binary_of_Data[position_in_binary]=1;
  }
  
  pinMode(sda, OUTPUT);

  digitalWrite(sda, HIGH);  //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(sda, LOW);   // Start
  delay(delay_time);        //
  digitalWrite(scl, LOW);   // 
  delay(delay_time);        //
  
  /************** DEVICE ADDRESS STARTS HERE ***************/
  
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
  delay(delay_time);
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(scl, LOW);   //
  delay(delay_time);        //

  digitalWrite(sda, binary_of_Memory_byte_address[1]);   //  
  delay(delay_time);
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

  /************** DEVICE ADDRESS ENDS HERE ***************/

  digitalWrite(scl, HIGH);         //  
  delay(delay_time);               //
  pinMode(sda, INPUT);             //
  Serial.print(digitalRead(sda));  //   ACKNOWLEDGEMENT
  delay(delay_time);               //
  digitalWrite(scl, LOW);          //
  delay(delay_time);               //

  /************** WORD ADDRESS STARTS HERE ***************/
  
  pinMode(sda, OUTPUT);     //
 
  for(i=3;i<11;i++)
  {
    digitalWrite(sda, binary_of_Memory_byte_address[i]);   //  
    delay(delay_time);        //
    digitalWrite(scl, HIGH);  //  
    delay(delay_time);        //   1   MSB
    digitalWrite(scl, LOW);   //
    delay(delay_time);        //
  }
  
  /************** DEVICE ADDRESS ENDS HERE ***************/
  
  digitalWrite(sda, LOW);            //
  delay(delay_time);                 //
  digitalWrite(scl, HIGH);           //  
  delay(delay_time);                 //  
  pinMode(sda, INPUT);               //
  Serial.print(digitalRead(sda));    //   ACKNOWLEDGEMENT
  delay(delay_time);                 //   
  digitalWrite(scl, LOW);            //
  delay(delay_time);                 //

  /************** DATA STARTS HERE ***************/
  
  pinMode(sda, OUTPUT);
  
  for(i=0;i<8;i++)
  {
    digitalWrite(sda, binary_of_Data[i]);  //
    delay(delay_time);                     //
    digitalWrite(scl, HIGH);               //  
    delay(delay_time);                     //   1   MSB
    digitalWrite(scl, LOW);                //
    delay(delay_time);                     // 
  }
  
  /************** DATA ENDS HERE ***************/

  digitalWrite(sda, LOW);            //
  delay(delay_time);                 // 
  digitalWrite(scl, HIGH);           //  
  delay(delay_time);                 //  
  pinMode(sda, INPUT);               //
  Serial.print(digitalRead(sda));    //   ACKNOWLEDGEMENT
  delay(delay_time);                 //   
  digitalWrite(scl, LOW);            //
  delay(delay_time);                 //
  
  pinMode(sda, OUTPUT);  
  digitalWrite(sda, LOW);   //
  delay(delay_time);        //
  digitalWrite(scl, HIGH);  //  
  delay(delay_time);        //   STOP
  digitalWrite(sda, HIGH);  //   
  delay(delay_time);        //

  //delay(3000);
  
  return;
}

// the loop function runs over and over again forever
void loop() {
              //   1    2     3    4    5    6    7    8    9   10
  char sn[10] = { 'A', 'I', 'R', 'J', 'A', 'A', 'S', 'R', 'T', 'I'};             
  byte snC[10];
  String senhaCripto = "brincandoComIdeias";
                        
  
  int byteOriginal;
  int byteSenha;
  int byteCripto;
                                                                                                
  for (int nL = 0; nL < 10; nL++) {

      byteOriginal = byte(sn[nL]);
      byteSenha    = byte(senhaCripto.charAt(nL + 1));
      
      byteCripto   = byteOriginal - byteSenha;
      if (byteCripto < 0) {
         byteCripto = 255 + byteCripto;
      }
      
      snC[nL] = byteCripto;  
  }

  
  
  // Memory Byte Address of the 24C16 to which data to be written
  int Memory_byte_address = 1532;   // In the range 0 - 2047
  
  // Data to be written to specified memory of 24C16
  int Data;       // In the range 0 - 255

  for (int nL=0; nL < 10; nL++) {
      Data = snC[nL];
      
      Serial.print("Escrevendo ");
      Serial.print(Data);
      Serial.print(" em ");
      Serial.print(Memory_byte_address);
      Serial.print(" byte da Memoria de ");
      Serial.print("24C16  ");    
      
      // Function to write data to 24C16
      write_to_24C16(Memory_byte_address, Data);
      
      Serial.println(" ");

      Memory_byte_address--;
  }

   Serial.println("Gravacao Finalizada!");  
  
  while( true );
}
