int enA = 10;
int enB = 6;
int in1 = 9;
int in2 = 8;
int in3 = 5;
int in4 = 4;
int sensor0 = A0;
int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;
bool robot_move = true;
int level_ss0 = 200;
int level_ss1 = 15;
int level_ss2 = 200;
int level_ss3 = 200;
int level_ss4 = 600;
void setup()
{

pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);

pinMode(sensor0, INPUT);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
//Serial.begin(9600);

}
void loop()
{

int ss0 = analogRead(sensor0);
int ss1 = analogRead(sensor1);
int ss2 = analogRead(sensor2);
int ss3 = analogRead(sensor3);
int ss4 = analogRead(sensor4);
if(ss0<=level_ss0){ss0 = 0;}else{ss0 = 1;};
if(ss1<=level_ss1){ss1 = 0;}else{ss1 = 1;};
if(ss2<=level_ss2){ss2 = 0;}else{ss2 = 1;}; //ss2เริม200 ส่วน ss4 ประมาณ700ทีเริ่มวางบนเส้นดำ
if(ss3<=level_ss3){ss3 = 0;}else{ss3 = 1;};
if(ss4<=level_ss4){ss4 = 0;}else{ss4 = 1;};
//Serial.print(ss0);
//Serial.print(" ");
//Serial.print(ss1);
//Serial.print(" ");
//Serial.print(ss2);
//Serial.print(" ");
//Serial.print(ss3);
//Serial.print(" ");
//Serial.println(ss4);
//delay(500);

if((ss0==0)&&(ss1==0)&&(ss2==0)&&(ss3==0)&&(ss4==0)){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,0); //Left Motor Speed
  analogWrite(enB,0); //Right Motor Speed
  robot_move = false;
}
else if(robot_move == true){
                                                                                         //เซนเซอร์ค่าอาร์เรย์  ค่าความผิดพลาด

if((ss4==0)){                                           //1 1 1 1 0               4
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,100); //Left Motor Speed
  analogWrite(enB,180); //Right Motor Speed


}
else if((ss1==0)){                                             //0 1 1 1 1              -4

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,160); //Left Motor Speed
  analogWrite(enB,180); //Right Motor Speed
    
}
else if((ss0==1)&&(ss1==1)&&(ss2==0)&&(ss3==1)&&(ss4==1)){   //1 1 0 1 1               0
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,100); //Left Motor Speed
  analogWrite(enB,100); //Right Motor Speed
}  
else if((ss0==1)&&(ss1==1)&&(ss2==1)&&(ss3==0)&&(ss4==0)){   //1 1 1 0 0               3
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,130); //Left Motor Speed
  analogWrite(enB,160); //Right Motor Speed
}
else if((ss3==0)&&(ss2 == 1)){                                  //1 1 1 0 1               2 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,150); //Left Motor Speed
  analogWrite(enB,180); //Right Motor Speed

}
else if((ss3==0)&&(ss2==0)){                                  //1 1 0 0 1               2 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,150); //Left Motor Speed
  analogWrite(enB,160); //Right Motor Speed

}



else if((ss0==0)&&(ss1==0)&&(ss2==1)&&(ss3==1)&&(ss4==1)){   //0 0 1 1 1              -3
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,170); //Left Motor Speed
  analogWrite(enB,130); //Right Motor Speed
}

else if((ss1==0)&&(ss2 == 1)){                                                //1 0 1 1 1              -2
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,150); //Left Motor Speed
  analogWrite(enB,180); //Right Motor Speed
 
}
else if((ss1==0)&&(ss2 == 0)){                                                //1 0 0 1 1              -2
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,150); //Left Motor Speed
  analogWrite(enB,160); //Right Motor Speed
 
}


else if((ss2==0)&&(ss3==0)&&(ss4==0)){                      //1 1 0 0 0               5
    
  while((ss3 == 0)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA,200); //Left Motor Speed
    analogWrite(enB,100); //Right Motor Speed
    int ss3 = digitalRead(sensor3);
    if(ss3 == 1){
      break;
    }
  }
  

}
else if((ss0==0)&&(ss1==0)&&(ss2==0)&&(ss4==1)){                            //0 0 0 1 1              -5
  while(ss1 == 0){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA,100); //Left Motor Speed
    analogWrite(enB,200); //Right Motor Speed
    int ss1 = analogRead(sensor1);
    if(ss1<=level_ss1){ss1 = 0;}else{ss1 = 1;};
    if(ss1 == 1){
      break;
    }
  }

}

else if((ss0==1)&&(ss1==1)&&(ss2==1)&&(ss3==1)&&(ss4==1)){   //1 1 1 1 1 -5 หรือ 5 (ขึ้นอยู่กับค่าก่อนหน้านี้)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,100); //Left Motor Speed
  analogWrite(enB,100); //Right Motor Speed


}
}



}
//void check_stopline(){
//  int lss0 = digitalRead(sensor0);
//  int lss1 = analogRead(sensor1);
//  int lss2 = analogRead(sensor2);
//  int lss3 = digitalRead(sensor3);
//  int lss4 = digitalRead(sensor4);
//  if(lss1<=23){lss1 = 0;}else{lss1 = 1;}
//  if(lss2<=100){lss2 = 0;}else{lss2 = 1;}
//  
//  if((lss0==0)&&(lss4==0)){
//  digitalWrite(in1, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA,0); //Left Motor Speed
//  analogWrite(enB,0); //Right Motor Speed
//  robot_move = false;
//}
//}
