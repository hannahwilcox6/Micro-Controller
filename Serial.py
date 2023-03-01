#!/usr/bin/env python3
import serial
import time
import json

# Name of our attached arduino
arduino = '/dev/ttyACM0'

# We want to keep the baud rate consistent on Arduino and RasPi
baud = 9600

if __name__ == '__main__':
    ser = serial.Serial(arduino, baud, timeout=1)
    ser.reset_input_buffer()
    print("running serialComs")

    while True:
        #ser.write(b"Hello from Raspberry Pi\n")
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        data = json.loads(line)
        print(data["COM"])
        time.sleep(1)
        #if ser.in_waiting > 0:
        #    line = ser.readline().decode('utf-8').rstrip()
        #    print(line)      
