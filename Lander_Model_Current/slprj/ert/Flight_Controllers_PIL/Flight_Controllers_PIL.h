//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL.h
//
// Code generated for Simulink model 'Flight_Controllers_PIL'.
//
// Model version                  : 15.33
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Fri Oct 11 09:35:32 2024
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

#include "model_reference_types.h"

// Block signals for model 'Flight_Controllers_PIL'
struct B_Flight_Controllers_PIL_c_T {
  real_T y[10];
  real_T x[10];
  real_T y_m[10];
  real_T x_c[10];
  real_T rtu_switchLines[4];
  real_T rtu_switchLines_k[4];
  real_T y_c[4];
  real_T x_b[4];
  real_T hErr;
  real_T vErr;
  real_T vertCmd;
  real_T hCmd;
  real_T hDot_Cmd;
  real_T Gain;                         // '<S3>/Gain'
};

// Block states (default storage) for model 'Flight_Controllers_PIL'
struct DW_Flight_Controllers_PIL_f_T {
  real_T DiscreteTimeIntegrator_DSTATE;// '<S4>/Discrete-Time Integrator'
  real_T Integrator_DSTATE;            // '<S43>/Integrator'
  real_T Filter_DSTATE;                // '<S38>/Filter'
  real_T Integrator_DSTATE_e;          // '<S95>/Integrator'
  real_T Filter_DSTATE_a;              // '<S90>/Filter'
  real_T Integrator_DSTATE_i;          // '<S147>/Integrator'
  real_T Filter_DSTATE_k;              // '<S142>/Filter'
  real_T thr_previous;                 // '<Root>/Vertical_Controller'
};

// Parameters (default storage)
struct P_Flight_Controllers_PIL_T_ {
  real_T Lat_Position_PID_InitialConditi;
                              // Mask Parameter: Lat_Position_PID_InitialConditi
                                 //  Referenced by: '<S38>/Filter'

  real_T Lat_Vel_Control_InitialConditio;
                              // Mask Parameter: Lat_Vel_Control_InitialConditio
                                 //  Referenced by: '<S90>/Filter'

  real_T Pitch_Controller_InitialConditi;
                              // Mask Parameter: Pitch_Controller_InitialConditi
                                 //  Referenced by: '<S142>/Filter'

  real_T Lat_Position_PID_InitialCondi_l;
                              // Mask Parameter: Lat_Position_PID_InitialCondi_l
                                 //  Referenced by: '<S43>/Integrator'

  real_T Lat_Vel_Control_InitialCondit_k;
                              // Mask Parameter: Lat_Vel_Control_InitialCondit_k
                                 //  Referenced by: '<S95>/Integrator'

  real_T Pitch_Controller_InitialCondi_k;
                              // Mask Parameter: Pitch_Controller_InitialCondi_k
                                 //  Referenced by: '<S147>/Integrator'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S4>/Discrete-Time Integrator'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S43>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S38>/Filter'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S95>/Integrator'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S90>/Filter'

  real_T Integrator_gainval_c;       // Computed Parameter: Integrator_gainval_c
                                        //  Referenced by: '<S147>/Integrator'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S142>/Filter'

  real_T Negate34_Gain;                // Expression: -1
                                          //  Referenced by: '<S3>/Negate34'

  real_T Constant_Value;               // Expression: 0
                                          //  Referenced by: '<S3>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_Flight_Controllers_PI_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    int_T mdlref_GlobalTID[1];
  } Timing;

  time_T getClockTickH0() const;
  time_T getClockTick0() const;
  time_T getT() const;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const aErrorStatus) const;
  boolean_T isSampleHit(int32_T sti) const;
  const char_T** getErrorStatusPointer() const;
  void setErrorStatusPointer(const char_T** aErrorStatusPointer);
};

struct MdlrefDW_Flight_Controllers_P_T {
  B_Flight_Controllers_PIL_c_T rtb;
  DW_Flight_Controllers_PIL_f_T rtdw;
  RT_MODEL_Flight_Controllers_P_T rtm;
};

// Model block global parameters (default storage)
extern real_T rtP_Cant_cosine_Loss;    // Variable: Cant_cosine_Loss
                                          //  Referenced by: '<S3>/Cosine_Loss'

extern real_T rtP_Kd_LatPos;           // Variable: Kd_LatPos
                                          //  Referenced by: '<S36>/Derivative Gain'

extern real_T rtP_Kd_LatVel;           // Variable: Kd_LatVel
                                          //  Referenced by: '<S88>/Derivative Gain'

extern real_T rtP_Kd_Pitch;            // Variable: Kd_Pitch
                                          //  Referenced by: '<S140>/Derivative Gain'

extern real_T rtP_Ki_LatPos;           // Variable: Ki_LatPos
                                          //  Referenced by: '<S40>/Integral Gain'

extern real_T rtP_Ki_LatVel;           // Variable: Ki_LatVel
                                          //  Referenced by: '<S92>/Integral Gain'

