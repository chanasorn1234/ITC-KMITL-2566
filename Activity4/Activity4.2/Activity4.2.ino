const int buttonPin = 2;
const int buttonPin2 = 3;
volatile bool buttonPressed = false;
unsigned long lastInterruptTime = 0;
const unsigned long debounceDelay = 50; // Debounce time in milliseconds
int carry_time=0;

void setup() {
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), buttonInterrupt2, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Green Led Time : ");
  digitalWrite(12,HIGH);
  delay(7000);
  digitalWrite(12,LOW);
  Serial.println((millis()/1000)-carry_time);
  carry_time = millis()/1000;
  Serial.print("Yellow Led Time : ");
//  digitalWrite(11,HIGH);
//  delay(500);
//  digitalWrite(11,LOW);
//  delay(500);
//  digitalWrite(11,HIGH);
//  delay(500);
//  digitalWrite(11,LOW);
//  delay(500);
//  digitalWrite(11,HIGH);
//  delay(500);
//  digitalWrite(11,LOW);
//  delay(500);
  while((millis()/1000)-carry_time < 3){
      digitalWrite(11,HIGH);
      delay(250);
      digitalWrite(11,LOW);
      delay(250);
    }
  Serial.println((millis()/1000)-carry_time);
  carry_time = millis()/1000;
  Serial.print("Red Led Time : ");
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(10,LOW);
  Serial.println((millis()/1000)-carry_time);
  carry_time = millis()/1000;
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
 
}

void buttonInterrupt() {
  int check_green = digitalRead(12);
  int check_yellow = digitalRead(11);
  int check_red = digitalRead(10);
  Serial.println("Interrupt Mode1");
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
      digitalWrite(12,LOW);
   for(int i=0;i<=500;i++){ 
//    Serial.println(i);
    delayMicroseconds(10000);
    }
    digitalWrite(10,LOW);
   if(check_green){digitalWrite(12,HIGH);}
   if(check_yellow){digitalWrite(11,HIGH);}
   if(check_red){digitalWrite(10,HIGH);}

}
void buttonInterrupt2(){
  int check_green = digitalRead(12);
  int check_yellow = digitalRead(11);
  int check_red = digitalRead(10);
  Serial.println("Interrupt Mode2");
  digitalWrite(10,LOW);
    digitalWrite(11,LOW);
      digitalWrite(12,LOW);
   for(int i=0;i<=500;i++){ 
//    Serial.println(i);
    delayMicroseconds(10000);
    }
    if(check_green){digitalWrite(12,HIGH);}
   if(check_yellow){digitalWrite(11,HIGH);}
   if(check_red){digitalWrite(10,HIGH);}
}
