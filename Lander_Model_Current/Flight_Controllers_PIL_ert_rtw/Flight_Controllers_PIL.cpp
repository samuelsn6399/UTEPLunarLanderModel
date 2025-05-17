//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flight_Controllers_PIL.cpp
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
#include "rtwtypes.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals (default storage)
B_Flight_Controllers_PIL_T Flight_Controllers_PIL_B;

// Block states (default storage)
DW_Flight_Controllers_PIL_T Flight_Controllers_PIL_DW;

// External inputs (root inport signals with default storage)
ExtU_Flight_Controllers_PIL_T Flight_Controllers_PIL_U;

// External outputs (root outports fed by signals with default storage)
ExtY_Flight_Controllers_PIL_T Flight_Controllers_PIL_Y;

// Real-time model
RT_MODEL_Flight_Controllers_P_T Flight_Controllers_PIL_M_ =
  RT_MODEL_Flight_Controllers_P_T();
RT_MODEL_Flight_Controllers_P_T *const Flight_Controllers_PIL_M =
  &Flight_Controllers_PIL_M_;

// Forward declaration for local functions
static real_T Flight_Controllers_PIL_interp1(const real_T varargin_1[10], const
  real_T varargin_2[10], real_T varargin_3);
static real_T Flight_Controllers_PIL_interpn(const real_T varargin_1[4], const
  real_T varargin_2[4], real_T varargin_3);

