#include "SoftwareSerial.h"// import the serial library\

const int EN1=5; // Right front wheel 
const int EN2=6; // Right back wheel 
const int EN3=10; // Left front wheel
const int EN4=11; // left back wheel

// inputs  " input 1 and 0 will make the wheel rotate clockwise and vise versa " 
int Inright1 = 2 ; // input 1 of the right half of the car
int Inright2 = 3 ; // input 2 of the right half of the car
int Inleft1 = 7 ; // input 1 of the left half of the car
int Inleft2 = 8 ; // input 2 of the left half of the car

int BluetoothData; // save data recieved from the bluetooth module
 SoftwareSerial HC05 (10,11); // RX, TX
 int  Speed=255;


/////SETUP/////////////////////////////////////////////////////////////////////////////////
void setup() {
// fIRST , define the Motor's pin as an OUTPUT
HC05.begin(9600);

pinMode( EN1 ,OUTPUT);// Right Motor front wire
pinMode( EN2 ,OUTPUT);// Right Motor back wire
pinMode( EN3 ,OUTPUT);// left Motor front wire
pinMode( EN4 ,OUTPUT);// left Motor back wire

pinMode( Inright1 ,OUTPUT);
pinMode( Inright2 ,OUTPUT);
pinMode( Inleft1 ,OUTPUT);
pinMode( Inleft2 ,OUTPUT);


Serial.begin(9600); // Starting Serial Terminal

}



// the two back wheels are hooked up so that they always rotate clockwise "make the car move forwards " when Enable isn't off "0"
// the two front wheels are hooked up so that they alwats rotate counter clockwise " it makes the car move backwards and helps with the left/right movements " as long as enable isn't off "0"
void FORWARD(int Speed){

  // move the 
  analogWrite(EN1,Speed);  // RF off
  analogWrite(EN2,Speed); //RB on
  analogWrite(EN3,Speed); // LF off
  analogWrite(EN4,Speed); // LB on

  digitalWrite(Inright1,1);
  digitalWrite(Inright2,0);
  digitalWrite(Inleft1,1);
  digitalWrite(Inleft2,0);

}
void BACKWARD(int Speed){
  
  analogWrite(EN1,Speed); // RF on
  analogWrite(EN2,Speed); // RB off 
  analogWrite(EN3,Speed); // LF on 
  analogWrite(EN4,Speed); // LB off 

  digitalWrite(Inright1,0);
  digitalWrite(Inright2,1);
  digitalWrite(Inleft1,0);
  digitalWrite(Inleft2,1);
}
void LEFT(int Speed){
  
  analogWrite(EN1,0); // RF off
  analogWrite(EN2,Speed); // RB on 
  analogWrite(EN3,Speed); // LF on
  analogWrite(EN4,0); // LB off

  digitalWrite(Inright1,1);
  digitalWrite(Inright2,0);
  digitalWrite(Inleft1,0);
  digitalWrite(Inleft2,1);
}
void RIGHT(int Speed){

  analogWrite(EN1,Speed); // RF on
  analogWrite(EN2,0); // RB off
  analogWrite(EN3,0); // LF off
  analogWrite(EN4,Speed); // LB off
  
  digitalWrite(Inright1,0);
  digitalWrite(Inright2,1);
  digitalWrite(Inleft1,1);
  digitalWrite(Inleft2,0);
  
  }

void Stop(){

  analogWrite(EN1,0);
  analogWrite(EN2,0);
  analogWrite(EN3,0);
  analogWrite(EN4,0);
}

void loop() {

 if (HC05.available()){
 BluetoothData=HC05.read();
 Serial.println(BluetoothData);

/// FORWARD ///
  if(BluetoothData=='F'){   // if Forward direction pressed .... 
    
   FORWARD(Speed);
   }

/// BACKWWARD ///
  if(BluetoothData=='B'){   // if Back direction pressed .... 

  BACKWARD(Speed);}


/// LEFT ///   
  if(BluetoothData=='L'){   // if Left direction pressed .... 

  RIGHT(Speed);}


 /// RIGHT ///
  if(BluetoothData=='R'){   // if Right direction pressed ....

    LEFT(Speed);}
   
    
  if(BluetoothData=='S'){   // if nothing pressed ....
  Stop();}

   if(BluetoothData=='0'){  Speed=25 ;} 
   if(BluetoothData=='1'){  Speed=50; }
   if(BluetoothData=='2'){  Speed=75; } 
   if(BluetoothData=='3'){  Speed=100; } 
   if(BluetoothData=='4'){  Speed=125; } 
   if(BluetoothData=='5'){  Speed=150; } 
   if(BluetoothData=='6'){  Speed=175; } 
   if(BluetoothData=='7'){  Speed=200; } 
   if(BluetoothData=='8'){  Speed=225; } 
   if(BluetoothData=='9'){  Speed=255; } 
   if(BluetoothData=='q'){  Speed=255; }  
  }
}




