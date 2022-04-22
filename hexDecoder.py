

def decodeId(hexId):
    if hexId == '420':
        return 'CavToPcmLongCtrl1'
    elif hexId == '069':
        return 'UW_Mot_Status'
    else:
        return None
