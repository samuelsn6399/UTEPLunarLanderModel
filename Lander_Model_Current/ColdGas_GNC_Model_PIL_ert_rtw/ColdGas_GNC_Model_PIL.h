//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ColdGas_GNC_Model_PIL.h
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
#ifndef ColdGas_GNC_Model_PIL_h_
#define ColdGas_GNC_Model_PIL_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ColdGas_GNC_Model_PIL_types.h"
#include "Flight_Controllers_PIL.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rtGetNaN.h"
#include "model_reference_types.h"
#include <math.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_ColdGas_GNC_Model_PIL_T {
  States StatesBusCreator;             // '<S3>/StatesBusCreator'
  real_T Cntrl_telem[10];              // '<Root>/FCS'
  real_T rtb_TransportDelay_m[3];
  real_T m;                            // '<Root>/Sum1'
  real_T AirDensitykgm3;               // '<S8>/Air Density (kg//m^3)'
  real_T TrigonometricFunction1;       // '<S12>/Trigonometric Function1'
  real_T TrigonometricFunction;        // '<S12>/Trigonometric Function'
  real_T Sum;                          // '<Root>/Sum'
  real_T Switch;                       // '<S5>/Switch'
  real_T RefLengthm;                   // '<S1>/Ref. Length (m)'
  real_T Cm;                           // '<S10>/Cm Lookup Table (n-D)'
  real_T Sum2;                         // '<Root>/Sum2'
  real_T Fire_Cmd;                     // '<Root>/FCS'
  real_T M1;                           // '<Root>/FCS'
  real_T M2;                           // '<Root>/FCS'
  real_T M3;                           // '<Root>/FCS'
  real_T M4;                           // '<Root>/FCS'
  real_T Product[3];                   // '<S13>/Product'
  real_T one_over_tau[3];              // '<S13>/one_over_tau'
  real_T one_over_tau_e;               // '<S9>/one_over_tau'
  real_T g_Earth;                      // '<S13>/g_Earth'
  real_T mDot;                         // '<S13>/Divide'
  real_T Omega1;                       // '<S16>/Motor_TF1'
  real_T wind_speed_gust;              // '<S1>/MATLAB Function'
  real_T rtb_Clock1_tmp;
  real_T rtb_CE_Thrust_xyz_idx_2;
  real_T rtb_CE_Thrust_xyz_idx_1;
  real_T rtb_CE_Thrust_xyz_idx_0;
  real_T rtb_Sum_idx_2;
  real_T rtb_Sum_idx_1;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_l_idx_2;
  real_T rtb_Sum_l_idx_1;
  real_T rtb_Sum_l_idx_0;
  real_T rtb_Sum_b_idx_2;
  real_T rtb_Sum_b_idx_1;
  real_T rtb_Sum_b_idx_0;
  real_T rtb_Sum_i_idx_1;
  real_T rtb_Sum_i_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Add_idx_0;
  real_T rtb_Omega1_tmp;
  real_T M4_c;                         // '<Root>/FCS'
  real_T M3_k;                         // '<Root>/FCS'
  real_T M2_c;                         // '<Root>/FCS'
  real_T M1_b;                         // '<Root>/FCS'
  real_T yCmd;                         // '<Root>/FCS'
  real_T fire_Cmd;                     // '<Root>/FCS'
  real_T xCmd;                         // '<Root>/FCS'
  real_T vertCntrlMode;                // '<Root>/FCS'
  real_T q;
  int32_T i;
};

// Block states (default storage) for system '<Root>'
struct DW_ColdGas_GNC_Model_PIL_T {
  struct {
    real_T modelTStart;
    real_T TUbufferArea[6144];
  } TransportDelay_RWORK;              // '<S13>/Transport Delay'

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK;              // '<S13>/Transport Delay'

  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK;              // '<S13>/Transport Delay'

  MdlrefDW_Flight_Controllers_P_T FCS_InstanceData;// '<Root>/FCS'
};

