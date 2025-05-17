//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_TDelayInterpolate.h
//
// Code generated for Simulink model 'ColdGas_GNC_Model_PIL'.
//
// Model version                  : 15.36
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Aug 12 10:35:08 2024
//
#ifndef rt_TDelayInterpolate_h_
#define rt_TDelayInterpolate_h_
#include "rtwtypes.h"

real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  // tMinusDelay = currentSimTime - delay
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;

#endif                                 // rt_TDelayInterpolate_h_

//
// File trailer for generated code.
//
// [EOF]
//
