enum SENSOR_TYPE{
  MAGNETOMETER=1,
  DISTANCE=2,
  ENCODER=3
};

enum COMMAND_TYPE{
  MOVE=1,
  STOP=2,
  RESET=3
};

struct Info{
  SENSOR_TYPE sensor;
  int x;
  int y;
  int z;
};

struct Command{
  COMMAND_TYPE command;
  long param;
};

int readInt();
long readLong();
double readDouble();
bool readCommand(Command* commander);
