#include "motor_driver.h"
#include "SR04.h"

#define TRIG_PIN 8
#define ECHO_PIN 7

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long current_distance;
turn next_avoid = right_turn;
bool avoided = true;

void setup() {
  pinMode(LEFT_INPUT_1, OUTPUT);
  pinMode(LEFT_INPUT_2, OUTPUT);
  pinMode(RIGHT_INPUT_1, OUTPUT);
  pinMode(RIGHT_INPUT_2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  current_distance = sr04.Distance();
  if (current_distance < 13 && avoided) {
    driveMotor(reverse_direction);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    avoided = false;
  } else if (current_distance < 13 && !avoided) {
    driveMotor(next_avoid);
    delay(100);
  } else {
    avoided = true;
    driveMotor(straight);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    next_avoid = random(1, 3) == 1 ? left_turn : right_turn;
  }
}
