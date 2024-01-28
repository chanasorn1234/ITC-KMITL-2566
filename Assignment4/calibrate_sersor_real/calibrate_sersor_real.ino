int sensor0 = A0;
int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;

void setup() {
    pinMode(sensor0, INPUT);
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);
    Serial.begin(9600);

}

void loop() {
  int ss0 = analogRead(sensor0);//200
  int ss1 = analogRead(sensor1);//17
  int ss2 = analogRead(sensor2);//250
  int ss3 = analogRead(sensor3);//300
  int ss4 = analogRead(sensor4);//500

  Serial.print(ss0);
  Serial.print(" ");
  Serial.print(ss1);
  Serial.print(" ");
  Serial.print(ss2);
  Serial.print(" ");
  Serial.print(ss3);
  Serial.print(" ");
  Serial.println(ss4);
  delay(500);
}