// Function for MATLAB Function: '<Root>/Vertical_Controller'
static real_T Flight_Controllers_PIL_interp1(const real_T varargin_1[10], const
  real_T varargin_2[10], real_T varargin_3)
{
  real_T Vq;
  int32_T i;
  memcpy(&Flight_Controllers_PIL_B.y_m[0], &varargin_2[0], 10U * sizeof(real_T));
  memcpy(&Flight_Controllers_PIL_B.x_c[0], &varargin_1[0], 10U * sizeof(real_T));
  Vq = (rtNaN);
  i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (i < 10) {
      if (rtIsNaN(varargin_1[i])) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (i = 0; i < 5; i++) {
          real_T xtmp;
          xtmp = Flight_Controllers_PIL_B.x_c[i];
          Flight_Controllers_PIL_B.x_c[i] = Flight_Controllers_PIL_B.x_c[9 - i];
          Flight_Controllers_PIL_B.x_c[9 - i] = xtmp;
          xtmp = Flight_Controllers_PIL_B.y_m[i];
          Flight_Controllers_PIL_B.y_m[i] = Flight_Controllers_PIL_B.y_m[9 - i];
          Flight_Controllers_PIL_B.y_m[9 - i] = xtmp;
        }
      }

      if (!rtIsNaN(varargin_3)) {
        if (varargin_3 == Flight_Controllers_PIL_B.x_c[9]) {
          Vq = Flight_Controllers_PIL_B.y_m[9];
        } else if ((!(varargin_3 > Flight_Controllers_PIL_B.x_c[9])) &&
                   (!(varargin_3 < Flight_Controllers_PIL_B.x_c[0]))) {
          int32_T low_i;
          int32_T low_ip1;
          i = 10;
          low_i = 1;
          low_ip1 = 2;
          while (i > low_ip1) {
            int32_T mid_i;
            mid_i = (low_i + i) >> 1;
            if (varargin_3 >= Flight_Controllers_PIL_B.x_c[mid_i - 1]) {
              low_i = mid_i;
              low_ip1 = mid_i + 1;
            } else {
              i = mid_i;
            }
          }

          if (low_i > 0) {
            Vq = Flight_Controllers_PIL_B.y_m[low_i - 1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

// Function for MATLAB Function: '<Root>/Vertical_Controller'
static real_T Flight_Controllers_PIL_interpn(const real_T varargin_1[4], const
  real_T varargin_2[4], real_T varargin_3)
{
  real_T Vq;
  int32_T high_i;
  Flight_Controllers_PIL_B.x_cx[0] = varargin_1[0];
  Flight_Controllers_PIL_B.y_k[0] = varargin_2[0];
  Flight_Controllers_PIL_B.x_cx[1] = varargin_1[1];
  Flight_Controllers_PIL_B.y_k[1] = varargin_2[1];
  Flight_Controllers_PIL_B.x_cx[2] = varargin_1[2];
  Flight_Controllers_PIL_B.y_k[2] = varargin_2[2];
  Flight_Controllers_PIL_B.x_cx[3] = varargin_1[3];
  Flight_Controllers_PIL_B.y_k[3] = varargin_2[3];
  Vq = (rtNaN);
  high_i = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (high_i < 4) {
      if (rtIsNaN(varargin_1[high_i])) {
        exitg1 = 1;
      } else {
        high_i++;
      }
    } else {
      real_T xtmp;
      if (varargin_1[1] < varargin_1[0]) {
        xtmp = Flight_Controllers_PIL_B.x_cx[0];
        Flight_Controllers_PIL_B.x_cx[0] = Flight_Controllers_PIL_B.x_cx[3];
        Flight_Controllers_PIL_B.x_cx[3] = xtmp;
        xtmp = Flight_Controllers_PIL_B.y_k[0];
        Flight_Controllers_PIL_B.y_k[0] = Flight_Controllers_PIL_B.y_k[3];
        Flight_Controllers_PIL_B.y_k[3] = xtmp;
        xtmp = Flight_Controllers_PIL_B.x_cx[1];
        Flight_Controllers_PIL_B.x_cx[1] = Flight_Controllers_PIL_B.x_cx[2];
        Flight_Controllers_PIL_B.x_cx[2] = xtmp;
        xtmp = Flight_Controllers_PIL_B.y_k[1];
        Flight_Controllers_PIL_B.y_k[1] = Flight_Controllers_PIL_B.y_k[2];
        Flight_Controllers_PIL_B.y_k[2] = xtmp;
      }

      if ((!rtIsNaN(varargin_3)) && (!(varargin_3 >
            Flight_Controllers_PIL_B.x_cx[3])) && (!(varargin_3 <
            Flight_Controllers_PIL_B.x_cx[0]))) {
        int32_T low_i;
        int32_T low_ip1;
        high_i = 4;
        low_i = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i + high_i) >> 1;
          if (varargin_3 >= Flight_Controllers_PIL_B.x_cx[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        xtmp = Flight_Controllers_PIL_B.x_cx[low_i - 1];
        xtmp = (varargin_3 - xtmp) / (Flight_Controllers_PIL_B.x_cx[low_i] -
          xtmp);
        if (xtmp == 0.0) {
          Vq = Flight_Controllers_PIL_B.y_k[low_i - 1];
        } else if (xtmp == 1.0) {
          Vq = Flight_Controllers_PIL_B.y_k[low_i];
        } else {
          Vq = Flight_Controllers_PIL_B.y_k[low_i - 1];
          if (!(Vq == Flight_Controllers_PIL_B.y_k[low_i])) {
            Vq = (1.0 - xtmp) * Vq + xtmp * Flight_Controllers_PIL_B.y_k[low_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

// Model step function
void Flight_Controllers_PIL_step(void)
{
  real_T rtb_FilterCoefficient_fv;
  real_T rtb_Negate34;
  real_T rtb_Sum8;
  int32_T exitg1;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;

  // MATLAB Function: '<Root>/Vertical_Controller' incorporates:
  //   Inport generated from: '<Root>/Sched_Vertical'
  //   Inport generated from: '<Root>/t'

  Flight_Controllers_PIL_Y.Controls_fire_Cmd = 0.0;
  Flight_Controllers_PIL_B.hErr = 0.0;
  Flight_Controllers_PIL_B.vErr = 0.0;
  Flight_Controllers_PIL_Y.VertMode = Flight_Controllers_PIL_interp1
    (&Flight_Controllers_PIL_U.Sched_Vertical[0],
     &Flight_Controllers_PIL_U.Sched_Vertical[10], Flight_Controllers_PIL_U.t);
  Flight_Controllers_PIL_B.vertCmd = Flight_Controllers_PIL_interp1
    (&Flight_Controllers_PIL_U.Sched_Vertical[0],
     &Flight_Controllers_PIL_U.Sched_Vertical[20], Flight_Controllers_PIL_U.t);

  // Outport generated from: '<Root>/Cntrl_telem' incorporates:
  //   MATLAB Function: '<Root>/Vertical_Controller'

  Flight_Controllers_PIL_Y.Cntrl_telem[4] = 0.0;
  Flight_Controllers_PIL_Y.Cntrl_telem[3] = 0.0;

  // MATLAB Function: '<Root>/Vertical_Controller' incorporates:
  //   Inport generated from: '<Root>/Bus Element In2'
  //   Inport generated from: '<Root>/Bus Element In1'
  //   Inport generated from: '<Root>/switchLines'

  if (Flight_Controllers_PIL_Y.VertMode == 1.0) {
    // Outport generated from: '<Root>/Cntrl_telem'
    Flight_Controllers_PIL_Y.Cntrl_telem[3] = Flight_Controllers_PIL_B.vertCmd;
    Flight_Controllers_PIL_Y.Cntrl_telem[4] = (rtNaN);
    Flight_Controllers_PIL_B.vErr = -Flight_Controllers_PIL_U.States_VzB -
      Flight_Controllers_PIL_B.vertCmd;
    if (Flight_Controllers_PIL_B.vErr < -0.1) {
      Flight_Controllers_PIL_Y.Controls_fire_Cmd = 1.0;
    } else if ((!(Flight_Controllers_PIL_B.vErr > 0.1)) &&
               (Flight_Controllers_PIL_DW.thr_previous > 0.0)) {
      Flight_Controllers_PIL_Y.Controls_fire_Cmd = 1.0;
    }
  } else if (Flight_Controllers_PIL_Y.VertMode == 2.0) {
    // Outport generated from: '<Root>/Cntrl_telem'
    Flight_Controllers_PIL_Y.Cntrl_telem[4] = Flight_Controllers_PIL_B.vertCmd;
    Flight_Controllers_PIL_Y.Cntrl_telem[3] = (rtNaN);
    Flight_Controllers_PIL_B.hErr = -Flight_Controllers_PIL_U.States_z -
      Flight_Controllers_PIL_B.vertCmd;
    Flight_Controllers_PIL_B.vErr = -Flight_Controllers_PIL_U.States_VzB;
    if (Flight_Controllers_PIL_B.hErr < Flight_Controllers_PIL_U.switchLines[0])
    {
      Flight_Controllers_PIL_B.hErr = Flight_Controllers_PIL_U.switchLines[0];
    }

    if (Flight_Controllers_PIL_B.hErr > Flight_Controllers_PIL_U.switchLines[3])
    {
      Flight_Controllers_PIL_B.hErr = Flight_Controllers_PIL_U.switchLines[3];
    }

    Flight_Controllers_PIL_B.dv[0] = Flight_Controllers_PIL_U.switchLines[0];
    Flight_Controllers_PIL_B.dv1[0] = Flight_Controllers_PIL_U.switchLines[8];
    Flight_Controllers_PIL_B.dv[1] = Flight_Controllers_PIL_U.switchLines[1];
    Flight_Controllers_PIL_B.dv1[1] = Flight_Controllers_PIL_U.switchLines[9];
    Flight_Controllers_PIL_B.dv[2] = Flight_Controllers_PIL_U.switchLines[2];
    Flight_Controllers_PIL_B.dv1[2] = Flight_Controllers_PIL_U.switchLines[10];
    Flight_Controllers_PIL_B.dv[3] = Flight_Controllers_PIL_U.switchLines[3];
    Flight_Controllers_PIL_B.dv1[3] = Flight_Controllers_PIL_U.switchLines[11];
    Flight_Controllers_PIL_B.vertCmd = Flight_Controllers_PIL_interpn
      (Flight_Controllers_PIL_B.dv, Flight_Controllers_PIL_B.dv1,
       Flight_Controllers_PIL_B.hErr);
    if (-Flight_Controllers_PIL_U.States_VzB < Flight_Controllers_PIL_B.vertCmd)
    {
      Flight_Controllers_PIL_Y.Controls_fire_Cmd = 1.0;
    } else {
      Flight_Controllers_PIL_B.dv[0] = Flight_Controllers_PIL_U.switchLines[4];
      Flight_Controllers_PIL_B.dv1[0] = Flight_Controllers_PIL_U.switchLines[12];
      Flight_Controllers_PIL_B.dv[1] = Flight_Controllers_PIL_U.switchLines[5];
      Flight_Controllers_PIL_B.dv1[1] = Flight_Controllers_PIL_U.switchLines[13];
      Flight_Controllers_PIL_B.dv[2] = Flight_Controllers_PIL_U.switchLines[6];
      Flight_Controllers_PIL_B.dv1[2] = Flight_Controllers_PIL_U.switchLines[14];
      Flight_Controllers_PIL_B.dv[3] = Flight_Controllers_PIL_U.switchLines[7];
      Flight_Controllers_PIL_B.dv1[3] = Flight_Controllers_PIL_U.switchLines[15];
      if ((-Flight_Controllers_PIL_U.States_VzB >
           Flight_Controllers_PIL_B.vertCmd) &&
          (-Flight_Controllers_PIL_U.States_VzB < Flight_Controllers_PIL_interpn
           (Flight_Controllers_PIL_B.dv, Flight_Controllers_PIL_B.dv1,
            Flight_Controllers_PIL_B.hErr))) {
        Flight_Controllers_PIL_Y.Controls_fire_Cmd =
          Flight_Controllers_PIL_DW.thr_previous;
      }
    }
  }

  // Outport generated from: '<Root>/Cntrl_telem' incorporates:
  //   Inport generated from: '<Root>/Bus Element In2'
  //   Inport generated from: '<Root>/Bus Element In1'
  //   Inport generated from: '<Root>/t'
  //   MATLAB Function: '<Root>/Vertical_Controller'

  Flight_Controllers_PIL_Y.Cntrl_telem[0] = Flight_Controllers_PIL_U.t;
  Flight_Controllers_PIL_Y.Cntrl_telem[1] = -Flight_Controllers_PIL_U.States_z;
  Flight_Controllers_PIL_Y.Cntrl_telem[2] = -Flight_Controllers_PIL_U.States_VzB;
  Flight_Controllers_PIL_Y.Cntrl_telem[5] = Flight_Controllers_PIL_B.hErr;
  Flight_Controllers_PIL_Y.Cntrl_telem[6] = Flight_Controllers_PIL_B.vErr;
  Flight_Controllers_PIL_Y.Cntrl_telem[7] =
    Flight_Controllers_PIL_DW.thr_previous;
  Flight_Controllers_PIL_Y.Cntrl_telem[8] =
    Flight_Controllers_PIL_Y.Controls_fire_Cmd;
  Flight_Controllers_PIL_Y.Cntrl_telem[9] = Flight_Controllers_PIL_Y.VertMode;

  // MATLAB Function: '<Root>/Vertical_Controller'
  Flight_Controllers_PIL_DW.thr_previous =
    Flight_Controllers_PIL_Y.Controls_fire_Cmd;

  // Sum: '<S3>/Sum5' incorporates:
  //   Constant: '<S3>/Y_intercept'
  //   Gain: '<S3>/Cosine_Loss'
  //   Gain: '<S3>/Gain'
  //   Gain: '<S3>/Gain1'
  //   Gain: '<S3>/Gain2'
  //   Gain: '<S3>/slope'
  //   Inport generated from: '<Root>/m'

  Flight_Controllers_PIL_B.Sum5 = 1.0 /
    Flight_Controllers_PIL_P.Cant_cosine_Loss *
    (Flight_Controllers_PIL_P.g_Offset * Flight_Controllers_PIL_U.m) *
    Flight_Controllers_PIL_P.g * (1.0 / Flight_Controllers_PIL_P.nFans) *
    Flight_Controllers_PIL_P.mOmega + Flight_Controllers_PIL_P.bOmega;

  // Sum: '<S3>/Sum6' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   Inport generated from: '<Root>/Bus Element In6'

  Flight_Controllers_PIL_B.hErr =
    Flight_Controllers_PIL_DW.DiscreteTimeIntegrator_DSTATE -
    Flight_Controllers_PIL_U.States_x;

  // Gain: '<S45>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S37>/Filter'
  //   Gain: '<S35>/Derivative Gain'
  //   Sum: '<S37>/SumD'

  Flight_Controllers_PIL_B.vErr = (Flight_Controllers_PIL_P.Kd_LatPos *
    Flight_Controllers_PIL_B.hErr - Flight_Controllers_PIL_DW.Filter_DSTATE) *
    Flight_Controllers_PIL_P.N_LatPos;

  // Sum: '<S3>/Sum4' incorporates:
  //   DiscreteIntegrator: '<S42>/Integrator'
  //   Gain: '<S47>/Proportional Gain'
  //   Inport generated from: '<Root>/Bus Element In7'
  //   Sum: '<S51>/Sum'

  Flight_Controllers_PIL_B.vertCmd = ((Flight_Controllers_PIL_P.Kp_LatPos *
    Flight_Controllers_PIL_B.hErr + Flight_Controllers_PIL_DW.Integrator_DSTATE)
    + Flight_Controllers_PIL_B.vErr) - Flight_Controllers_PIL_U.States_VxE;

  // Gain: '<S95>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S87>/Filter'
  //   Gain: '<S85>/Derivative Gain'
  //   Sum: '<S87>/SumD'

  Flight_Controllers_PIL_B.FilterCoefficient_i =
    (Flight_Controllers_PIL_P.Kd_LatVel * Flight_Controllers_PIL_B.vertCmd -
     Flight_Controllers_PIL_DW.Filter_DSTATE_a) *
    Flight_Controllers_PIL_P.N_LatVel;

  // Sum: '<S3>/Sum8' incorporates:
  //   DiscreteIntegrator: '<S92>/Integrator'
  //   Gain: '<S97>/Proportional Gain'
  //   Inport generated from: '<Root>/Bus Element In9'
  //   Sum: '<S101>/Sum'

  rtb_Sum8 = ((Flight_Controllers_PIL_P.Kp_LatVel *
               Flight_Controllers_PIL_B.vertCmd +
               Flight_Controllers_PIL_DW.Integrator_DSTATE_e) +
              Flight_Controllers_PIL_B.FilterCoefficient_i) -
    Flight_Controllers_PIL_U.States_Theta;

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'
  //   Gain: '<S135>/Derivative Gain'
  //   Sum: '<S137>/SumD'

  rtb_FilterCoefficient_fv = (Flight_Controllers_PIL_P.Kd_Pitch * rtb_Sum8 -
    Flight_Controllers_PIL_DW.Filter_DSTATE_k) *
    Flight_Controllers_PIL_P.N_Pitch;

  // Gain: '<S3>/Spread_Out' incorporates:
  //   DiscreteIntegrator: '<S142>/Integrator'
  //   Gain: '<S147>/Proportional Gain'
  //   Sum: '<S151>/Sum'

  rtb_Negate34 = ((Flight_Controllers_PIL_P.Kp_Pitch * rtb_Sum8 +
                   Flight_Controllers_PIL_DW.Integrator_DSTATE_i) +
                  rtb_FilterCoefficient_fv) * (1.0 /
    Flight_Controllers_PIL_P.nFans);

  // Sum: '<S3>/Sum1' incorporates:
  //   Sum: '<S3>/Sum'

  Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1 = Flight_Controllers_PIL_B.Sum5
    + rtb_Negate34;

  // Sum: '<S3>/Sum2' incorporates:
  //   Gain: '<S3>/Negate34'
  //   Sum: '<S3>/Sum3'

  Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3 =
    Flight_Controllers_PIL_P.Negate34_Gain * rtb_Negate34 +
    Flight_Controllers_PIL_B.Sum5;

  // BusCreator generated from: '<Root>/MotorCmds' incorporates:
  //   Outport generated from: '<Root>/MotorCmds'
  //   Sum: '<S3>/Sum1'
  //   Sum: '<S3>/Sum2'

  Flight_Controllers_PIL_Y.MotorCmds.M1 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1;
  Flight_Controllers_PIL_Y.MotorCmds.M2 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1;
  Flight_Controllers_PIL_Y.MotorCmds.M3 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3;
  Flight_Controllers_PIL_Y.MotorCmds.M4 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3;

  // DigitalClock: '<S3>/Digital Clock'
  Flight_Controllers_PIL_B.Sum5 = ((Flight_Controllers_PIL_M->Timing.clockTick0)
    * 0.02);

  // MATLAB Function: '<S3>/Lateral_Flight_Plan' incorporates:
  //   Inport generated from: '<Root>/Sched_Lateral'

  memcpy(&Flight_Controllers_PIL_B.x[0],
         &Flight_Controllers_PIL_U.Sched_Lateral[0], 10U * sizeof(real_T));
  memcpy(&Flight_Controllers_PIL_B.y[0],
         &Flight_Controllers_PIL_U.Sched_Lateral[20], 10U * sizeof(real_T));
  Flight_Controllers_PIL_Y.Controls_xCmd = (rtNaN);
  high_i = 0;
  do {
    exitg1 = 0;
    if (high_i < 10) {
      if (rtIsNaN(Flight_Controllers_PIL_U.Sched_Lateral[high_i])) {
        exitg1 = 1;
      } else {
        high_i++;
      }
    } else {
      if (Flight_Controllers_PIL_U.Sched_Lateral[1] <
          Flight_Controllers_PIL_U.Sched_Lateral[0]) {
        for (high_i = 0; high_i < 5; high_i++) {
          rtb_Negate34 = Flight_Controllers_PIL_B.x[high_i];
          Flight_Controllers_PIL_B.x[high_i] = Flight_Controllers_PIL_B.x[9 -
            high_i];
          Flight_Controllers_PIL_B.x[9 - high_i] = rtb_Negate34;
        }

        memcpy(&Flight_Controllers_PIL_B.y[0],
               &Flight_Controllers_PIL_U.Sched_Lateral[20], 10U * sizeof(real_T));
        for (high_i = 0; high_i < 5; high_i++) {
          rtb_Negate34 = Flight_Controllers_PIL_B.y[high_i];
          Flight_Controllers_PIL_B.y[high_i] = Flight_Controllers_PIL_B.y[9 -
            high_i];
          Flight_Controllers_PIL_B.y[9 - high_i] = rtb_Negate34;
        }
      }

      if ((!rtIsNaN(Flight_Controllers_PIL_B.Sum5)) &&
          (!(Flight_Controllers_PIL_B.Sum5 > Flight_Controllers_PIL_B.x[9])) &&
          (!(Flight_Controllers_PIL_B.Sum5 < Flight_Controllers_PIL_B.x[0]))) {
        high_i = 10;
        low_i = 1;
        low_ip1 = 2;
        while (high_i > low_ip1) {
          mid_i = (low_i + high_i) >> 1;
          if (Flight_Controllers_PIL_B.Sum5 >= Flight_Controllers_PIL_B.x[mid_i
              - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        rtb_Negate34 = Flight_Controllers_PIL_B.x[low_i - 1];
        Flight_Controllers_PIL_B.Sum5 = (Flight_Controllers_PIL_B.Sum5 -
          rtb_Negate34) / (Flight_Controllers_PIL_B.x[low_i] - rtb_Negate34);
        if (Flight_Controllers_PIL_B.Sum5 == 0.0) {
          Flight_Controllers_PIL_Y.Controls_xCmd =
            Flight_Controllers_PIL_B.y[low_i - 1];
        } else if (Flight_Controllers_PIL_B.Sum5 == 1.0) {
          Flight_Controllers_PIL_Y.Controls_xCmd =
            Flight_Controllers_PIL_B.y[low_i];
        } else {
          Flight_Controllers_PIL_Y.Controls_xCmd =
            Flight_Controllers_PIL_B.y[low_i - 1];
          if (!(Flight_Controllers_PIL_Y.Controls_xCmd ==
                Flight_Controllers_PIL_B.y[low_i])) {
            Flight_Controllers_PIL_Y.Controls_xCmd = (1.0 -
              Flight_Controllers_PIL_B.Sum5) *
              Flight_Controllers_PIL_Y.Controls_xCmd +
              Flight_Controllers_PIL_B.Sum5 * Flight_Controllers_PIL_B.y[low_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S4>/1_over_tau'
  //   Sum: '<S4>/Sum6'

  Flight_Controllers_PIL_DW.DiscreteTimeIntegrator_DSTATE += 1.0 /
    Flight_Controllers_PIL_P.tau_vCmd * (Flight_Controllers_PIL_Y.Controls_xCmd
    - Flight_Controllers_PIL_DW.DiscreteTimeIntegrator_DSTATE) *
    Flight_Controllers_PIL_P.DiscreteTimeIntegrator_gainval;

  // Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
  //   Gain: '<S39>/Integral Gain'

  Flight_Controllers_PIL_DW.Integrator_DSTATE +=
    Flight_Controllers_PIL_P.Ki_LatPos * Flight_Controllers_PIL_B.hErr *
    Flight_Controllers_PIL_P.Integrator_gainval;

  // Update for DiscreteIntegrator: '<S37>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE +=
    Flight_Controllers_PIL_P.Filter_gainval * Flight_Controllers_PIL_B.vErr;

  // Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
  //   Gain: '<S89>/Integral Gain'

  Flight_Controllers_PIL_DW.Integrator_DSTATE_e +=
    Flight_Controllers_PIL_P.Ki_LatVel * Flight_Controllers_PIL_B.vertCmd *
    Flight_Controllers_PIL_P.Integrator_gainval_g;

  // Update for DiscreteIntegrator: '<S87>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE_a +=
    Flight_Controllers_PIL_P.Filter_gainval_d *
    Flight_Controllers_PIL_B.FilterCoefficient_i;

  // Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
  //   Gain: '<S139>/Integral Gain'

  Flight_Controllers_PIL_DW.Integrator_DSTATE_i +=
    Flight_Controllers_PIL_P.Ki_Pitch * rtb_Sum8 *
    Flight_Controllers_PIL_P.Integrator_gainval_c;

  // Update for DiscreteIntegrator: '<S137>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE_k +=
    Flight_Controllers_PIL_P.Filter_gainval_i * rtb_FilterCoefficient_fv;

  // Outport generated from: '<Root>/Out Bus Element3' incorporates:
  //   Constant: '<S3>/Constant'

  Flight_Controllers_PIL_Y.Controls_yCmd =
    Flight_Controllers_PIL_P.Constant_Value;

  // Outport generated from: '<Root>/Controls_Outport_4'
  Flight_Controllers_PIL_Y.Controls_OmegaCmds_M2 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1;

  // Outport generated from: '<Root>/Controls_Outport_4'
  Flight_Controllers_PIL_Y.Controls_OmegaCmds_M4 =
    Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3;

  // Outport generated from: '<Root>/fireCmd' incorporates:
  //   MATLAB Function: '<Root>/Vertical_Controller'

  Flight_Controllers_PIL_Y.fireCmd = Flight_Controllers_PIL_Y.Controls_fire_Cmd;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.02, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Flight_Controllers_PIL_M->Timing.clockTick0++;
}

// Model initialize function
void Flight_Controllers_PIL_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
  Flight_Controllers_PIL_DW.DiscreteTimeIntegrator_DSTATE =
    Flight_Controllers_PIL_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S42>/Integrator'
  Flight_Controllers_PIL_DW.Integrator_DSTATE =
    Flight_Controllers_PIL_P.Lat_Position_PID_InitialCondi_l;

  // InitializeConditions for DiscreteIntegrator: '<S37>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE =
    Flight_Controllers_PIL_P.Lat_Position_PID_InitialConditi;

  // InitializeConditions for DiscreteIntegrator: '<S92>/Integrator'
  Flight_Controllers_PIL_DW.Integrator_DSTATE_e =
    Flight_Controllers_PIL_P.Lat_Vel_Control_InitialCondit_k;

  // InitializeConditions for DiscreteIntegrator: '<S87>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE_a =
    Flight_Controllers_PIL_P.Lat_Vel_Control_InitialConditio;

  // InitializeConditions for DiscreteIntegrator: '<S142>/Integrator'
  Flight_Controllers_PIL_DW.Integrator_DSTATE_i =
    Flight_Controllers_PIL_P.Pitch_Controller_InitialCondi_k;

  // InitializeConditions for DiscreteIntegrator: '<S137>/Filter'
  Flight_Controllers_PIL_DW.Filter_DSTATE_k =
    Flight_Controllers_PIL_P.Pitch_Controller_InitialConditi;
}

// Model terminate function
void Flight_Controllers_PIL_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
