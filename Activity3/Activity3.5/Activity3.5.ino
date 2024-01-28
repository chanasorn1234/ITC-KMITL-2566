// C++ code
//
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int x=0;

  ////GO
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);

  pinMode(8, INPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(8,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);

  //BACK
//  
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  pinMode(10, OUTPUT);
  

  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(500);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);

  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(500);
  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(500);
  pinMode(8, OUTPUT);

  pinMode(10, INPUT);
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9,LOW);
  delay(500);

}
