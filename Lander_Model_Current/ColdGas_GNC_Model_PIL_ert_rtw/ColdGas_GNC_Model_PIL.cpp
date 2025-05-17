//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ColdGas_GNC_Model_PIL.cpp
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
#include "ColdGas_GNC_Model_PIL.h"
#include "rtwtypes.h"
#include <math.h>
#include "ColdGas_GNC_Model_PIL_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <float.h>
#include "rt_TDelayInterpolate.h"
#include "look1_binlxpw.h"
#include "Flight_Controllers_PIL.h"

rtTimingBridge ColdGas_GNC_Model_PI_TimingBrdg;

// Block signals (default storage)
B_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_B;

// Continuous states
X_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_X;

// Disabled State Vector
XDis_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_XDis;

// Block states (default storage)
DW_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_DW;

// Periodic continuous states
PeriodicIndX_ColdGas_GNC_Mode_T ColdGas_GNC_Model__PeriodicIndX;
PeriodicRngX_ColdGas_GNC_Mode_T ColdGas_GNC_Model__PeriodicRngX;

// Real-time model
RT_MODEL_ColdGas_GNC_Model_PI_T ColdGas_GNC_Model_PIL_M_ =
  RT_MODEL_ColdGas_GNC_Model_PI_T();
RT_MODEL_ColdGas_GNC_Model_PI_T *const ColdGas_GNC_Model_PIL_M =
  &ColdGas_GNC_Model_PIL_M_;

// Forward declaration for local functions
static real_T ColdGas_GNC_Model_P_rt_remd_snf(real_T u0, real_T u1);

