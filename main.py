import preProcessing

msgs = [43C, 038]
refreshRate = 1


loggedMsg = dict.fromkeys(msgs)
while True:
    preProcessing.preprocessing(refreshRate, loggedMsg)
    print(loggedMsg)