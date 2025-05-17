//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ColdGas_GNC_Model_PIL_data.cpp
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

// Model block global parameters (default storage)
real_T rtP_Aero_Forces_On = 1.0;       // Variable: Aero_Forces_On
                                          //  Referenced by:
                                          //    '<Root>/Aero_OnOff2'
                                          //    '<Root>/Aero_OnOff3'

real_T rtP_CE_Direction[3] = { 0.0, 0.0, -1.0 } ;// Variable: CE_Direction
                                                    //  Referenced by: '<S13>/CE_Orientation'


real_T rtP_CE_ISP = 40.0;              // Variable: CE_ISP
                                          //  Referenced by: '<S13>/ISP'

real_T rtP_CE_Location[3] = { 0.0, 0.0, 0.0 } ;// Variable: CE_Location
                                                  //  Referenced by: '<S13>/CE_Loc_Vector'


real_T rtP_CE_Thrust = 132.0;          // Variable: CE_Thrust
                                          //  Referenced by: '<S13>/CE_Rated_Thrust'

real_T rtP_CE_tDelay = 0.03;           // Variable: CE_tDelay
                                          //  Referenced by: '<S13>/Transport Delay'

real_T rtP_CE_tau = 0.1;               // Variable: CE_tau
                                          //  Referenced by: '<S13>/one_over_tau'

real_T rtP_Cant_cosine_Loss = 0.96592582628906831;// Variable: Cant_cosine_Loss
                                                     //  Referenced by: '<Root>/FCS'

real_T rtP_Cd = 1.2;                   // Variable: Cd
                                          //  Referenced by: '<S1>/Drag_Coeff'

real_T rtP_Fan_den[3] = { 1.0, 70.7, 2500.0 } ;// Variable: Fan_den
                                                  //  Referenced by:
                                                  //    '<S16>/Motor_TF1'
                                                  //    '<S16>/Motor_TF2'
                                                  //    '<S16>/Motor_TF3'
                                                  //    '<S16>/Motor_TF4'


real_T rtP_Fan_num = 2500.0;           // Variable: Fan_num
                                          //  Referenced by:
                                          //    '<S16>/Motor_TF1'
                                          //    '<S16>/Motor_TF2'
                                          //    '<S16>/Motor_TF3'
                                          //    '<S16>/Motor_TF4'

real_T rtP_FlightPlan_Lateral[40] = { 0.0, 1.0, 11.0, 12.0, 13.0, 22.0, 29.4,
  29.6, 29.8, 30.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0,
  20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
  5.0, 5.0, 5.0, 5.0 } ;               // Variable: FlightPlan_Lateral
                                          //  Referenced by: '<Root>/Constant'


real_T rtP_FlightPlan_Vertical[30] = { 0.0, 3.0, 3.01, 17.0, 29.0, 29.2, 29.4,
  29.6, 29.8, 30.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
  3.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 } ;// Variable: FlightPlan_Vertical
                                                      //  Referenced by: '<Root>/Vertical_FlightPlan'


real_T rtP_Kd_LatPos = 0.0;            // Variable: Kd_LatPos
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Kd_LatVel = 0.0;            // Variable: Kd_LatVel
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Kd_Pitch = 41.5;            // Variable: Kd_Pitch
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Ki_LatPos = 0.0;            // Variable: Ki_LatPos
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Ki_LatVel = 0.0;            // Variable: Ki_LatVel
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Ki_Pitch = 0.65;            // Variable: Ki_Pitch
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Kp_LatPos = 0.4;            // Variable: Kp_LatPos
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Kp_LatVel = -0.3;           // Variable: Kp_LatVel
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Kp_Pitch = 16.0;            // Variable: Kp_Pitch
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Lref = 0.6096;              // Variable: Lref
                                          //  Referenced by: '<S1>/Ref. Length (m)'

real_T rtP_N_LatPos = 0.0;             // Variable: N_LatPos
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_N_LatVel = 0.0;             // Variable: N_LatVel
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_N_Pitch = 85.6;             // Variable: N_Pitch
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_Psi_Angle_deg = 5.0;        // Variable: Psi_Angle_deg
                                          //  Referenced by: '<Root>/Yaw_deg1'

real_T rtP_Sref = 0.37161216;          // Variable: Sref
                                          //  Referenced by: '<S1>/Reference Area'

