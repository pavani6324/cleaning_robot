#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
#define echoPin 3
#define trigPin 2
int a=0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
   pinMode(14, OUTPUT);
  digitalWrite(14,LOW);

  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
    Serial.begin(9600);

  mySerial.begin(9600);
       mySerial.print("Welcome\n\r");
} 

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration)/2) / 29.1;
  Serial.print("D1:");
  Serial.print(distance);
  Serial.print("\n");
 delay(200);
  if(distance<=30)
  {
    mySerial.print("Obstacle detected...\n\r");
    digitalWrite(14, HIGH);
    digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
delay(500);
    digitalWrite(14, LOW);
delay(500);
  }
  /*if(digitalRead(14)==LOW)
    {
           Serial.print("Alert! Metal detected with \n\r");
delay(1000);
    }
    if(a==1)
    {
    if(digitalRead(14)==LOW)
    {
      mySerial.print("Forward\n\r");
    digitalWrite(7,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);     delay(500);

    }
    
    else if(digitalRead(15)==LOW)
    {
     digitalWrite(7,LOW);
     digitalWrite(6,HIGH);
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     mySerial.print("Backward\n\r");
          delay(500);

    }
    
    else if(digitalRead(16)==LOW)
    {
     digitalWrite(6,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     mySerial.print("Left\n\r");
          delay(500);

    }
    
    else if(digitalRead(17)==LOW)
    {
     digitalWrite(7,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     mySerial.print("Right\n\r");
     delay(500);
    }
    else
    {

     digitalWrite(7,LOW);
     digitalWrite(6,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     mySerial.print("STOP\n\r");     delay(500);

    }
  }*/
  if (mySerial.available() > 0)
  { 
    char c = mySerial.read();
    if (c == 'C')
    {
     mySerial.print("Sprayer ON\n\r");
     digitalWrite(8, LOW);
     //a=1;
    }
    if (c == 'D')
    {
     mySerial.print("Sprayer OFF\n\r");
     digitalWrite(8, HIGH);
     //a=1;
    }
    if (c == 'F')
    {
      a=0;
     mySerial.print("Forward\n\r");
      digitalWrite(7,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     
    }
    
    if(c=='B')
    {      a=0;

     digitalWrite(7,LOW);
     digitalWrite(6,HIGH);
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     mySerial.print("Backward\n\r");
     
    }
    
    if(c=='L')
    {      a=0;

     digitalWrite(6,HIGH);
     digitalWrite(7,LOW);
     digitalWrite(5,HIGH);
     digitalWrite(4,LOW);
     mySerial.print("Left\n\r");
     
    }
    
    if(c=='R')
    {      a=0;

     digitalWrite(7,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,HIGH);
     mySerial.print("Right\n\r");
     
    }
    if(c=='S')
    {      a=0;

     digitalWrite(7,LOW);
     digitalWrite(6,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
     mySerial.print("Stop\n\r");
    }
   /*if(c=='A')
    {
     digitalWrite(12,LOW);
     Serial.print("Fan ON\n\r");
    }
    if(c=='C')
    {
     digitalWrite(12,HIGH);
     Serial.print("Fan OFF\n\r");
    }
    /*if(digitalRead(14)==HIGH)
    {
           Serial.print("Alert! Metal detected\n\r");
delay(1000);
    }*/
}
}
