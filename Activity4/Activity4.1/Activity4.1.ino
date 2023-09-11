 int sw1_state = 0;
 int sw2_state = 0;
 int sw3_state = 0;
 int pre_sw1 = 0;
 int pre_sw2 = 0;
 int pre_sw3 = 0;

void setup() {
  pinMode(8,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
 
}

void loop() {
 
   int sw1 = digitalRead(8);
   int sw2 = digitalRead(3);
   int sw3 = digitalRead(2);
   if(sw1 == 1 && sw1_state == 0 && pre_sw1 != 1){
    sw1_state = 1;
    digitalWrite(11,HIGH);
    }
   else if(sw1 == 1 && sw1_state == 1 && pre_sw1 != 1){
    sw1_state = 0;
    digitalWrite(11,LOW);
    }
   if(sw2 == 0 && sw2_state == 0 && pre_sw2 != 0){
    sw2_state = 1;
    digitalWrite(12,HIGH);
    }
   else if(sw2 == 0 && sw2_state == 1 && pre_sw2 != 0){
    sw2_state = 0;
    digitalWrite(12,LOW);
    }
   if(sw3 == 0 && sw3_state == 0 && pre_sw3 != 0){
    sw3_state = 1;
    digitalWrite(10,HIGH);
    }
   else if(sw3 == 0 && sw3_state == 1 && pre_sw3 != 0){
    sw3_state = 0;
    digitalWrite(10,LOW);
    }
   Serial.print(sw1_state);
   Serial.print(" ");
   Serial.print(sw2_state);
   Serial.print(" ");
   Serial.println(sw3_state);
   pre_sw1 = digitalRead(8);
   pre_sw2 = digitalRead(3);
   pre_sw3 = digitalRead(2);
   delay(150);
  

}
