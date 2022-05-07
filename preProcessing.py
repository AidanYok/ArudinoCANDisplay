import serial
import RPi.GPIO as GPIO
import hexDecoder
import time

def getId(sData):
    return hexDecoder.decodeId(sData[2])
    
def getData(sData):
    return ''.join([str(item) for item in sData[3:]])

def preprocess(loggedMsg):
    beginTime = time.time()
    ser=serial.Serial("/dev/ttyACM0",115200)  
   
    while (time.time() - beginTime < 2):
        try:
            read_ser=ser.readline().decode('utf-8').rstrip()
        except:
            read_ser = None
        if read_ser == None:
            break
        else:
            serialData = read_ser.split()
            if (len(serialData) > 8):
                print(loggedMsg)
                try:
                    if getId(serialData) in loggedMsg:
                        loggedMsg[getId(serialData)] = getData(serialData)
                except:
                    continue
