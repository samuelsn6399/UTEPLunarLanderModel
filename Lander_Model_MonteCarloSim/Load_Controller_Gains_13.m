%  Load_Controller_Gains_13.m      Discretize the Continuous  PID Gains and create a discrete
%                           controller (PID, PD, Pi, etc ...)
%
%      This gain set (13) is a discrete version of continuous gain set (3).   
%      Get the continuous gains from  "Load_Controller_Gains_3.m"
%
%     This set of gains (version 2) is for the variant with a Pitch inner
%     loop and a Position outer loop (Cascade Control with one inner loop).
%     Velocity is controlled indirectly by the design of the postion
%         command input.

s = tf('s');  % LaPlace Operator
 pitch_Cmd_Limit = 7*pi/180; % radians    Limit placed on the Pitch Command


%%  Inner Loop Pitch PD Controller
%  These continuous gains come from  "Load_Controller_Gains_3.m"
% disp(' '), disp(' '),  disp('---------   Pitch Controller   ----')
Kp_Pitch = 38;     Kd_Pitch = 40;     N_Pitch = 550;    %   BW = 6.67 rad/s  =  1.06 Hz

Gc = ( (Kp_Pitch + N_Pitch*Kd_Pitch)*s + N_Pitch*Kp_Pitch ) / (s + N_Pitch);  % TF of a PD
    [numGc, denGc] = tfdata(Gc, 'v');    %   damp(Gc)        [z, p, k] = zpkdata(Gc, 'v')
                                                       %      figure(8), clf,  pzmap(Gc)

Gc_z_Pitch = c2d(Gc, T,  'tustin');      %     'zoh'    'tustin'                               Pitch Controller
    [num_Gc_z_Pitch, den_Gc_z_Pitch] = tfdata(Gc_z_Pitch, 'v');

% figure(16), clf,  bode(Gc, Gc_z_Pitch), grid
%       legend('Gc(s)',  'Gc(z)')
% 
% figure(17),   clf,    step(Gc, [0  2]),  hold on,   step(Gc_z_Pitch, [0  2]),   hold off,  grid




%%  Outer Loop Position PD Controller
%  These continuous gains come from  "Load_Controller_Gains_3.m"
% disp(' '), disp(' '),  disp('---------   Position Controller   ----')
                % Kp_LatPos = -0.0175*1;   Ki_LatPos = 0;  Kd_LatPos = -0.103;  N_LatPos = 12;   % BW = 1.73 rad/s = 0.276 Hz
                % 
                % Gc = ( (Kp_LatPos + N_LatPos*Kd_LatPos)*s + N_LatPos*Kp_LatPos) / (s + N_LatPos);  % TF of a PD
                %     [numGc, denGc] = tfdata(Gc, 'v');    %   damp(Gc)        [z, p, k] = zpkdata(Gc, 'v')
                %                                                        %      figure(8), clf,  pzmap(Gc)
                % 
                % Gc_z_Pos = c2d(Gc, T,  'tustin');      %     'zoh'    'tustin'                              Position Controller
                %     [num_Gc_z_Pos, den_Gc_z_Pos] = tfdata(Gc_z_Pos, 'v');



%    *****  Add an Integral term (Ki) to the original PD Controller   *****
% Kp_LatPos = -0.0175*1;   Ki_LatPos =  -0.035;  Kd_LatPos = -0.103;  N_LatPos = 12;   % BW = 1.73 rad/s = 0.276 Hz
Kp_LatPos = -0.0248;   Ki_LatPos = 0.001;  Kd_LatPos = -0.1;  N_LatPos = 120;   %  BW = 1.54 rad/s = 0.245 Hz

Gc = ( (Kp_LatPos + N_LatPos*Kd_LatPos)*s^2 + (Ki_LatPos + N_LatPos*Kp_LatPos)*s + N_LatPos*Ki_LatPos ) / (s^2 + N_LatPos*s);  % TF of a PID
%   Gc = ( (Kp_LatPos + N_LatPos*Kd_LatPos)*s + N_LatPos*Kp_LatPos) / (s + N_LatPos);  % TF of a PD

    [numGc, denGc] = tfdata(Gc, 'v');    %   damp(Gc)        [z, p, k] = zpkdata(Gc, 'v')
                                                       %      figure(8), clf,  pzmap(Gc)

Gc_z_Pos = c2d(Gc, T,  'tustin');      %     'zoh'    'tustin'                              Position Controller
    [num_Gc_z_Pos, den_Gc_z_Pos] = tfdata(Gc_z_Pos, 'v');




  figure(26), clf,  bode(Gc, Gc_z_Pos), grid
      legend('Gc(s)',  'Gc(z)')

   figure(27),   clf,    step(Gc, [0  2]),  hold on,   step(Gc_z_Pos, [0  2]),   hold off,  grid

   disp(' ')
