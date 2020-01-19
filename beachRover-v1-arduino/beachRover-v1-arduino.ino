#include "motor_driver.h"
#include "SR04.h"

#define TRIG_PIN 8
#define ECHO_PIN 7

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long current_distance;
turn next_avoid = right_turn;
bool avoided = true;

volatile double left_wheel_encoder_count = 0;
volatile double right_wheel_encoder_count = 0.0;
double prev_left_wheel_encoder_count = 0.0;
double prev_right_wheel_encoder_count = 0.0;
double distance_travelled = 0.0;
unsigned long prev_time = -500;
double left_wheel_speed = 0;
double right_wheel_speed = 0;
double current_speed = 0.0;
bool forward = true;

void left_encoder_update() {
  left_wheel_encoder_count += .05;
}

void right_encoder_update() {
  right_wheel_encoder_count += .05;
}


void setup() {

  Serial.begin(9600);

  //pinModes
  pinMode(LEFT_INPUT_1, OUTPUT);
  pinMode(LEFT_INPUT_2, OUTPUT);
  pinMode(RIGHT_INPUT_1, OUTPUT);
  pinMode(RIGHT_INPUT_2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //encoder interrupts
  attachInterrupt(digitalPinToInterrupt(2), left_encoder_update, RISING);
  attachInterrupt(digitalPinToInterrupt(3), right_encoder_update, RISING);
}

double kalman(double prev_value, double new_value, double ratio) {
  return (prev_value * ratio) + (new_value * (1 - ratio));
}

void loop() {
  //  current_distance = sr04.Distance();
  unsigned long current_time = millis();
  distance_travelled = (left_wheel_encoder_count + right_wheel_encoder_count) / 2;
  double current_left_wheel_speed = (left_wheel_encoder_count - prev_left_wheel_encoder_count) * 1000 * 60;
  left_wheel_speed = kalman(left_wheel_speed, current_left_wheel_speed, 0.8) / (current_time - prev_time);
  double current_right_wheel_speed = (right_wheel_encoder_count - prev_right_wheel_encoder_count) * 1000 * 60;
  right_wheel_speed = kalman(right_wheel_speed, current_right_wheel_speed, 0.8) / (current_time - prev_time);

  prev_left_wheel_encoder_count = left_wheel_encoder_count;
  prev_right_wheel_encoder_count = right_wheel_encoder_count;
  prev_time = millis();
  //  current_direction = kalman(current_direction, 180 + (left_wheel_speed - right_wheel_speed) * 5, 0.8);

  if (forward) {
    driveMotor(0.5, current_speed);
    current_speed += 0.1;
    if (current_speed >= 1) {
      forward = false;
    }
  } else {
    driveMotor(0.5, current_speed);
    current_speed -= 0.1;
    if (current_speed <= 0) {
      forward = true;
    }
  }
  delay(100);
  //  if (current_distance < 13 && avoided) {
  //    driveMotor(reverse_direction);
  //    delay(500);
  //    digitalWrite(LED_BUILTIN, HIGH);
  //    avoided = false;
  //  } else if (current_distance < 13 && !avoided) {
  //    driveMotor(next_avoid);
  //    delay(100);
  //  } else {
  //    avoided = true;
  //    driveMotor(straight);
  //    delay(100);
  //    digitalWrite(LED_BUILTIN, LOW);
  //    next_avoid = random(1, 3) == 1 ? left_turn : right_turn;
  //  }
}
