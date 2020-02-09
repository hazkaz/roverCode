import time
import serial
import struct
import random
import math
from enum import Enum


class SensorType(Enum):
    MAGNETOMETER = 1
    DISTANCE = 2
    ENCODER = 3

class CommandType(Enum):
    MOVE=1
    STOP=2

class Command():

    def __init__(self,command_type,command_param):
        self.command_type = command_type
        self.command_param = command_param

    def __str__(self):
        return CommandType(command_type).name+" "+str(command_param)

class Info():
    sensor_type = 0
    sensor_values = 0

    def __init__(self, unpacked_sensor_data):
        self.sensor_type = unpacked_sensor_data[0]
        self.sensor_values = unpacked_sensor_data[1:]

    def __str__(self):
        return SensorType(self.sensor_type).name+" "+",".join([str(v) for v in self.sensor_values])


def send_command(command):
    # print(command.command_param)
    port.write(b'^'+struct.pack('<h', command.command_type.value)+struct.pack('<f', command.command_param))


def read_info():
    info = port.readline()
    if(info[0] == 94 and len(info[1:-1])==14):
        data = struct.unpack('<hfff', info[1:-1])
        sensor_info = Info(data)
        print(data)
        return sensor_info
    else:
        print(info, info[0])
        return None


with serial.Serial('/dev/ttyUSB1', 115200, timeout=0.5) as port:
    time.sleep(5)
    while True:
        if (port.in_waiting >= 14):
            sensor_info = read_info()
            if(sensor_info is None):
                continue
            # print(sensor_info)
            heading = math.atan2(sensor_info.sensor_values[1], sensor_info.sensor_values[0]);
            headingDegrees = heading * 180 / math.pi;
            print(sensor_info.sensor_values[0])
            target = 0.;
            error = target - headingDegrees;
            if (abs(error) > 180 and error > 0) :
                error = 180 - error
            elif (abs(error) > 180 and error < 0):
                error = (180 - error) % 360;
            command_to_send = Command(CommandType.MOVE,error)
            send_command(command_to_send)
            correction = error;
        time.sleep(0.15)
