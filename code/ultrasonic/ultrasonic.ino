#include <Servo.h>
Servo servo1;
int pos1 = 0;
#define trig 10
#define echo 8
#define button 11
long duration, distance, ClosestTarget, AngleTarget;
void setup()
{
Serial.begin(9600);
servo1.attach(9);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(button, INPUT);
}
void loop()
{
if(digitalRead(button)==HIGH)
{
for(pos1 = 0; pos1 < 180; pos1 += 1) { servo1.write(pos1); 
delay(10); 
digitalWrite(trig, LOW); 
delayMicroseconds(2); 
digitalWrite(trig, HIGH); 
delayMicroseconds(10); 
digitalWrite(trig, LOW); 
duration = pulseIn(echo, HIGH); // Wait for HIGH, timer on, timer ends on LOW distance = duration / 58; if(ClosestTarget>distance)
{
ClosestTarget=distance;
AngleTarget=pos1;
}
}
for(pos1 = 180; pos1>=1; pos1-=1)
{
servo1.write(pos1);
delay(10);
}
Serial.print("Closest Target = " );
Serial.print(ClosestTarget);
Serial.println(" ");
Serial.print("Target Angle = " );
Serial.print(AngleTarget);
Serial.println(" ");
ClosestTarget = 1000;
}
}
