import serial
import time
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
    ser.reset_input_buffer()
    for i in range(4):
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(1)
