const int LED = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);   //to turn on led
//time on=2000*0.25
delay(500);
digitalWrite(LED,LOW);    //to turn off led
//time off=2000*0.75
delay(1500);
}


