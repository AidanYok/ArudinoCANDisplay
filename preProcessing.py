import serial
import RPi.GPIO as GPIO
import hexDecoder
import time

def getId(sData):
    return hexDecoder.decodeId(sData[2][6:9])
    
def getData(sData):
    return ''.join([str(item) for item in sData[3:]])

def preprocess(loggedMsg):
    beginTime = time.time()
    ser=serial.Serial("/dev/ttyACM0",115200)  
   
    while (time.time() - beginTime < 2):
        try:
            read_ser=ser.readline().decode()
        except:
            read_ser = None
        if read_ser == None:
            pass
        else:
            serialData = read_ser.split()
            if (len(serialData) < 10):
                pass
            else:
                if getId(serialData) in loggedMsg:
                    loggedMsg[getId(serialData)] = getData(serialData)
