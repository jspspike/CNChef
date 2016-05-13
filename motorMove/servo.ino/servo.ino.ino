#include <Servo.h>
#include <Wire.h>

Servo servo1;
Servo servo2;

int BUTTON_1 = 5;
int BUTTON_2 = 6;
int BUTTON_3 = 7;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);

  Wire.begin();

  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON_1) == HIGH) {
    Wire.beginTransmission(9);
    Wire.write(4);
    Wire.endTransmission();
    delay(4900);
    servo1.write(150);
    delay(1500);
    servo1.write(0);
    delay(1750)
    servo2.write(150);
  }

  if (digitalRead(BUTTON_2) == HIGH) {
    servo1.write(0);
    servo2.write(0);
    Wire.beginTransmission(9);
    Wire.write(1);
    Wire.endTransmission();
  }
//  servo1.write(130);
//  delay(1000);
}
