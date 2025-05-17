//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL.h
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
#ifndef Flight_Controllers_PIL_h_
#define Flight_Controllers_PIL_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Flight_Controllers_PIL_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_Flight_Controllers_PIL_T {
  real_T y[10];
  real_T x[10];
  real_T y_m[10];
  real_T x_c[10];
  real_T dv[4];
  real_T dv1[4];
  real_T y_k[4];
  real_T x_cx[4];
  real_T hErr;
  real_T vErr;
  real_T vertCmd;
  real_T Sum5;                         // '<S3>/Sum5'
  real_T FilterCoefficient_i;          // '<S95>/Filter Coefficient'
};

// Block states (default storage) for system '<Root>'
struct DW_Flight_Controllers_PIL_T {
  real_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real_T Integrator_DSTATE;            // '<S42>/Integrator'
  real_T Filter_DSTATE;                // '<S37>/Filter'
  real_T Integrator_DSTATE_e;          // '<S92>/Integrator'
  real_T Filter_DSTATE_a;              // '<S87>/Filter'
  real_T Integrator_DSTATE_i;          // '<S142>/Integrator'
  real_T Filter_DSTATE_k;              // '<S137>/Filter'
  real_T thr_previous;                 // '<Root>/Vertical_Controller'
};

// External inputs (root inport signals with default storage)
struct ExtU_Flight_Controllers_PIL_T {
  real_T t;                            // '<Root>/t'
  real_T switchLines[16];              // '<Root>/switchLines'
  real_T m;                            // '<Root>/m'
  boolean_T LandNowFl;                 // '<Root>/LandNowFl'
  real_T States_x;                     // '<Root>/States_x'
  real_T States_VxE;                   // '<Root>/States_VxE'
  real_T States_Theta;                 // '<Root>/States_Theta'
  real_T States_z;                     // '<Root>/States_z'
  real_T States_VzB;                   // '<Root>/States_VzB'
  real_T Sched_Vertical[30];           // '<Root>/Sched_Vertical'
  real_T Sched_Lateral[40];            // '<Root>/Sched_Lateral'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_Flight_Controllers_PIL_T {
  real_T fireCmd;                      // '<Root>/fireCmd'
  real_T VertMode;                     // '<Root>/VertMode'
  real_T Cntrl_telem[10];              // '<Root>/Cntrl_telem'
  real_T Controls_xCmd;                // '<Root>/Controls_xCmd'
  real_T Controls_fire_Cmd;            // '<Root>/Controls_fire_Cmd'
  real_T Controls_yCmd;                // '<Root>/Controls_yCmd'
  real_T Controls_OmegaCmds_M1;        // '<Root>/Controls_OmegaCmds_M1'
  real_T Controls_OmegaCmds_M2;        // '<Root>/Controls_OmegaCmds_M2'
  real_T Controls_OmegaCmds_M3;        // '<Root>/Controls_OmegaCmds_M3'
  real_T Controls_OmegaCmds_M4;        // '<Root>/Controls_OmegaCmds_M4'
  MotorCmd_Bus MotorCmds;              // '<Root>/MotorCmds'
};

// Parameters (default storage)
struct P_Flight_Controllers_PIL_T_ {
  real_T Cant_cosine_Loss;             // Variable: Cant_cosine_Loss
                                          //  Referenced by: '<S3>/Cosine_Loss'

  real_T Kd_LatPos;                    // Variable: Kd_LatPos
                                          //  Referenced by: '<S35>/Derivative Gain'

  real_T Kd_LatVel;                    // Variable: Kd_LatVel
                                          //  Referenced by: '<S85>/Derivative Gain'

  real_T Kd_Pitch;                     // Variable: Kd_Pitch
                                          //  Referenced by: '<S135>/Derivative Gain'

  real_T Ki_LatPos;                    // Variable: Ki_LatPos
                                          //  Referenced by: '<S39>/Integral Gain'

  real_T Ki_LatVel;                    // Variable: Ki_LatVel
                                          //  Referenced by: '<S89>/Integral Gain'

  real_T Ki_Pitch;                     // Variable: Ki_Pitch
                                          //  Referenced by: '<S139>/Integral Gain'

  real_T Kp_LatPos;                    // Variable: Kp_LatPos
                                          //  Referenced by: '<S47>/Proportional Gain'

  real_T Kp_LatVel;                    // Variable: Kp_LatVel
                                          //  Referenced by: '<S97>/Proportional Gain'

  real_T Kp_Pitch;                     // Variable: Kp_Pitch
                                          //  Referenced by: '<S147>/Proportional Gain'

  real_T N_LatPos;                     // Variable: N_LatPos
                                          //  Referenced by: '<S45>/Filter Coefficient'

  real_T N_LatVel;                     // Variable: N_LatVel
                                          //  Referenced by: '<S95>/Filter Coefficient'

  real_T N_Pitch;                      // Variable: N_Pitch
                                          //  Referenced by: '<S145>/Filter Coefficient'

