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
  float x;
  float y;
  float z;
};

struct Command{
  COMMAND_TYPE command;
  float param;
};

int readInt();
long readLong();
float readFloat();
double readDouble();
bool readCommand(Command* commander);
void sendInfo(Info* info);
