#import preProcessing
from tkinter import *

msgs = ['43C', '038']


loggedMsg = dict.fromkeys(msgs)

root = Tk()
root.geometry("800x400")
grid = Frame(root)

def updateMsgs(loggedMsg):
    #preProcessing.preprocess(loggedMsg)
    print(loggedMsg)
    root.after(5, updateMsgs)

root.after(5,updateMsgs(loggedMsg))

engTemp = Label(grid, text = 'engTemp: ' + str(loggedMsg['43C']))
battTemp = Label(grid, text = 'battTemp: ' + str(loggedMsg['43C']))
eRadTemp = Label(grid, text = 'eRadTemp: ' + str(loggedMsg['43C']))
battSOC = Label(grid, text = 'battSOC: ' + str(loggedMsg['43C']))
battCurrent = Label(grid, text = 'battCurrent: ' + str(loggedMsg['43C']))
vehDetected = Label(grid, text = 'vehDetected: ' + str(loggedMsg['43C']))
distance = Label(grid, text = 'distance: ' + str(loggedMsg['43C']))
headwayTime = Label(grid, text = 'headwayTime: ' + str(loggedMsg['43C']))
cavFaults = Label(grid, text = 'cavFaults: ' + str(loggedMsg['43C']))

engTemp.grid(row = 0, column = 0)
battTemp.grid(row = 0, column = 1)
eRadTemp.grid(row = 0, column = 2)
battSOC.grid(row = 0, column = 3)
battCurrent.grid(row = 0, column = 4)
vehDetected.grid(row = 1, column = 0)
distance.grid(row = 1, column = 1)
headwayTime.grid(row = 1, column = 2)
cavFaults.grid(row = 1, column = 3)

grid.pack(expand=True)

# root.attributes('-fullscreen', True)
root.mainloop()
