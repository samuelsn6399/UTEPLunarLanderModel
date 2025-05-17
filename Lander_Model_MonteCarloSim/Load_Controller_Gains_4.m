%  Load_Controller_Gains_4.m     Gains (Kp, Ki & Kd) for the PID Controllers
%     This set of gains (version 4) is for the variant with a Pitch inner
%     loop, a Velocity middle loop, and a Position outer loop (Triple Cascade Control).
%     Sam's Solution

% Pitch Controller
Kp_Pitch = 43.7;
Ki_Pitch = 3.17;
Kd_Pitch = 78.1;
N_Pitch = 1115;
% BW = 6.67 rad/s = 1.06 Hz NOT UPDATED
pitch_Cmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command

% LatVel Controller
Kp_LatVel = -0.291;
Ki_LatVel = 0;
Kd_LatVel = 0;
N_LatVel = 0;
% BW = 6.67 rad/s = 1.06 Hz NOT UPDATED
velCmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command

% LatPos Control
Kp_LatPos = 0.413;
Ki_LatPos = 0;  
Kd_LatPos = 0;
N_LatPos = 0;
% BW = 1.73 rad/s = 0.276 Hz NOT UPDATED

tau_vCmd = 0.1;   % sec   Filter the xCmd  
