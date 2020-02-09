#include<SR04.h>
#include<Wire.h>

#include "motor_driver.h"
#include "robot.h"
#include "Communication.h"
#include "QMC5883L-offset.h"

#define TRIG_PIN 8
#define ECHO_PIN 7

#define P_VAL 0.5
#define D_VAL 0.01


SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

//MechaQMC5883 qmc;
QMC5883L compass;

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
float max_mag_value = -8000.0;
float min_mag_value = 8000.0;

float motorDirection = 0.5;
float prevError = 0;

void left_encoder_update() {
  left_wheel_encoder_count += .05;
}

void right_encoder_update() {
  right_wheel_encoder_count += .05;
}


void setup() {

  // Initialize I2C and Serial port
  Wire.begin();
  Serial.begin(115200);

  // Magnetometer
  compass.init(2666, 120, 0);
  compass.setMode(Mode_Continuous, ODR_100Hz, RNG_2G, OSR_512);

  //pinModes
  pinMode(LEFT_INPUT_1, OUTPUT);
  pinMode(LEFT_INPUT_2, OUTPUT);
  pinMode(RIGHT_INPUT_1, OUTPUT);
  pinMode(RIGHT_INPUT_2, OUTPUT);
  //  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //encoder interrupts
  attachInterrupt(digitalPinToInterrupt(2), left_encoder_update, RISING);
  attachInterrupt(digitalPinToInterrupt(3), right_encoder_update, RISING);

  // test buzzer and LED
  run_diagnostics();

}

double kalman(double prev_value, double new_value, double ratio) {
  return (prev_value * ratio) + (new_value * (1 - ratio));
}

void loop() {

  int x, y, z;
  compass.read(&x, &y, &z);

  Info info;
  info.sensor = MAGNETOMETER;
  info.x = x;
  info.y = y;
  info.z = z;
//  Serial.println(info.x);
  sendInfo(&info);
//  float heading = atan2(y, x);
//
//  float headingDegrees = heading * 180 / M_PI;
//  float target = 0.;
//  float error = target - headingDegrees;
//
//  if (abs(error) > 180 && error > 0) {
//    error = 180 - error;
//  } else if (abs(error) > 180 && error < 0) {
//    error = (int)(180 - error) % 360;
//  }
//
//  float correction = error;

  Command receivedCommand;
  bool commandReceived = readCommand(&receivedCommand);
  if (commandReceived) {
//    Serial.println(receivedCommand.command);
//    Serial.println(receivedCommand.param);
    if (receivedCommand.param >= 0) {
      indicate_led(YELLOW_LED, false);
    } else {
      indicate_led(YELLOW_LED, true);
    }
  }
//

//  motorDirection = kalman(motorDirection, (correction / 360) + 0.5, 0.98);
//  motorDirection = (correction / 360) + 0.5;
//  driveMotor(motorDirection, 0.35);
  delay(30);
}

float pd(float error) {
  float pd_p_term = error * P_VAL;
  float pd_d_term = (error - prevError) * D_VAL;
  prevError = error;
  float finalCorrection = pd_p_term + pd_d_term;
  if (finalCorrection > 0.5) {
    return 0.5;
  } else if (finalCorrection < -0.5) {
    return -0.5;
  }
  return -finalCorrection;
}

void extra_stuff() {
  //  float declinationAngle = -1.733;
  //  heading += declinationAngle;

  //  if(heading > 2*PI)
  //    heading -= 2*PI;
  //
  //  float headingDegrees = heading * 180/M_PI;

  //  current_distance = sr04.Distance();
  //  unsigned long current_time = millis();
  //  distance_travelled = (left_wheel_encoder_count + right_wheel_encoder_count) / 2;
  //  double current_left_wheel_speed = (left_wheel_encoder_count - prev_left_wheel_encoder_count) * 1000 * 60;
  //  left_wheel_speed = kalman(left_wheel_speed, current_left_wheel_speed, 0.8) / (current_time - prev_time);
  //  double current_right_wheel_speed = (right_wheel_encoder_count - prev_right_wheel_encoder_count) * 1000 * 60;
  //  right_wheel_speed = kalman(right_wheel_speed, current_right_wheel_speed, 0.8) / (current_time - prev_time);
  //
  //  prev_left_wheel_encoder_count = left_wheel_encoder_count;
  //  prev_right_wheel_encoder_count = right_wheel_encoder_count;
  //  prev_time = millis();
  //  //  current_direction = kalman(current_direction, 180 + (left_wheel_speed - right_wheel_speed) * 5, 0.8);
  //
  //
  //  float diff = (float)max_mag_value - x;
  //
  //  if (x > max_mag_value) {
  //    max_mag_value = (float)x;
  //    diff = 0.0;
  //  }
  //  if (x < min_mag_value) {
  //    min_mag_value = (float)x;
  //  }
  //
  //  float correction = diff / (4.0 * (max_mag_value - min_mag_value));
  //  correction = 0.5 - correction;

  //  delay(100);
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
