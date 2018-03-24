//ERFINDER CODE
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
const int trigPin = 45;
const int echoPin = 44;
int flag = 0;
// defines variables
long duration;
int distance = 100;
void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);   
  delay(100);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}


void loop()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance <= 15)
    {
      Serial.println("step1");
      delay(2000);
      SendMessage();
      Serial.println("step2");
      delay(2000);
    }
 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000); 
  mySerial.println("AT+CMGS=\"+919560823326\"\r");
  delay(1000);
  mySerial.println("The dustbin is full!!");
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

 