// State reduction function
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 19;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  ColdGas_GNC_Model_PIL_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ColdGas_GNC_Model_PIL_step();
  ColdGas_GNC_Model_PIL_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ColdGas_GNC_Model_PIL_step();
  ColdGas_GNC_Model_PIL_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static real_T ColdGas_GNC_Model_P_rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      ColdGas_GNC_Model_PIL_B.q = ceil(u1);
    } else {
      ColdGas_GNC_Model_PIL_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != ColdGas_GNC_Model_PIL_B.q)) {
      ColdGas_GNC_Model_PIL_B.q = fabs(u0 / u1);
      if (!(fabs(ColdGas_GNC_Model_PIL_B.q - floor(ColdGas_GNC_Model_PIL_B.q +
             0.5)) > DBL_EPSILON * ColdGas_GNC_Model_PIL_B.q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Model step function
void ColdGas_GNC_Model_PIL_step(void)
{
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&ColdGas_GNC_Model_PIL_M->solverInfo,
                          ((ColdGas_GNC_Model_PIL_M->Timing.clockTick0+1)*
      ColdGas_GNC_Model_PIL_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    ColdGas_GNC_Model_PIL_M->Timing.t[0] = rtsiGetT
      (&ColdGas_GNC_Model_PIL_M->solverInfo);
  }

  // Sum: '<Root>/Sum1' incorporates:
  //   Constant: '<Root>/Initial_mass'
  //   Integrator: '<S13>/Int_mDot'

  ColdGas_GNC_Model_PIL_B.m = rtP_massInitial -
    ColdGas_GNC_Model_PIL_X.Int_mDot_CSTATE;

  // Integrator: '<S13>/Int_Descent'
  ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_0 =
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[0];
  ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_1 =
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[1];
  ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_2 =
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[2];

  // TransferFcn: '<S16>/Motor_TF1' incorporates:
  //   TransferFcn: '<S16>/Motor_TF2'
  //   TransferFcn: '<S16>/Motor_TF3'
  //   TransferFcn: '<S16>/Motor_TF4'

  ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp = rtP_Fan_num / rtP_Fan_den[0];
  ColdGas_GNC_Model_PIL_B.Omega1 = ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[1] + 0.0 *
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[0];

  // Polyval: '<S16>/Fan_Thrust_Polynomial1'
  ColdGas_GNC_Model_PIL_B.Omega1 = (rtP_fan_thrust_Poly[0] *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[1]) *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[2];

  // Product: '<S17>/Product' incorporates:
  //   Constant: '<S17>/Unit_Vector_1'

  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_1_Value[0] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_1_Value[1] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_1_Value[2] *
    ColdGas_GNC_Model_PIL_B.Omega1;

  // TransferFcn: '<S16>/Motor_TF2'
  ColdGas_GNC_Model_PIL_B.Omega1 = ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[1] + 0.0 *
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[0];

  // Polyval: '<S16>/Fan_Thrust_Polynomial2'
  ColdGas_GNC_Model_PIL_B.Omega1 = (rtP_fan_thrust_Poly[0] *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[1]) *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[2];

  // Product: '<S17>/Product1' incorporates:
  //   Constant: '<S17>/Unit_Vector_2'

  ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_2_Value[0] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_2_Value[1] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_2 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_2_Value[2] *
    ColdGas_GNC_Model_PIL_B.Omega1;

  // TransferFcn: '<S16>/Motor_TF3'
  ColdGas_GNC_Model_PIL_B.Omega1 = ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[1] + 0.0 *
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[0];

  // Polyval: '<S16>/Fan_Thrust_Polynomial3'
  ColdGas_GNC_Model_PIL_B.Omega1 = (rtP_fan_thrust_Poly[0] *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[1]) *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[2];

  // Product: '<S17>/Product2' incorporates:
  //   Constant: '<S17>/Unit_Vector_3'

  ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_0 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_3_Value[0] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_1 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_3_Value[1] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_2 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_3_Value[2] *
    ColdGas_GNC_Model_PIL_B.Omega1;

  // TransferFcn: '<S16>/Motor_TF4'
  ColdGas_GNC_Model_PIL_B.Omega1 = ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[1] + 0.0 *
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[0];

  // Polyval: '<S16>/Fan_Thrust_Polynomial4'
  ColdGas_GNC_Model_PIL_B.Omega1 = (rtP_fan_thrust_Poly[0] *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[1]) *
    ColdGas_GNC_Model_PIL_B.Omega1 + rtP_fan_thrust_Poly[2];

  // Product: '<S17>/Product3' incorporates:
  //   Constant: '<S17>/Unit_Vector_4'

  ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_4_Value[0] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_0 =
    ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp;

  // TransportDelay: '<S13>/Transport Delay' incorporates:
  //   Integrator: '<S13>/Int_Descent'
  //   Sum: '<S17>/Sum1'
  //   Sum: '<S6>/Sum1'

  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[0] =
    (((ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 +
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0) +
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_0) +
     ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp) +
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[0];

  // Product: '<S17>/Product3' incorporates:
  //   Constant: '<S17>/Unit_Vector_4'

  ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_1 =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_4_Value[1] *
    ColdGas_GNC_Model_PIL_B.Omega1;
  ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp =
    ColdGas_GNC_Model_PIL_P.Unit_Vector_4_Value[2] *
    ColdGas_GNC_Model_PIL_B.Omega1;

  // TransportDelay: '<S13>/Transport Delay' incorporates:
  //   Integrator: '<S13>/Int_Descent'
  //   Sum: '<S17>/Sum1'
  //   Sum: '<S6>/Sum1'

  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2] =
    (((ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 +
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_2) +
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_2) +
     ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp) +
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[2];
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // Gain: '<S8>/Air Density (kg//m^3)' incorporates:
    //   Constant: '<S8>/Const'

    ColdGas_GNC_Model_PIL_B.AirDensitykgm3 = rtP_rho_air *
      ColdGas_GNC_Model_PIL_P.Const_Value;
  }

  // Integrator: '<S9>/Int_LP'
  ColdGas_GNC_Model_PIL_B.Omega1 = ColdGas_GNC_Model_PIL_X.Int_LP_CSTATE;

  // Clock: '<S1>/Clock1' incorporates:
  //   Clock: '<S5>/Clock'

  ColdGas_GNC_Model_PIL_B.rtb_Clock1_tmp = ColdGas_GNC_Model_PIL_M->Timing.t[0];

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   Clock: '<S1>/Clock1'
  //   Constant: '<Root>/windSP_mPerSec'
  //   Constant: '<S1>/Constant2'
  //   Constant: '<S1>/Constant3'
  //   Constant: '<S1>/Constant4'
  //   Constant: '<S1>/Constant5'

  if ((ColdGas_GNC_Model_PIL_B.rtb_Clock1_tmp >= rtP_tGust_Start) &&
      (ColdGas_GNC_Model_PIL_B.rtb_Clock1_tmp <= rtP_tGust_End)) {
    ColdGas_GNC_Model_PIL_B.wind_speed_gust = (1.0 - cos
      ((ColdGas_GNC_Model_PIL_B.rtb_Clock1_tmp - rtP_tGust_Start) *
       6.2831853071795862 / rtP_gustDuration)) * ((rtP_gustFactor - 1.0) *
      rtP_windSpeed * 0.5) + rtP_windSpeed;
  } else {
    ColdGas_GNC_Model_PIL_B.wind_speed_gust = rtP_windSpeed;
  }

  // End of MATLAB Function: '<S1>/MATLAB Function'
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // Trigonometry: '<S12>/Trigonometric Function1' incorporates:
    //   Constant: '<Root>/Wind_Angle_rad1'

    ColdGas_GNC_Model_PIL_B.TrigonometricFunction1 = cos(rtP_wind_angle);

    // Trigonometry: '<S12>/Trigonometric Function' incorporates:
    //   Constant: '<Root>/Wind_Angle_rad1'

    ColdGas_GNC_Model_PIL_B.TrigonometricFunction = sin(rtP_wind_angle);
  }

  // Sum: '<S12>/Add' incorporates:
  //   Constant: '<S12>/Z_Wind'
  //   Integrator: '<S9>/Int_LP'
  //   Product: '<S12>/Product'

  ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 =
    ColdGas_GNC_Model_PIL_B.wind_speed_gust *
    ColdGas_GNC_Model_PIL_B.TrigonometricFunction1 +
    ColdGas_GNC_Model_PIL_X.Int_LP_CSTATE;
  ColdGas_GNC_Model_PIL_B.rtb_Add_idx_1 =
    ColdGas_GNC_Model_PIL_B.wind_speed_gust *
    ColdGas_GNC_Model_PIL_B.TrigonometricFunction +
    ColdGas_GNC_Model_PIL_X.Int_LP_CSTATE;
  ColdGas_GNC_Model_PIL_B.wind_speed_gust =
    ColdGas_GNC_Model_PIL_B.wind_speed_gust *
    ColdGas_GNC_Model_PIL_P.Z_Wind_Value + ColdGas_GNC_Model_PIL_X.Int_LP_CSTATE;

  // Product: '<S8>/Product' incorporates:
  //   DotProduct: '<S8>/Dot Product'

  ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 =
    ((ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 *
      ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 +
      ColdGas_GNC_Model_PIL_B.rtb_Add_idx_1 *
      ColdGas_GNC_Model_PIL_B.rtb_Add_idx_1) +
     ColdGas_GNC_Model_PIL_B.wind_speed_gust *
     ColdGas_GNC_Model_PIL_B.wind_speed_gust) *
    ColdGas_GNC_Model_PIL_B.AirDensitykgm3;

  // Sum: '<Root>/Sum' incorporates:
  //   Constant: '<S1>/Drag_Coeff'
  //   Constant: '<S1>/Reference Area'
  //   Gain: '<Root>/Aero_OnOff3'
  //   Product: '<S1>/Prod_F'

  ColdGas_GNC_Model_PIL_B.Sum = rtP_Cd * rtP_Sref *
    ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 * rtP_Aero_Forces_On +
    ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[0];

  // Product: '<S5>/Product1' incorporates:
  //   Constant: '<S5>/g_negated'
  //   Product: '<S5>/Product'
  //   Switch: '<S5>/Switch'

  ColdGas_GNC_Model_PIL_B.Switch = ColdGas_GNC_Model_PIL_B.m * -rtP_g;

  // Switch: '<S5>/Switch' incorporates:
  //   Constant: '<S5>/Constant'
  //   Logic: '<S5>/Logical Operator'
  //   Product: '<S5>/Product1'
  //   RelationalOperator: '<S5>/Relational Operator1'
  //   RelationalOperator: '<S5>/Relational Operator2'

  if ((!(ColdGas_GNC_Model_PIL_B.rtb_Clock1_tmp <= rtP_t_Liftoff_Achieved)) || (
       !(ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2] >=
         ColdGas_GNC_Model_PIL_B.Switch))) {
    // Switch: '<S5>/Switch'
    ColdGas_GNC_Model_PIL_B.Switch =
      ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2];
  }

  // TransportDelay: '<S13>/Transport Delay' incorporates:
  //   Constant: '<S13>/CE_Loc_Vector'
  //   Constant: '<S17>/rFan1'
  //   Constant: '<S17>/rFan2'
  //   Constant: '<S17>/rFan3'
  //   Constant: '<S17>/rFan4'
  //   Integrator: '<S13>/Int_Descent'
  //   Product: '<S15>/Element Product'
  //   Product: '<S17>/Product3'
  //   Product: '<S18>/Element Product'
  //   Product: '<S19>/Element Product'
  //   Product: '<S20>/Element Product'
  //   Product: '<S21>/Element Product'
  //   Sum: '<S15>/Sum'
  //   Sum: '<S17>/Sum4'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S19>/Sum'
  //   Sum: '<S20>/Sum'
  //   Sum: '<S21>/Sum'
  //   Sum: '<S6>/Sum'

  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[0] = rtP_CE_Location[1] *
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[2] -
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[1] * rtP_CE_Location[2];
  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[1] =
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[0] * rtP_CE_Location[2] -
    rtP_CE_Location[0] * ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[2];
  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2] = rtP_CE_Location[0] *
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[1] -
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[0] * rtP_CE_Location[1];
  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[0] +=
    (((ColdGas_GNC_Model_PIL_P.rFan1_Value[1] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 -
       ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 *
       ColdGas_GNC_Model_PIL_P.rFan1_Value[2]) +
      (ColdGas_GNC_Model_PIL_P.rFan2_Value[1] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_2 -
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1 *
       ColdGas_GNC_Model_PIL_P.rFan2_Value[2])) +
     (ColdGas_GNC_Model_PIL_P.rFan3_Value[1] *
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_2 -
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_1 *
      ColdGas_GNC_Model_PIL_P.rFan3_Value[2])) +
    (ColdGas_GNC_Model_PIL_P.rFan4_Value[1] *
     ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp -
     ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_1 *
     ColdGas_GNC_Model_PIL_P.rFan4_Value[2]);
  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[1] +=
    (((ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 *
       ColdGas_GNC_Model_PIL_P.rFan1_Value[2] -
       ColdGas_GNC_Model_PIL_P.rFan1_Value[0] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2) +
      (ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0 *
       ColdGas_GNC_Model_PIL_P.rFan2_Value[2] -
       ColdGas_GNC_Model_PIL_P.rFan2_Value[0] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_2)) +
     (ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_0 *
      ColdGas_GNC_Model_PIL_P.rFan3_Value[2] -
      ColdGas_GNC_Model_PIL_P.rFan3_Value[0] *
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_2)) +
    (ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_0 *
     ColdGas_GNC_Model_PIL_P.rFan4_Value[2] -
     ColdGas_GNC_Model_PIL_P.rFan4_Value[0] *
     ColdGas_GNC_Model_PIL_B.rtb_Omega1_tmp);
  ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2] +=
    (((ColdGas_GNC_Model_PIL_P.rFan1_Value[0] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 -
       ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 *
       ColdGas_GNC_Model_PIL_P.rFan1_Value[1]) +
      (ColdGas_GNC_Model_PIL_P.rFan2_Value[0] *
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1 -
       ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0 *
       ColdGas_GNC_Model_PIL_P.rFan2_Value[1])) +
     (ColdGas_GNC_Model_PIL_P.rFan3_Value[0] *
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_1 -
      ColdGas_GNC_Model_PIL_B.rtb_Sum_b_idx_0 *
      ColdGas_GNC_Model_PIL_P.rFan3_Value[1])) +
    (ColdGas_GNC_Model_PIL_P.rFan4_Value[0] *
     ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_1 -
     ColdGas_GNC_Model_PIL_B.rtb_Sum_i_idx_0 *
     ColdGas_GNC_Model_PIL_P.rFan4_Value[1]);
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // Gain: '<S1>/Ref. Length (m)' incorporates:
    //   Constant: '<S1>/Reference Area'

    ColdGas_GNC_Model_PIL_B.RefLengthm = rtP_Lref * rtP_Sref;

    // Lookup_n-D: '<S10>/Cm Lookup Table (n-D)' incorporates:
    //   Constant: '<Root>/Yaw_deg1'

    ColdGas_GNC_Model_PIL_B.Cm = look1_binlxpw(rtP_Psi_Angle_deg,
      ColdGas_GNC_Model_PIL_P.CmLookupTablenD_bp01Data,
      ColdGas_GNC_Model_PIL_P.CmLookupTablenD_tableData, 72U);
  }

  // Sum: '<Root>/Sum2' incorporates:
  //   Gain: '<Root>/Aero_OnOff2'
  //   Product: '<S1>/Prod_M'

  ColdGas_GNC_Model_PIL_B.Sum2 = ColdGas_GNC_Model_PIL_B.RefLengthm *
    ColdGas_GNC_Model_PIL_B.Cm * ColdGas_GNC_Model_PIL_B.rtb_Add_idx_0 *
    rtP_Aero_Forces_On + ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[1];

  // EOM3DOF: '<Root>/Custom Variable Mass 3dof (Body Axes)' incorporates:
  //   Constant: '<Root>/Iyy'
  //   Constant: '<Root>/dI'
  //   Fcn: '<S2>/Fcn'
  //   Fcn: '<S2>/Fcn1'

  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5];
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 =
    ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAx_hl;
  if (fabs(ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5]) >
      3.1415926535897931) {
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 = ColdGas_GNC_Model_P_rt_remd_snf
      (ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5],
       6.2831853071795862);
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 =
      ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 / 3.1415926535897931;
    if (ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 < 0.0) {
      ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 = ceil
        (ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1);
    } else {
      ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 = floor
        (ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1);
    }

    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2 -= 6.2831853071795862 *
      ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;
    if (rtsiIsModeUpdateTimeStep(&ColdGas_GNC_Model_PIL_M->solverInfo)) {
      ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5] =
        ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2;
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&ColdGas_GNC_Model_PIL_M->solverInfo, true);
    }
  }

  ColdGas_GNC_Model_PIL_B.StatesBusCreator.dq = (ColdGas_GNC_Model_PIL_B.Sum2 -
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4] *
    ColdGas_GNC_Model_PIL_P.dI_Value) / ColdGas_GNC_Model_PIL_P.Iyy_Value;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 = sin
    (ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2);
  ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0 = ColdGas_GNC_Model_PIL_B.Sum /
    ColdGas_GNC_Model_PIL_B.m - ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;
  ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1 = cos
    (ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2);
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 = ColdGas_GNC_Model_PIL_B.Switch /
    ColdGas_GNC_Model_PIL_B.m + ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1;

  // Fcn: '<S2>/Fcn' incorporates:
  //   EOM3DOF: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VxE =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1 +
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;

  // BusCreator: '<S3>/StatesBusCreator' incorporates:
  //   Constant: '<S3>/Const'
  //   Constant: '<S3>/Const1'
  //   Constant: '<S3>/Const2'
  //   Constant: '<S3>/Const3'
  //   Constant: '<S3>/Const4'
  //   EOM3DOF: '<Root>/Custom Variable Mass 3dof (Body Axes)'
  //   Fcn: '<S2>/Fcn1'

  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Theta =
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_2;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.q =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.x =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[2];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.y =
    ColdGas_GNC_Model_PIL_P.Const_Value_d;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.z =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[3];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VxB =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VyB =
    ColdGas_GNC_Model_PIL_P.Const1_Value;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VzB =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Axb =
    ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0 -
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] *
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4];
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Ayb =
    ColdGas_GNC_Model_PIL_P.Const3_Value;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Azb =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] *
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4] +
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Axe =
    ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_0;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Aye =
    ColdGas_GNC_Model_PIL_P.Const4_Value;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.Aze =
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VyE =
    ColdGas_GNC_Model_PIL_P.Const2_Value;
  ColdGas_GNC_Model_PIL_B.StatesBusCreator.VzE =
    -ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 +
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_l_idx_1;
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // DigitalClock: '<Root>/Digital Clock'
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0 =
      ((ColdGas_GNC_Model_PIL_M->Timing.clockTick1) * 0.02);

    // ModelReference generated from: '<Root>/FCS' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/SwitchLines'
    //   Constant: '<Root>/Vertical_FlightPlan'

    Flight_Controllers_PIL(&(ColdGas_GNC_Model_PIL_DW.FCS_InstanceData.rtm),
      &ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_0, &rtP_switchLines[0],
      &ColdGas_GNC_Model_PIL_B.m, &ColdGas_GNC_Model_PIL_B.StatesBusCreator.x,
      &ColdGas_GNC_Model_PIL_B.StatesBusCreator.VxE,
      &ColdGas_GNC_Model_PIL_B.StatesBusCreator.Theta,
      &ColdGas_GNC_Model_PIL_B.StatesBusCreator.z,
      &ColdGas_GNC_Model_PIL_B.StatesBusCreator.VzB, &rtP_FlightPlan_Vertical[0],
      &rtP_FlightPlan_Lateral[0], &ColdGas_GNC_Model_PIL_B.Fire_Cmd,
      &ColdGas_GNC_Model_PIL_B.vertCntrlMode,
      &ColdGas_GNC_Model_PIL_B.Cntrl_telem[0], &ColdGas_GNC_Model_PIL_B.xCmd,
      &ColdGas_GNC_Model_PIL_B.fire_Cmd, &ColdGas_GNC_Model_PIL_B.yCmd,
      &ColdGas_GNC_Model_PIL_B.M1_b, &ColdGas_GNC_Model_PIL_B.M2_c,
      &ColdGas_GNC_Model_PIL_B.M3_k, &ColdGas_GNC_Model_PIL_B.M4_c,
      &ColdGas_GNC_Model_PIL_B.M1, &ColdGas_GNC_Model_PIL_B.M2,
      &ColdGas_GNC_Model_PIL_B.M3, &ColdGas_GNC_Model_PIL_B.M4,
      &(ColdGas_GNC_Model_PIL_DW.FCS_InstanceData.rtb),
      &(ColdGas_GNC_Model_PIL_DW.FCS_InstanceData.rtdw));

    // Product: '<S13>/Product' incorporates:
    //   Constant: '<S13>/CE_Orientation'
    //   Constant: '<S13>/CE_Rated_Thrust'
    //   Product: '<S13>/Product1'

    ColdGas_GNC_Model_PIL_B.Product[0] = rtP_CE_Direction[0] * rtP_CE_Thrust *
      ColdGas_GNC_Model_PIL_B.Fire_Cmd;
    ColdGas_GNC_Model_PIL_B.Product[1] = rtP_CE_Direction[1] * rtP_CE_Thrust *
      ColdGas_GNC_Model_PIL_B.Fire_Cmd;
    ColdGas_GNC_Model_PIL_B.Product[2] = rtP_CE_Direction[2] * rtP_CE_Thrust *
      ColdGas_GNC_Model_PIL_B.Fire_Cmd;
  }

  // TransportDelay: '<S13>/Transport Delay'
  {
    static const boolean_T isDiscrete[] = { true, true, true } ;

    real_T **uBuffer = (real_T**)
      &ColdGas_GNC_Model_PIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T simTime = ColdGas_GNC_Model_PIL_M->Timing.t[0];
    real_T tMinusDelay ;
    for (ColdGas_GNC_Model_PIL_B.i = 0; ColdGas_GNC_Model_PIL_B.i < 3;
         ColdGas_GNC_Model_PIL_B.i++) {
      tMinusDelay = ((rtP_CE_tDelay > 0.0) ? rtP_CE_tDelay : 0.0);
      tMinusDelay = simTime - tMinusDelay;
      ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[ColdGas_GNC_Model_PIL_B.i] =
        rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[ColdGas_GNC_Model_PIL_B.i],
        &ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Last[ColdGas_GNC_Model_PIL_B.i],
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[ColdGas_GNC_Model_PIL_B.i],
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[ColdGas_GNC_Model_PIL_B.i],
        ColdGas_GNC_Model_PIL_P.TransportDelay_InitOutput,
        isDiscrete[ColdGas_GNC_Model_PIL_B.i],
        0);
      uBuffer++;
    }
  }

  // Gain: '<S13>/one_over_tau'
  ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1 = 1.0 / rtP_CE_tau;

  // Gain: '<S13>/one_over_tau' incorporates:
  //   Sum: '<S13>/Sum3'

  ColdGas_GNC_Model_PIL_B.one_over_tau[0] =
    (ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[0] -
     ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_0) *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;
  ColdGas_GNC_Model_PIL_B.one_over_tau[1] =
    (ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[1] -
     ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_1) *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;
  ColdGas_GNC_Model_PIL_B.one_over_tau[2] =
    (ColdGas_GNC_Model_PIL_B.rtb_TransportDelay_m[2] -
     ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_2) *
    ColdGas_GNC_Model_PIL_B.rtb_Sum_idx_1;
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // Stop: '<S7>/End' incorporates:
    //   Constant: '<S7>/Stop_Altitude'
    //   Gain: '<S7>/Gain'
    //   RelationalOperator: '<S7>/Relational Operator'

    if (ColdGas_GNC_Model_PIL_P.Gain_Gain *
        ColdGas_GNC_Model_PIL_B.StatesBusCreator.z <= rtP_hFinal) {
      rtmSetStopRequested(ColdGas_GNC_Model_PIL_M, 1);
    }

    // End of Stop: '<S7>/End'

    // Gain: '<S13>/g_Earth' incorporates:
    //   Constant: '<S13>/ISP'

    ColdGas_GNC_Model_PIL_B.g_Earth = rtP_g * rtP_CE_ISP;
  }

  // Gain: '<S9>/one_over_tau' incorporates:
  //   Sum: '<S9>/Sum3'

  ColdGas_GNC_Model_PIL_B.one_over_tau_e = 1.0 / rtP_tau_AlgLoop *
    (ColdGas_GNC_Model_PIL_B.StatesBusCreator.VxE -
     ColdGas_GNC_Model_PIL_B.Omega1);

  // Product: '<S13>/Divide' incorporates:
  //   DotProduct: '<S13>/Dot Product'
  //   Sqrt: '<S13>/Sqrt'

  ColdGas_GNC_Model_PIL_B.mDot = sqrt
    ((ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_0 *
      ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_0 +
      ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_1 *
      ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_1) +
     ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_2 *
     ColdGas_GNC_Model_PIL_B.rtb_CE_Thrust_xyz_idx_2) * (1.0 /
    ColdGas_GNC_Model_PIL_B.g_Earth);
  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    // Update for TransportDelay: '<S13>/Transport Delay'
    {
      real_T **uBuffer = (real_T**)
        &ColdGas_GNC_Model_PIL_DW.TransportDelay_PWORK.TUbufferPtrs[0];
      real_T simTime = ColdGas_GNC_Model_PIL_M->Timing.t[0];
      ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0] =
        ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0] <
          (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[0]-1)) ?
         (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0]+1) : 0);
      if (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0] ==
          ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[0]) {
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[0] =
          ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[0] <
            (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[0]-1))
           ? (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[0]+1) : 0);
      }

      (*uBuffer + ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize
        [0])[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0]] = simTime;
      (*uBuffer++)[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[0]] =
        ColdGas_GNC_Model_PIL_B.Product[0];
      ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1] =
        ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1] <
          (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[1]-1)) ?
         (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1]+1) : 0);
      if (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1] ==
          ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[1]) {
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[1] =
          ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[1] <
            (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[1]-1))
           ? (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[1]+1) : 0);
      }

      (*uBuffer + ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize
        [1])[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1]] = simTime;
      (*uBuffer++)[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[1]] =
        ColdGas_GNC_Model_PIL_B.Product[1];
      ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2] =
        ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2] <
          (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[2]-1)) ?
         (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2]+1) : 0);
      if (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2] ==
          ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[2]) {
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[2] =
          ((ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[2] <
            (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[2]-1))
           ? (ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[2]+1) : 0);
      }

      (*uBuffer + ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize
        [2])[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2]] = simTime;
      (*uBuffer)[ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[2]] =
        ColdGas_GNC_Model_PIL_B.Product[2];
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(ColdGas_GNC_Model_PIL_M)) {
    rt_ertODEUpdateContinuousStates(&ColdGas_GNC_Model_PIL_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++ColdGas_GNC_Model_PIL_M->Timing.clockTick0;
    ColdGas_GNC_Model_PIL_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ColdGas_GNC_Model_PIL_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.02s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.02, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      ColdGas_GNC_Model_PIL_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void ColdGas_GNC_Model_PIL_derivatives(void)
{
  XDot_ColdGas_GNC_Model_PIL_T *_rtXdot;
  real_T Motor_TF1_CSTATE_tmp;
  real_T cosTheta;
  _rtXdot = ((XDot_ColdGas_GNC_Model_PIL_T *) ColdGas_GNC_Model_PIL_M->derivs);

  // Derivatives for Integrator: '<S13>/Int_mDot'
  _rtXdot->Int_mDot_CSTATE = ColdGas_GNC_Model_PIL_B.mDot;

  // Derivatives for Integrator: '<S13>/Int_Descent'
  _rtXdot->Int_Descent_CSTATE[0] = ColdGas_GNC_Model_PIL_B.one_over_tau[0];
  _rtXdot->Int_Descent_CSTATE[1] = ColdGas_GNC_Model_PIL_B.one_over_tau[1];
  _rtXdot->Int_Descent_CSTATE[2] = ColdGas_GNC_Model_PIL_B.one_over_tau[2];

  // Derivatives for TransferFcn: '<S16>/Motor_TF1' incorporates:
  //   TransferFcn: '<S16>/Motor_TF2'
  //   TransferFcn: '<S16>/Motor_TF3'
  //   TransferFcn: '<S16>/Motor_TF4'

  Motor_TF1_CSTATE_tmp = -rtP_Fan_den[1] / rtP_Fan_den[0];
  _rtXdot->Motor_TF1_CSTATE[0] = Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[0];

  // Derivatives for TransferFcn: '<S16>/Motor_TF2'
  _rtXdot->Motor_TF2_CSTATE[0] = Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[0];

  // Derivatives for TransferFcn: '<S16>/Motor_TF3'
  _rtXdot->Motor_TF3_CSTATE[0] = Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[0];

  // Derivatives for TransferFcn: '<S16>/Motor_TF4'
  _rtXdot->Motor_TF4_CSTATE[0] = Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[0];

  // Derivatives for TransferFcn: '<S16>/Motor_TF1' incorporates:
  //   TransferFcn: '<S16>/Motor_TF2'
  //   TransferFcn: '<S16>/Motor_TF3'
  //   TransferFcn: '<S16>/Motor_TF4'

  Motor_TF1_CSTATE_tmp = -rtP_Fan_den[2] / rtP_Fan_den[0];
  _rtXdot->Motor_TF1_CSTATE[0] += Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[1];

  // Derivatives for TransferFcn: '<S16>/Motor_TF2'
  _rtXdot->Motor_TF2_CSTATE[0] += Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[1];

  // Derivatives for TransferFcn: '<S16>/Motor_TF3'
  _rtXdot->Motor_TF3_CSTATE[0] += Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[1];

  // Derivatives for TransferFcn: '<S16>/Motor_TF4'
  _rtXdot->Motor_TF4_CSTATE[0] += Motor_TF1_CSTATE_tmp *
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[1];

  // Derivatives for TransferFcn: '<S16>/Motor_TF1'
  _rtXdot->Motor_TF1_CSTATE[1] = ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[0];
  _rtXdot->Motor_TF1_CSTATE[0] += ColdGas_GNC_Model_PIL_B.M1;

  // Derivatives for TransferFcn: '<S16>/Motor_TF2'
  _rtXdot->Motor_TF2_CSTATE[1] = ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[0];
  _rtXdot->Motor_TF2_CSTATE[0] += ColdGas_GNC_Model_PIL_B.M2;

  // Derivatives for TransferFcn: '<S16>/Motor_TF3'
  _rtXdot->Motor_TF3_CSTATE[1] = ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[0];
  _rtXdot->Motor_TF3_CSTATE[0] += ColdGas_GNC_Model_PIL_B.M3;

  // Derivatives for TransferFcn: '<S16>/Motor_TF4'
  _rtXdot->Motor_TF4_CSTATE[1] = ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[0];
  _rtXdot->Motor_TF4_CSTATE[0] += ColdGas_GNC_Model_PIL_B.M4;

  // Derivatives for Integrator: '<S9>/Int_LP'
  _rtXdot->Int_LP_CSTATE = ColdGas_GNC_Model_PIL_B.one_over_tau_e;

  // Derivatives for EOM3DOF: '<Root>/Custom Variable Mass 3dof (Body Axes)' incorporates:
  //   Constant: '<Root>/Iyy'
  //   Constant: '<Root>/dI'

  Motor_TF1_CSTATE_tmp = sin
    (ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5]);
  cosTheta = cos(ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5]);
  _rtXdot->CustomVariableMass3dofBodyAxes_[2] =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] * cosTheta +
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] *
    Motor_TF1_CSTATE_tmp;
  _rtXdot->CustomVariableMass3dofBodyAxes_[3] =
    -ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] *
    Motor_TF1_CSTATE_tmp +
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] * cosTheta;
  _rtXdot->CustomVariableMass3dofBodyAxes_[5] =
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4];
  _rtXdot->CustomVariableMass3dofBodyAxes_[0] = (ColdGas_GNC_Model_PIL_B.Sum /
    ColdGas_GNC_Model_PIL_B.m -
    ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAx_hl *
    Motor_TF1_CSTATE_tmp) -
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] *
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4];
  _rtXdot->CustomVariableMass3dofBodyAxes_[1] = (ColdGas_GNC_Model_PIL_B.Switch /
    ColdGas_GNC_Model_PIL_B.m +
    ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAx_hl * cosTheta) +
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] *
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4];
  _rtXdot->CustomVariableMass3dofBodyAxes_[4] = (ColdGas_GNC_Model_PIL_B.Sum2 -
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4] *
    ColdGas_GNC_Model_PIL_P.dI_Value) / ColdGas_GNC_Model_PIL_P.Iyy_Value;
}

