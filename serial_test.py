import serial

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) 

while True:
    data = ser.read()

    print(data)