  real_T bOmega;                       // Variable: bOmega
                                          //  Referenced by: '<S3>/Y_intercept'

  real_T g;                            // Variable: g
                                          //  Referenced by: '<S3>/Gain2'

  real_T g_Offset;                     // Variable: g_Offset
                                          //  Referenced by: '<S3>/Gain'

  real_T mOmega;                       // Variable: mOmega
                                          //  Referenced by: '<S3>/slope'

  real_T nFans;                        // Variable: nFans
                                          //  Referenced by:
                                          //    '<S3>/Gain1'
                                          //    '<S3>/Spread_Out'

  real_T tau_vCmd;                     // Variable: tau_vCmd
                                          //  Referenced by: '<S4>/1_over_tau'

  real_T Lat_Position_PID_InitialConditi;
                              // Mask Parameter: Lat_Position_PID_InitialConditi
                                 //  Referenced by: '<S37>/Filter'

  real_T Lat_Vel_Control_InitialConditio;
                              // Mask Parameter: Lat_Vel_Control_InitialConditio
                                 //  Referenced by: '<S87>/Filter'

  real_T Pitch_Controller_InitialConditi;
                              // Mask Parameter: Pitch_Controller_InitialConditi
                                 //  Referenced by: '<S137>/Filter'

  real_T Lat_Position_PID_InitialCondi_l;
                              // Mask Parameter: Lat_Position_PID_InitialCondi_l
                                 //  Referenced by: '<S42>/Integrator'

  real_T Lat_Vel_Control_InitialCondit_k;
                              // Mask Parameter: Lat_Vel_Control_InitialCondit_k
                                 //  Referenced by: '<S92>/Integrator'

  real_T Pitch_Controller_InitialCondi_k;
                              // Mask Parameter: Pitch_Controller_InitialCondi_k
                                 //  Referenced by: '<S142>/Integrator'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S42>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S37>/Filter'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S92>/Integrator'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S87>/Filter'

  real_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S142>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S137>/Filter'

  real_T Negate34_Gain;                // Expression: -1
                                          //  Referenced by: '<S3>/Negate34'

