%  Load_Controller_Gains_1.m     Gains (Kp, Ki & Kd) for the PID Controllers

%     This set of gains (version 1) is for the variant where velocity
%     control and position control are seperate.  The velocity control is
%     not an inner loop to the positon control as it is in version 2.

% Pitch Controller
   Kp_Pitch = 5.36;    % Proportional Gain    Inner Loop Pitch Controller
   Kd_Pitch = 14.4;    % Derivative Gain
   N_Pitch = 18.2;     % Derivative Filter N 


% Lateral Velocity Controller
   Kp_LatVel = -0.0296;  % Proportional Gain
   Ki_LatVel = -0.00284; % Integral Gain


% Lateral Position Controller
   % Kp_LatPos = -0.00942;  % Proportional Gain
   % Ki_LatPos = -0.00031;  % Integral Gain
   % Kd_LatPos = -0.0717;   % Derivative Gain
   % N_LatPos = 86.13;      % Derivative Filter N  (1/s)

   Kp_LatPos = -0.0024;    % Proportional Gain
   Ki_LatPos = -9.22e-6;  % Integral Gain
   Kd_LatPos = -0.04577;   % Derivative Gain
   N_LatPos = 54.3;        % Derivative Filter N  (1/s)
   tau_LatPos = 0.2; % sec   Time Constant for filter on the output of this PID Controller
