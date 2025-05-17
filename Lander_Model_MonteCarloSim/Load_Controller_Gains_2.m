%  Load_Controller_Gains_2.m     Gains (Kp, Ki & Kd) for the PID Controllers
%     This set of gains (version 2) is for the variant where velocity
%     control is an inner loop to an outer position control loop.  Velocity
%     is "controlled" with a limit placed on the velocity command from the
%     position controller.

% Pitch Controller  (Same gains as in the version 1 variant)
   % Kp_Pitch = 5.36;    % Proportional Gain    Inner Loop Pitch Controller
   % Kd_Pitch = 14.4;    % Derivative Gain
   % N_Pitch = 18.2;     % Derivative Filter N 

   Kp_Pitch = 24.8;    % Proportional Gain    Inner Loop Pitch Controller
   Kd_Pitch = 33;    % Derivative Gain
   N_Pitch = 109;     % Derivative Filter N 
   pitch_Cmd_Limit = 6*pi/180; % radians    Limit placed on the Pitch Command


%  LatVel PI Control Gains
    % Kp_LatVel = -0.102;     Ki_LatVel = -0.038976;
    Kp_LatVel = -0.059;     Ki_LatVel = -0.0122;


%   LatPos PID Control Gains
    % Kp_LatPos = 0.5435;
    % Ki_LatPos = 0.06212;
    % Kd_LatPos = 0.3754;

    % Kp_LatPos = 0.182;   Ki_LatPos = 0.0068;  Kd_LatPos = -0.1348;  N_LatPos = 0.42;
    % Kp_LatPos = 1*0.174;   Ki_LatPos = 1*0.0183;  Kd_LatPos = 0;  N_LatPos = 0.42;
    
    % For the 2DOF PID Controller
    Kp_LatPos = 1.53;   Ki_LatPos = 0.0199;  Kd_LatPos = 0.642;  N_LatPos = 15.8;  b_LatPos = 0.005;  c_LatPos = 0.0133;



    vCmd_Integr_Limit = 0.25; % m   Limit the Integral component of the 
                %  Velocity Command out of the Postion Controller

    velCmd_Limit = 2; % m/s   The Limit placed on the velocity command coming
                      %            out of the Lateral Position controller.
                      %    This should come from "vLim" in the Flight Plan.
    tau_LatPos = 0.01; % sec   Time Constant for filter on the output of this PID Controller  
    tau_vCmd = 0.01;   % sec   Filter the xCmd  
