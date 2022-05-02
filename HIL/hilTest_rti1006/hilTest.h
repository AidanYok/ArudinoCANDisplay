/*
 * hilTest.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "hilTest".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon May  2 10:16:49 2022
 *
 * Target selection: rti1006.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hilTest_h_
#define RTW_HEADER_hilTest_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef hilTest_COMMON_INCLUDES_
# define hilTest_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <can2202.h>
#include <dsts.h>
#include <DsCanBoard.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* hilTest_COMMON_INCLUDES_ */

#include "hilTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T veh_spd;                      /* '<S10>/Cast' */
  real_T y;                            /* '<Root>/MATLAB Function' */
  int32_T sfcn_o1;                     /* '<S3>/sfcn' */
  int32_T sfcn_o2;                     /* '<S3>/sfcn' */
  int32_T sfcn_o3;                     /* '<S3>/sfcn' */
  int32_T sfcn_o4;                     /* '<S3>/sfcn' */
  int32_T sfcn_o5;                     /* '<S3>/sfcn' */
  int32_T sfcn_o6;                     /* '<S3>/sfcn' */
  int32_T sfcn_o7;                     /* '<S3>/sfcn' */
  int32_T sfcn_o8;                     /* '<S3>/sfcn' */
  int32_T sfcn_o9;                     /* '<S3>/sfcn' */
  int32_T sfcn_o10;                    /* '<S3>/sfcn' */
  uint8_T Variation_DTC;               /* '<S3>/Variation_DTC' */
  boolean_T ResetRTICANMMControllerSetup;
                                   /* '<Root>/Reset@RTICANMM ControllerSetup' */
} B_hilTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T sfcn_RWORK;                   /* '<S5>/sfcn' */
  void *sfcn_PWORK[16];                /* '<S5>/sfcn' */
} DW_hilTest_T;

/* Parameters (default storage) */
struct P_hilTest_T_ {
  real_T RTICANMMCHANNEL_TLC_P1;       /* Expression: 2202
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P2;       /* Expression: 1
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P3;       /* Expression: 1
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P4;       /* Expression: 0
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P5;       /* Expression: 500
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  real_T RTICANMMCHANNEL_TLC_P6;       /* Expression: 22021143421
                                        * Referenced by: '<S3>/RTICANMMCHANNEL_TLC'
                                        */
  boolean_T ResetRTICANMMControllerSetup_Va;
                          /* Computed Parameter: ResetRTICANMMControllerSetup_Va
                           * Referenced by: '<Root>/Reset@RTICANMM ControllerSetup'
                           */
  uint8_T VariationRTICANMMControllerSetu;
                          /* Computed Parameter: VariationRTICANMMControllerSetu
                           * Referenced by: '<Root>/Variation@RTICANMM ControllerSetup'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_hilTest_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssSFcnModelMethods4 methods4[2];
    struct _ssStatesInfo2 statesInfo2[2];
    ssPeriodicStatesInfo periodicStatesInfo[2];
    struct _ssPortInfo2 inputOutputPortInfo2[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      struct _ssPortOutputs outputPortInfo[10];
      struct _ssOutPortUnit outputPortUnits[10];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[10];
    } Sfcn1;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_hilTest_T hilTest_P;

/* Block signals (default storage) */
extern B_hilTest_T hilTest_B;

/* Block states (default storage) */
extern DW_hilTest_T hilTest_DW;

/* Model entry point functions */
extern void hilTest_initialize(void);
extern void hilTest_output(void);
extern void hilTest_update(void);
extern void hilTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hilTest_T *const hilTest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hilTest'
 * '<S1>'   : 'hilTest/MATLAB Function'
 * '<S2>'   : 'hilTest/RTI Data'
 * '<S3>'   : 'hilTest/RTICANMM ControllerSetup'
 * '<S4>'   : 'hilTest/RTICANMM GeneralSetup'
 * '<S5>'   : 'hilTest/RTICANMM MainBlock'
 * '<S6>'   : 'hilTest/User2RTICANMM MainBlock'
 * '<S7>'   : 'hilTest/RTI Data/RTI Data Store'
 * '<S8>'   : 'hilTest/RTI Data/RTI Data Store/RTI Data Store'
 * '<S9>'   : 'hilTest/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 * '<S10>'  : 'hilTest/User2RTICANMM MainBlock/PcmToCav1'
 */
#endif                                 /* RTW_HEADER_hilTest_h_ */
