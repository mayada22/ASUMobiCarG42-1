
const int buttonPin = 2;     
const int led =  13;      
int val = 0;        

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
 
  val = digitalRead(buttonPin);
  if (val == HIGH) {
  
    digitalWrite(led, HIGH);
    delay (1000);
    digitalWrite(led , LOW);
    delay(1000);
  } 
  else {
    digitalWrite(led, LOW);
  }
}