extern real_T rtP_Ki_Pitch;            // Variable: Ki_Pitch
                                          //  Referenced by: '<S144>/Integral Gain'

extern real_T rtP_Kp_LatPos;           // Variable: Kp_LatPos
                                          //  Referenced by: '<S48>/Proportional Gain'

extern real_T rtP_Kp_LatVel;           // Variable: Kp_LatVel
                                          //  Referenced by: '<S100>/Proportional Gain'

extern real_T rtP_Kp_Pitch;            // Variable: Kp_Pitch
                                          //  Referenced by: '<S152>/Proportional Gain'

extern real_T rtP_N_LatPos;            // Variable: N_LatPos
                                          //  Referenced by: '<S46>/Filter Coefficient'

extern real_T rtP_N_LatVel;            // Variable: N_LatVel
                                          //  Referenced by: '<S98>/Filter Coefficient'

extern real_T rtP_N_Pitch;             // Variable: N_Pitch
                                          //  Referenced by: '<S150>/Filter Coefficient'

extern real_T rtP_bOmega;              // Variable: bOmega
                                          //  Referenced by: '<S3>/Y_intercept'

extern real_T rtP_g;                   // Variable: g
                                          //  Referenced by: '<S3>/Gain2'

extern real_T rtP_g_Offset;            // Variable: g_Offset
                                          //  Referenced by: '<S3>/Gain'

extern real_T rtP_mOmega;              // Variable: mOmega
                                          //  Referenced by: '<S3>/slope'

extern real_T rtP_nFans;               // Variable: nFans
                                          //  Referenced by:
                                          //    '<S3>/Gain1'
                                          //    '<S3>/Spread_Out'

extern real_T rtP_tau_vCmd;            // Variable: tau_vCmd
                                          //  Referenced by: '<S4>/1_over_tau'


// Model reference registration function
extern void Flight_Controllers_P_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0,
  RT_MODEL_Flight_Controllers_P_T *const Flight_Controllers_PIL_M);
