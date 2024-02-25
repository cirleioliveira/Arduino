/****************************************************************************************
  Exemplo de Uso do Controle de HardLock
  
  Desenvolvido pela Fábrica de Programas - Brincando com Ideias (www.brincandocomideias.com)
  www.youtube.com/c/BrincandoComIdeias

  Desenvolvido exclusivamente para os alunos do Curso de Arduino (www.cursoDeArduino.net)
  
*****************************************************************************************/ 

//********************** PARAMETRIZAÇÃO DO PROJETO ***********************
  #define hardLockSDA 9
  #define hardLockSCL 10

  //coloque aqui as definicoes e parametrizacoes do seu projeto

//********************** FINAL DA PARAMETRIZAÇÃO DO PROJETO ***********************


void setup()
{   
  //coloque aqui os comandos a serem executados uma única vez, quando o Arduino for ligado ou resetado
  

  //Blink para teste da senha (Apague este trecho do código ao codificar o seu projeto
  pinMode(13, OUTPUT);

  //verifica a existencia do HardLock com o código informado na segunda camada de criptografia (use o arquivo Excel do pacote para gerar o código da segunda camada) 
  if (!checkPins("DO[VPShjog")) {  //ESTE É O SEGUNDO CODIGO SECRETO QUE FOI CRIADO NO EXCEL
     while(true) {  //se nao achou o código, trava a execução

       //Blink para teste da senha (Apague este trecho do código ao codificar o seu projeto
       digitalWrite(13, HIGH);
       delay(100);
       digitalWrite(13, LOW);
       delay(100);     
     }
  }
} //setup()


// ----------------------------------------------------------------------------------------------------
void loop()
{
  //coloque aqui os comandos a serem executados em sequencia até que o Arduino seja desligado ou resetado

  //Blink para teste da senha (Apague este trecho do código ao codificar o seu projeto
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(2000);
  
  
} //loop()





//Mantenha as funçoes abaixo. São necessárias para a leitura do HardLock
int power(int x, unsigned int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}

int read_from_24C16(int Memory_byte_address) {
  int sda_read;
  int delay_time=1;

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

  pinMode(hardLockSDA, OUTPUT);

  digitalWrite(hardLockSDA, HIGH);  //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(hardLockSDA, LOW);   //   START
  delay(delay_time);        // 
  digitalWrite(hardLockSCL, LOW);   // 
  delay(delay_time);        //
  
  /*****************  DEVICE ADDRESS STARTS HERE  ******************/
  
  digitalWrite(hardLockSDA, HIGH);  //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, LOW);   //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(hardLockSDA, HIGH);  // 
  delay(delay_time);        // 
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, LOW);   //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[0]);   //  
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[1]);   //  
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        // 

  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[2]);   //  
  delay(delay_time);        //  
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  digitalWrite(hardLockSDA, LOW);   //  
  delay(delay_time);        //  
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //  

  /*****************  DEVICE ADDRESS ENDS HERE  ******************/
  
  pinMode(hardLockSDA, INPUT);      //
                            
  digitalWrite(hardLockSCL, HIGH);  //
  sda_read=digitalRead(hardLockSDA);//  
  delay(delay_time);        //   ACKNOWLEDGEMENT 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  /*****************  WORD ADDRESS STARTS HERE  ******************/

  pinMode(hardLockSDA, OUTPUT);

  for(i=3;i<11;i++)
  {
    digitalWrite(hardLockSDA, binary_of_Memory_byte_address[i]);   //  
    delay(delay_time);        //
    digitalWrite(hardLockSCL, HIGH);  //  
    delay(delay_time);        //   1   MSB
    digitalWrite(hardLockSCL, LOW);   //
    delay(delay_time);        //
  }
  
  /*****************  WORD ADDRESS ENDS HERE  ******************/

  pinMode(hardLockSDA, INPUT);
  
  digitalWrite(hardLockSCL, HIGH);  //
  delay(delay_time);        //
  sda_read=digitalRead(hardLockSDA);//   ACKNOWLEDGEMENT
  delay(delay_time);        //
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  pinMode(hardLockSDA, OUTPUT);

  digitalWrite(hardLockSDA, HIGH);  //                 
  delay(delay_time);        // 
  digitalWrite(hardLockSCL, HIGH);  //                
  delay(delay_time);        //
  digitalWrite(hardLockSDA, LOW);   //   START
  delay(delay_time);        //
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  /*****************  DEVICE ADDRESS STARTS HERE  ******************/

  digitalWrite(hardLockSDA, HIGH);  //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   1   MSB
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, LOW);   //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   2 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        // 
  
  digitalWrite(hardLockSDA, HIGH);  // 
  delay(delay_time);        // 
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   3 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, LOW);   //
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   4 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //
  
  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[0]);   //  
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   5 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[1]);   //  
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   6 
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        // 

  digitalWrite(hardLockSDA, binary_of_Memory_byte_address[2]);   //  
  delay(delay_time);        //  
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   7
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  digitalWrite(hardLockSDA, HIGH);  //  
  delay(delay_time);        //  
  digitalWrite(hardLockSCL, HIGH);  //  
  delay(delay_time);        //   8   LSB
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        // 

  /*****************  DEVICE ADDRESS ENDS HERE  ******************/

  pinMode(hardLockSDA, INPUT);      //    
  delay(delay_time);        //
  digitalWrite(hardLockSCL, HIGH);  //
  delay(delay_time);        //
  sda_read=digitalRead(hardLockSDA);//   ACKNOWLEDGEMENT
  delay(delay_time);        //
  digitalWrite(hardLockSCL, LOW);   //
  delay(delay_time);        //

  /***************** DATA STARTS HERE  ******************/

  for(j=0;j<8;j++)
  {
    digitalWrite(hardLockSCL, HIGH);    //
    delay(delay_time);          //
    for(i=0;i<10;i++)           // 
    {                           //
      sda_read=digitalRead(hardLockSDA);//   1   MSB
    }                           //
    
    data_read = data_read + sda_read * power(2,7-j);
    digitalWrite(hardLockSCL, LOW);     //
    delay(delay_time);          //
  }
  
  /*****************  DATA ENDS HERE  ******************/
  
  pinMode(hardLockSDA, OUTPUT);       //
  digitalWrite(hardLockSDA, LOW);     //                
  delay(delay_time);          //
  digitalWrite(hardLockSCL, HIGH);    //   STOP
  delay(delay_time);          //
  digitalWrite(hardLockSDA, HIGH);    // 
  delay(delay_time);          //
  
  return(data_read);
}

bool checkPins(String comando) {
  char sn[10];             
  char snC[10];
  String senhaCripto = "brincandoComIdeias";
  
  int byteOriginal;
  int byteSenha;
  
  int data;

  // Memory Byte Address of the 24C16 from which data to be read
  int Memory_byte_address = 1532;    // In the range 0 - 2047

  pinMode(hardLockSCL, OUTPUT);

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
      snC[nL] = char(   byte(comando.charAt(nL)) - ((nL + 1)*3)   );
  }


  bool statCheck = true; 
  for (int nL=0; nL < 10; nL++) {
      if (sn[nL] != snC[nL]) {         
         statCheck = false; 
      }
      
  }

  return statCheck;
}
