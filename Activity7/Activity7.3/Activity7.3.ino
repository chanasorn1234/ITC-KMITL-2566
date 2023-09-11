#include "LedControl.h"

LedControl lc=LedControl(11,13,10,4);  // CLK,DIN,CS,Number of LED Module

unsigned long delaytime=70;  // time to updates of the display

void setup() {
  int devices=lc.getDeviceCount();  // find no of LED modules
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {  // set up each device 
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
}

void loop() { 
  int devices=lc.getDeviceCount();  // find no of LED modules
//  lc.setLed(0,0,0,true);
//  lc.setLed(0,0,1,true);
    for(int col=0;col<6;col++){
        lc.setLed(0,0,col,true);
        delay(delaytime);
        lc.setLed(0,0,col+1,true);
        delay(delaytime);
        lc.setLed(0,0,col,false);
        lc.setLed(0,0,col+1,false);
     
    }
        
      for(int row=0;row<7;row++){
        lc.setLed(0,row,7,true);
        delay(delaytime);
        lc.setLed(0,row+1,7,true);
        delay(delaytime);
        lc.setLed(0,row,7,false);
        lc.setLed(0,row+1,7,false);
     
    }
        for(int col=7;col>=1;col--){
        lc.setLed(0,7,col,true);
        delay(delaytime);
        lc.setLed(0,7,col-1,true);
        delay(delaytime);
        lc.setLed(0,7,col,false);
        lc.setLed(0,7,col-1,false);
     
    }
        for(int row=7;row>=1;row--){
        lc.setLed(0,row,0,true);
        delay(delaytime);
        lc.setLed(0,row-1,0,true);
        delay(delaytime);
        lc.setLed(0,row,0,false);
        lc.setLed(0,row-1,0,false);
    }
}
