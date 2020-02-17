import time
import serial
import struct
import random
import math
from enum import Enum

# Change this to the virtual port of your arduino
SERIAL_PORT = '/dev/ttyUSB0'

# The SensorType enum should match the one in the Arduino code
class SensorType(Enum):
    MAGNETOMETER = 1
    DISTANCE = 2
    ENCODER = 3

# Add more commands here
class CommandType(Enum):
    MOVE=1
    STOP=2


# Class to contain command info
class Command():
    def __init__(self,command_type,command_param):
        self.command_type = command_type
        self.command_param = command_param

    def __str__(self):
        return CommandType(command_type).name+" "+str(command_param)

# Class that stores sensor info from Arduino
class Info():
    sensor_type = 0
    sensor_values = 0

    def __init__(self, unpacked_sensor_data):
        self.sensor_type = unpacked_sensor_data[0]
        self.sensor_values = unpacked_sensor_data[1:]

    def __str__(self):
        return SensorType(self.sensor_type).name+" "+",".join([str(v) for v in self.sensor_values])

# write to serial port in binary
def send_command(command):
    port.write(b'^'+struct.pack('<h', command.command_type.value)+struct.pack('<f', command.command_param))

# read from serial port into variables
def read_info():
    info = port.readline()
    if(info[0] == 94 and len(info[1:-1])==14):
        data = struct.unpack('<hfff', info[1:-1])
        sensor_info = Info(data)
        return sensor_info
    else:
        print(info, info[0])
        return None

# Called every 30 milliseconds (roughly 33 times a second)
def main(i):
    if (port.in_waiting >= 14):
        sensor_info = read_info()
        if(sensor_info is None):
            return
        # Convert x and y magnitude of magnetometer data to magnetic heading
        heading = math.atan2(sensor_info.sensor_values[1], sensor_info.sensor_values[0]);
        headingDegrees = heading * 180 / math.pi;
        print(headingDegrees)
        target = 0.;
        # Shortest path to North
        error = target - headingDegrees;
        if (abs(error) > 180 and error > 0) :
            error = 180 - error
        elif (abs(error) > 180 and error < 0):
            error = (180 - error) % 360;
        command_to_send = Command(CommandType.MOVE,error)
        send_command(command_to_send)
        correction = error;


if __name__ == '__main__':
    with serial.Serial(SERIAL_PORT, 115200, timeout=0.5) as port:
        # 5s timeout to wait for reset sequence and diagnostics on arduino
        time.sleep(5)
        while True:
            start_time = time.clock()
            main(1)
            # 30 millisecond loop
            while (time.clock()-start_time)<0.03:
                pass
        