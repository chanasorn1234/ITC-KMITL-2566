int A = 3;
void setup() {
  Serial.begin(9600);

}

void loop() {
//  float angle = 0;
//  for(angle = 0;angle<2*22/7;angle +=0.1){
//    float sina = A*sin(angle);
//    float cosa = A*cos(angle);
//    Serial.print(sina);
//    Serial.print(",");
//    Serial.println(cosa);
//    delay(1);

//  float t = 0;
//  for(t = 0;t<10;t +=0.2){
//    Serial.println(t);
//    if(t >= 9){
//      for(t=9;t>0;t-=0.2){
//        Serial.println(t);
//      }
//    }
//    delay(10);
//  }

 float t = 0;
  for(int i=0;i<=50;i++){
    Serial.println(t);
  delay(10);
  }
  if(t==0){
    t=5;
    for(int j=0;j<=50;j++){
      Serial.println(t);
      delay(10);
    }
    t=0;
  }



}
