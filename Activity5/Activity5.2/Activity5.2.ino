void setup() {
    pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if(val<60 && val > 0){
    digitalWrite(8,HIGH);
   
    }
  if(val<400 && val > 300){
   digitalWrite(9,HIGH);
    }
  if(val<800 && val > 700){
   digitalWrite(10,HIGH);
    }
  if(val<150 && val > 90){
   digitalWrite(11,HIGH);
    }
  if(val==0){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }

}
