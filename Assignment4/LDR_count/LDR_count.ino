int count = 0;
bool toggle_count = true;

void setup() {
  pinMode(A5,INPUT);
  Serial.begin(9600);
}

void loop() {

  int inp = analogRead(A5);
  Serial.print(inp);
  Serial.print(" ");
  Serial.println(count);
  
  int start_time = millis();
  if(inp < 300 && toggle_count == true){//350
    count += 1;
    toggle_count = false;
//    while(millis() - start_time < 3000){
//      inp = analogRead(A5);
//      if(inp > 500){
//        toggle_count = true;
//        break;
//      }
//    }
  }
   if(inp > 400){//380
    toggle_count = true;
    
   }
}
