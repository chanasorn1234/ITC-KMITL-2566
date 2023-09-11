#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);
String tx_msg = "";
String rx_msg = "";
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  attachInterrupt(0,RX,FALLING);
 
}

void loop(){
   while(Serial.available()>0){
    char val = Serial.read();
    mySerial.print(val);
    tx_msg += val;
    if(val == '\n'){
      Serial.print("Me: ");
      Serial.print(tx_msg);
      tx_msg = "";
    }
  }
}



void RX(){
  //Serial.print("B: ");
  if(mySerial.available()>0){
    char val = mySerial.read();
    rx_msg += val;
    if(val == '\n'){
      Serial.print("A: ");
      Serial.print(rx_msg);
      rx_msg = "";
    }
  }
}
