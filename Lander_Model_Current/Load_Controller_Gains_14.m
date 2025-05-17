%  Load_Controller_Gains_14.m     Gains (Kp, Ki & Kd) for the PID Controllers
%     This set of gains (version 14) is for the discrete variant with a Pitch inner
%     loop, a Velocity middle loop, and a Position outer loop (Triple Cascade Control).
%     Sam's Solution

%% Pitch Controller
pitch_Cmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command

% Kp_Pitch = 10.2894809952795;
% Ki_Pitch = 0.991589588406881;
% Kd_Pitch = 23.8131803392969;
% N_Pitch = 77.3994433194139;

Kp_Pitch = 16;
Ki_Pitch = 0.65;
Kd_Pitch = 41.5;
N_Pitch = 85.6;

%% LatVel Controller
velCmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command

% Kp_LatVel = -0.307192948493179;
% Ki_LatVel = 0;
% Kd_LatVel = 0;
% N_LatVel = 0;

% Kp_LatVel = -0.2;
% Ki_LatVel = 0;
% Kd_LatVel = 0;
% N_LatVel = 0;

Kp_LatVel = -0.3;
Ki_LatVel = 0;
Kd_LatVel = 0;
N_LatVel = 0;

%% LatPos Control
tau_vCmd = 0.1;   % sec   Filter the xCmd  

% Kp_LatPos = 0.417765176087918;
% Ki_LatPos = 0;  
% Kd_LatPos = 0;
% N_LatPos = 0;

% Kp_LatPos = 0.417765176087918;
% Ki_LatPos = 0;  
% Kd_LatPos = 0;
% N_LatPos = 0;

Kp_LatPos = 0.4;
Ki_LatPos = 0;  
Kd_LatPos = 0;
N_LatPos = 0;