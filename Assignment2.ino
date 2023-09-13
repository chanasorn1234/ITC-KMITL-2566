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
int hp = 5;
boolean delete_hp = false;
boolean limit_delete_hp = false;
int hitbox[4];// เก็บ hitbox
int count_item = 0;


boolean state_bullet = true;
int bullet_x;
int bullet_y;
int bullet_radius = 2;
int pre_bullet_y;
int speed_chip =3;
int speed_bullet = 3;


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
int speed_bullet_enemy = 4;
int pre_bullet_enemy=0;
int hitbox_enemy[4];// เก็บ hitbox ศัตรู
int hp_enemy = 7;
boolean delete_hp_enemy = false;
boolean limit_delete_hp_enemy = false;
int multl_bullet_x[3];
int multl_bullet_y[3];
int pre_multibullet_y[3];
int speed_chip_enemy = 2;


int button_c;
TEE_ST7735 lcd(9, 10, 11, 12, 13); //Arduino  csk,sda,A0,rst,cs
void setup() {
    lcd.init(lcd.VERTICAL);
    lcd.fillScreen(BLACK);
    Serial.begin(9600);
    Serial.print("Enemy HP: ");
    Serial.println(hp_enemy);
    Serial.print("Your HP: ");
    Serial.println(hp);
    
}

void loop() {
  Game_lunch();

//  lcd.drawCircle(52,74,7,WHITE);
//lcd.drawChar(50, 70, 'H', YELLOW, 1);
}

