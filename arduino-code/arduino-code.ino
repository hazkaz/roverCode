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

bool forward = true;
float max_mag_value = -8000.0;
float min_mag_value = 8000.0;

float motorDirection = 0.5;
float prevError = 0;

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

  // test buzzer and LED
  run_diagnostics();

}

double kalman(double prev_value, double new_value, double ratio) {
  return (prev_value * ratio) + (new_value * (1 - ratio));
}

void loop() {

  int x, y, z;
  //  Read magnetometer data
  compass.read(&x, &y, &z);

  Info headingInfo;
  headingInfo.sensor = MAGNETOMETER;
  headingInfo.x = x;
  headingInfo.y = y;
  headingInfo.z = z;

  sendInfo(&headingInfo);

  // Object to receive command into
  Command receivedCommand;
  bool commandReceived = readCommand(&receivedCommand);
  if (commandReceived) {
    Info diagnosticInfo;
    diagnosticInfo.sensor = INFO;
    diagnosticInfo.x = receivedCommand.param;
    sendInfo(&diagnosticInfo);

    if (receivedCommand.param >= 0) {
      //  Show Yellow LED if turning right
      indicate_led(YELLOW_LED, false);
    } else {
      //  Show Green LED if turning left
      indicate_led(YELLOW_LED, true);
    }

    if (receivedCommand.command == MOVE) {
      motorDirection = kalman(motorDirection, (receivedCommand.param / 360) + 0.5, 0.98);
      motorDirection = (receivedCommand.param / 360) + 0.5;
      driveMotor(motorDirection, 0.35);
    } else if (receivedCommand.param == STOP) {
      driveMotor(0.5, 0);
    }
  } else {
    driveMotor(0.5, 0);
  }
  //  30 millisecond loop
  delay(30);
}
