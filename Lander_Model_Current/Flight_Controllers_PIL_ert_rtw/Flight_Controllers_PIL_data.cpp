//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL_data.cpp
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
#include "Flight_Controllers_PIL.h"

// Block parameters (default storage)
P_Flight_Controllers_PIL_T Flight_Controllers_PIL_P = {
  // Variable: Cant_cosine_Loss
  //  Referenced by: '<S3>/Cosine_Loss'

  0.96592582628906831,

  // Variable: Kd_LatPos
  //  Referenced by: '<S35>/Derivative Gain'

  0.0,

  // Variable: Kd_LatVel
  //  Referenced by: '<S85>/Derivative Gain'

  0.0,

  // Variable: Kd_Pitch
  //  Referenced by: '<S135>/Derivative Gain'

  41.5,

  // Variable: Ki_LatPos
  //  Referenced by: '<S39>/Integral Gain'

  0.0,

  // Variable: Ki_LatVel
  //  Referenced by: '<S89>/Integral Gain'

  0.0,

  // Variable: Ki_Pitch
  //  Referenced by: '<S139>/Integral Gain'

  0.65,

  // Variable: Kp_LatPos
  //  Referenced by: '<S47>/Proportional Gain'

  0.4,

  // Variable: Kp_LatVel
  //  Referenced by: '<S97>/Proportional Gain'

  -0.3,

  // Variable: Kp_Pitch
  //  Referenced by: '<S147>/Proportional Gain'

  16.0,

  // Variable: N_LatPos
  //  Referenced by: '<S45>/Filter Coefficient'

  0.0,

  // Variable: N_LatVel
  //  Referenced by: '<S95>/Filter Coefficient'

  0.0,

  // Variable: N_Pitch
  //  Referenced by: '<S145>/Filter Coefficient'

  85.6,

  // Variable: bOmega
  //  Referenced by: '<S3>/Y_intercept'

  168.96383979244365,

  // Variable: g
  //  Referenced by: '<S3>/Gain2'

  9.807,

  // Variable: g_Offset
  //  Referenced by: '<S3>/Gain'

  0.83333333333333337,

  // Variable: mOmega
  //  Referenced by: '<S3>/slope'

  1.6215339711366952,

  // Variable: nFans
  //  Referenced by:
  //    '<S3>/Gain1'
  //    '<S3>/Spread_Out'

  4.0,

  // Variable: tau_vCmd
  //  Referenced by: '<S4>/1_over_tau'

  0.1,

  // Mask Parameter: Lat_Position_PID_InitialConditi
  //  Referenced by: '<S37>/Filter'

  0.0,

  // Mask Parameter: Lat_Vel_Control_InitialConditio
  //  Referenced by: '<S87>/Filter'

  0.0,

  // Mask Parameter: Pitch_Controller_InitialConditi
  //  Referenced by: '<S137>/Filter'

  0.0,

  // Mask Parameter: Lat_Position_PID_InitialCondi_l
  //  Referenced by: '<S42>/Integrator'

  0.0,

  // Mask Parameter: Lat_Vel_Control_InitialCondit_k
  //  Referenced by: '<S92>/Integrator'

  0.0,

  // Mask Parameter: Pitch_Controller_InitialCondi_k
  //  Referenced by: '<S142>/Integrator'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  0.02,

  // Expression: 0
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S42>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S37>/Filter'

  0.02,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S92>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S87>/Filter'

  0.02,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S142>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S137>/Filter'

  0.02,

  // Expression: -1
  //  Referenced by: '<S3>/Negate34'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S3>/Constant'

  0.0
};

//
// File trailer for generated code.
//
// [EOF]
//
