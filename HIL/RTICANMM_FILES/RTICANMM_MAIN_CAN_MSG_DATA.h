/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_MSG_DATA */
/*                                                                                                                           */
/*   AUTHOR(S):                                                                                                              */
/*      U. Homann                                                                                                              */
/*      M. Eikermann                                                                                                              */
/*                                                                                                                           */
/*                                                                                                                           */
/*   RTICANMM Date: 07-Apr-2020 08:38:10                                                                                     */
/*   RTICANMM Version: 5.4.737888.359837963                                                                                     */
/*                                                                                                                           */
/*  Copyright 2022, dSPACE GmbH. All rights reserved.                                                                    */
/*      Brand names or product names are trademarks or registered trademarks of their respective companies or organizations. */
/*                                                                                                                           */
/* ***************************************************************************************************************************/

/* Global variables used for signal decoding */                               
#if defined(_DS1006) | defined(_DS1007) | defined(_DS2510) | defined(_DS1202) 
static volatile ULong64 ulong64Temp  = 0;                                     
static volatile Long64  long64Temp   = 0;                                     
static volatile Int32   signedTemp   = 0;                                     
static volatile UInt32  unsignedTemp = 0;                                     
static volatile Float32 floatTemp    = 0.0;                                   
static volatile double  doubleTemp   = 0.0;                                   
#else                                                                         
static ULong64 ulong64Temp  = 0;                                              
static Long64  long64Temp   = 0;                                              
static Int32   signedTemp   = 0;                                              
static UInt32  unsignedTemp = 0;                                              
static Float32 floatTemp    = 0.0;                                            
static double  doubleTemp   = 0.0;                                            
#endif                                                                        

static uint8_T canFdLen[7] = {12, 16, 20, 24, 32, 48, 64};                    