void Game_lunch(){

  changepo_ship_x = analogRead(PIN_ANALOG_X);
  button_c = digitalRead(4);

  if(hp <= 2){
    lcd.fillRect(ship_x, ship_y, ship_width, ship_height, CYAN);//ship
  }else{
    lcd.fillRect(ship_x, ship_y, ship_width, ship_height, YELLOW);//ship
  }
  
  hitbox[0] = ship_x;
  hitbox[1] = ship_x + ship_width;
  hitbox[2] = ship_y;
  if(delete_hp == true){
    hp -= 1;
    lcd.fillRect(ship_x, ship_y, ship_width, ship_height, WHITE);
    delete_hp = false;
//    limit_delete_hp = true;
    Serial.print("Enemy HP: ");
    Serial.println(hp_enemy);
    Serial.print("Your HP: ");
    Serial.println(hp);
  }

   ///ศัตรู///
  if(state_enemy == true){
  if(delete_hp_enemy == true){
    hp_enemy -= 1;
    lcd.fillRect(ship_enemy_x, ship_enemy_y, ship_width, ship_height,WHITE);
    delete_hp_enemy = false;
//    limit_delete_hp_enemy = true;
    Serial.print("Enemy HP: ");
    Serial.println(hp_enemy);
    Serial.print("Your HP: ");
    Serial.println(hp);
  }
  if(hp_enemy <= 3){
    lcd.fillRect(ship_enemy_x, ship_enemy_y, ship_width, ship_height,RED);//ememy ship
    speed_bullet_enemy = 5;
    speed_chip = 4;
    speed_bullet = 4;
    speed_chip_enemy = 3;
  }
  else{
    lcd.fillRect(ship_enemy_x, ship_enemy_y, ship_width, ship_height,BLUE);//ememy ship
  }
  hitbox_enemy[0] = ship_enemy_x;
  hitbox_enemy[1] = ship_enemy_x + ship_width;
  hitbox_enemy[2] = ship_enemy_y + ship_height;
//  Serial.println(hp_enemy);
  }
  
  random_enemy();//เคลื่อนที่ยานศัตรู
  if(random_direction_enemy == 0 && pre_chip_enemy_x >= 2){
    pre_chip_enemy_x = ship_enemy_x;
    ship_enemy_x -= speed_chip_enemy;
    lcd.fillRect(pre_chip_enemy_x+ship_width, ship_enemy_y, ship_width, ship_height, BLACK);//delete ship
    pre_chip_enemy_x -= 1;
    }
   if(random_direction_enemy == 1 && pre_chip_enemy_x <= 118){
     pre_chip_enemy_x = ship_enemy_x;
    ship_enemy_x += speed_chip_enemy;
    lcd.fillRect(pre_chip_enemy_x-ship_width, ship_enemy_y, ship_width, ship_height, BLACK);//delete ship
    pre_chip_enemy_x += 1;
    }
    
   shot_enemy = random_shot_enemy();//ศัตรูยิงกระสุน
   if(shot_enemy == 1 && state_bullet_enemy != false){
      state_bullet_enemy = false;
      bullet_enemy_x = ship_enemy_x + (ship_width/2);
      bullet_enemy_y = ship_enemy_y + (ship_height);
    }
   if(state_bullet_enemy == false){
    if(hp_enemy > 3 || pre_bullet_enemy != 0){
    lcd.fillCircle(bullet_enemy_x,bullet_enemy_y,bullet_radius,RED);//bullet enemy
    pre_bullet_enemy = bullet_enemy_y-2-bullet_radius;
    bullet_enemy_y += speed_bullet_enemy;
    lcd.fillCircle(bullet_enemy_x,pre_bullet_enemy,bullet_radius+1,BLACK);//delete bullet
    pre_bullet_enemy += 2;
    if(bullet_enemy_y >= 160){
        lcd.fillCircle(bullet_enemy_x,pre_bullet_enemy+3,bullet_radius+1,BLACK);//delete bullet
      state_bullet_enemy = true;
      pre_bullet_enemy = 0;  
//      limit_delete_hp = false;   
      }
//    bullet_enemy_coliision_ship(bullet_enemy_x,bullet_enemy_y,pre_bullet_enemy,-1);
    if(delete_hp == false && ((bullet_enemy_x-bullet_radius >= hitbox[0] && bullet_enemy_x-bullet_radius <= hitbox[1]) || (bullet_enemy_x+bullet_radius <= hitbox[1] && bullet_enemy_x+bullet_radius >= hitbox[0])) && bullet_enemy_y +bullet_radius >= hitbox[2]){
//           Serial.println("Collision");
           delete_hp = true;

           lcd.fillCircle(bullet_enemy_x,pre_bullet_enemy+3,bullet_radius+1,BLACK);//delete bullet
           pre_bullet_enemy = 0;
           state_bullet_enemy = true; 
     }
    }else{
      if(multl_bullet_x[0]>0){
        //state_bullet_enemy = true; 
        lcd.fillCircle(multl_bullet_x[0],multl_bullet_y[0],bullet_radius,RED);
        pre_multibullet_y[0] = multl_bullet_y[0]-2-bullet_radius;
        multl_bullet_y[0] += speed_bullet_enemy;
        lcd.fillCircle(multl_bullet_x[0],pre_multibullet_y[0],bullet_radius+1,BLACK);
        pre_multibullet_y[0] += 2;
        
        if(multl_bullet_y[0] >= 160){
        lcd.fillCircle(multl_bullet_x[0],pre_multibullet_y[0]+3,bullet_radius+1,BLACK);//delete bullet
        //state_bullet_enemy = true; 
        multl_bullet_x[0] = 0;
        }
        
    bullet_enemy_coliision_ship(multl_bullet_x[0],multl_bullet_y[0],pre_multibullet_y[0],0);
        
        if(multl_bullet_y[0] >= 70 && multl_bullet_y[0] <= 75 && multl_bullet_x[1] == 0){
          multl_bullet_x[1] = ship_enemy_x + (ship_width/2);
          multl_bullet_y[1] = ship_enemy_y + (ship_height);
        }
      }
      else if(multl_bullet_x[0] == 0){
        multl_bullet_x[0] = ship_enemy_x + (ship_width/2);
        multl_bullet_y[0] = ship_enemy_y + (ship_height);
        //lcd.fillCircle(multl_bullet_x[0],multl_bullet_y[0],bullet_radius,RED);
        
      }
      
     if(multl_bullet_x[1] > 0){
        //state_bullet_enemy = true; 
        lcd.fillCircle(multl_bullet_x[1],multl_bullet_y[1],bullet_radius,RED);
        pre_multibullet_y[1] = multl_bullet_y[1]-2-bullet_radius;
        multl_bullet_y[1] += speed_bullet_enemy;
        lcd.fillCircle(multl_bullet_x[1],pre_multibullet_y[1],bullet_radius+1,BLACK);
        pre_multibullet_y[1] += 2;
        

        if(multl_bullet_y[1] >= 160){
        lcd.fillCircle(multl_bullet_x[1],pre_multibullet_y[1]+3,bullet_radius+1,BLACK);//delete bullet
        multl_bullet_x[1] = 0;
//        multl_bullet_x[0] = 0;
        //state_bullet_enemy = true; 
        }
        bullet_enemy_coliision_ship(multl_bullet_x[1],multl_bullet_y[1],pre_multibullet_y[1],1);
      }
//      else if(multl_bullet_x[1] == 0){
//        multl_bullet_x[1] = ship_enemy_x + (ship_width/2);
//        multl_bullet_y[1] = ship_enemy_y + (ship_height);
//      }
       
    }
   }
    
   ///จบศัตรู///

    
  if(changepo_ship_x <= 10 && ship_x>2){
      pre_chip_x = ship_x;
      if(state_bullet == false){ //ปรับความเร็วยาน  เวลายิงกระสุนแล้วเคลื่อนช้า
        ship_x -= 1;
        }
      ship_x -= speed_chip;
      lcd.fillRect(pre_chip_x+(ship_width/2), ship_y, ship_width, ship_height, BLACK);//delete ship
      pre_chip_x -= 1;
//      Serial.println(changepo_ship_x);
    }
   if(changepo_ship_x >= 1000 && ship_x<116){
      pre_chip_x = ship_x;
      if(state_bullet == false){//ปรับความเร็วยาน  เวลายิงกระสุนแล้วเคลื่อนช้า
        ship_x += 1;
        }
      ship_x += speed_chip;
      lcd.fillRect(pre_chip_x-(ship_width/2), ship_y, ship_width, ship_height, BLACK);//delete ship
      pre_chip_x += 1;
//      Serial.println(changepo_ship_x);
    }
    if(button_c == 0 && state_bullet != false){
      state_bullet = false;
      bullet_x = ship_x+(ship_width/2);
      bullet_y = ship_y-(ship_height/2);
       
      }
     if(state_bullet == false){
      lcd.fillCircle(bullet_x,bullet_y,bullet_radius,WHITE);//bullet
      pre_bullet_y = bullet_y+2+bullet_radius;
      bullet_y -= speed_bullet;
      lcd.fillCircle(bullet_x,pre_bullet_y,bullet_radius,BLACK);//delete bullet
      pre_bullet_y -= 1;
      if(bullet_y <= 2){
        lcd.fillCircle(bullet_x,pre_bullet_y-3,bullet_radius+1,BLACK);//delete bullet
        state_bullet = true; 
//        limit_delete_hp_enemy = false; 
      }
        hitbox_enemy[0] = ship_enemy_x;
        hitbox_enemy[1] = ship_enemy_x + ship_width;
        hitbox_enemy[2] = ship_enemy_y + ship_height;
      if(state_bullet == false && ((bullet_x-bullet_radius >= hitbox_enemy[0] && bullet_x-bullet_radius <= hitbox_enemy[1]) || (bullet_x+bullet_radius <= hitbox_enemy[1] && bullet_x+bullet_radius >= hitbox_enemy[0])) && bullet_y-bullet_radius <= hitbox_enemy[2]){
//           Serial.println("Collision");
           delete_hp_enemy = true;

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
    if(count_move == 10){
      count_move = 0;
      }
//      Serial.print(random_direction_enemy);
//      Serial.print(" ");
//      Serial.println(count_move);
  }
int random_shot_enemy(){
    return random(0,2);
  }

void bullet_enemy_coliision_ship(int x,int y,int pre_y,int index){
  hitbox[0] = ship_x;
  hitbox[1] = ship_x + ship_width;
  hitbox[2] = ship_y;
      if(delete_hp == false && ((x-bullet_radius >= hitbox[0] && y-bullet_radius <= hitbox[1]) || (x+bullet_radius <= hitbox[1] && x+bullet_radius >= hitbox[0])) && y +bullet_radius >= hitbox[2]){
//            Serial.println("Collision");
           delete_hp = true;

           lcd.fillCircle(x,pre_y+3,bullet_radius+1,BLACK);//delete bullet

           if(hp_enemy > 3){
           state_bullet_enemy = true; 
           }
           else{
           if(index == 0){
            multl_bullet_x[0] = 0;
            multl_bullet_y[0] = 0;
           }
           else if(index == 1){
            multl_bullet_x[1] = 0;
            multl_bullet_y[1] = 0;
           }
           }
     }
 }










 
