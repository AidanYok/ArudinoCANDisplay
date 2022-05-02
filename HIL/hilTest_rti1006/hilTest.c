/*
 * hilTest.c
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

#include "hilTest_trc_ptr.h"
#include "hilTest.h"
#include "hilTest_private.h"

/* Block signals (default storage) */
B_hilTest_T hilTest_B;

/* Block states (default storage) */
DW_hilTest_T hilTest_DW;

/* Real-time model */
RT_MODEL_hilTest_T hilTest_M_;
RT_MODEL_hilTest_T *const hilTest_M = &hilTest_M_;

/* Model output function */
void hilTest_output(void)
{
  /* Clock: '<Root>/Clock' */
  hilTest_B.Clock = hilTest_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:3' */
  if (rtIsNaN(hilTest_B.Clock) || rtIsInf(hilTest_B.Clock)) {
    hilTest_B.y = (rtNaN);
  } else if (hilTest_B.Clock == 0.0) {
    hilTest_B.y = 0.0;
  } else {
    hilTest_B.y = fmod(hilTest_B.Clock, 69.0);
    if (hilTest_B.y == 0.0) {
      hilTest_B.y = 0.0;
    } else {
      if (hilTest_B.Clock < 0.0) {
        hilTest_B.y += 69.0;
      }
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* DataTypeConversion: '<S10>/Cast' */
  hilTest_B.veh_spd = hilTest_B.y;

  /* S-Function (RTICANMM_MAIN_CAN): '<S5>/sfcn' */

  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* DataTypeConversion: '<S3>/Variation_DTC' incorporates:
   *  Constant: '<Root>/Variation@RTICANMM ControllerSetup'
   */
  hilTest_B.Variation_DTC = hilTest_P.VariationRTICANMMControllerSetu;

  /* Constant: '<Root>/Reset@RTICANMM ControllerSetup' */
  hilTest_B.ResetRTICANMMControllerSetup =
    hilTest_P.ResetRTICANMMControllerSetup_Va;

  /* S-Function (RTICANMM_SETUP_CAVPCM): '<S3>/sfcn' */

  /* Level2 S-Function Block: '<S3>/sfcn' (RTICANMM_SETUP_CAVPCM) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }
}

/* Model update function */
void hilTest_update(void)
{
  /* Update for S-Function (RTICANMM_MAIN_CAN): '<S5>/sfcn' */
  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[0];
    sfcnUpdate(rts,1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for S-Function (RTICANMM_SETUP_CAVPCM): '<S3>/sfcn' */
  /* Level2 S-Function Block: '<S3>/sfcn' (RTICANMM_SETUP_CAVPCM) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[1];
    sfcnUpdate(rts,1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++hilTest_M->Timing.clockTick0)) {
    ++hilTest_M->Timing.clockTickH0;
  }

  hilTest_M->Timing.t[0] = hilTest_M->Timing.clockTick0 *
    hilTest_M->Timing.stepSize0 + hilTest_M->Timing.clockTickH0 *
    hilTest_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++hilTest_M->Timing.clockTick1)) {
      ++hilTest_M->Timing.clockTickH1;
    }

    hilTest_M->Timing.t[1] = hilTest_M->Timing.clockTick1 *
      hilTest_M->Timing.stepSize1 + hilTest_M->Timing.clockTickH1 *
      hilTest_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void hilTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)hilTest_M, 0,
                sizeof(RT_MODEL_hilTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&hilTest_M->solverInfo, &hilTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&hilTest_M->solverInfo, &rtmGetTPtr(hilTest_M));
    rtsiSetStepSizePtr(&hilTest_M->solverInfo, &hilTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&hilTest_M->solverInfo, (&rtmGetErrorStatus(hilTest_M)));
    rtsiSetRTModelPtr(&hilTest_M->solverInfo, hilTest_M);
  }

  rtsiSetSimTimeStep(&hilTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&hilTest_M->solverInfo,"FixedStepDiscrete");
  hilTest_M->solverInfoPtr = (&hilTest_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = hilTest_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    hilTest_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    hilTest_M->Timing.sampleTimes = (&hilTest_M->Timing.sampleTimesArray[0]);
    hilTest_M->Timing.offsetTimes = (&hilTest_M->Timing.offsetTimesArray[0]);

    /* task periods */
    hilTest_M->Timing.sampleTimes[0] = (0.0);
    hilTest_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    hilTest_M->Timing.offsetTimes[0] = (0.0);
    hilTest_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(hilTest_M, &hilTest_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = hilTest_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    hilTest_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(hilTest_M, -1);
  hilTest_M->Timing.stepSize0 = 0.001;
  hilTest_M->Timing.stepSize1 = 0.001;
  hilTest_M->solverInfoPtr = (&hilTest_M->solverInfo);
  hilTest_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&hilTest_M->solverInfo, 0.001);
  rtsiSetSolverMode(&hilTest_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &hilTest_B), 0,
                sizeof(B_hilTest_T));

  /* states (dwork) */
  (void) memset((void *)&hilTest_DW, 0,
                sizeof(DW_hilTest_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &hilTest_M->NonInlinedSFcns.sfcnInfo;
    hilTest_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(hilTest_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &hilTest_M->Sizes.numSampTimes);
    hilTest_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(hilTest_M)[0]);
    hilTest_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(hilTest_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,hilTest_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(hilTest_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(hilTest_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(hilTest_M));
    rtssSetStepSizePtr(sfcnInfo, &hilTest_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(hilTest_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &hilTest_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &hilTest_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &hilTest_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &hilTest_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &hilTest_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &hilTest_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &hilTest_M->solverInfoPtr);
  }

  hilTest_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&hilTest_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    hilTest_M->childSfunctions = (&hilTest_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);
    hilTest_M->childSfunctions[0] = (&hilTest_M->
      NonInlinedSFcns.childSFunctions[0]);
    hilTest_M->childSfunctions[1] = (&hilTest_M->
      NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: hilTest/<S5>/sfcn (RTICANMM_MAIN_CAN) */
    {
      SimStruct *rts = hilTest_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = hilTest_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = hilTest_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = hilTest_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hilTest_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hilTest_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hilTest_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hilTest_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hilTest_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hilTest_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hilTest_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &hilTest_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &hilTest_B.veh_spd);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "hilTest/RTICANMM MainBlock/sfcn");
      ssSetRTModel(rts,hilTest_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &hilTest_DW.sfcn_RWORK);
      ssSetPWork(rts, (void **) &hilTest_DW.sfcn_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &hilTest_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &hilTest_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &hilTest_DW.sfcn_RWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 16);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &hilTest_DW.sfcn_PWORK[0]);
      }

      /* registration */
      RTICANMM_MAIN_CAN(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: hilTest/<S3>/sfcn (RTICANMM_SETUP_CAVPCM) */
    {
      SimStruct *rts = hilTest_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = hilTest_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = hilTest_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = hilTest_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &hilTest_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &hilTest_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, hilTest_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &hilTest_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &hilTest_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &hilTest_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &hilTest_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &hilTest_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &hilTest_B.Variation_DTC);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &hilTest_B.ResetRTICANMMControllerSetup);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 10);
        _ssSetPortInfo2ForOutputUnits(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        ssSetOutputPortUnit(rts, 7, 0);
        ssSetOutputPortUnit(rts, 8, 0);
        ssSetOutputPortUnit(rts, 9, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &hilTest_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 7, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 8, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 9, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *) &hilTest_B.sfcn_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((int32_T *) &hilTest_B.sfcn_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int32_T *) &hilTest_B.sfcn_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int32_T *) &hilTest_B.sfcn_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int32_T *) &hilTest_B.sfcn_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *) &hilTest_B.sfcn_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int32_T *) &hilTest_B.sfcn_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int32_T *) &hilTest_B.sfcn_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((int32_T *) &hilTest_B.sfcn_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((int32_T *) &hilTest_B.sfcn_o10));
        }
      }

      /* path info */
      ssSetModelName(rts, "sfcn");
      ssSetPath(rts, "hilTest/RTICANMM ControllerSetup/sfcn");
      ssSetRTModel(rts,hilTest_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      RTICANMM_SETUP_CAVPCM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    hilTest_rti_init_trc_pointers();
  }

  /* user code (Start function Body) */
  {
    /* Initialize host service for CAN monitoring */
    ts_timestamp_type ts = { 0, 0 };

    host_service(31, &ts);
  }

  /* Start for S-Function (RTICANMM_MAIN_CAN): '<S5>/sfcn' */
  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Reset@RTICANMM ControllerSetup' */
  hilTest_B.ResetRTICANMMControllerSetup =
    hilTest_P.ResetRTICANMMControllerSetup_Va;

  /* Start for S-Function (RTICANMM_SETUP_CAVPCM): '<S3>/sfcn' */
  /* Level2 S-Function Block: '<S3>/sfcn' (RTICANMM_SETUP_CAVPCM) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (RTICANMM_MAIN_CAN): '<S5>/sfcn' */
  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (RTICANMM_SETUP_CAVPCM): '<S3>/sfcn' */
  /* Level2 S-Function Block: '<S3>/sfcn' (RTICANMM_SETUP_CAVPCM) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void hilTest_terminate(void)
{
  /* Terminate for S-Function (RTICANMM_MAIN_CAN): '<S5>/sfcn' */
  /* Level2 S-Function Block: '<S5>/sfcn' (RTICANMM_MAIN_CAN) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (RTICANMM_SETUP_CAVPCM): '<S3>/sfcn' */
  /* Level2 S-Function Block: '<S3>/sfcn' (RTICANMM_SETUP_CAVPCM) */
  {
    SimStruct *rts = hilTest_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}