void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl3(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl4(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl5(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl6(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl3(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl4(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl5(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl6(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav1(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav2(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav3(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav4(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav5(MainSetupMsgData* data, int direction, SimStruct *S);
void RTICANMM_MAIN_CAN_copy_PcmToCav6(MainSetupMsgData* data, int direction, SimStruct *S);
                                           
/* Message for custom code manipulations */         
static RTICANMMMsgStruct custCodeMsg;               
                                                    
static void custCodeMsg2Data(RTICANMMMsgStruct *msg, MainSetupMsgData *data) {         
  int i = 0;                                        
  int rawBytes = 0;                                 
  data->CANMsg.Format  = (CanMM_Msg_Format) msg->idformat;
  data->CANMsg.Id      = msg->identifier;           
  data->CANMsg.Dlc     = msg->len;                  
  switch(data->CANMsg.Format) {                     
      case CANMM_MSG_FORMAT_FD_STD_SLOW:            
      case CANMM_MSG_FORMAT_FD_EXT_SLOW:            
      case CANMM_MSG_FORMAT_FD_STD_FAST:            
      case CANMM_MSG_FORMAT_FD_EXT_FAST:            
          rawBytes = (msg->len<8 ? 8 : msg->len);   
          break;                                    
      default:                                      
          rawBytes = 8;                             
          break;                                    
  }                                                 
  for (i=0; i<rawBytes && i<64; i++) {              
      data->pData[i] = msg->RAW_DATA[i];            
  }                                                 
  data->CANMsg.HwTime      = msg->HwTime;           
  data->DelayTime   = msg->DelayTime;               
  data->CycleTime   = msg->CycleTime;               
  data->Status      = msg->status;                  
  data->TXCounter   = msg->TX_counter;              
  data->RXCounter   = msg->RX_counter;              
}                                                   
                                                    
                                                    
/* CustomCode requires all data (TX path) */        
static void data2CustCodeMsg(MainSetupMsgData *data, RTICANMMMsgStruct *msg) {        
  int i = 0;                                        
  int rawBytes = 0;                                 
  msg->idformat    = (int)data->CANMsg.Format;      
  msg->identifier  = data->CANMsg.Id;               
  msg->HwTime      = data->CANMsg.HwTime;           
  msg->DelayTime   = data->DelayTime;               
  msg->CycleTime   = data->CycleTime;               
  msg->status      = data->Status;                  
  msg->TX_counter  = data->TXCounter;               
  msg->RX_counter  = data->RXCounter;               
                                                    
  msg->deltatime   = data->DeltaTime;               
  msg->time        = data->CANMsg.TimeStamp;        
                                                    
  msg->len         = data->CANMsg.Dlc;              
  switch(data->CANMsg.Format) {                     
      case CANMM_MSG_FORMAT_FD_STD_SLOW:            
      case CANMM_MSG_FORMAT_FD_EXT_SLOW:            
      case CANMM_MSG_FORMAT_FD_STD_FAST:            
      case CANMM_MSG_FORMAT_FD_EXT_FAST:            
          rawBytes = (data->CANMsg.Dlc<8 ? 8 : data->CANMsg.Dlc);     
          break;                                    
      default:                                      
          rawBytes = 8;                             
          break;                                    
  }                                                 
  for (i=0; i<rawBytes && i<64; i++) {              
      msg->RAW_DATA[i] = data->pData[i];            
  }                                                 
}                                                   
                                                    
/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl1  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[0] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[0] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[0];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat1_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_1_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat1_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_1_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl2  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl2(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[1] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[1] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[1];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat2_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_2_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat2_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_2_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl3  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl3(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[2] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[2] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[2];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat3_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_3_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat3_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_3_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl4  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl4(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[3] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[3] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[3];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat4_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_4_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat4_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_4_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl5  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl5(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[4] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[4] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[4];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat5_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_5_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat5_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_5_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLateralCtrl6  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLateralCtrl6(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[5] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[5] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[5];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLat6_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_6_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLat6_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_6_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl1  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[6] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[6] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[6];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong1_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_7_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* obj1_pos */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFF;                             
  CANMMCAN_RX_Msg_7_Sgn_2 = (double)0.125 * (double)unsignedTemp + (double)(0);                    

}

if(currentMsgLength >= 3) {
/* obj1_vel */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x7FF;                             
  if (unsignedTemp & 0x400) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFF800;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_RX_Msg_7_Sgn_3 = (double)0.125 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong1_PV */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0xF;                             
  CANMMCAN_RX_Msg_7_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl2  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl2(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[7] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[7] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[7];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong2_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_8_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong2_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_8_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl3  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl3(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[8] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[8] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[8];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong3_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_9_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong3_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_9_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl4  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl4(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[9] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[9] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[9];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong4_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_10_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong4_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_10_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl5  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl5(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[10] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[10] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[10];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong5_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_11_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong5_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_11_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- CavToPcmLongCtrl6  -----*/  
void RTICANMM_MAIN_CAN_copy_CavToPcmLongCtrl6(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[11] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[11] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[11];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* CavToPcmLong6_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_12_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* CavToPcmLong6_PV */ 
ulong64Temp = INT64_FROM_BE(*(ULong64*)(data->pData + (0)));           
  ulong64Temp = ulong64Temp >> 2;                    
  ulong64Temp = ulong64Temp & 0x7FFFFFFF;                             
  CANMMCAN_RX_Msg_12_Sgn_2 = (UInt32)1 * (UInt32)ulong64Temp + (UInt32)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav1  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav1(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[12] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[12] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[12];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav1_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_13_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* veh_spd */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0xFFFF;                             
  CANMMCAN_RX_Msg_13_Sgn_2 = (double)0.001 * (double)unsignedTemp + (double)(0);                    

}

if(currentMsgLength >= 3) {
/* connect_swch_stat */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_13_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* long_swch_stat */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_13_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
else {  /* TX ========================================================================================== */ 

  /* Init encode structure */                               
    *((UInt32*)(data->pData)) = INT32_TO_BE(0x00000000);        
    *((UInt32*)(data->pData+4)) = INT32_TO_BE(0x00000000);      

/* PcmToCav1_RC */
CANMMCAN_TX_Msg_13_Sgn_1 = CANMMCAN_TX_Msg_13_Sgn_1_constant;

/* veh_spd */
CANMMCAN_TX_Msg_13_Sgn_2 = ((real_T*)GetInputPortSignal(S,0))[0];

/* connect_swch_stat */
CANMMCAN_TX_Msg_13_Sgn_3 = CANMMCAN_TX_Msg_13_Sgn_3_constant;

/* long_swch_stat */
CANMMCAN_TX_Msg_13_Sgn_4 = CANMMCAN_TX_Msg_13_Sgn_4_constant;
/* PcmToCav1_RC */ 
unsignedTemp = (CANMMCAN_TX_Msg_13_Sgn_1 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x3)) << 0;                         
*((UInt8*)&data->pData[7]) = (*((UInt8*)&data->pData[7]) & INT8_TO_BE(~(0x3 << 0))) | INT8_TO_BE(unsignedTemp);               

/* veh_spd */ 
unsignedTemp = (((CANMMCAN_TX_Msg_13_Sgn_2 - (0)) / ((double)0.001)) + (CANMMCAN_TX_Msg_13_Sgn_2 > 0) - 0.5);                                
unsignedTemp = ((UInt32)(unsignedTemp & 0xFFFF)) << 0;                         
*((UInt16*)&data->pData[0]) = (*((UInt16*)&data->pData[0]) & INT16_TO_LE(~(0xFFFF << 0))) | INT16_TO_LE(unsignedTemp);               

/* connect_swch_stat */ 
unsignedTemp = (CANMMCAN_TX_Msg_13_Sgn_3 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 0;                         
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x1 << 0))) | INT8_TO_LE(unsignedTemp);               

/* long_swch_stat */ 
unsignedTemp = (CANMMCAN_TX_Msg_13_Sgn_4 );                               
unsignedTemp = ((UInt32)(unsignedTemp & 0x1)) << 1;                         
*((UInt8*)&data->pData[2]) = (*((UInt8*)&data->pData[2]) & INT8_TO_LE(~(0x1 << 1))) | INT8_TO_LE(unsignedTemp);               


data->CANMsg.Dlc = rticanmmmaxsat(CANMMCAN_TXLEN[0], (uint8_T)8, (uint8_T)0);

data->CANMsg.Id = CANMMCAN_MIDRX[12];          
data->CANMsg.Format = (CanMM_Msg_Format) CANMMCAN_MIDFTX[12];  
CANMMCAN_TXsta[0] = 1;                                       
} /* TX */
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav2  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav2(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[13] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[13] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[13];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav2_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_14_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* BattSOC */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_14_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* iceOnly */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_14_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* BattTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_RX_Msg_14_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* BattCurrent */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_RX_Msg_14_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* EngTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_14_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* regenEnbld */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_14_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 5) {
/* eRadTemp */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_RX_Msg_14_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* egoDistance */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_14_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 7) {
/* BattV */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (5)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1FF;                             
  CANMMCAN_RX_Msg_14_Sgn_10 = (UInt16)1 * (UInt16)unsignedTemp + (UInt16)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav3  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav3(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[14] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[14] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[14];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav3_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_15_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* uwACCAct */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_15_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* targetGap */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_15_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 2) {
/* cavLondgAct */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_15_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* setSpd */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_15_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* targetDist */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (3)));           
  unsignedTemp = unsignedTemp & 0x7F;                             
  CANMMCAN_RX_Msg_15_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 6) {
/* accDecelCmd */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (4)));           
  unsignedTemp = unsignedTemp & 0x3FF;                             
  if (unsignedTemp & 0x200) /* extend sign */      
    unsignedTemp = unsignedTemp | 0xFFFFFC00;                     
  signedTemp = *((Int32*)&unsignedTemp);                     
  CANMMCAN_RX_Msg_15_Sgn_7 = (double)0.01 * (double)signedTemp + (double)(0);                    

}

if(currentMsgLength >= 7) {
/* driverIntervention */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (6)));           
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_15_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav4  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav4(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[15] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[15] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[15];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav4_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_16_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* ccFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 1;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_2 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* hybridFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 2;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_3 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* propFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 3;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_4 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* grndFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 4;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_5 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* magnaEradFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 5;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_6 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* uwEradFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_7 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 1) {
/* cntrFault */ 
unsignedTemp = INT8_FROM_LE(*(UInt8*)(data->pData + (0)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0x1;                             
  CANMMCAN_RX_Msg_16_Sgn_8 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 3) {
/* ACCFault */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (1)));           
  unsignedTemp = unsignedTemp >> 6;                    
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_RX_Msg_16_Sgn_9 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

if(currentMsgLength >= 4) {
/* uwFaults */ 
unsignedTemp = INT16_FROM_LE(*(UInt16*)(data->pData + (2)));           
  unsignedTemp = unsignedTemp >> 7;                    
  unsignedTemp = unsignedTemp & 0xFF;                             
  CANMMCAN_RX_Msg_16_Sgn_10 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav5  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav5(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[16] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[16] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[16];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav5_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_17_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
}


/*----------------------------------------------------------------------------------------------*/
/* ----- PcmToCav6  -----*/  
void RTICANMM_MAIN_CAN_copy_PcmToCav6(MainSetupMsgData* data, int direction, SimStruct *S)
{
UInt32  currentMsgLength = 0;
 
if (direction == RX) {                                          
  CANMMCAN_MIDFRX[17] = (int)data->CANMsg.Format;                            
  
                                                                    
    /* Decode message data */                                       
    CANMMCAN_RXLEN[17] = data->CANMsg.Dlc;                                               
    currentMsgLength = CANMMCAN_RXLEN[17];                                   
                                                                                 
if(currentMsgLength >= 8) {
/* PcmToCav6_RC */ 
unsignedTemp = INT8_FROM_BE(*(UInt8*)(data->pData + (7)));           
  unsignedTemp = unsignedTemp & 0x3;                             
  CANMMCAN_RX_Msg_18_Sgn_1 = (UInt8)1 * (UInt8)unsignedTemp + (UInt8)(0);                    

}

}      
}


