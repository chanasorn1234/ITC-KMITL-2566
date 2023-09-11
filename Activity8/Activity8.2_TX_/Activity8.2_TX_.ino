#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  while(Serial.available()>0){
    String val = Serial.readStringUntil('\n');
    Serial.println(val);
    mySerial.print(val);
  }
    
}
