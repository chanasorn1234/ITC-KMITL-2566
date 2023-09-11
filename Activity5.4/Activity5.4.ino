const byte numpins = 8;
const int segmentpin[8] = {2,3,4,5,6,7,8,9};
const int bitpattern[11] = {B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01101111,B10000000};
int display;
void setup() {
  Serial.begin(9600);
  for(int i=0;i<numpins;i++){
    //Serial.println(i);
    pinMode(segmentpin[i],OUTPUT);
    digitalWrite(segmentpin[i],HIGH);
  }
 Serial.print("Please Enter Number: ");
}

void loop() {
  
  if(Serial.available()>0){
    String val = Serial.readStringUntil('\n');
    if(val=="0"){
      display = 0;
    }
    else if(val=="1"){
      display = 1;
    }
    else if(val=="2"){
      display = 2;
    }
    else if(val=="3"){
      display = 3;
    }
    else if(val=="4"){
      display = 4;
    }
    else if(val=="5"){
      display = 5;
    }
    else if(val=="6"){
      display = 6;
    }
    else if(val=="7"){
      display = 7;
    }
    else if(val=="8"){
      display = 8;
    }
    else if(val=="9"){
      display = 9;
    }
    else{
      display = 10;
    }  
//    Serial.println(display);
     boolean isbitset;
 for(int segment =0;segment<8;segment++){
    isbitset = bitRead(bitpattern[display],segment);
    isbitset = !isbitset;
   digitalWrite(segmentpin[segment],isbitset);
//    Serial.print(isbitset);
    
  }
  if(display == 10){
    Serial.println(val);
    Serial.print("Input isn't number");
    Serial.println("  !!! Try Again !!!");
    
    }else{
    Serial.print(val);
    Serial.println("");
    }
    Serial.print("Please Enter Number: ");
  }


//    isbitset = bitRead(bitpattern[0],1);
 //  digitalWrite(2,HIGH);
//    Serial.println(isbitset);
    
  











}
