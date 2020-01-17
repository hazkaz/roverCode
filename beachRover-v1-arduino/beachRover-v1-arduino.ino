#ifndef MOTOR_DRIVER_H
#include "motor_driver.h"
#endif


void setup() {
  pinMode(LEFT_INPUT_1, OUTPUT);
  pinMode(LEFT_INPUT_2, OUTPUT);
  pinMode(RIGHT_INPUT_1, OUTPUT);
  pinMode(RIGHT_INPUT_2, OUTPUT);
}

void loop() {
  driveMotor(left_turn);
  delay(500);
  driveMotor(stop_moving);
  delay(500);
  driveMotor(right_turn);
  delay(500);
  driveMotor(stop_moving);
  delay(500);
  driveMotor(straight);
  delay(500);
  driveMotor(stop_moving);
  delay(500);
}
