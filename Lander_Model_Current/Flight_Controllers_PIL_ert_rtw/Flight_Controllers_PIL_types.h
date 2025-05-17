//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL_types.h
//
// Code generated for Simulink model 'Flight_Controllers_PIL'.
//
// Model version                  : 15.29
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Aug 12 10:48:02 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Flight_Controllers_PIL_types_h_
#define Flight_Controllers_PIL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_MotorCmd_Bus_
#define DEFINED_TYPEDEF_FOR_MotorCmd_Bus_

struct MotorCmd_Bus
{
  real_T M1;
  real_T M2;
  real_T M3;
  real_T M4;
};

#endif

// Parameters (default storage)
typedef struct P_Flight_Controllers_PIL_T_ P_Flight_Controllers_PIL_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Flight_Controllers_PI_T RT_MODEL_Flight_Controllers_P_T;

#endif                                 // Flight_Controllers_PIL_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
