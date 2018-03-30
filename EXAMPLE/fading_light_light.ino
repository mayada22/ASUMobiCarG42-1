int ledpin=4;
int i;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<255;i++)
{
  analogWrite(ledpin,i);
  delay(50);
}
for(i=255;i>0;i--)
{
  analogWrite(ledpin,i);
  delay(50);
}
}
