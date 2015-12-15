#include <Servo.h>


int MOTOR1_DIR1 = 2;
int MOTOR1_DIR2 = 3;
int MOTOR1_SPEED = 9;

int MOTOR2_DIR1 = 4;
int MOTOR2_DIR2 = 5;
int MOTOR2_SPEED = 10;

int BUTTON_1 = 6;
int BUTTON_2 = 7;

Servo servo1;

void dropMili(int mil) {
  mil /= 1.16;
  servo1.write(125);
  delay(1000);
  servo1.write(180);
}

void setup() {
  //pinMode(11, OUTPUT);
  Serial.begin(9600);
  
  servo1.attach(11);
  
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);

  pinMode(MOTOR1_DIR1, OUTPUT);
  pinMode(MOTOR1_DIR2, OUTPUT);
  pinMode(MOTOR1_SPEED, OUTPUT);
  pinMode(MOTOR2_DIR1, OUTPUT);
  pinMode(MOTOR2_DIR2, OUTPUT);
  pinMode(MOTOR2_SPEED, OUTPUT);
  
  servo1.write(180);
}

void moveLeft(int speed) {
    analogWrite(MOTOR1_SPEED, speed);
    digitalWrite(MOTOR1_DIR1, LOW);
    digitalWrite(MOTOR1_DIR2, HIGH);

    analogWrite(MOTOR2_SPEED, speed);
    digitalWrite(MOTOR2_DIR1, LOW);
    digitalWrite(MOTOR2_DIR2, HIGH);
}

void moveRight(int speed) {
    analogWrite(MOTOR1_SPEED, speed);
    digitalWrite(MOTOR1_DIR1, HIGH);
    digitalWrite(MOTOR1_DIR2, LOW);

    analogWrite(MOTOR2_SPEED, speed);
    digitalWrite(MOTOR2_DIR1, HIGH);
    digitalWrite(MOTOR2_DIR2, LOW);
}

void stopMotors() {
    analogWrite(MOTOR1_SPEED, 0);
    digitalWrite(MOTOR1_DIR1, LOW);
    digitalWrite(MOTOR1_DIR2, HIGH);

    analogWrite(MOTOR2_SPEED, 0);
    digitalWrite(MOTOR2_DIR1, LOW);
    digitalWrite(MOTOR2_DIR2, HIGH);
}

void loop() {

  if (digitalRead(BUTTON_1) == LOW && digitalRead(BUTTON_2) == LOW) {
    servo1.write(125);
    delay(200);
    while (!(digitalRead(BUTTON_1) == LOW && digitalRead(BUTTON_2) == LOW)) {
      delay(10);
      stopMotors();
    }
    servo1.write(180);
    delay(200);
  }

  else if (digitalRead(BUTTON_1) == LOW && digitalRead(BUTTON_2) == HIGH) {
    moveRight(255);
  }

  else if (digitalRead(BUTTON_1) == HIGH && digitalRead(BUTTON_2) == LOW) {
    moveLeft(255);
  }

  else {
    stopMotors();
  }


  
//  if (digitalRead(2) == LOW) {
//    servo1.write(125);  
//  }
//  if (digitalRead(3) == LOW) {
//    servo1.write(180);
//  } 
}
