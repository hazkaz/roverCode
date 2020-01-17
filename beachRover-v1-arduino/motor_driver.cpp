#ifndef MOTOR_DRIVER_H
#include "motor_driver.h"
#endif
#include<Arduino.h>

int LEFT_INPUT_1 = 16;
int LEFT_INPUT_2 = 17;
int RIGHT_INPUT_1 = 14;
int RIGHT_INPUT_2 = 15;


void driveMotor(turn direction) {
  switch (direction) {
    case left_turn:
      digitalWrite(LEFT_INPUT_1, 1);
      digitalWrite(LEFT_INPUT_2, 1);
      digitalWrite(RIGHT_INPUT_1, 1);
      digitalWrite(RIGHT_INPUT_2, 0);
      break;
    case right_turn:
      digitalWrite(LEFT_INPUT_1, 1);
      digitalWrite(LEFT_INPUT_2, 0);
      digitalWrite(RIGHT_INPUT_1, 1);
      digitalWrite(RIGHT_INPUT_2, 1);
      break;
    case straight:
      digitalWrite(LEFT_INPUT_1, 1);
      digitalWrite(LEFT_INPUT_2, 0);
      digitalWrite(RIGHT_INPUT_1, 1);
      digitalWrite(RIGHT_INPUT_2, 0);
      break;
    case stop_moving:
      digitalWrite(LEFT_INPUT_1, 1);
      digitalWrite(LEFT_INPUT_2, 1);
      digitalWrite(RIGHT_INPUT_1, 1);
      digitalWrite(RIGHT_INPUT_2, 1);
      break;
    case reverse:
      digitalWrite(LEFT_INPUT_1, 0);
      digitalWrite(LEFT_INPUT_2, 1);
      digitalWrite(RIGHT_INPUT_1, 0);
      digitalWrite(RIGHT_INPUT_2, 1);
    default:
      digitalWrite(LEFT_INPUT_1, 0);
      digitalWrite(LEFT_INPUT_2, 0);
      digitalWrite(RIGHT_INPUT_1, 0);
      digitalWrite(RIGHT_INPUT_2, 0);
  }
}
