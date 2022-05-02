/*****************************************************************************************************************************/
/* RTICANMM_MAIN_CAN_DEFS */
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


/*********
 *  CavToPcmLateralCtrl1 - 1
 *     CavToPcmLateralCtrl1.CavToPcmLat1_RC - 1
 *     CavToPcmLateralCtrl1.CavToPcmLat1_PV - 2
 */

/*********
 *  CavToPcmLateralCtrl2 - 2
 *     CavToPcmLateralCtrl2.CavToPcmLat2_RC - 1
 *     CavToPcmLateralCtrl2.CavToPcmLat2_PV - 2
 */

/*********
 *  CavToPcmLateralCtrl3 - 3
 *     CavToPcmLateralCtrl3.CavToPcmLat3_RC - 1
 *     CavToPcmLateralCtrl3.CavToPcmLat3_PV - 2
 */

/*********
 *  CavToPcmLateralCtrl4 - 4
 *     CavToPcmLateralCtrl4.CavToPcmLat4_RC - 1
 *     CavToPcmLateralCtrl4.CavToPcmLat4_PV - 2
 */

/*********
 *  CavToPcmLateralCtrl5 - 5
 *     CavToPcmLateralCtrl5.CavToPcmLat5_RC - 1
 *     CavToPcmLateralCtrl5.CavToPcmLat5_PV - 2
 */

/*********
 *  CavToPcmLateralCtrl6 - 6
 *     CavToPcmLateralCtrl6.CavToPcmLat6_RC - 1
 *     CavToPcmLateralCtrl6.CavToPcmLat6_PV - 2
 */

/*********
 *  CavToPcmLongCtrl1 - 7
 *     CavToPcmLongCtrl1.CavToPcmLong1_RC - 1
 *     CavToPcmLongCtrl1.obj1_pos - 2
 *     CavToPcmLongCtrl1.obj1_vel - 3
 *     CavToPcmLongCtrl1.CavToPcmLong1_PV - 4
 */

/*********
 *  CavToPcmLongCtrl2 - 8
 *     CavToPcmLongCtrl2.CavToPcmLong2_RC - 1
 *     CavToPcmLongCtrl2.CavToPcmLong2_PV - 2
 */

/*********
 *  CavToPcmLongCtrl3 - 9
 *     CavToPcmLongCtrl3.CavToPcmLong3_RC - 1
 *     CavToPcmLongCtrl3.CavToPcmLong3_PV - 2
 */

/*********
 *  CavToPcmLongCtrl4 - 10
 *     CavToPcmLongCtrl4.CavToPcmLong4_RC - 1
 *     CavToPcmLongCtrl4.CavToPcmLong4_PV - 2
 */

/*********
 *  CavToPcmLongCtrl5 - 11
 *     CavToPcmLongCtrl5.CavToPcmLong5_RC - 1
 *     CavToPcmLongCtrl5.CavToPcmLong5_PV - 2
 */

/*********
 *  CavToPcmLongCtrl6 - 12
 *     CavToPcmLongCtrl6.CavToPcmLong6_RC - 1
 *     CavToPcmLongCtrl6.CavToPcmLong6_PV - 2
 */

/*********
 *  PcmToCav1 - 13
 *     PcmToCav1.PcmToCav1_RC - 1
 *     PcmToCav1.veh_spd - 2
 *     PcmToCav1.connect_swch_stat - 3
 *     PcmToCav1.long_swch_stat - 4
 */

/*********
 *  PcmToCav2 - 14
 *     PcmToCav2.PcmToCav2_RC - 1
 *     PcmToCav2.BattSOC - 2
 *     PcmToCav2.iceOnly - 3
 *     PcmToCav2.BattTemp - 4
 *     PcmToCav2.BattCurrent - 5
 *     PcmToCav2.EngTemp - 6
 *     PcmToCav2.regenEnbld - 7
 *     PcmToCav2.eRadTemp - 8
 *     PcmToCav2.egoDistance - 9
 *     PcmToCav2.BattV - 10
 */

