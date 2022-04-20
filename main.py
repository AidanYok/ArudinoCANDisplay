#import preProcessing
from tkinter import *

msgs = ['43C', '038']
refreshRate = 1


loggedMsg = dict.fromkeys(msgs)

root = Tk()
def updateMsgs(refreshRate, loggedMsg):
    #preProcessing.preprocess(refreshRate, loggedMsg)
    print(loggedMsg)
    root.after(1000, updateMsgs)

root.after(1000,updateMsgs(refreshRate, loggedMsg))
l1 = Label(text = '0x43c: ' + str(loggedMsg['43C']))
l2 = Label(text = '0x038: ' + str(loggedMsg['038']))

l1.grid()
l2.grid()

root.mainloop()
