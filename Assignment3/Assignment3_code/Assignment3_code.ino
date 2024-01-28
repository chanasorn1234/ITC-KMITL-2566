#define BUTTON_NORTH A1
#define LED_N_R 10
#define LED_N_Y 9
#define LED_N_G 8

#define BUTTON_EAST A2
#define LED_E_R 6
#define LED_E_Y 5
#define LED_E_G 4

#define BUTTON_people 2
#define LED_peo_R 12
#define LED_peo_G 11

#define goN 0
#define waitN 1
#define goE 2
#define waitE 3
#define goPeople 4
#define waitPeople 5

int input;
int input0;
int input1;
int input2;
bool toggle_all_intput = true;

struct State{
  unsigned long ST_Out; 
  unsigned long Time; 
  unsigned long NextST[9];
};

typedef const struct State SType;

SType fs[6] = {
  {B10001100, 10000, {goN, waitN, goN, waitN, waitN, waitN, waitN, waitN}},
  {B10010100, 5000, {goE, goE, goE, goE, goPeople, goPeople, goPeople, goPeople}},
  {B10100001, 10000, {goE, goE, waitE, waitE, waitE, waitE, waitE, waitE}},
  {B10100010, 5000, {goN, goN, goN, goN, goPeople, goPeople, goPeople, goPeople}},
  {B01100100, 5000, {goPeople, waitPeople, waitPeople, waitPeople, goPeople, waitPeople, waitPeople, waitPeople}}, 
  {B01100100, 3000, {goN, goE, goN, goE, goN, goE, goN, goN,goE}}
    
};
  unsigned long st=0;

void setup() {
  pinMode(BUTTON_NORTH,INPUT);
  pinMode(LED_N_R,OUTPUT);
  pinMode(LED_N_Y,OUTPUT);
  pinMode(LED_N_G,OUTPUT);

  pinMode(BUTTON_EAST,INPUT);
  pinMode(LED_E_R,OUTPUT);
  pinMode(LED_E_Y,OUTPUT);
  pinMode(LED_E_G,OUTPUT);
  
  pinMode(BUTTON_people,INPUT);
  pinMode(LED_peo_R,OUTPUT);
  pinMode(LED_peo_G,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
 digitalWrite(LED_N_R,fs[st].ST_Out & B00100000);
 digitalWrite(LED_N_Y,fs[st].ST_Out & B00010000); 
 digitalWrite(LED_N_G,fs[st].ST_Out & B00001000); 
  
 digitalWrite(LED_E_R,fs[st].ST_Out & B00000100);
 digitalWrite(LED_E_Y,fs[st].ST_Out & B00000010); 
 digitalWrite(LED_E_G,fs[st].ST_Out & B00000001); 

 if(st == 5){
    digitalWrite(LED_peo_R,fs[st].ST_Out & B01000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B10000000);  
    delay(fs[st].Time/6);
    digitalWrite(LED_peo_R,fs[st].ST_Out & B11000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B11000000);  
    delay(fs[st].Time/6);
    digitalWrite(LED_peo_R,fs[st].ST_Out & B01000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B10000000);  
    delay(fs[st].Time/6);
    digitalWrite(LED_peo_R,fs[st].ST_Out & B11000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B11000000);  
    delay(fs[st].Time/6);
    digitalWrite(LED_peo_R,fs[st].ST_Out & B01000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B10000000);  
    delay(fs[st].Time/6);
    digitalWrite(LED_peo_R,fs[st].ST_Out & B11000000); 
    digitalWrite(LED_peo_G,fs[st].ST_Out & B11000000); 
    delay(fs[st].Time/6);
  }
  else{  
    
 digitalWrite(LED_peo_R,fs[st].ST_Out & B01000000); 
 digitalWrite(LED_peo_G,fs[st].ST_Out & B10000000);  
 delay(fs[st].Time);
    
  }
  
  input0 = analogRead(BUTTON_NORTH);
  input1 = analogRead(BUTTON_EAST);
  input2 = digitalRead(BUTTON_people);
  
  if(input0 > 15){
    input0=1;
    }
   else{
    input0=0;
   }
  
  if(input1 > 15){
    input1=1;
    }
    else{
      input1=0;
    }

  Serial.print(input2);
  Serial.print(" ");
  Serial.print(input0);
  Serial.print(" ");
  Serial.println(input1);
  input = input0*2 + input1 + input2*4;
  if(toggle_all_intput == true && st == 5 && input == 7){
    input = 7;
    toggle_all_intput = false;
  }
  else if(toggle_all_intput == false && st == 5 && input == 7){
    input = 8;
    toggle_all_intput = true;
  }
 
  st = fs[st].NextST[input];
//  Serial.println(input);



  
}