/*********
 *  PcmToCav3 - 15
 *     PcmToCav3.PcmToCav3_RC - 1
 *     PcmToCav3.uwACCAct - 2
 *     PcmToCav3.targetGap - 3
 *     PcmToCav3.cavLondgAct - 4
 *     PcmToCav3.setSpd - 5
 *     PcmToCav3.targetDist - 6
 *     PcmToCav3.accDecelCmd - 7
 *     PcmToCav3.driverIntervention - 8
 */

/*********
 *  PcmToCav4 - 16
 *     PcmToCav4.PcmToCav4_RC - 1
 *     PcmToCav4.ccFault - 2
 *     PcmToCav4.hybridFault - 3
 *     PcmToCav4.propFault - 4
 *     PcmToCav4.grndFault - 5
 *     PcmToCav4.magnaEradFault - 6
 *     PcmToCav4.uwEradFault - 7
 *     PcmToCav4.cntrFault - 8
 *     PcmToCav4.ACCFault - 9
 *     PcmToCav4.uwFaults - 10
 */

/*********
 *  PcmToCav5 - 17
 *     PcmToCav5.PcmToCav5_RC - 1
 */

/*********
 *  PcmToCav6 - 18
 *     PcmToCav6.PcmToCav6_RC - 1
 */
volatile uint8_T CANMMCAN_RTVE;
volatile boolean_T CANMMCAN_TRAFFIC;
volatile int32_T CANMMCAN_MAXMSGPERSTEP;

volatile uint8_T CANMMCAN_TVAR8;

volatile uint8_T CANMMCAN_TVAR8_2;

volatile uint32_T CANMMCAN_TVAR32;

volatile uint8_T CANMMCAN_TVAR8A[8];

volatile double CANMMCAN_TVARD;
volatile double CANMMCAN_TVARD2;

/* Globale Enable */
volatile boolean_T CANMMCAN_GEIN;
#define CANMMCAN_GE CANMMCAN_GEIN

/* Reset */
#define CANMMCAN_RE 1


/* Feedthrough debug variable*/
volatile uint8_T CANMMCAN_FTD;

/* Globale Enable TX */
volatile boolean_T CANMMCAN_TXGEIN;
#define CANMMCAN_TXGE CANMMCAN_TXGEIN
                               
                               
/* ECU ENABLE */               
volatile boolean_T CANMMCAN_TXEEIE[1] = {1};     
volatile boolean_T CANMMCAN_TXEEIEOLD[1] = {1};     
volatile boolean_T CANMMCAN_TXECUEN_PCM = 1;   
                            
                            

/* Message would be sent */
volatile uint8_T CANMMCAN_WBS[NUM_TX_MSG];
volatile boolean_T CANMMCAN_BYKICK[NUM_TX_MSG];

/* Message enable */
volatile boolean_T CANMMCAN_TXENIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXEIN[NUM_TX_MSG];
#define CANMMCAN_TXEN(X) (CANMMCAN_TXENIE[X])
#define USE_LOCAL_ENABLE

