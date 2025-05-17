//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ColdGas_GNC_Model_PIL_private.h
//
// Code generated for Simulink model 'ColdGas_GNC_Model_PIL'.
//
// Model version                  : 15.36
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Aug 12 10:35:08 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef ColdGas_GNC_Model_PIL_private_h_
#define ColdGas_GNC_Model_PIL_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "ColdGas_GNC_Model_PIL_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern rtTimingBridge ColdGas_GNC_Model_PI_TimingBrdg;

// private model entry point functions
extern void ColdGas_GNC_Model_PIL_derivatives(void);

#endif                                 // ColdGas_GNC_Model_PIL_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
