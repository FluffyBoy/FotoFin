
unsigned int StartTime=0,SetTime=0;
int den=72;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(17);
Serial.println("Timer stable 1111");
}

void loop() {
  Serial.println("Timer stable");
  int startDist=analogRead(A0);
  int diff=abs(analogRead(A0)-startDist);
  while(diff<den){diff=abs(analogRead(A0)-startDist);}
  StartTime=millis();Serial.print(diff);Serial.println(" Start");
  while(diff>den){diff=abs(analogRead(A0)-startDist);}
  while(diff<den){diff=abs(analogRead(A0)-startDist);}
  SetTime=millis()-StartTime;
  Serial.print("Time");Serial.println(SetTime);
  delay(1999);
  

}
