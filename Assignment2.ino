#include "ST7735_TEE.h"
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;
const byte PIN_A = 2;
const byte PIN_B = 3;
const byte PIN_C = 4;
const byte PIN_D = 5;
const byte PIN_E = 6;
const byte PIN_F = 7;
const byte PIN_K = 8;

int ship_x = 57;
int pre_chip_x;
int ship_y = 145;
int changepo_ship_x;
int ship_height = 10;
int ship_width = 10;


boolean state_bullet = true;
int bullet_x;
int bullet_y;
int bullet_radius = 2;
int pre_bullet_y;


boolean state_enemy = true;
int random_move_enemy;
int random_direction_enemy;
int ship_enemy_x = 57;
int ship_enemy_y = 13;
int pre_chip_enemy_x;
int count_move = 0;
boolean state_bullet_enemy = true;
int shot_enemy;
int bullet_enemy_x;
int bullet_enemy_y;
int pre_bullet_enemy;


int button_c;
TEE_ST7735 lcd(9, 10, 11, 12, 13); //Arduino  csk,sda,A0,rst,cs
void setup() {
    lcd.init(lcd.VERTICAL);
    lcd.fillScreen(BLACK);
    Serial.begin(9600);
    Serial.println(lcd.width);
    Serial.println(lcd.height);
    
}

void loop() {
  Game_lunch();


}

void Game_lunch(){
  
  changepo_ship_x = analogRead(PIN_ANALOG_X);
  button_c = digitalRead(4);
  
  lcd.fillRect(ship_x, ship_y, ship_width, ship_height, YELLOW);//ship


  if(state_enemy == true){
  lcd.fillRect(ship_enemy_x, ship_enemy_y, ship_width, ship_height,BLUE);//ememy ship
  }
  random_enemy();//เคลื่อนที่ยานศัตรู
  if(random_direction_enemy == 0 && pre_chip_enemy_x >= 2){
    pre_chip_enemy_x = ship_enemy_x;
    ship_enemy_x -= 2;
    lcd.fillRect(pre_chip_enemy_x+ship_width, ship_enemy_y, ship_width, ship_height, BLACK);//delete ship
    pre_chip_enemy_x -= 2;
    }
   if(random_direction_enemy == 1 && pre_chip_enemy_x <= 118){
     pre_chip_enemy_x = ship_enemy_x;
    ship_enemy_x += 2;
    lcd.fillRect(pre_chip_enemy_x-ship_width, ship_enemy_y, ship_width, ship_height, BLACK);//delete ship
    pre_chip_enemy_x += 2;
    }
    
   shot_enemy = random_shot_enemy();//ศัตรูยิงกระสุน
   if(shot_enemy == 1 && state_bullet_enemy != false){
      state_bullet_enemy = false;
      bullet_enemy_x = ship_enemy_x + (ship_width/2);
      bullet_enemy_y = ship_enemy_y + (ship_height);
    }
   if(state_bullet_enemy == false){
    lcd.fillCircle(bullet_enemy_x,bullet_enemy_y,bullet_radius,RED);//bullet enemy
    pre_bullet_enemy = bullet_enemy_y-2-bullet_radius;
    bullet_enemy_y += 4;
    lcd.fillCircle(bullet_enemy_x,pre_bullet_enemy,bullet_radius,BLACK);//delete bullet
    pre_bullet_enemy += 1;
    if(bullet_enemy_y >= 160){
        lcd.fillCircle(bullet_enemy_x,pre_bullet_enemy+3,bullet_radius+1,BLACK);//delete bullet
      state_bullet_enemy = true;     
      }
   }
    
    

    
  if(changepo_ship_x <= 10 && ship_x>0){
      pre_chip_x = ship_x;
      if(state_bullet == false){ //ปรับความเร็วยาน  เวลายิงกระสุนแล้วเคลื่อนช้า
        ship_x -= 1;
        }
      ship_x -= 2;
      lcd.fillRect(pre_chip_x+ship_width, ship_y, ship_width, ship_height, BLACK);//delete ship
      pre_chip_x -= 1;
      Serial.println(changepo_ship_x);
    }
   if(changepo_ship_x >= 1000 && ship_x<118){
      pre_chip_x = ship_x;
      if(state_bullet == false){//ปรับความเร็วยาน  เวลายิงกระสุนแล้วเคลื่อนช้า
        ship_x += 1;
        }
      ship_x += 2;
      lcd.fillRect(pre_chip_x-ship_width, ship_y, ship_width, ship_height, BLACK);//delete ship
      pre_chip_x += 1;
      Serial.println(changepo_ship_x);
    }
    if(button_c == 0 && state_bullet != false){
      state_bullet = false;
      bullet_x = ship_x+(ship_width/2);
      bullet_y = ship_y-(ship_height/2);
       
      }
     if(state_bullet == false){
      lcd.fillCircle(bullet_x,bullet_y,bullet_radius,WHITE);//bullet
      pre_bullet_y = bullet_y+2+bullet_radius;
      bullet_y -= 3;
      lcd.fillCircle(bullet_x,pre_bullet_y,bullet_radius,BLACK);//delete bullet
      pre_bullet_y -= 1;
      if(bullet_y <= 2){
        lcd.fillCircle(bullet_x,pre_bullet_y-3,bullet_radius+1,BLACK);//delete bullet
      state_bullet = true;     
      }
     }

  
}

void random_enemy(){
    if(count_move == 0){  
      random_direction_enemy = random(0,2);
    }
    if(count_move != 10){
      if(pre_chip_enemy_x >= 118 || pre_chip_enemy_x <=2){
        count_move = 0;
        return;
        }
        count_move += 1;
    }
    if(count_move == 10){count_move = 0;}
      Serial.print(random_direction_enemy);
      Serial.print(" ");
      Serial.println(count_move);
  }
int random_shot_enemy(){
    return random(0,2);
  }
