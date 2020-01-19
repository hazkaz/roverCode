#include "motor_driver.h"
#include<Arduino.h>

int LEFT_INPUT_1 = 11;
int LEFT_INPUT_2 = 10;
int RIGHT_INPUT_1 = 9;
int RIGHT_INPUT_2 = 6;


void driveMotor(float angle, float speed) {
  if (speed > 1) {
    speed = 1;
  }
  if (speed < -1) {
    speed = -1;
  }
  if (angle > 1) {
    angle = 1;
  }
  if (angle < 0) {
    angle = 0;
  }

  int left_motor_speed = angle * 255 * speed*2;
  int right_motor_speed = (1 - angle) * 255 * speed*2;
  Serial.println(left_motor_speed);
  if (speed > 0) {
    analogWrite(LEFT_INPUT_1, left_motor_speed);
    analogWrite(LEFT_INPUT_2, 0);
    analogWrite(RIGHT_INPUT_1, right_motor_speed);
    analogWrite(RIGHT_INPUT_2, 0);
  }
  else {
    analogWrite(LEFT_INPUT_1, 0);
    analogWrite(LEFT_INPUT_2,  left_motor_speed * -1);
    analogWrite(RIGHT_INPUT_1, 0);
    analogWrite(RIGHT_INPUT_2,  right_motor_speed * -1);
  }



}
