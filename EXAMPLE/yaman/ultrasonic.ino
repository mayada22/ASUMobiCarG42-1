#include "SoftwareSerial.h"// import the serial library\


const int trigPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
long duration, distanceCm; // define time duration , distance in inches ,and cm
float minObstacleDistance = 5 ; // min distace of obstacle detection

long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}



/////SETUP/////////////////////////////////////////////////////////////////////////////////
void setup() {
Serial.begin(9600); // Starting Serial Terminal
pinMode (trigPin , OUTPUT ) ;
pinMode (echoPin , INPUT ) ; 
}


void loop() {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);
 distanceCm = microsecondsToCentimeters(duration);


  if ( distanceCm < minObstacleDistance ) 
  return 1 ; 

  else 
  return 0 ;
  
}


}




