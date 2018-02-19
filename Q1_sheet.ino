int pinLED = 9 ; // the pin number I want to use 
float Time = 2000 ; // total time  

void setup() {
  pinMode ( pinLED , OUTPUT ) ; // Declare pin to be Output
}

void loop() {
digitalWrite ( pinLED , 1 ) ; // turn on for 0.25*Time " Duty cycle of 25%"
delay (0.25 * Time ) ;
digitalWrite ( pinLED , 0 ) ;
delay (0.75 * Time ) ;
}
