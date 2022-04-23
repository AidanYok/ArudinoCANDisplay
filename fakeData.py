#import serial
#import RPi.GPIO as GPIO
import hexDecoder
import time
import numpy as np
import random
import secrets

def getId(sData):
    return hexDecoder.decodeId(sData[2][6:9])
    
def getData(sData):
    return ''.join([str(item) for item in sData[3:]])

def preprocess(loggedMsg):
    time.sleep(0.2)
    for msg in loggedMsg:
        loggedMsg[msg] = secrets.token_hex(14)

    return loggedMsg