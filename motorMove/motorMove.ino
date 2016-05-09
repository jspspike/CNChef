#include <Servo.h>


int MOTOR1_DIR1 = 2;
int MOTOR1_DIR2 = 3;
int MOTOR1_SPEED = 9;

int BUTTON_1 = 5;
int BUTTON_2 = 6;
int BUTTON_3 = 7;

int SERVO_1 = 0;
int SERVO_2 = 1;
int SERVO_3 = 4;


bool active = false;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);

  pinMode(SERVO_1, OUTPUT);
  pinMode(SERVO_2, OUTPUT);
  pinMode(SERVO_3, OUTPUT);

  pinMode(MOTOR1_DIR1, OUTPUT);
  pinMode(MOTOR1_DIR2, OUTPUT);
  pinMode(MOTOR1_SPEED, OUTPUT);

  
  
  moveLeft(255);
  delay(3000);
  stopMotors();
}

void moveLeftTime(int time, int speed) {
  moveLeft(speed);
  delay(time);
  stopMotors();
}

void moveRightTime(int time, int speed) {
  moveRight(speed);
  delay(time);
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

}
