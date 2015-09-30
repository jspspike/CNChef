#include <Servo.h>

Servo servo1;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  
  servo1.attach(10);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  servo1.write(180);
}

void loop() {
  /*digitalWrite(9, 255);
  delay(5000);
  digitalWrite(9, 0);
  delay(3000);
  servo1.write(90);
  delay(2000);
  servo1.write(180);
  delay(2000);
  servo1.write(0);
  delay(2000);*/
  
  
  if (digitalRead(2) == LOW) {
    servo1.write(125);  
  }
  if (digitalRead(3) == LOW) {
    servo1.write(180);
  } 
}
