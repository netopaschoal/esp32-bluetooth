#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char valorRecebido;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("eletronica_e_programacao"); 
  Serial.println("O dispositivo já pode ser pareado!");

  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
    valorRecebido =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    if(valorRecebido == '1')
    {
     SerialBT.println("LED 1 ligado:");
     digitalWrite(13, HIGH);
    }
    if(valorRecebido == '2')
    {
     SerialBT.println("LED 1 desligado:");
      digitalWrite(13, LOW);
    }    
    if(valorRecebido == '3')
    {
     SerialBT.println("LED 2 ligado:");
     digitalWrite(14, HIGH);
       
    }
    if(valorRecebido == '4')
    {
     SerialBT.println("LED 2 desligado");
      digitalWrite(14, LOW); 
    }
     
  
  }
  delay(30);
}