/* Cyclic triggering */
volatile boolean_T CANMMCAN_TXCIE[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXCIN[NUM_TX_MSG];
#define CANMMCAN_TXC(X) (CANMMCAN_TXCIE[X])

/* Message kickout */
volatile boolean_T CANMMCAN_TXKIEX[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXKIN[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXKIEXC[NUM_TX_MSG];
#define CANMMCAN_TXKOUT(X) (CANMMCAN_TXKIEX[X])
#undef MESSAGETIMEOUT


#define ID_Table_RX(X) (int)(CANMMCAN_MIDRX[X])
#define ID_Table_TX(X) (int)(CANMMCAN_MIDTX[X])
uint8_T CANMMCAN_MIDTXSW[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTXIN[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTXS[NUM_RX_MSG];
uint32_T CANMMCAN_MIDRX[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFRX[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTXIN[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTXS[NUM_RX_MSG];
uint8_T CANMMCAN_MIDFTX[NUM_RX_MSG];
uint8_T CANMMCAN_RXMT[NUM_RX_MSG];
 

volatile real_T CANMMCAN_RXt[NUM_RX_MSG];
volatile real_T CANMMCAN_RXdt[NUM_RX_MSG];
volatile boolean_T CANMMCAN_RXsta[NUM_RX_MSG];
volatile uint8_T CANMMCAN_RXerr[NUM_RX_MSG];
volatile real_T CANMMCAN_RXCTMIN[NUM_RX_MSG];
volatile real_T CANMMCAN_RXCTMAX[NUM_RX_MSG];
volatile uint8_T CANMMCAN_RXLEN[NUM_RX_MSG];
volatile uint32_T CANMMCAN_RXCNT[NUM_RX_MSG];
uint32_T CANMMCAN_MIDTX[NUM_TX_MSG];
volatile real_T CANMMCAN_TXCT[NUM_TX_MSG];
volatile real_T CANMMCAN_TXDT[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXcraw[NUM_TX_MSG];
volatile boolean_T CANMMCAN_TXsta[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXRBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXRXBUF[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXusrm[NUM_TX_MSG];
volatile uint8_T CANMMCAN_TXLEN[NUM_TX_MSG];



/* Define RX/TX structure */

volatile real_T CANMMCAN_RXCT1;
UInt8 CANMMCAN_RX_Msg_1_Sgn_1;
UInt32 CANMMCAN_RX_Msg_1_Sgn_2;
volatile real_T CANMMCAN_RXCT2;
UInt8 CANMMCAN_RX_Msg_2_Sgn_1;
UInt32 CANMMCAN_RX_Msg_2_Sgn_2;
volatile real_T CANMMCAN_RXCT3;
UInt8 CANMMCAN_RX_Msg_3_Sgn_1;
UInt32 CANMMCAN_RX_Msg_3_Sgn_2;
volatile real_T CANMMCAN_RXCT4;
UInt8 CANMMCAN_RX_Msg_4_Sgn_1;
UInt32 CANMMCAN_RX_Msg_4_Sgn_2;
volatile real_T CANMMCAN_RXCT5;
UInt8 CANMMCAN_RX_Msg_5_Sgn_1;
UInt32 CANMMCAN_RX_Msg_5_Sgn_2;
volatile real_T CANMMCAN_RXCT6;
UInt8 CANMMCAN_RX_Msg_6_Sgn_1;
UInt32 CANMMCAN_RX_Msg_6_Sgn_2;
volatile real_T CANMMCAN_RXCT7;
UInt8 CANMMCAN_RX_Msg_7_Sgn_1;
double CANMMCAN_RX_Msg_7_Sgn_2;
double CANMMCAN_RX_Msg_7_Sgn_3;
UInt8 CANMMCAN_RX_Msg_7_Sgn_4;
volatile real_T CANMMCAN_RXCT8;
UInt8 CANMMCAN_RX_Msg_8_Sgn_1;
UInt32 CANMMCAN_RX_Msg_8_Sgn_2;
volatile real_T CANMMCAN_RXCT9;
UInt8 CANMMCAN_RX_Msg_9_Sgn_1;
UInt32 CANMMCAN_RX_Msg_9_Sgn_2;
volatile real_T CANMMCAN_RXCT10;
UInt8 CANMMCAN_RX_Msg_10_Sgn_1;
UInt32 CANMMCAN_RX_Msg_10_Sgn_2;
volatile real_T CANMMCAN_RXCT11;
UInt8 CANMMCAN_RX_Msg_11_Sgn_1;
UInt32 CANMMCAN_RX_Msg_11_Sgn_2;
volatile real_T CANMMCAN_RXCT12;
UInt8 CANMMCAN_RX_Msg_12_Sgn_1;
UInt32 CANMMCAN_RX_Msg_12_Sgn_2;
UInt8 CANMMCAN_RX_Msg_13_Sgn_1;
UInt8 CANMMCAN_TX_Msg_13_Sgn_1;
UInt8 CANMMCAN_TX_Msg_13_Sgn_1_constant;
UInt8 CANMMCAN_TX_Msg_13_Sgn_1_DynValue;
UInt8 CANMMCAN_TX_Msg_13_Sgn_1_error;
double CANMMCAN_RX_Msg_13_Sgn_2;
double CANMMCAN_TX_Msg_13_Sgn_2;
double CANMMCAN_TX_Msg_13_Sgn_2_constant;
double CANMMCAN_TX_Msg_13_Sgn_2_DynValue;
double CANMMCAN_TX_Msg_13_Sgn_2_error;
UInt8 CANMMCAN_RX_Msg_13_Sgn_3;
UInt8 CANMMCAN_TX_Msg_13_Sgn_3;
UInt8 CANMMCAN_TX_Msg_13_Sgn_3_constant;
UInt8 CANMMCAN_TX_Msg_13_Sgn_3_DynValue;
UInt8 CANMMCAN_TX_Msg_13_Sgn_3_error;
UInt8 CANMMCAN_RX_Msg_13_Sgn_4;
UInt8 CANMMCAN_TX_Msg_13_Sgn_4;
UInt8 CANMMCAN_TX_Msg_13_Sgn_4_constant;
UInt8 CANMMCAN_TX_Msg_13_Sgn_4_DynValue;
UInt8 CANMMCAN_TX_Msg_13_Sgn_4_error;
volatile real_T CANMMCAN_RXCT14;
UInt8 CANMMCAN_RX_Msg_14_Sgn_1;
UInt8 CANMMCAN_RX_Msg_14_Sgn_2;
UInt8 CANMMCAN_RX_Msg_14_Sgn_3;
UInt8 CANMMCAN_RX_Msg_14_Sgn_4;
UInt8 CANMMCAN_RX_Msg_14_Sgn_5;
UInt8 CANMMCAN_RX_Msg_14_Sgn_6;
UInt8 CANMMCAN_RX_Msg_14_Sgn_7;
UInt8 CANMMCAN_RX_Msg_14_Sgn_8;
UInt8 CANMMCAN_RX_Msg_14_Sgn_9;
UInt16 CANMMCAN_RX_Msg_14_Sgn_10;
volatile real_T CANMMCAN_RXCT15;
UInt8 CANMMCAN_RX_Msg_15_Sgn_1;
UInt8 CANMMCAN_RX_Msg_15_Sgn_2;
UInt8 CANMMCAN_RX_Msg_15_Sgn_3;
UInt8 CANMMCAN_RX_Msg_15_Sgn_4;
UInt8 CANMMCAN_RX_Msg_15_Sgn_5;
UInt8 CANMMCAN_RX_Msg_15_Sgn_6;
double CANMMCAN_RX_Msg_15_Sgn_7;
UInt8 CANMMCAN_RX_Msg_15_Sgn_8;
volatile real_T CANMMCAN_RXCT16;
UInt8 CANMMCAN_RX_Msg_16_Sgn_1;
UInt8 CANMMCAN_RX_Msg_16_Sgn_2;
UInt8 CANMMCAN_RX_Msg_16_Sgn_3;
UInt8 CANMMCAN_RX_Msg_16_Sgn_4;
UInt8 CANMMCAN_RX_Msg_16_Sgn_5;
UInt8 CANMMCAN_RX_Msg_16_Sgn_6;
UInt8 CANMMCAN_RX_Msg_16_Sgn_7;
UInt8 CANMMCAN_RX_Msg_16_Sgn_8;
UInt8 CANMMCAN_RX_Msg_16_Sgn_9;
UInt8 CANMMCAN_RX_Msg_16_Sgn_10;
volatile real_T CANMMCAN_RXCT17;
UInt8 CANMMCAN_RX_Msg_17_Sgn_1;
volatile real_T CANMMCAN_RXCT18;
UInt8 CANMMCAN_RX_Msg_18_Sgn_1;






volatile uint8_T CANMMCAN_TXs[4];
volatile uint8_T CANMMCAN_TXm[4];
volatile uint8_T CANMMCAN_TXGWs[4];
volatile uint32_T CANMMCAN_TXcdo[4];
