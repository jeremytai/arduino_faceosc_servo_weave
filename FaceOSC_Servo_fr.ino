// FaceOSC Servo Action
// by Truth Dare Double Dare / http://truthdaredoubledare.com
// Jeremy Tai Abbett / Franziska Hübler

#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
int pos = 0;    // variable to store the servo position 

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 

void loop() 
{ 
  boolean update = false;
  while(Serial.available() > 0) {
    byte temp = Serial.read();
    
    if(temp == '.') {
      update = true;
      break;
    } 
    else {
      pos *= 10; // shift the currently stored position
      pos += (temp - '0'); // Add the new digit;
      myservo.write(pos); 
    }
  }

  if(update && pos >= 0 && pos <= 180) {
    pos = 0;
  }
  else if(update) {
    pos = 0;
  }
}
