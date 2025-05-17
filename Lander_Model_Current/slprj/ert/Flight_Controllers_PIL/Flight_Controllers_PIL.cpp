//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL.cpp
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
#include "Flight_Controllers_PIL.h"
#include "rtwtypes.h"
#include "Flight_Controllers_PIL_private.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

P_Flight_Controllers_PIL_T Flight_Controllers_PIL_P = {
  // Mask Parameter: Lat_Position_PID_InitialConditi
  //  Referenced by: '<S38>/Filter'

  0.0,

  // Mask Parameter: Lat_Vel_Control_InitialConditio
  //  Referenced by: '<S90>/Filter'

  0.0,

  // Mask Parameter: Pitch_Controller_InitialConditi
  //  Referenced by: '<S142>/Filter'

  0.0,

  // Mask Parameter: Lat_Position_PID_InitialCondi_l
  //  Referenced by: '<S43>/Integrator'

  0.0,

  // Mask Parameter: Lat_Vel_Control_InitialCondit_k
  //  Referenced by: '<S95>/Integrator'

  0.0,

  // Mask Parameter: Pitch_Controller_InitialCondi_k
  //  Referenced by: '<S147>/Integrator'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  0.02,

  // Expression: 0
  //  Referenced by: '<S4>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S43>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S38>/Filter'

  0.02,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S95>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S90>/Filter'

  0.02,

  // Computed Parameter: Integrator_gainval_c
  //  Referenced by: '<S147>/Integrator'

  0.02,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S142>/Filter'

  0.02,

  // Expression: -1
  //  Referenced by: '<S3>/Negate34'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S3>/Constant'

  0.0
};

// Forward declaration for local functions
static real_T Flight_Control_interp1_QO2chnuP(const real_T varargin_1[10], const
  real_T varargin_2[10], real_T varargin_3, B_Flight_Controllers_PIL_c_T *localB);
static real_T Flight_Control_interpn_UfYuwGaF(const real_T varargin_1[4], const
  real_T varargin_2[4], real_T varargin_3, B_Flight_Controllers_PIL_c_T *localB);

