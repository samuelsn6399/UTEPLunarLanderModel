//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ColdGas_GNC_Model_PIL_types.h
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
#ifndef ColdGas_GNC_Model_PIL_types_h_
#define ColdGas_GNC_Model_PIL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_States_
#define DEFINED_TYPEDEF_FOR_States_

struct States
{
  real_T Theta;
  real_T q;
  real_T dq;
  real_T x;
  real_T y;
  real_T z;
  real_T VxB;
  real_T VyB;
  real_T VzB;
  real_T Axb;
  real_T Ayb;
  real_T Azb;
  real_T Axe;
  real_T Aye;
  real_T Aze;
  real_T VxE;
  real_T VyE;
  real_T VzE;
};

#endif

// Parameters (default storage)
typedef struct P_ColdGas_GNC_Model_PIL_T_ P_ColdGas_GNC_Model_PIL_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ColdGas_GNC_Model_PIL_T RT_MODEL_ColdGas_GNC_Model_PI_T;

#endif                                 // ColdGas_GNC_Model_PIL_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
