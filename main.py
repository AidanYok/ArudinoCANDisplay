import preProcessing
from tkinter import *
import dbcManager as dbc
import time

msgs = ['CavToPcmLongCtrl1', 'UW_Mot_Status']
sigs = ['obj1_pos','MotP0Temp']

loggedMsg = dict.fromkeys(msgs)
sigVals = dict.fromkeys(sigs)

root = Tk()
root.geometry("800x400")
grid = Frame(root)


engTemp = Label(grid, text = 'engTemp: ' + str(sigVals['obj1_pos']))
battTemp = Label(grid, text = 'battTemp: ' + str(sigVals['MotP0Temp']))
#eRadTemp = Label(grid, text = 'eRadTemp: ' + str(loggedMsg['43C']))
#battSOC = Label(grid, text = 'battSOC: ' + str(loggedMsg['43C']))
#battCurrent = Label(grid, text = 'battCurrent: ' + str(loggedMsg['43C']))
#vehDetected = Label(grid, text = 'vehDetected: ' + str(loggedMsg['43C']))
#distance = Label(grid, text = 'distance: ' + str(loggedMsg['43C']))
#headwayTime = Label(grid, text = 'headwayTime: ' + str(loggedMsg['43C']))
#cavFaults = Label(grid, text = 'cavFaults: ' + str(loggedMsg['43C']))

engTemp.grid(row = 0, column = 0)
battTemp.grid(row = 0, column = 1)
#eRadTemp.grid(row = 0, column = 2)
#battSOC.grid(row = 0, column = 3)
#battCurrent.grid(row = 0, column = 4)
#vehDetected.grid(row = 1, column = 0)
#distance.grid(row = 1, column = 1)
#headwayTime.grid(row = 1, column = 2)
#cavFaults.grid(row = 1, column = 3)

grid.pack(expand=True)

def updateMsgs(loggedMsg):
    preProcessing.preprocess(loggedMsg)
    for i in msgs:
        for j in sigs:
            try:
                sigVals[sigs] = dbc.deCode(i, j, loggedMsg[i].encode('UTF-8'))
            except:
                pass
    root.after(1000, updateMsgs(loggedMsg))

updateMsgs(loggedMsg)

while True:
    print(sigVals['MotP0Temp'])

# root.attributes('-fullscreen', True)
root.mainloop()