// Continuous states (default storage)
struct X_ColdGas_GNC_Model_PIL_T {
  real_T Int_mDot_CSTATE;              // '<S13>/Int_mDot'
  real_T Int_Descent_CSTATE[3];        // '<S13>/Int_Descent'
  real_T Motor_TF1_CSTATE[2];          // '<S16>/Motor_TF1'
  real_T Motor_TF2_CSTATE[2];          // '<S16>/Motor_TF2'
  real_T Motor_TF3_CSTATE[2];          // '<S16>/Motor_TF3'
  real_T Motor_TF4_CSTATE[2];          // '<S16>/Motor_TF4'
  real_T Int_LP_CSTATE;                // '<S9>/Int_LP'
  real_T CustomVariableMass3dofBodyAxes_[6];
                              // '<Root>/Custom Variable Mass 3dof (Body Axes)'
};

// Periodic continuous state vector (global)
typedef int_T PeriodicIndX_ColdGas_GNC_Mode_T[1];
typedef real_T PeriodicRngX_ColdGas_GNC_Mode_T[2];

// State derivatives (default storage)
struct XDot_ColdGas_GNC_Model_PIL_T {
  real_T Int_mDot_CSTATE;              // '<S13>/Int_mDot'
  real_T Int_Descent_CSTATE[3];        // '<S13>/Int_Descent'
  real_T Motor_TF1_CSTATE[2];          // '<S16>/Motor_TF1'
  real_T Motor_TF2_CSTATE[2];          // '<S16>/Motor_TF2'
  real_T Motor_TF3_CSTATE[2];          // '<S16>/Motor_TF3'
  real_T Motor_TF4_CSTATE[2];          // '<S16>/Motor_TF4'
  real_T Int_LP_CSTATE;                // '<S9>/Int_LP'
  real_T CustomVariableMass3dofBodyAxes_[6];
                              // '<Root>/Custom Variable Mass 3dof (Body Axes)'
};

// State disabled
struct XDis_ColdGas_GNC_Model_PIL_T {
  boolean_T Int_mDot_CSTATE;           // '<S13>/Int_mDot'
  boolean_T Int_Descent_CSTATE[3];     // '<S13>/Int_Descent'
  boolean_T Motor_TF1_CSTATE[2];       // '<S16>/Motor_TF1'
  boolean_T Motor_TF2_CSTATE[2];       // '<S16>/Motor_TF2'
  boolean_T Motor_TF3_CSTATE[2];       // '<S16>/Motor_TF3'
  boolean_T Motor_TF4_CSTATE[2];       // '<S16>/Motor_TF4'
  boolean_T Int_LP_CSTATE;             // '<S9>/Int_LP'
  boolean_T CustomVariableMass3dofBodyAxes_[6];
                              // '<Root>/Custom Variable Mass 3dof (Body Axes)'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_ColdGas_GNC_Model_PIL_T_ {
  real_T Int_mDot_IC;                  // Expression: 0
                                          //  Referenced by: '<S13>/Int_mDot'

  real_T Int_Descent_IC;               // Expression: 0
                                          //  Referenced by: '<S13>/Int_Descent'

  real_T Unit_Vector_1_Value[3];       // Expression: uvFans(1,:)
                                          //  Referenced by: '<S17>/Unit_Vector_1'

  real_T Unit_Vector_2_Value[3];       // Expression: uvFans(2,:)
                                          //  Referenced by: '<S17>/Unit_Vector_2'

  real_T Unit_Vector_3_Value[3];       // Expression: uvFans(3,:)
                                          //  Referenced by: '<S17>/Unit_Vector_3'

  real_T Unit_Vector_4_Value[3];       // Expression: uvFans(4,:)
                                          //  Referenced by: '<S17>/Unit_Vector_4'

  real_T Const_Value;                  // Expression: 0.5
                                          //  Referenced by: '<S8>/Const'

