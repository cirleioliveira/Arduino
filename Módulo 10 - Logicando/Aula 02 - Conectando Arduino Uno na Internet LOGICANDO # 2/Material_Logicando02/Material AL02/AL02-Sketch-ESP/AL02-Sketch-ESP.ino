#define monitorSerial false

#define pinLED  1

#define pinRele1 0
#define pinRele2 2

#define nivelHIGH_LED LOW

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>

boolean connectWifi();

void firstDeviceChanged(uint8_t brightness);
void secondDeviceChanged(uint8_t brightness);

// COLOQUE AQUI A REDE E SENHA DO SEU WiFi
const char* ssid = "WiFi003";
const char* password = "mexico@2008";

boolean wifiConnected = false;

Espalexa espalexa;

void setup()
{
  pinMode(pinRele1, OUTPUT); //Relé1
  pinMode(pinRele2, OUTPUT); //Relé2
  
  pinMode(pinLED,  OUTPUT); //LED
  digitalWrite(pinLED, !nivelHIGH_LED);

  #if monitorSerial == true
    Serial.begin(115200);
  #endif
  
  while (! connectWifi()) {
  }
  digitalWrite(pinLED, nivelHIGH_LED);

  // Defina seus dispositivos aqui
  espalexa.addDevice("Luz", firstDeviceChanged);  
  espalexa.addDevice("Tomada", secondDeviceChanged); 

  espalexa.begin();
}

void loop()
{
  espalexa.loop();
  delay(1);

  //Se houve perda de conexão
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(pinLED, !nivelHIGH_LED);
    while (! connectWifi()) {
    }
    digitalWrite(pinLED, nivelHIGH_LED);
  }
}


void firstDeviceChanged(uint8_t brightness) {
  #if monitorSerial == true
     Serial.print("Dispositivo LUZ alterado para ");
  #endif

  if (brightness) {
    #if monitorSerial == true
       Serial.print("LIGADO, luminosidade ");
       Serial.println(brightness);
    #endif
    digitalWrite(pinRele1, HIGH);
  }
  else  {
    #if monitorSerial == true
       Serial.println("DESLIGADO");
    #endif
    digitalWrite(pinRele1, LOW);
  }
}

void secondDeviceChanged(uint8_t brightness) {
  #if monitorSerial == true
     Serial.print("Dispositivo LED alterado para ");
  #endif

  if (brightness) {
    #if monitorSerial == true
       Serial.print("LIGADO, luminosidade ");
       Serial.println(brightness);
    #endif
    digitalWrite(pinRele2, HIGH);
  }
  else  {
    #if monitorSerial == true
       Serial.println("DESLIGADO");
    #endif
    digitalWrite(pinRele2, LOW);
  }
}

boolean connectWifi() {
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #if monitorSerial == true
     Serial.println("");
     Serial.println("Connecting to WiFi");

     // Wait for connection
     Serial.print("Connecting...");
  #endif
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    #if monitorSerial == true
       Serial.print(".");
    #endif
    
    if (i > 20) {
      state = false; break;
    }
    i++;
  }

  #if monitorSerial == true
    Serial.println("");
    if (state) {
      Serial.print("Connected to ");
      Serial.println(ssid);
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
    }
    else {
      Serial.println("Connection failed.");
    }
  #endif
  return state;
}
