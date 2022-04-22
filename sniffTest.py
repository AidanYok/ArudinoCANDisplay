import preProcessing
import cantools
import can
msgs = ['2CB', '331']
db = cantools.database.load_file('../hs.dbc')

loggedMsg = dict.fromkeys(msgs)

def updateMsgs(loggedMsg):
    while True:
        preProcessing.preprocess(loggedMsg)
        print(loggedMsg)
        print(db.decode_message('0x2CB', loggedMsg['2CB']))


updateMsgs(loggedMsg)


