#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop()
{
  while(mySerial.available()>0){
    int val = mySerial.parseInt();
    Serial.println(val);

    for(int i=0;i<val;i++){
      digitalWrite(13,HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
    }   
  }
}