real_T rtP_bOmega = 168.96383979244365;// Variable: bOmega
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_fan_thrust_Poly[3] = { 0.0009987, -0.04316, 4.44 } ;// Variable: fan_thrust_Poly
                                                                  //  Referenced by:
                                                                  //    '<S16>/Fan_Thrust_Polynomial1'
                                                                  //    '<S16>/Fan_Thrust_Polynomial2'
                                                                  //    '<S16>/Fan_Thrust_Polynomial3'
                                                                  //    '<S16>/Fan_Thrust_Polynomial4'


real_T rtP_g = 9.807;                  // Variable: g
                                          //  Referenced by:
                                          //    '<Root>/FCS'
                                          //    '<S5>/g_neg'
                                          //    '<S5>/g_negated'
                                          //    '<S13>/g_Earth'

real_T rtP_g_Offset = 0.83333333333333337;// Variable: g_Offset
                                             //  Referenced by: '<Root>/FCS'

real_T rtP_gustDuration = 10.0;        // Variable: gustDuration
                                          //  Referenced by: '<S1>/Constant5'

real_T rtP_gustFactor = 1.4;           // Variable: gustFactor
                                          //  Referenced by: '<S1>/Constant4'

real_T rtP_hFinal = 0.28;              // Variable: hFinal
                                          //  Referenced by: '<S7>/Stop_Altitude'

real_T rtP_mOmega = 1.6215339711366952;// Variable: mOmega
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_massInitial = 47.600000000000009;// Variable: massInitial
                                               //  Referenced by: '<Root>/Initial_mass'

real_T rtP_nFans = 4.0;                // Variable: nFans
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_q0 = 0.0;                   // Variable: q0
                                          //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

real_T rtP_rho_air = 1.2;              // Variable: rho_air
                                          //  Referenced by: '<S8>/Air Density (kg//m^3)'

real_T rtP_switchLines[16] = { -3.1500000000000004, -2.0621320343559644,
  1.9378679656440356, 3.1500000000000004, -3.1500000000000004,
  -1.9378679656440356, 2.0, 3.1500000000000004, 1.8900000000000001,
  1.8900000000000001, -2.11, -2.11, 2.19, 2.19, -1.81, -1.81 } ;// Variable: switchLines
                                                                   //  Referenced by: '<Root>/SwitchLines'


real_T rtP_tGust_End = 15.0;           // Variable: tGust_End
                                          //  Referenced by: '<S1>/Constant3'

real_T rtP_tGust_Start = 5.0;          // Variable: tGust_Start
                                          //  Referenced by: '<S1>/Constant2'

real_T rtP_t_Liftoff_Achieved = 1.0;   // Variable: t_Liftoff_Achieved
                                          //  Referenced by: '<S5>/Constant'

real_T rtP_tau_AlgLoop = 0.01;         // Variable: tau_AlgLoop
                                          //  Referenced by: '<S9>/one_over_tau'

real_T rtP_tau_vCmd = 0.1;             // Variable: tau_vCmd
                                          //  Referenced by: '<Root>/FCS'

real_T rtP_theta0 = 0.0;               // Variable: theta0
                                          //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

real_T rtP_windSpeed = 4.115552;       // Variable: windSpeed
                                          //  Referenced by: '<Root>/windSP_mPerSec'

real_T rtP_wind_angle = 0.0;           // Variable: wind_angle
                                          //  Referenced by: '<Root>/Wind_Angle_rad1'

boolean_T rtP_LandNowFlag = false;     // Variable: LandNowFlag
                                          //  Referenced by: '<Root>/Emergency'


