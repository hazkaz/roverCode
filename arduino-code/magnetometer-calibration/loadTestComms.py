import time
import serial
import struct
import random

def test_constant_command_acknowledgements():
	with open('loadTest.txt','w') as f:
		for i in range(100):
			const_int = 1
			const_long = 2147483647
			const_float = 0.25
			port.write(b'^'+struct.pack('<h',const_int)+struct.pack('<f',const_float))
			time.sleep(0.015)
			out = port.readline().decode("utf-8")
			f.write(out)
			print(int(out,10),const_int)
			assert(int(out,10)==const_int)
			out = port.readline().decode("utf-8")
			f.write(out)
			print(float(out),const_float)
			assert((float(out)-const_float)<0.01)
			f.write('\n')

def test_random_command_acknowledgements():
	with open('loadTest.txt','w') as f:
		for i in range(100):
			randShort = random.randint(-32768,32768)
			randLong = random.randint(-2147483648,2147483648)
			rand_float = (random.random()*10)-5
			port.write(b'^'+struct.pack('<h',randShort)+struct.pack('<f',rand_float))
			time.sleep(0.015)
			out = port.readline().decode("utf-8")
			f.write(out)
			print(int(out,10),randShort)
			assert(int(out,10)==randShort)
			out = port.readline().decode("utf-8")
			f.write(out)
			print(float(out),rand_float)
			assert((float(out)-rand_float)<0.01)
			


with serial.Serial('/dev/ttyUSB1',115200,timeout=0) as port:
	time.sleep(5)
	test_random_command_acknowledgements()	
	test_constant_command_acknowledgements()