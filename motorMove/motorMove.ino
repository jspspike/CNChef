#include <Servo.h>
#include <Wire.h>

int MOTOR1_DIR1 = 2;
int MOTOR1_DIR2 = 3;
int MOTOR1_SPEED = 9;

int SERVO_1 = 0;
int SERVO_2 = 1;
int SERVO_3 = 4;

int x;

bool active = false;

void setup() {
  
  Serial.begin(9600);
  


  pinMode(SERVO_1, OUTPUT);
  pinMode(SERVO_2, OUTPUT);
  pinMode(SERVO_3, OUTPUT);

  pinMode(MOTOR1_DIR1, OUTPUT);
  pinMode(MOTOR1_DIR2, OUTPUT);
  pinMode(MOTOR1_SPEED, OUTPUT);

  
  Wire.begin(9);

  Wire.onReceive(receiveEvent);
  //
}

void receiveEvent(int bytes) {
  x = Wire.read();
}

void moveLeftTime(int time, int speed) {
  moveLeft(speed);
  delay(time);
  moveRight(100);
  delay(50);
  stopMotors();
}

void moveRightTime(int time, int speed) {
  moveRight(speed);
  delay(time);
  moveLeft(100);
  delay(50);
  stopMotors();
}

void moveLeft(int speed) {
    analogWrite(MOTOR1_SPEED, speed);
    digitalWrite(MOTOR1_DIR1, LOW);
    digitalWrite(MOTOR1_DIR2, HIGH);
}

void moveRight(int speed) {
    analogWrite(MOTOR1_SPEED, speed);
    digitalWrite(MOTOR1_DIR1, HIGH);
    digitalWrite(MOTOR1_DIR2, LOW);
}

void stopMotors() {
    analogWrite(MOTOR1_SPEED, 0);
    digitalWrite(MOTOR1_DIR1, LOW);
    digitalWrite(MOTOR1_DIR2, HIGH);
}



void loop() {
  if(x == 4) {
    moveRightTime(4900, 255);
    delay(1500);
    moveLeftTime(1750, 255);
    x = 0;
  }

  if(x == 1) {
    moveLeftTime(250, 255);
    x = 0; 
  }
}