// Block parameters (default storage)
P_ColdGas_GNC_Model_PIL_T ColdGas_GNC_Model_PIL_P = {
  // Expression: 0
  //  Referenced by: '<S13>/Int_mDot'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/Int_Descent'

  0.0,

  // Expression: uvFans(1,:)
  //  Referenced by: '<S17>/Unit_Vector_1'

  { -0.183, 0.183, -0.9659 },

  // Expression: uvFans(2,:)
  //  Referenced by: '<S17>/Unit_Vector_2'

  { -0.183, -0.183, -0.9659 },

  // Expression: uvFans(3,:)
  //  Referenced by: '<S17>/Unit_Vector_3'

  { 0.183, -0.183, -0.9659 },

  // Expression: uvFans(4,:)
  //  Referenced by: '<S17>/Unit_Vector_4'

  { 0.183, 0.183, -0.9659 },

  // Expression: 0.5
  //  Referenced by: '<S8>/Const'

  0.5,

  // Expression: 0
  //  Referenced by: '<S9>/Int_LP'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/Z_Wind'

  0.0,

  // Expression: rFans(1,:)
  //  Referenced by: '<S17>/rFan1'

  { 0.6605, -0.6605, -0.1146 },

  // Expression: rFans(2,:)
  //  Referenced by: '<S17>/rFan2'

  { 0.6605, 0.6605, -0.1146 },

  // Expression: rFans(3,:)
  //  Referenced by: '<S17>/rFan3'

  { -0.6605, 0.6605, -0.1146 },

  // Expression: rFans(4,:)
  //  Referenced by: '<S17>/rFan4'

  { -0.6605, -0.6605, -0.1146 },

  // Expression: Cm_Lookup(:,2)
  //  Referenced by: '<S10>/Cm Lookup Table (n-D)'

  { -0.26986863531386857, -0.26764625698643757, -0.25310679328018948,
    -0.23844866668570147, -0.22667277801753075, -0.21350866156422604,
    -0.19548436926154214, -0.18018674094110085, -0.16320093696063889,
    -0.16115519490270205, -0.1571187009696943, -0.15785593680762677,
    -0.14685934462387409, -0.12880264834587996, -0.1129542206406865,
    -0.10012996930591377, -0.0822384472338743, -0.054283134239841151,
    -0.027340130874640066, -0.0075097141355432544, 0.020901238101673946,
    0.033172831549444573, 0.050523503182245889, 0.061977428288881531,
    0.072403711496058523, 0.095459847588065541, 0.12102414439423859,
    0.14781025250890259, 0.169561675331169, 0.18094142108644065,
    0.18795332482471661, 0.20506202262687978, 0.21841810414357826,
    0.23178808376620286, 0.25003604319866279, 0.25597789995544268,
    0.26301106810513958, 0.25855565627352084, 0.257195770837681,
    0.24862353331295348, 0.24184111604359168, 0.25088919602963328,
    0.24406500767165237, 0.24156940248429126, 0.22695650217462618,
    0.21414728491444562, 0.20735192534938909, 0.19002596409479294,
    0.17505428205564511, 0.15945657519142115, 0.15114447272471834,
    0.13993892562617719, 0.12384334694816854, 0.10652050308508847,
    0.078763954113516943, 0.052779266323781146, 0.022477963250772365,
    -0.0029777644379947233, -0.021462270689679944, -0.034751410427200487,
    -0.061789286762297793, -0.091015662765584246, -0.11767174801299098,
    -0.13984040060110053, -0.16040806676773339, -0.1819242466405146,
    -0.19878318454890045, -0.22898628587991135, -0.2499776742374043,
    -0.255841107498169, -0.25830903175089609, -0.264288550293369,
    -0.26695204443066417 },

  // Expression: Cm_Lookup(:,1)
  //  Referenced by: '<S10>/Cm Lookup Table (n-D)'

  { -180.0, -175.0, -170.0, -165.0, -160.0, -155.0, -150.0, -145.0, -140.0,
    -135.0, -130.0, -125.0, -120.0, -115.0, -110.0, -105.0, -100.0, -95.0, -90.0,
    -85.0, -80.0, -75.0, -70.0, -65.0, -60.0, -55.0, -50.0, -45.0, -40.0, -35.0,
    -30.0, -25.0, -20.0, -15.0, -10.0, -5.0, 0.0, 5.0, 10.0, 15.0, 20.0, 25.0,
    30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0,
    95.0, 100.0, 105.0, 110.0, 115.0, 120.0, 125.0, 130.0, 135.0, 140.0, 145.0,
    150.0, 155.0, 160.0, 165.0, 170.0, 175.0, 180.0 },

  // Expression: 0
  //  Referenced by: '<Root>/dI'

  0.0,

  // Expression: I(2, 2)
  //  Referenced by: '<Root>/Iyy'

  12.0,

  // Expression: 0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  0.0,

  // Expression: [x0 z0]
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  { 0.0, -0.3 },

  // Expression: 1.0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  0.5,

  // Expression: 3.0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  3.0,

  // Expression: 1.0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  0.5,

  // Expression: 3.0
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  3.0,

  // Expression: 9.81
  //  Referenced by: '<Root>/Custom Variable Mass 3dof (Body Axes)'

  9.81,

  // Expression: 0
  //  Referenced by: '<S3>/Const'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Const1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Const3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Const4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Const2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/Transport Delay'

  0.0,

  // Expression: -1
  //  Referenced by: '<S7>/Gain'

  -1.0
};

//
// File trailer for generated code.
//
// [EOF]
//
