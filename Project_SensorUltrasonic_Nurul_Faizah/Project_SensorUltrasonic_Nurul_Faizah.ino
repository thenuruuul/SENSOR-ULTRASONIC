const int trigger = 7;
const int echo = 6;
const int led = 13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long duration;
long cm;
pinMode(trigger, OUTPUT);
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
pinMode(echo, INPUT);
duration = pulseIn(echo, HIGH);
cm = microsecondsToCentimeters(duration);
if(cm <= 200) {
  digitalWrite(led, HIGH);
}
else{
  digitalWrite(led, LOW);
}
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);
}

long microsecondsToCentimeters(long microseconds)
{return microseconds*0.034/2;
}
