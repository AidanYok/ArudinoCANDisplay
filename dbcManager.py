import can
import cantools


def deCode(canid, sig, data):
    db = cantools.database.load_file('EMC_PCM_CAV_Interface.dbc')

    decoded = db.decode_message(canid, data)
    
    return decoded[sig]
