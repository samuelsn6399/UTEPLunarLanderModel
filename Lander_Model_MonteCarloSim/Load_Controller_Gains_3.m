%  Load_Controller_Gains_3.m     Gains (Kp, Ki & Kd) for the PID Controllers
%     This set of gains (version 2) is for the variant with a Pitch inner
%     loop and a Position outer loop (Cascade Control with one inner loop).
%     Velocity is controlled indirectly by the design of the postion
%         command input.

% Pitch Controller  (Same gains as in the version 1 variant)
   % Kp_Pitch = 5.36;    % Proportional Gain    Inner Loop Pitch Controller
   % Kd_Pitch = 14.4;    % Derivative Gain
   % N_Pitch = 18.2;     % Derivative Filter N 

   % Kp_Pitch = 24.8;    % Proportional Gain    Inner Loop Pitch Controller
   % Kd_Pitch = 33;    % Derivative Gain
   % N_Pitch = 109;     % Derivative Filter N 

    Kp_Pitch = 38;     Kd_Pitch = 40;     N_Pitch = 550;    %   BW = 6.67 rad/s  =  1.06 Hz

   pitch_Cmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command



%   LatPos PID Control Gains
    %  PD Controller
    % Kp_LatPos = -0.0284*1.5;   Ki_LatPos = 0;  Kd_LatPos = -0.182*1;  N_LatPos = 204;   % BW = 3.18 rad/s = 0.506 Hz
     % Kp_LatPos = -0.0163*1.5;   Ki_LatPos = 0;  Kd_LatPos = -0.0984*1;  N_LatPos = 11.5;   % BW = 0.992 rad/s = 0.157 Hz
     Kp_LatPos = -0.0175*1;   Ki_LatPos = 0;  Kd_LatPos = -0.103;  N_LatPos = 12;   % BW = 1.73 rad/s = 0.276 Hz
    tau_xCmd = 0.005; % sec   Time constant for the position command filter

  tau_xCmd = 0.2



    % tau_LatPos = 0.01; % sec   Time Constant for filter on the output of this PID Controller  
    % tau_vCmd = 0.01;   % sec   Filter the xCmd  
