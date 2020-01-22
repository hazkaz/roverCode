#!/usr/bin/env python
# coding: utf-8

import serial
import time
from matplotlib import pyplot as plt

x_data=[]
y_data = []
with serial.Serial("/dev/ttyUSB0",9600,timeout=10) as port:
    for i in range(100):
        time.sleep(0.1)
        line = port.readline().decode("utf-8")
        if "\t" in line:
            x,y =line.split('\t')
        else:
            continue
        x = int(x)
        y= int(y)
        x_data.append(x)
        y_data.append(y)

plt.scatter(x_data,y_data)
plt.show()
