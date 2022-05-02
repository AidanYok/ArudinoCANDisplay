/*********************** dSPACE target specific file *************************

   Header file hilTest_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1006 7.13 (02-Nov-2019)
   Mon May  2 10:38:15 2022

   Copyright 2022, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_hilTest_trc_ptr_h_
#define RTI_HEADER_hilTest_trc_ptr_h_

/* Include the model header file. */
#include "hilTest.h"
#include "hilTest_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_hilTest_real_T_0;
EXTERN_C volatile int32_T *p_0_hilTest_int32_T_1;
EXTERN_C volatile uint8_T *p_0_hilTest_uint8_T_2;
EXTERN_C volatile boolean_T *p_0_hilTest_boolean_T_3;
EXTERN_C volatile real_T *p_1_hilTest_real_T_0;
EXTERN_C volatile boolean_T *p_1_hilTest_boolean_T_1;
EXTERN_C volatile uint8_T *p_1_hilTest_uint8_T_2;
EXTERN_C volatile real_T *p_2_hilTest_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void hilTest_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_hilTest_trc_ptr_h_ */
