int led=13;
int button=9;
int flag;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(button,INPUT);
}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(led,LOW);
flag= digitalRead(button);
while (flag==1){
digitalWrite(led,HIGH);
if (flag==0)
break;
}
}