// Model initialize function
void ColdGas_GNC_Model_PIL_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
                          &ColdGas_GNC_Model_PIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ColdGas_GNC_Model_PIL_M->solverInfo, &rtmGetTPtr
                (ColdGas_GNC_Model_PIL_M));
    rtsiSetStepSizePtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
                       &ColdGas_GNC_Model_PIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
                 &ColdGas_GNC_Model_PIL_M->derivs);
    rtsiSetContStatesPtr(&ColdGas_GNC_Model_PIL_M->solverInfo, (real_T **)
                         &ColdGas_GNC_Model_PIL_M->contStates);
    rtsiSetNumContStatesPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
      &ColdGas_GNC_Model_PIL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
      &ColdGas_GNC_Model_PIL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
      &ColdGas_GNC_Model_PIL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
      &ColdGas_GNC_Model_PIL_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ColdGas_GNC_Model_PIL_M->solverInfo, (boolean_T**)
      &ColdGas_GNC_Model_PIL_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
                          (&rtmGetErrorStatus(ColdGas_GNC_Model_PIL_M)));
    rtsiSetRTModelPtr(&ColdGas_GNC_Model_PIL_M->solverInfo,
                      ColdGas_GNC_Model_PIL_M);
  }

  rtsiSetSimTimeStep(&ColdGas_GNC_Model_PIL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ColdGas_GNC_Model_PIL_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&ColdGas_GNC_Model_PIL_M->solverInfo, false);
  ColdGas_GNC_Model_PIL_M->intgData.y = ColdGas_GNC_Model_PIL_M->odeY;
  ColdGas_GNC_Model_PIL_M->intgData.f[0] = ColdGas_GNC_Model_PIL_M->odeF[0];
  ColdGas_GNC_Model_PIL_M->intgData.f[1] = ColdGas_GNC_Model_PIL_M->odeF[1];
  ColdGas_GNC_Model_PIL_M->intgData.f[2] = ColdGas_GNC_Model_PIL_M->odeF[2];
  ColdGas_GNC_Model_PIL_M->contStates = ((X_ColdGas_GNC_Model_PIL_T *)
    &ColdGas_GNC_Model_PIL_X);
  ColdGas_GNC_Model_PIL_M->contStateDisabled = ((XDis_ColdGas_GNC_Model_PIL_T *)
    &ColdGas_GNC_Model_PIL_XDis);
  ColdGas_GNC_Model_PIL_M->Timing.tStart = (0.0);
  ColdGas_GNC_Model_PIL_M->periodicContStateIndices = ((int_T*)
    ColdGas_GNC_Model__PeriodicIndX);
  ColdGas_GNC_Model_PIL_M->periodicContStateRanges = ((real_T*)
    ColdGas_GNC_Model__PeriodicRngX);
  rtsiSetSolverData(&ColdGas_GNC_Model_PIL_M->solverInfo, static_cast<void *>
                    (&ColdGas_GNC_Model_PIL_M->intgData));
  rtsiSetSolverName(&ColdGas_GNC_Model_PIL_M->solverInfo,"ode3");
  rtmSetTPtr(ColdGas_GNC_Model_PIL_M, &ColdGas_GNC_Model_PIL_M->Timing.tArray[0]);
  ColdGas_GNC_Model_PIL_M->Timing.stepSize0 = 0.02;

  {
    static uint32_T *clockTickPtrs[2];
    static real_T *taskTimePtrs[2];
    ColdGas_GNC_Model_PI_TimingBrdg.nTasks = 2;
    clockTickPtrs[0] = &(ColdGas_GNC_Model_PIL_M->Timing.clockTick0);
    clockTickPtrs[1] = &(ColdGas_GNC_Model_PIL_M->Timing.clockTick1);
    ColdGas_GNC_Model_PI_TimingBrdg.clockTick = clockTickPtrs;
    ColdGas_GNC_Model_PI_TimingBrdg.clockTickH = (NULL);
    taskTimePtrs[0] = &(ColdGas_GNC_Model_PIL_M->Timing.t[0]);
    taskTimePtrs[1] = (NULL);
    ColdGas_GNC_Model_PI_TimingBrdg.taskTime = taskTimePtrs;
  }

  // Model Initialize function for ModelReference Block: '<Root>/FCS'
  Flight_Controllers_P_initialize(rtmGetErrorStatusPointer
    (ColdGas_GNC_Model_PIL_M), &ColdGas_GNC_Model_PI_TimingBrdg, 1,
    &(ColdGas_GNC_Model_PIL_DW.FCS_InstanceData.rtm));

  {
    int32_T i;

    // Start for TransportDelay: '<S13>/Transport Delay'
    {
      real_T *pBuffer =
        &ColdGas_GNC_Model_PIL_DW.TransportDelay_RWORK.TUbufferArea[0];
      for (i = 0; i < 3; i++) {
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Tail[i] = 0;
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Head[i] = 0;
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.Last[i] = 0;
        ColdGas_GNC_Model_PIL_DW.TransportDelay_IWORK.CircularBufSize[i] = 1024;
        pBuffer[0] = ColdGas_GNC_Model_PIL_P.TransportDelay_InitOutput;
        pBuffer[1024] = ColdGas_GNC_Model_PIL_M->Timing.t[0];
        ColdGas_GNC_Model_PIL_DW.TransportDelay_PWORK.TUbufferPtrs[i] = (void *)
          &pBuffer[0];
        pBuffer += 2048;
      }
    }

    // InitializeConditions for Integrator: '<S13>/Int_mDot'
    ColdGas_GNC_Model_PIL_X.Int_mDot_CSTATE =
      ColdGas_GNC_Model_PIL_P.Int_mDot_IC;

    // InitializeConditions for Integrator: '<S13>/Int_Descent'
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[0] =
      ColdGas_GNC_Model_PIL_P.Int_Descent_IC;
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[1] =
      ColdGas_GNC_Model_PIL_P.Int_Descent_IC;
    ColdGas_GNC_Model_PIL_X.Int_Descent_CSTATE[2] =
      ColdGas_GNC_Model_PIL_P.Int_Descent_IC;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF1'
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[0] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF2'
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[0] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF3'
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[0] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF4'
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[0] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF1'
    ColdGas_GNC_Model_PIL_X.Motor_TF1_CSTATE[1] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF2'
    ColdGas_GNC_Model_PIL_X.Motor_TF2_CSTATE[1] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF3'
    ColdGas_GNC_Model_PIL_X.Motor_TF3_CSTATE[1] = 0.0;

    // InitializeConditions for TransferFcn: '<S16>/Motor_TF4'
    ColdGas_GNC_Model_PIL_X.Motor_TF4_CSTATE[1] = 0.0;

    // InitializeConditions for Integrator: '<S9>/Int_LP'
    ColdGas_GNC_Model_PIL_X.Int_LP_CSTATE = ColdGas_GNC_Model_PIL_P.Int_LP_IC;

    // InitializeConditions for EOM3DOF: '<Root>/Custom Variable Mass 3dof (Body Axes)' 
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[0] =
      ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxes_ * cos
      (ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxe_a);
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[1] =
      ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxes_ * sin
      (ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxe_a);
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[2] =
      ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxe_o[0];
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[3] =
      ColdGas_GNC_Model_PIL_P.CustomVariableMass3dofBodyAxe_o[1];
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[4] = rtP_q0;
    ColdGas_GNC_Model_PIL_X.CustomVariableMass3dofBodyAxes_[5] = rtP_theta0;

    // SystemInitialize for ModelReference generated from: '<Root>/FCS'
    Flight_Controllers_PIL_Init(&(ColdGas_GNC_Model_PIL_DW.FCS_InstanceData.rtdw));

    // InitializeConditions for root-level periodic continuous states
    {
      int_T rootPeriodicContStateIndices[1] = { 0 };

      real_T rootPeriodicContStateRanges[2] = { 0.0, 0.0 };

      (void) memcpy((void*)ColdGas_GNC_Model__PeriodicIndX,
                    rootPeriodicContStateIndices,
                    1*sizeof(int_T));
      (void) memcpy((void*)ColdGas_GNC_Model__PeriodicRngX,
                    rootPeriodicContStateRanges,
                    2*sizeof(real_T));
    }
  }
}

// Model terminate function
void ColdGas_GNC_Model_PIL_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