  real_T Int_LP_IC;                    // Expression: 0
                                          //  Referenced by: '<S9>/Int_LP'

  real_T Z_Wind_Value;                 // Expression: 0
                                          //  Referenced by: '<S12>/Z_Wind'

  real_T rFan1_Value[3];               // Expression: rFans(1,:)
                                          //  Referenced by: '<S17>/rFan1'

  real_T rFan2_Value[3];               // Expression: rFans(2,:)
                                          //  Referenced by: '<S17>/rFan2'

  real_T rFan3_Value[3];               // Expression: rFans(3,:)
                                          //  Referenced by: '<S17>/rFan3'

  real_T rFan4_Value[3];               // Expression: rFans(4,:)
                                          //  Referenced by: '<S17>/rFan4'

  real_T CmLookupTablenD_tableData[73];// Expression: Cm_Lookup(:,2)
                                          //  Referenced by: '<S10>/Cm Lookup Table (n-D)'

  real_T CmLookupTablenD_bp01Data[73]; // Expression: Cm_Lookup(:,1)
                                          //  Referenced by: '<S10>/Cm Lookup Table (n-D)'

  real_T dI_Value;                     // Expression: 0
                                          //  Referenced by: '<Root>/dI'

  real_T Iyy_Value;                    // Expression: I(2, 2)
                                          //  Referenced by: '<Root>/Iyy'

  real_T CustomVariableMass3dofBodyAxes_;// Expression: 0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_n;// Expression: 0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_a;// Expression: 0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_o[2];// Expression: [x0 z0]
                                               //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAx_og;// Expression: 1.0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_l;// Expression: 0.5
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAx_ad;// Expression: 3.0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_m;// Expression: 1.0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAx_af;// Expression: 0.5
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAxe_h;// Expression: 3.0
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T CustomVariableMass3dofBodyAx_hl;// Expression: 9.81
                                            //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  real_T Const_Value_d;                // Expression: 0
                                          //  Referenced by: '<S3>/Const'

  real_T Const1_Value;                 // Expression: 0
                                          //  Referenced by: '<S3>/Const1'

  real_T Const3_Value;                 // Expression: 0
                                          //  Referenced by: '<S3>/Const3'

  real_T Const4_Value;                 // Expression: 0
                                          //  Referenced by: '<S3>/Const4'

  real_T Const2_Value;                 // Expression: 0
                                          //  Referenced by: '<S3>/Const2'

