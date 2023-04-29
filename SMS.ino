#include <SoftwareSerial.h>
  SoftwareSerial mySerial(7, 8);
  void setup()
  {
    pinMode(3,OUTPUT);
    digitalWrite(3,0);
Serial.begin(9600);
mySerial.begin(9600);
Serial.println("Initializing...");
delay(1000);
mySerial.println("AT");
updateSerial();
mySerial.println("AT+CMGF=1");
updateSerial();
mySerial.println("AT+CNMI=1,2,0,0,0");
updateSerial();
}
void loop()
{
updateSerial();
}
 
void updateSerial()
{
delay(500);
while (Serial.available()) 
{
mySerial.write(Serial.readString());
String st=mySerial.readString();
if (st=="SOS"){
  digitalWrite(3,1);
}
}
while(mySerial.available()) 
{
Serial.write(mySerial.readString());
String st=mySerial.readString();
if (st=="SOS"){
  digitalWrite(3,1);
}
}
}
