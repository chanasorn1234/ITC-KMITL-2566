#include<EEPROM.h>
const int speaker = 5;
const int numtone = 7;
const int tones[7] = {261,294,330,349,392,440,494};
int state_tones;
int address_play_record;
int address = 0;
int scale_address;
boolean save=false;
boolean play=false;

volatile bool switchState = HIGH; 
volatile bool lastSwitchState = HIGH;
volatile unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 1; 
void setup()
{
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
//  for(int i=0;i<numtone;i++){
  //  tone(speaker,tones[i]);
  //  delay(500);
  //}
  //noTone(speaker);
  attachInterrupt(0,record,FALLING);
  attachInterrupt(1,play_record,FALLING);
  EEPROM.put(0,address);
}

void loop()
{
  int sw1 = digitalRead(7);
  int sw2 = digitalRead(8);
  int sw3 = digitalRead(9);
  int sw4 = digitalRead(10);
  int sw5 = digitalRead(11);
  int sw6 = digitalRead(12);
  int sw7 = digitalRead(13);
// Serial.println(sw4);
 if(sw1){
    tone(speaker,tones[6]);
   if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,6);
     //Serial.println(address);
   }
 }
  else if(sw2){
    tone(speaker,tones[5]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,5);
     //Serial.println(address);
   }
  }
   else if(sw3){
    tone(speaker,tones[4]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,4);
   }
  }
  else if(sw4){
    tone(speaker,tones[3]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,3);
   }
  }
  else if(sw5){
    tone(speaker,tones[2]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,2);
   }
  }
  else if(sw6){
    tone(speaker,tones[1]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,1);
   }
  }
  else if(sw7){
    tone(speaker,tones[0]);
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,0);
   }
  }
  else{
    if(save){
     address += 1;
     EEPROM.put(0,address);
     EEPROM.put(address,8);
  }
  }
  if(play){
    //EEPROM.get(1,address_play_record);
    EEPROM.get(0,scale_address);
    Serial.println(scale_address);
   // Serial.println(EEPROM.read(0));
   // EEPROM.get(1,address_play_record);
   // Serial.println(EEPROM.read(1));
   // EEPROM.get(2,address_play_record);
    //Serial.println(EEPROM.read(2));
   
    for(int i=2;i<=scale_address;i++){
      //EEPROM.get(i,address_play_record);
      Serial.print(i);
      Serial.print("  ");
      Serial.println(EEPROM.read(i));
      if(EEPROM.read(i) == 8){
        noTone(speaker);
      }
      else{
        tone(speaker,tones[EEPROM.read(i)]);
      }
    delay(150);
    }
    play = false;
  }
  delay(150);
  noTone(speaker);
  
}

void record(){
    int reading = digitalRead(2);
  switchState = HIGH;
  // Check if the new reading is different from the last recorded state
  if (reading != lastSwitchState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }

  // If the switch state has been stable for longer than the debounce delay
  if (millis() - lastDebounceTime > debounceDelay) {
    // Update the switch state only if it's different from the last recorded state
    if (reading != switchState) {
      switchState = reading;

      // Your code to respond to the switch state change goes here
      if (switchState == 0) {
        address = 0;
       save = !save;
      Serial.print("Mode record is ");
        Serial.println(save);
      } 
    }
  }

  // Update lastSwitchState to the current reading for the next iteration
  lastSwitchState = reading;
  
}
void play_record(){
  if(save==false){
  play = !play;
  Serial.print("Mode play is ");
  Serial.println(play);
  }
}
