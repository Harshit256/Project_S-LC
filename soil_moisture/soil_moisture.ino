void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//char ch;  
int sensorValue = analogRead(A0);
Serial.print(sensorValue);
//Serial.println("Moisture Content \tType");
/*if(sensorValue>=1000)
  {
    ch="D";
  }
 else if(sensorValue>=37 && sensorValue<1000)
 {
  ch="M";
 }
 else
 {
  ch="W";
 }
 
Serial.print(sensorValue);
Serial.print("\t\t");
Serial.print("%s",ch);*/

delay(1000);
}
