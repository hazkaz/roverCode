# Arduino Code

This is the place you want to add code to read from your sensors
and customize the data being sent to the Jetson Nano. Here you can
also implement additional logic based on the commands received from
the Jetson Nano. 

1. Just add a new type of command
2. Add code in the [Jetson module](https://github.com/hazkaz/roverCode/blob/master/jetson%20code/serial-communication/communication.py) to send the command
2. Write code to handle it in [arduino-code.ino](https://github.com/hazkaz/roverCode/blob/master/arduino-code/arduino-code.ino)
3. Profit...