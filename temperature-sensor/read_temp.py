#!/usr/bin/python3

import serial

with serial.Serial('/dev/ttyACM0', 9600) as acm:
    while(True):
        line = acm.readline()
        print(line)
