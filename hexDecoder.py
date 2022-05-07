

def decodeId(hexId):
    if hexId == '[00000430](00)':
        return 'PcmToCav1'
    elif hexId == '069':
        return 'UW_Mot_Status'
    else:
        return None
