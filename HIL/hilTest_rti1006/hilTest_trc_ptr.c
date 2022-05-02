/***************************************************************************

   Source file hilTest_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1006 7.13 (02-Nov-2019)
   Mon May  2 10:38:15 2022

   Copyright 2022, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "hilTest_trc_ptr.h"
#include "hilTest.h"
#include "hilTest_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_hilTest_real_T_0 = NULL;
volatile int32_T *p_0_hilTest_int32_T_1 = NULL;
volatile uint8_T *p_0_hilTest_uint8_T_2 = NULL;
volatile boolean_T *p_0_hilTest_boolean_T_3 = NULL;
volatile real_T *p_1_hilTest_real_T_0 = NULL;
volatile boolean_T *p_1_hilTest_boolean_T_1 = NULL;
volatile uint8_T *p_1_hilTest_uint8_T_2 = NULL;
volatile real_T *p_2_hilTest_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_hilTest_real_T_0 = &hilTest_B.Clock;
  p_0_hilTest_int32_T_1 = &hilTest_B.sfcn_o1;
  p_0_hilTest_uint8_T_2 = &hilTest_B.Variation_DTC;
  p_0_hilTest_boolean_T_3 = &hilTest_B.ResetRTICANMMControllerSetup;
  p_1_hilTest_real_T_0 = &hilTest_P.RTICANMMCHANNEL_TLC_P1;
  p_1_hilTest_boolean_T_1 = &hilTest_P.ResetRTICANMMControllerSetup_Va;
  p_1_hilTest_uint8_T_2 = &hilTest_P.VariationRTICANMMControllerSetu;
  p_2_hilTest_real_T_0 = &hilTest_DW.sfcn_RWORK;
}

void hilTest_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
