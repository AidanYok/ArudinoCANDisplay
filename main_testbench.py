import fakeData
from tkinter import *
import dbcManager as dbc
import time
from threading import *

def main():
    msgs = ['CavToPcmLongCtrl1', 'PcmToCav1', 'PcmToCav2']
    sigs = ['obj1_pos','veh_spd', 'BattSOC']

    loggedMsg = dict.fromkeys(msgs)
    sigVals = dict.fromkeys(sigs)

    root = Tk()
    root.geometry("800x400")
    detailed = Frame(root)

    for i in sigVals:
        sigVals[i] = StringVar()

    for i in sigs:
        Label(detailed, textvariable = sigVals[i]).grid()

    detailed.pack(expand=True)

    def updateMsgs(loggedMsg, root):
        while True:
            loggedMsg = fakeData.preprocess(loggedMsg)
            for i in msgs:
                for j in sigs:
                    if (loggedMsg[i] != None):
                        try:
                            sigVals[j].set(j + ': ' + str(dbc.deCode(i, j, loggedMsg[i].encode('UTF-8'))))
                        except:
                            pass
            root.update()

    def threading():
        t1 = Thread(target=updateMsgs(loggedMsg, root))
        t1.start()
    threading()
    # Button(root,text="Click Me",command = threading).pack()
    # root.attributes('-fullscreen', True)
    root.mainloop()


if __name__ == "__main__":
    main()
