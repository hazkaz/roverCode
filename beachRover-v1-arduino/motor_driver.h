extern int LEFT_INPUT_1;
extern int LEFT_INPUT_2;
extern int RIGHT_INPUT_1;
extern int RIGHT_INPUT_2;

enum turn {
  left_turn,
  right_turn,
  straight,
  stop_moving,
  reverse_direction
};

void driveMotor(float angle,float speed);