  real_T TransportDelay_InitOutput;    // Expression: 0
                                          //  Referenced by: '<S13>/Transport Delay'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S7>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_ColdGas_GNC_Model_PIL_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ColdGas_GNC_Model_PIL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ColdGas_GNC_Model_PIL_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[19];
  real_T odeF[3][19];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_X;

// Disabled states (default storage)
extern XDis_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_XDis;

// Block states (default storage)
extern struct DW_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_DW;

// Model block global parameters (default storage)
extern real_T rtP_Aero_Forces_On;      // Variable: Aero_Forces_On
                                          //  Referenced by:
                                          //    '<Root>/Aero_OnOff2'
                                          //    '<Root>/Aero_OnOff3'

extern real_T rtP_CE_Direction[3];     // Variable: CE_Direction
                                          //  Referenced by: '<S13>/CE_Orientation'

extern real_T rtP_CE_ISP;              // Variable: CE_ISP
                                          //  Referenced by: '<S13>/ISP'

extern real_T rtP_CE_Location[3];      // Variable: CE_Location
                                          //  Referenced by: '<S13>/CE_Loc_Vector'

extern real_T rtP_CE_Thrust;           // Variable: CE_Thrust
                                          //  Referenced by: '<S13>/CE_Rated_Thrust'

extern real_T rtP_CE_tDelay;           // Variable: CE_tDelay
                                          //  Referenced by: '<S13>/Transport Delay'

extern real_T rtP_CE_tau;              // Variable: CE_tau
                                          //  Referenced by: '<S13>/one_over_tau'

extern real_T rtP_Cant_cosine_Loss;    // Variable: Cant_cosine_Loss
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Cd;                  // Variable: Cd
                                          //  Referenced by: '<S1>/Drag_Coeff'

extern real_T rtP_Fan_den[3];          // Variable: Fan_den
                                          //  Referenced by:
                                          //    '<S16>/Motor_TF1'
                                          //    '<S16>/Motor_TF2'
                                          //    '<S16>/Motor_TF3'
                                          //    '<S16>/Motor_TF4'

extern real_T rtP_Fan_num;             // Variable: Fan_num
                                          //  Referenced by:
                                          //    '<S16>/Motor_TF1'
                                          //    '<S16>/Motor_TF2'
                                          //    '<S16>/Motor_TF3'
                                          //    '<S16>/Motor_TF4'

extern real_T rtP_FlightPlan_Lateral[40];// Variable: FlightPlan_Lateral
                                            //  Referenced by: '<Root>/Constant'

extern real_T rtP_FlightPlan_Vertical[30];// Variable: FlightPlan_Vertical
                                             //  Referenced by: '<Root>/Vertical_FlightPlan'

extern real_T rtP_Kd_LatPos;           // Variable: Kd_LatPos
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Kd_LatVel;           // Variable: Kd_LatVel
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Kd_Pitch;            // Variable: Kd_Pitch
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Ki_LatPos;           // Variable: Ki_LatPos
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Ki_LatVel;           // Variable: Ki_LatVel
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Ki_Pitch;            // Variable: Ki_Pitch
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Kp_LatPos;           // Variable: Kp_LatPos
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Kp_LatVel;           // Variable: Kp_LatVel
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Kp_Pitch;            // Variable: Kp_Pitch
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Lref;                // Variable: Lref
                                          //  Referenced by: '<S1>/Ref. Length (m)'

extern real_T rtP_N_LatPos;            // Variable: N_LatPos
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_N_LatVel;            // Variable: N_LatVel
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_N_Pitch;             // Variable: N_Pitch
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_Psi_Angle_deg;       // Variable: Psi_Angle_deg
                                          //  Referenced by: '<Root>/Yaw_deg1'

extern real_T rtP_Sref;                // Variable: Sref
                                          //  Referenced by: '<S1>/Reference Area'

extern real_T rtP_bOmega;              // Variable: bOmega
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_fan_thrust_Poly[3];  // Variable: fan_thrust_Poly
                                          //  Referenced by:
                                          //    '<S16>/Fan_Thrust_Polynomial1'
                                          //    '<S16>/Fan_Thrust_Polynomial2'
                                          //    '<S16>/Fan_Thrust_Polynomial3'
                                          //    '<S16>/Fan_Thrust_Polynomial4'

extern real_T rtP_g;                   // Variable: g
                                          //  Referenced by:
                                          //    '<Root>/FCS'
                                          //    '<S5>/g_neg'
                                          //    '<S5>/g_negated'
                                          //    '<S13>/g_Earth'

extern real_T rtP_g_Offset;            // Variable: g_Offset
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_gustDuration;        // Variable: gustDuration
                                          //  Referenced by: '<S1>/Constant5'

extern real_T rtP_gustFactor;          // Variable: gustFactor
                                          //  Referenced by: '<S1>/Constant4'

extern real_T rtP_hFinal;              // Variable: hFinal
                                          //  Referenced by: '<S7>/Stop_Altitude'

extern real_T rtP_mOmega;              // Variable: mOmega
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_massInitial;         // Variable: massInitial
                                          //  Referenced by: '<Root>/Initial_mass'

extern real_T rtP_nFans;               // Variable: nFans
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_q0;                  // Variable: q0
                                          //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

extern real_T rtP_rho_air;             // Variable: rho_air
                                          //  Referenced by: '<S8>/Air Density (kg//m^3)'

extern real_T rtP_switchLines[16];     // Variable: switchLines
                                          //  Referenced by: '<Root>/SwitchLines'

extern real_T rtP_tGust_End;           // Variable: tGust_End
                                          //  Referenced by: '<S1>/Constant3'

extern real_T rtP_tGust_Start;         // Variable: tGust_Start
                                          //  Referenced by: '<S1>/Constant2'

extern real_T rtP_t_Liftoff_Achieved;  // Variable: t_Liftoff_Achieved
                                          //  Referenced by: '<S5>/Constant'

extern real_T rtP_tau_AlgLoop;         // Variable: tau_AlgLoop
                                          //  Referenced by: '<S9>/one_over_tau'

extern real_T rtP_tau_vCmd;            // Variable: tau_vCmd
                                          //  Referenced by: '<Root>/FCS'

extern real_T rtP_theta0;              // Variable: theta0
                                          //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

extern real_T rtP_windSpeed;           // Variable: windSpeed
                                          //  Referenced by: '<Root>/windSP_mPerSec'

extern real_T rtP_wind_angle;          // Variable: wind_angle
                                          //  Referenced by: '<Root>/Wind_Angle_rad1'

extern boolean_T rtP_LandNowFlag;      // Variable: LandNowFlag
                                          //  Referenced by: '<Root>/Emergency'


#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void ColdGas_GNC_Model_PIL_initialize(void);
  extern void ColdGas_GNC_Model_PIL_step(void);
  extern void ColdGas_GNC_Model_PIL_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_ColdGas_GNC_Model_PI_T *const ColdGas_GNC_Model_PIL_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S8>/Sqrt' : Unused code path elimination
//  Block '<S8>/wind_Speed' : Unused code path elimination
//  Block '<S10>/Display' : Unused code path elimination
//  Block '<S1>/windVec' : Unused code path elimination
//  Block '<Root>/CG1' : Unused code path elimination
//  Block '<S16>/N2kg' : Unused code path elimination
//  Block '<S16>/Sum4' : Unused code path elimination
//  Block '<Root>/misc_data' : Unused code path elimination


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
//  '<Root>' : 'ColdGas_GNC_Model_PIL'
//  '<S1>'   : 'ColdGas_GNC_Model_PIL/Aero Model'
//  '<S2>'   : 'ColdGas_GNC_Model_PIL/Body_to_Inertial'
//  '<S3>'   : 'ColdGas_GNC_Model_PIL/Construct_Bus'
//  '<S4>'   : 'ColdGas_GNC_Model_PIL/Data_Logging'
//  '<S5>'   : 'ColdGas_GNC_Model_PIL/Liftoff'
//  '<S6>'   : 'ColdGas_GNC_Model_PIL/Propulsion'
//  '<S7>'   : 'ColdGas_GNC_Model_PIL/Touchdown'
//  '<S8>'   : 'ColdGas_GNC_Model_PIL/Aero Model/Calculate q'
//  '<S9>'   : 'ColdGas_GNC_Model_PIL/Aero Model/LP_Filter'
//  '<S10>'  : 'ColdGas_GNC_Model_PIL/Aero Model/Lookup Aero Coeffs'
//  '<S11>'  : 'ColdGas_GNC_Model_PIL/Aero Model/MATLAB Function'
//  '<S12>'  : 'ColdGas_GNC_Model_PIL/Aero Model/Relative Wind Calculation'
//  '<S13>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Center_Engine'
//  '<S14>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans'
//  '<S15>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Center_Engine/Cross Product'
//  '<S16>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Determine_Motor_Speeds'
//  '<S17>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Moments'
//  '<S18>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Moments/rXF'
//  '<S19>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Moments/rXF1'
//  '<S20>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Moments/rXF2'
//  '<S21>'  : 'ColdGas_GNC_Model_PIL/Propulsion/Electric_Fans/Moments/rXF3'

#endif                                 // ColdGas_GNC_Model_PIL_h_

//
// File trailer for generated code.
//
// [EOF]
//