// Function for MATLAB Function: '<Root>/Vertical_Controller'
static real_T Flight_Control_interp1_QO2chnuP(const real_T varargin_1[10], const
  real_T varargin_2[10], real_T varargin_3, B_Flight_Controllers_PIL_c_T *localB)
{
  real_T Vq;
  int32_T i;
  memcpy(&localB->y_m[0], &varargin_2[0], 10U * sizeof(real_T));
  memcpy(&localB->x_c[0], &varargin_1[0], 10U * sizeof(real_T));
  if (varargin_1[1] < varargin_1[0]) {
    for (i = 0; i < 5; i++) {
      real_T xtmp;
      xtmp = localB->x_c[i];
      localB->x_c[i] = localB->x_c[9 - i];
      localB->x_c[9 - i] = xtmp;
      xtmp = localB->y_m[i];
      localB->y_m[i] = localB->y_m[9 - i];
      localB->y_m[9 - i] = xtmp;
    }
  }

  Vq = (rtNaN);
  if (!rtIsNaN(varargin_3)) {
    if (varargin_3 == localB->x_c[9]) {
      Vq = localB->y_m[9];
    } else if ((!(varargin_3 > localB->x_c[9])) && (!(varargin_3 < localB->x_c[0])))
    {
      int32_T low_i;
      int32_T low_ip1;
      i = 10;
      low_i = 1;
      low_ip1 = 2;
      while (i > low_ip1) {
        int32_T mid_i;
        mid_i = (low_i + i) >> 1;
        if (varargin_3 >= localB->x_c[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          i = mid_i;
        }
      }

      if (low_i > 0) {
        Vq = localB->y_m[low_i - 1];
      }
    }
  }

  return Vq;
}

// Function for MATLAB Function: '<Root>/Vertical_Controller'
static real_T Flight_Control_interpn_UfYuwGaF(const real_T varargin_1[4], const
  real_T varargin_2[4], real_T varargin_3, B_Flight_Controllers_PIL_c_T *localB)
{
  real_T Vq;
  localB->x_b[0] = varargin_1[0];
  localB->y_c[0] = varargin_2[0];
  localB->x_b[1] = varargin_1[1];
  localB->y_c[1] = varargin_2[1];
  localB->x_b[2] = varargin_1[2];
  localB->y_c[2] = varargin_2[2];
  localB->x_b[3] = varargin_1[3];
  localB->y_c[3] = varargin_2[3];
  if (varargin_1[1] < varargin_1[0]) {
    localB->x_b[0] = varargin_1[3];
    localB->x_b[3] = varargin_1[0];
    localB->y_c[0] = varargin_2[3];
    localB->y_c[3] = varargin_2[0];
    localB->x_b[1] = varargin_1[2];
    localB->x_b[2] = varargin_1[1];
    localB->y_c[1] = varargin_2[2];
    localB->y_c[2] = varargin_2[1];
  }

  Vq = (rtNaN);
  if ((!rtIsNaN(varargin_3)) && (!(varargin_3 > localB->x_b[3])) &&
      (!(varargin_3 < localB->x_b[0]))) {
    real_T r;
    int32_T high_i;
    int32_T low_i;
    int32_T low_ip1;
    high_i = 4;
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = (low_i + high_i) >> 1;
      if (varargin_3 >= localB->x_b[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    r = localB->x_b[low_i - 1];
    r = (varargin_3 - r) / (localB->x_b[low_i] - r);
    if (r == 0.0) {
      Vq = localB->y_c[low_i - 1];
    } else if (r == 1.0) {
      Vq = localB->y_c[low_i];
    } else {
      Vq = localB->y_c[low_i - 1];
      if (!(Vq == localB->y_c[low_i])) {
        Vq = (1.0 - r) * Vq + r * localB->y_c[low_i];
      }
    }
  }

  return Vq;
}

// System initialize for referenced model: 'Flight_Controllers_PIL'
void Flight_Controllers_PIL_Init(DW_Flight_Controllers_PIL_f_T *localDW)
{
  // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
  localDW->DiscreteTimeIntegrator_DSTATE =
    Flight_Controllers_PIL_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator'
  localDW->Integrator_DSTATE =
    Flight_Controllers_PIL_P.Lat_Position_PID_InitialCondi_l;

  // InitializeConditions for DiscreteIntegrator: '<S38>/Filter'
  localDW->Filter_DSTATE =
    Flight_Controllers_PIL_P.Lat_Position_PID_InitialConditi;

  // InitializeConditions for DiscreteIntegrator: '<S95>/Integrator'
  localDW->Integrator_DSTATE_e =
    Flight_Controllers_PIL_P.Lat_Vel_Control_InitialCondit_k;

  // InitializeConditions for DiscreteIntegrator: '<S90>/Filter'
  localDW->Filter_DSTATE_a =
    Flight_Controllers_PIL_P.Lat_Vel_Control_InitialConditio;

  // InitializeConditions for DiscreteIntegrator: '<S147>/Integrator'
  localDW->Integrator_DSTATE_i =
    Flight_Controllers_PIL_P.Pitch_Controller_InitialCondi_k;

  // InitializeConditions for DiscreteIntegrator: '<S142>/Filter'
  localDW->Filter_DSTATE_k =
    Flight_Controllers_PIL_P.Pitch_Controller_InitialConditi;
}

// Output and update for referenced model: 'Flight_Controllers_PIL'
void Flight_Controllers_PIL(RT_MODEL_Flight_Controllers_P_T * const
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
  B_Flight_Controllers_PIL_c_T *localB, DW_Flight_Controllers_PIL_f_T *localDW)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_Negate34;
  real_T rtb_Sum5;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;

  // MATLAB Function: '<Root>/Vertical_Controller'
  rtb_FilterCoefficient = 0.0;
  localB->hErr = 0.0;
  localB->vErr = 0.0;
  localB->Gain = Flight_Control_interp1_QO2chnuP(&rtu_Sched_Vertical[0],
    &rtu_Sched_Vertical[10], *rtu_t, localB);
  localB->vertCmd = Flight_Control_interp1_QO2chnuP(&rtu_Sched_Vertical[0],
    &rtu_Sched_Vertical[20], *rtu_t, localB);
  localB->hCmd = 0.0;
  localB->hDot_Cmd = 0.0;
  if (localB->Gain == 1.0) {
    localB->hDot_Cmd = localB->vertCmd;
    localB->hCmd = (rtNaN);
    localB->vErr = -*rtu_States_VzB - localB->vertCmd;
    if (localB->vErr < -0.1) {
      rtb_FilterCoefficient = 1.0;
    } else if ((!(localB->vErr > 0.1)) && (localDW->thr_previous > 0.0)) {
      rtb_FilterCoefficient = 1.0;
    }
  } else if (localB->Gain == 2.0) {
    localB->hCmd = localB->vertCmd;
    localB->hDot_Cmd = (rtNaN);
    localB->hErr = -*rtu_States_z - localB->vertCmd;
    localB->vErr = -*rtu_States_VzB;
    if (localB->hErr < rtu_switchLines[0]) {
      localB->hErr = rtu_switchLines[0];
    }

    if (localB->hErr > rtu_switchLines[3]) {
      localB->hErr = rtu_switchLines[3];
    }

    localB->rtu_switchLines[0] = rtu_switchLines[0];
    localB->rtu_switchLines_k[0] = rtu_switchLines[8];
    localB->rtu_switchLines[1] = rtu_switchLines[1];
    localB->rtu_switchLines_k[1] = rtu_switchLines[9];
    localB->rtu_switchLines[2] = rtu_switchLines[2];
    localB->rtu_switchLines_k[2] = rtu_switchLines[10];
    localB->rtu_switchLines[3] = rtu_switchLines[3];
    localB->rtu_switchLines_k[3] = rtu_switchLines[11];
    localB->vertCmd = Flight_Control_interpn_UfYuwGaF(localB->rtu_switchLines,
      localB->rtu_switchLines_k, localB->hErr, localB);
    if (-*rtu_States_VzB < localB->vertCmd) {
      rtb_FilterCoefficient = 1.0;
    } else if (-*rtu_States_VzB > localB->vertCmd) {
      localB->rtu_switchLines[0] = rtu_switchLines[4];
      localB->rtu_switchLines_k[0] = rtu_switchLines[12];
      localB->rtu_switchLines[1] = rtu_switchLines[5];
      localB->rtu_switchLines_k[1] = rtu_switchLines[13];
      localB->rtu_switchLines[2] = rtu_switchLines[6];
      localB->rtu_switchLines_k[2] = rtu_switchLines[14];
      localB->rtu_switchLines[3] = rtu_switchLines[7];
      localB->rtu_switchLines_k[3] = rtu_switchLines[15];
      if (-*rtu_States_VzB < Flight_Control_interpn_UfYuwGaF
          (localB->rtu_switchLines, localB->rtu_switchLines_k, localB->hErr,
           localB)) {
        rtb_FilterCoefficient = localDW->thr_previous;
      }
    }
  }

  rty_Cntrl_telem[0] = *rtu_t;
  rty_Cntrl_telem[1] = -*rtu_States_z;
  rty_Cntrl_telem[2] = -*rtu_States_VzB;
  rty_Cntrl_telem[3] = localB->hDot_Cmd;
  rty_Cntrl_telem[4] = localB->hCmd;
  rty_Cntrl_telem[5] = localB->hErr;
  rty_Cntrl_telem[6] = localB->vErr;
  rty_Cntrl_telem[7] = localDW->thr_previous;
  rty_Cntrl_telem[8] = rtb_FilterCoefficient;
  rty_Cntrl_telem[9] = localB->Gain;
  localDW->thr_previous = rtb_FilterCoefficient;
  *rty_Controls_fire_Cmd = rtb_FilterCoefficient;
  *rty_VertMode = localB->Gain;

  // End of MATLAB Function: '<Root>/Vertical_Controller'

  // SignalConversion generated from: '<Root>/fireCmd'
  *rty_fireCmd = *rty_Controls_fire_Cmd;

  // Gain: '<S3>/Gain'
  localB->Gain = rtP_g_Offset * *rtu_m;

  // Sum: '<S3>/Sum5' incorporates:
  //   Constant: '<S3>/Y_intercept'
  //   Gain: '<S3>/Cosine_Loss'
  //   Gain: '<S3>/Gain1'
  //   Gain: '<S3>/Gain2'
  //   Gain: '<S3>/slope'

  rtb_Sum5 = 1.0 / rtP_Cant_cosine_Loss * localB->Gain * rtP_g * (1.0 /
    rtP_nFans) * rtP_mOmega + rtP_bOmega;

  // Sum: '<S3>/Sum6' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

  localB->Gain = localDW->DiscreteTimeIntegrator_DSTATE - *rtu_States_x;

  // Gain: '<S46>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S38>/Filter'
  //   Gain: '<S36>/Derivative Gain'
  //   Sum: '<S38>/SumD'

  rtb_FilterCoefficient = (rtP_Kd_LatPos * localB->Gain - localDW->Filter_DSTATE)
    * rtP_N_LatPos;

  // Sum: '<S3>/Sum4' incorporates:
  //   DiscreteIntegrator: '<S43>/Integrator'
  //   Gain: '<S48>/Proportional Gain'
  //   Sum: '<S52>/Sum'

  localB->hErr = ((rtP_Kp_LatPos * localB->Gain + localDW->Integrator_DSTATE) +
                  rtb_FilterCoefficient) - *rtu_States_VxE;

  // Gain: '<S98>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S90>/Filter'
  //   Gain: '<S88>/Derivative Gain'
  //   Sum: '<S90>/SumD'

  localB->vErr = (rtP_Kd_LatVel * localB->hErr - localDW->Filter_DSTATE_a) *
    rtP_N_LatVel;

  // Sum: '<S3>/Sum8' incorporates:
  //   DiscreteIntegrator: '<S95>/Integrator'
  //   Gain: '<S100>/Proportional Gain'
  //   Sum: '<S104>/Sum'

  localB->hCmd = ((rtP_Kp_LatVel * localB->hErr + localDW->Integrator_DSTATE_e)
                  + localB->vErr) - *rtu_States_Theta;

  // Gain: '<S150>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S142>/Filter'
  //   Gain: '<S140>/Derivative Gain'
  //   Sum: '<S142>/SumD'

  localB->hDot_Cmd = (rtP_Kd_Pitch * localB->hCmd - localDW->Filter_DSTATE_k) *
    rtP_N_Pitch;

  // Gain: '<S3>/Spread_Out' incorporates:
  //   DiscreteIntegrator: '<S147>/Integrator'
  //   Gain: '<S152>/Proportional Gain'
  //   Sum: '<S156>/Sum'

  rtb_Negate34 = ((rtP_Kp_Pitch * localB->hCmd + localDW->Integrator_DSTATE_i) +
                  localB->hDot_Cmd) * (1.0 / rtP_nFans);

  // Sum: '<S3>/Sum1' incorporates:
  //   Sum: '<S3>/Sum'

  localB->vertCmd = rtb_Sum5 + rtb_Negate34;
  *rty_MotorCmds_M1 = localB->vertCmd;

  // SignalConversion generated from: '<Root>/Controls_Outport_4'
  *rty_Controls_OmegaCmds_M1 = *rty_MotorCmds_M1;

  // Sum: '<S3>/Sum'
  *rty_MotorCmds_M2 = localB->vertCmd;

  // SignalConversion generated from: '<Root>/Controls_Outport_4'
  *rty_Controls_OmegaCmds_M2 = *rty_MotorCmds_M2;

  // Sum: '<S3>/Sum2' incorporates:
  //   Gain: '<S3>/Negate34'
  //   Sum: '<S3>/Sum3'

  localB->vertCmd = Flight_Controllers_PIL_P.Negate34_Gain * rtb_Negate34 +
    rtb_Sum5;
  *rty_MotorCmds_M3 = localB->vertCmd;

  // SignalConversion generated from: '<Root>/Controls_Outport_4'
  *rty_Controls_OmegaCmds_M3 = *rty_MotorCmds_M3;

  // Sum: '<S3>/Sum3'
  *rty_MotorCmds_M4 = localB->vertCmd;

  // SignalConversion generated from: '<Root>/Controls_Outport_4'
  *rty_Controls_OmegaCmds_M4 = *rty_MotorCmds_M4;

  // DigitalClock: '<S3>/Digital Clock'
  localB->vertCmd = (Flight_Controllers_PIL_M->getClockTick0() * 0.02);

  // MATLAB Function: '<S3>/Lateral_Flight_Plan'
  memcpy(&localB->x[0], &rtu_Sched_Lateral[0], 10U * sizeof(real_T));
  memcpy(&localB->y[0], &rtu_Sched_Lateral[20], 10U * sizeof(real_T));
  if (rtu_Sched_Lateral[1] < rtu_Sched_Lateral[0]) {
    for (high_i = 0; high_i < 5; high_i++) {
      rtb_Sum5 = localB->x[high_i];
      localB->x[high_i] = localB->x[9 - high_i];
      localB->x[9 - high_i] = rtb_Sum5;
    }

    memcpy(&localB->y[0], &rtu_Sched_Lateral[20], 10U * sizeof(real_T));
    for (high_i = 0; high_i < 5; high_i++) {
      rtb_Sum5 = localB->y[high_i];
      localB->y[high_i] = localB->y[9 - high_i];
      localB->y[9 - high_i] = rtb_Sum5;
    }
  }

  *rty_Controls_xCmd = (rtNaN);
  if (rtIsNaN(localB->vertCmd)) {
    *rty_Controls_xCmd = (rtNaN);
  } else if ((!(localB->vertCmd > localB->x[9])) && (!(localB->vertCmd <
               localB->x[0]))) {
    high_i = 10;
    low_i = 1;
    low_ip1 = 2;
    while (high_i > low_ip1) {
      mid_i = (low_i + high_i) >> 1;
      if (localB->vertCmd >= localB->x[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    rtb_Sum5 = localB->x[low_i - 1];
    rtb_Sum5 = (localB->vertCmd - rtb_Sum5) / (localB->x[low_i] - rtb_Sum5);
    if (rtb_Sum5 == 0.0) {
      *rty_Controls_xCmd = localB->y[low_i - 1];
    } else if (rtb_Sum5 == 1.0) {
      *rty_Controls_xCmd = localB->y[low_i];
    } else {
      localB->vertCmd = localB->y[low_i - 1];
      if (localB->vertCmd == localB->y[low_i]) {
        *rty_Controls_xCmd = localB->vertCmd;
      } else {
        *rty_Controls_xCmd = (1.0 - rtb_Sum5) * localB->vertCmd + rtb_Sum5 *
          localB->y[low_i];
      }
    }
  }

  // End of MATLAB Function: '<S3>/Lateral_Flight_Plan'

  // Sum: '<S4>/Sum6' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

  localB->vertCmd = *rty_Controls_xCmd - localDW->DiscreteTimeIntegrator_DSTATE;

  // Constant: '<S3>/Constant'
  *rty_Controls_yCmd = Flight_Controllers_PIL_P.Constant_Value;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S4>/1_over_tau'

  localDW->DiscreteTimeIntegrator_DSTATE += 1.0 / rtP_tau_vCmd * localB->vertCmd
    * Flight_Controllers_PIL_P.DiscreteTimeIntegrator_gainval;

  // Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
  //   Gain: '<S40>/Integral Gain'

  localDW->Integrator_DSTATE += rtP_Ki_LatPos * localB->Gain *
    Flight_Controllers_PIL_P.Integrator_gainval;

  // Update for DiscreteIntegrator: '<S38>/Filter'
  localDW->Filter_DSTATE += Flight_Controllers_PIL_P.Filter_gainval *
    rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
  //   Gain: '<S92>/Integral Gain'

  localDW->Integrator_DSTATE_e += rtP_Ki_LatVel * localB->hErr *
    Flight_Controllers_PIL_P.Integrator_gainval_g;

  // Update for DiscreteIntegrator: '<S90>/Filter'
  localDW->Filter_DSTATE_a += Flight_Controllers_PIL_P.Filter_gainval_d *
    localB->vErr;

  // Update for DiscreteIntegrator: '<S147>/Integrator' incorporates:
  //   Gain: '<S144>/Integral Gain'

  localDW->Integrator_DSTATE_i += rtP_Ki_Pitch * localB->hCmd *
    Flight_Controllers_PIL_P.Integrator_gainval_c;

  // Update for DiscreteIntegrator: '<S142>/Filter'
  localDW->Filter_DSTATE_k += Flight_Controllers_PIL_P.Filter_gainval_i *
    localB->hDot_Cmd;
}

// Model initialize function
void Flight_Controllers_P_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0,
  RT_MODEL_Flight_Controllers_P_T *const Flight_Controllers_PIL_M)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // setup the global timing engine
  Flight_Controllers_PIL_M->Timing.mdlref_GlobalTID[0] = mdlref_TID0;
  Flight_Controllers_PIL_M->timingBridge = (timingBridge);

  // initialize error status
  Flight_Controllers_PIL_M->setErrorStatusPointer(rt_errorStatus);
}

time_T RT_MODEL_Flight_Controllers_P_T::getClockTickH0() const
{
  return ( *(timingBridge->clockTickH[Timing.mdlref_GlobalTID[0]]) );
}

time_T RT_MODEL_Flight_Controllers_P_T::getClockTick0() const
{
  return ( *((timingBridge->clockTick[Timing.mdlref_GlobalTID[0]])) );
}

time_T RT_MODEL_Flight_Controllers_P_T::getT() const
{
  return (*(timingBridge->taskTime[0]));
}

const char_T* RT_MODEL_Flight_Controllers_P_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void RT_MODEL_Flight_Controllers_P_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

boolean_T RT_MODEL_Flight_Controllers_P_T::isSampleHit(int32_T sti) const
{
  return (timingBridge->taskCounter[Timing.mdlref_GlobalTID[sti]] == 0);
}

const char_T** RT_MODEL_Flight_Controllers_P_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void RT_MODEL_Flight_Controllers_P_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

//
// File trailer for generated code.
//
// [EOF]
//