extern void Flight_Controllers_PIL_Init(DW_Flight_Controllers_PIL_f_T *localDW);
extern void Flight_Controllers_PIL(RT_MODEL_Flight_Controllers_P_T * const
  Flight_Controllers_PIL_M, const real_T *rtu_t, const real_T rtu_switchLines[16],
  const real_T *rtu_m, const real_T *rtu_States_x, const real_T *rtu_States_VxE,
  const real_T *rtu_States_Theta, const real_T *rtu_States_z, const real_T
  *rtu_States_VzB, const real_T rtu_Sched_Vertical[30], const real_T
  rtu_Sched_Lateral[40], real_T *rty_fireCmd, real_T *rty_VertMode, real_T
  rty_Cntrl_telem[10], real_T *rty_Controls_xCmd, real_T *rty_Controls_fire_Cmd,
  real_T *rty_Controls_yCmd, real_T *rty_Controls_OmegaCmds_M1, real_T
  *rty_Controls_OmegaCmds_M2, real_T *rty_Controls_OmegaCmds_M3, real_T
  *rty_Controls_OmegaCmds_M4, real_T *rty_MotorCmds_M1, real_T *rty_MotorCmds_M2,
  real_T *rty_MotorCmds_M3, real_T *rty_MotorCmds_M4,
  B_Flight_Controllers_PIL_c_T *localB, DW_Flight_Controllers_PIL_f_T *localDW);

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
//  '<S33>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preInt Signal'
//  '<S34>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preSat Signal'
//  '<S35>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Anti-windup/Passthrough'
//  '<S36>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/D Gain/Internal Parameters'
//  '<S37>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/External Derivative/Error'
//  '<S38>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter/Disc. Forward Euler Filter'
//  '<S39>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Filter ICs/Internal IC - Filter'
//  '<S40>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/I Gain/Internal Parameters'
//  '<S41>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain/Passthrough'
//  '<S42>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator/Discrete'
//  '<S44>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Integrator ICs/Internal IC'
//  '<S45>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Copy/Disabled'
//  '<S46>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/N Gain/Internal Parameters'
//  '<S47>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/P Copy/Disabled'
//  '<S48>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Parallel P Gain/Internal Parameters'
//  '<S49>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Reset Signal/Disabled'
//  '<S50>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation/Passthrough'
//  '<S51>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Saturation Fdbk/Disabled'
//  '<S52>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum/Sum_PID'
//  '<S53>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Sum Fdbk/Disabled'
//  '<S54>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode/Disabled'
//  '<S55>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/postSat Signal/Forward_Path'
//  '<S59>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preInt Signal/Internal PreInt'
//  '<S60>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Position_PID/preSat Signal/Forward_Path'
//  '<S61>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Anti-windup'
//  '<S62>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/D Gain'
//  '<S63>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/External Derivative'
//  '<S64>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter'
//  '<S65>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter ICs'
//  '<S66>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/I Gain'
//  '<S67>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain'
//  '<S68>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain Fdbk'
//  '<S69>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator'
//  '<S70>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator ICs'
//  '<S71>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Copy'
//  '<S72>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Gain'
//  '<S73>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/P Copy'
//  '<S74>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Parallel P Gain'
//  '<S75>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Reset Signal'
//  '<S76>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation'
//  '<S77>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation Fdbk'
//  '<S78>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum'
//  '<S79>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum Fdbk'
//  '<S80>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode'
//  '<S81>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode Sum'
//  '<S82>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Integral'
//  '<S83>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Ngain'
//  '<S84>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/postSat Signal'
//  '<S85>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preInt Signal'
//  '<S86>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preSat Signal'
//  '<S87>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Anti-windup/Passthrough'
//  '<S88>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/D Gain/Internal Parameters'
//  '<S89>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/External Derivative/Error'
//  '<S90>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter/Disc. Forward Euler Filter'
//  '<S91>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Filter ICs/Internal IC - Filter'
//  '<S92>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/I Gain/Internal Parameters'
//  '<S93>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain/Passthrough'
//  '<S94>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Ideal P Gain Fdbk/Disabled'
//  '<S95>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator/Discrete'
//  '<S96>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Integrator ICs/Internal IC'
//  '<S97>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Copy/Disabled'
//  '<S98>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/N Gain/Internal Parameters'
//  '<S99>'  : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/P Copy/Disabled'
//  '<S100>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Parallel P Gain/Internal Parameters'
//  '<S101>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Reset Signal/Disabled'
//  '<S102>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation/Passthrough'
//  '<S103>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Saturation Fdbk/Disabled'
//  '<S104>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum/Sum_PID'
//  '<S105>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Sum Fdbk/Disabled'
//  '<S106>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode/Disabled'
//  '<S107>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tracking Mode Sum/Passthrough'
//  '<S108>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Integral/TsSignalSpecification'
//  '<S109>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/Tsamp - Ngain/Passthrough'
//  '<S110>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/postSat Signal/Forward_Path'
//  '<S111>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preInt Signal/Internal PreInt'
//  '<S112>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Lat_Vel_Control/preSat Signal/Forward_Path'
//  '<S113>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Anti-windup'
//  '<S114>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/D Gain'
//  '<S115>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/External Derivative'
//  '<S116>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter'
//  '<S117>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter ICs'
//  '<S118>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/I Gain'
//  '<S119>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain'
//  '<S120>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain Fdbk'
//  '<S121>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator'
//  '<S122>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator ICs'
//  '<S123>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Copy'
//  '<S124>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Gain'
//  '<S125>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/P Copy'
//  '<S126>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Parallel P Gain'
//  '<S127>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Reset Signal'
//  '<S128>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation'
//  '<S129>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation Fdbk'
//  '<S130>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum'
//  '<S131>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum Fdbk'
//  '<S132>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode'
//  '<S133>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode Sum'
//  '<S134>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Integral'
//  '<S135>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Ngain'
//  '<S136>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/postSat Signal'
//  '<S137>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preInt Signal'
//  '<S138>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preSat Signal'
//  '<S139>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Anti-windup/Passthrough'
//  '<S140>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/D Gain/Internal Parameters'
//  '<S141>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/External Derivative/Error'
//  '<S142>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter/Disc. Forward Euler Filter'
//  '<S143>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Filter ICs/Internal IC - Filter'
//  '<S144>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/I Gain/Internal Parameters'
//  '<S145>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain/Passthrough'
//  '<S146>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Ideal P Gain Fdbk/Disabled'
//  '<S147>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator/Discrete'
//  '<S148>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Integrator ICs/Internal IC'
//  '<S149>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Copy/Disabled'
//  '<S150>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/N Gain/Internal Parameters'
//  '<S151>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/P Copy/Disabled'
//  '<S152>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Parallel P Gain/Internal Parameters'
//  '<S153>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Reset Signal/Disabled'
//  '<S154>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation/Passthrough'
//  '<S155>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Saturation Fdbk/Disabled'
//  '<S156>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum/Sum_PID'
//  '<S157>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Sum Fdbk/Disabled'
//  '<S158>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode/Disabled'
//  '<S159>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tracking Mode Sum/Passthrough'
//  '<S160>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S161>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/Tsamp - Ngain/Passthrough'
//  '<S162>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/postSat Signal/Forward_Path'
//  '<S163>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preInt Signal/Internal PreInt'
//  '<S164>' : 'Flight_Controllers_PIL/Lateral_Controllers/Lateral_Control_14/Pitch_ Controller/preSat Signal/Forward_Path'

#endif                                 // Flight_Controllers_PIL_h_

//
// File trailer for generated code.
//
// [EOF]
//
