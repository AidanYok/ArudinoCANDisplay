import serial
import RPi.GPIO as GPIO
import time

def getId(sData):
    return sData[2][:3]
    
def getData(sData):
    data = ""
    for i in range(4, len(sData) - 4):
        data = data + str(sData[i])
    return data
    
def preprocess(refreshRate, loggedMsg):
    beginTime =time.time()
    ser=serial.Serial("/dev/ttyACM0",115200)  
    
    while (time.time() - beginTime < refreshRate):
        read_ser=ser.readline()
        if read_ser == None:
            pass
        else:
            serialData = read_ser.split()
            if (len(serialData) < 5):
                pass
            else:
                print(read_ser)
                if getId(serialData) in loggedMsg:
                    loggedMsg[getId(serialData)] = getData(serialData)
