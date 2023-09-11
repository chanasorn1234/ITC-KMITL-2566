const byte numpins = 8;
const int segmentpin[8] = {10,11,4,5,6,7,8,9};
const int bitpattern[11] = {B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01101111,B10000000};
const int guess_result[3] = {B00111111,B00110001,B00111000};
int display = 1;
int random_number;
boolean lunch_game = true;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  attachInterrupt(0,handdle_add_button,RISING);
  attachInterrupt(1,haddle_guest_button,RISING);
  for(int i=0;i<numpins;i++){
    //Serial.println(i);
    pinMode(segmentpin[i],OUTPUT);
    digitalWrite(segmentpin[i],HIGH);
  }
  boolean isbitset2;
   for(int segment =0;segment<8;segment++){
    isbitset2 = bitRead(bitpattern[display],segment);
    isbitset2 = !isbitset2;
   digitalWrite(segmentpin[segment],isbitset2);
//    Serial.print(isbitset);
    
  }
  
}

void loop() {
  
  if(lunch_game == true){
    random_number = random(1,10);
    Serial.print("Answer is ");
    Serial.println(random_number);
    lunch_game = false;
  }
 
}

void handdle_add_button(){
   display += 1;
  if(display>9){display=1;}
//    Serial.println(display);
   boolean isbitset;
 for(int segment =0;segment<8;segment++){
    isbitset = bitRead(bitpattern[display],segment);
    isbitset = !isbitset;
   digitalWrite(segmentpin[segment],isbitset);
//    Serial.print(isbitset);
    
  }
   
}

void haddle_guest_button(){
  int result_display;
  if(display==random_number){
    result_display=0;
    Serial.print("You win!!! your number is ");
    Serial.print(display);
    Serial.print(" And answer is ");
    Serial.println(random_number);
    lunch_game = true;
    
  }
  else if(display>random_number){
    result_display=2;
    Serial.print("You lose your number is ");
    Serial.print(display);
    Serial.print(" And answer is ");
    Serial.println(random_number);
  }
  else{
    result_display=1;
    Serial.print("You lose your number is ");
    Serial.print(display);
    Serial.print(" And answer is ");
    Serial.println(random_number);
  }
   boolean isbitset;
  for(int segment =0;segment<8;segment++){
    isbitset = bitRead(guess_result[result_display],segment);
    isbitset = !isbitset;
   digitalWrite(segmentpin[segment],isbitset);
//    Serial.print(isbitset);
    
  }
  
  
  
  
  
  
  
}
