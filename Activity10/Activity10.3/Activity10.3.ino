int enA = 10;
int enB = 6;
int in1 = 9;
int in2 = 8;
int in3 = 5;
int in4 = 4;

void setup()
{
// set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);

}
void loop()
{

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, 255); 
analogWrite(enB, 255); 

}
