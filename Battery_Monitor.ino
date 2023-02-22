
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 0); // RX, TX
 
//Inputs
int in1 = A3; // Voltage
int in2 = A2; // Current
int in3 = A0; // Speed
int led = 1 ;
int speed ;

void setup() {
  mySerial.begin(9600);
  pinMode(in1,INPUT);  
  pinMode(in2,INPUT);  
  pinMode(in3,INPUT);  
  pinMode(led,OUTPUT);  
}

void loop() {
    speed = map(analogRead(in3), 0, 1023, 25, 1000);
    mySerial.print("A");                                 
    mySerial.println(analogRead(in2));                               
    mySerial.print("V");                                
    mySerial.println(analogRead(in1));  
    digitalWrite(led, !digitalRead(led));                  
    delay(speed);                                       
}