  real_T Constant_Value;               // Expression: 0
                                          //  Referenced by: '<S3>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_Flight_Controllers_PI_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Flight_Controllers_PIL_T Flight_Controllers_PIL_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Flight_Controllers_PIL_T Flight_Controllers_PIL_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Flight_Controllers_PIL_T Flight_Controllers_PIL_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_Flight_Controllers_PIL_T Flight_Controllers_PIL_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_Flight_Controllers_PIL_T Flight_Controllers_PIL_Y;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Flight_Controllers_PIL_initialize(void);
  extern void Flight_Controllers_PIL_step(void);
  extern void Flight_Controllers_PIL_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Flight_Controllers_P_T *const Flight_Controllers_PIL_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Zero-Order Hold' : Eliminated since input and output rates are identical
//  Block '<S3>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S3>/Zero-Order Hold2' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Flight_Controllers_PIL'
//  '<S1>'   : 'Flight_Controllers_PIL/Lateral_Controllers'
//  '<S2>'   : 'Flight_Controllers_PIL/Vertical_Controller'
//  '<S3>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14'
//  '<S4>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Filter_Cmd1'
//  '<S5>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID'
//  '<S6>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control'
//  '<S7>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lateral_Flight_Plan'
//  '<S8>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller'
//  '<S9>'   : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Anti-windup'
//  '<S10>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/D Gain'
//  '<S11>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/External Derivative'
//  '<S12>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter'
//  '<S13>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter ICs'
//  '<S14>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/I Gain'
//  '<S15>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain'
//  '<S16>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain Fdbk'
//  '<S17>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator'
//  '<S18>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator ICs'
//  '<S19>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Copy'
//  '<S20>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Gain'
//  '<S21>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/P Copy'
//  '<S22>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Parallel P Gain'
//  '<S23>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Reset Signal'
//  '<S24>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation'
//  '<S25>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation Fdbk'
//  '<S26>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum'
//  '<S27>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum Fdbk'
//  '<S28>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode'
//  '<S29>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode Sum'
//  '<S30>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Integral'
//  '<S31>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Ngain'
//  '<S32>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/postSat Signal'
//  '<S33>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preSat Signal'
//  '<S34>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Anti-windup/Passthrough'
//  '<S35>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/D Gain/Internal Parameters'
//  '<S36>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/External Derivative/Error'
//  '<S37>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter/Disc. Forward Euler Filter'
//  '<S38>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter ICs/Internal IC - Filter'
//  '<S39>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/I Gain/Internal Parameters'
//  '<S40>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain/Passthrough'
//  '<S41>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain Fdbk/Disabled'
//  '<S42>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator/Discrete'
//  '<S43>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator ICs/Internal IC'
//  '<S44>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Copy/Disabled'
//  '<S45>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Gain/Internal Parameters'
//  '<S46>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/P Copy/Disabled'
//  '<S47>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Parallel P Gain/Internal Parameters'
//  '<S48>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Reset Signal/Disabled'
//  '<S49>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation/Passthrough'
//  '<S50>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation Fdbk/Disabled'
//  '<S51>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum/Sum_PID'
//  '<S52>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum Fdbk/Disabled'
//  '<S53>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode/Disabled'
//  '<S54>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode Sum/Passthrough'
//  '<S55>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S56>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Ngain/Passthrough'
//  '<S57>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/postSat Signal/Forward_Path'
//  '<S58>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preSat Signal/Forward_Path'
//  '<S59>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Anti-windup'
//  '<S60>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/D Gain'
//  '<S61>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/External Derivative'
//  '<S62>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter'
//  '<S63>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter ICs'
//  '<S64>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/I Gain'
//  '<S65>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain'
//  '<S66>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain Fdbk'
//  '<S67>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator'
//  '<S68>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator ICs'
//  '<S69>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Copy'
//  '<S70>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Gain'
//  '<S71>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/P Copy'
//  '<S72>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Parallel P Gain'
//  '<S73>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Reset Signal'
//  '<S74>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation'
//  '<S75>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation Fdbk'
//  '<S76>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum'
//  '<S77>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum Fdbk'
//  '<S78>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode'
//  '<S79>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode Sum'
//  '<S80>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Integral'
//  '<S81>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Ngain'
//  '<S82>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/postSat Signal'
//  '<S83>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preSat Signal'
//  '<S84>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Anti-windup/Passthrough'
//  '<S85>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/D Gain/Internal Parameters'
//  '<S86>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/External Derivative/Error'
//  '<S87>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter/Disc. Forward Euler Filter'
//  '<S88>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter ICs/Internal IC - Filter'
//  '<S89>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/I Gain/Internal Parameters'
//  '<S90>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain/Passthrough'
//  '<S91>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain Fdbk/Disabled'
//  '<S92>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator/Discrete'
//  '<S93>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator ICs/Internal IC'
//  '<S94>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Copy/Disabled'
//  '<S95>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Gain/Internal Parameters'
//  '<S96>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/P Copy/Disabled'
//  '<S97>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Parallel P Gain/Internal Parameters'
//  '<S98>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Reset Signal/Disabled'
//  '<S99>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation/Passthrough'
//  '<S100>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation Fdbk/Disabled'
//  '<S101>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum/Sum_PID'
//  '<S102>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum Fdbk/Disabled'
//  '<S103>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode/Disabled'
//  '<S104>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode Sum/Passthrough'
//  '<S105>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Integral/TsSignalSpecification'
//  '<S106>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Ngain/Passthrough'
//  '<S107>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/postSat Signal/Forward_Path'
//  '<S108>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preSat Signal/Forward_Path'
//  '<S109>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Anti-windup'
//  '<S110>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/D Gain'
//  '<S111>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/External Derivative'
//  '<S112>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter'
//  '<S113>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter ICs'
//  '<S114>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/I Gain'
//  '<S115>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain'
//  '<S116>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain Fdbk'
//  '<S117>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator'
//  '<S118>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator ICs'
//  '<S119>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Copy'
//  '<S120>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Gain'
//  '<S121>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/P Copy'
//  '<S122>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Parallel P Gain'
//  '<S123>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Reset Signal'
//  '<S124>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation'
//  '<S125>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation Fdbk'
//  '<S126>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum'
//  '<S127>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum Fdbk'
//  '<S128>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode'
//  '<S129>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode Sum'
//  '<S130>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Integral'
//  '<S131>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Ngain'
//  '<S132>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/postSat Signal'
//  '<S133>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preSat Signal'
//  '<S134>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Anti-windup/Passthrough'
//  '<S135>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/D Gain/Internal Parameters'
//  '<S136>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/External Derivative/Error'
//  '<S137>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter/Disc. Forward Euler Filter'
//  '<S138>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter ICs/Internal IC - Filter'
//  '<S139>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/I Gain/Internal Parameters'
//  '<S140>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain/Passthrough'
//  '<S141>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator/Discrete'
//  '<S143>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator ICs/Internal IC'
//  '<S144>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Copy/Disabled'
//  '<S145>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Gain/Internal Parameters'
//  '<S146>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/P Copy/Disabled'
//  '<S147>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Parallel P Gain/Internal Parameters'
//  '<S148>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Reset Signal/Disabled'
//  '<S149>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation/Passthrough'
//  '<S150>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation Fdbk/Disabled'
//  '<S151>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum/Sum_PID'
//  '<S152>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum Fdbk/Disabled'
//  '<S153>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode/Disabled'
//  '<S154>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode Sum/Passthrough'
//  '<S155>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S156>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Ngain/Passthrough'
//  '<S157>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/postSat Signal/Forward_Path'
//  '<S158>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preSat Signal/Forward_Path'

#endif                                 // Flight_Controllers_PIL_h_

//
// File trailer for generated code.
//
// [EOF]
//
