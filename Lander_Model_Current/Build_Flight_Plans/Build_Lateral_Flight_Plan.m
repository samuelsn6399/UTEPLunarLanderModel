%  Build_Lateral_Flight_Plan.m    Build a Flight Plan for the Lateral 
                       %  or translation part a a Mission.  This is 
                       %  the Vertical controller.  This Lateral Mission 
                       %  Plan covers both Lateral "X" velocity and Position.


clear, close all, disp(' ')

%   Mode 1 --> Lateral Velocity Mode    Translate downrange at some velocity
%                 for Mode 1 the Cmd is m/s
%   Mode 2 --> Lateral Position Mode    Move to some "XY" coordinate.  
%                 for Mode 2 the Cmd is meters
%

%  Turn "Interpolation" OFF in the "From Worksapce" Block


%  ----------------------------------------------------------------------------
%               Flight Plan 1:    Ascend  ->  Hover  -->  Land

%                        time      Mode     X Cmd   Y Cmd
% FlightPlan_Lateral = [    0          2        0       0;  
%                          30          2        0       0]; 
% 
% saveFileName = 'Lateral_Flight_Schedule_1.mat';
% disp(['  *** Saving the Lateral Flight plan to the file "' saveFileName '" '])
% save(saveFileName, "FlightPlan_Lateral")
%  ----------------------------------------------------------------------------



%  ----------------------------------------------------------------------------
% Flight Plan 2:    Ascend  
%                   Hover
%                   Translate Laterally at 2 m/s
%                   Command X position to 20 meters downrange
%                   Hover
%                   Descend & Land   (Ascent & Descent are controlled by
%                                            seperate Vertical controller)

%                        time      Mode     X Cmd   Y Cmd
% FlightPlan_Lateral = [    0          2        0       0;   % Liftoff
%                           3          2        0       0;
%                           4          2        0       0;
%                           6          1        2       0;    % Begin translation @ 2 m/s
%                          13          1        1       0;    % Slow down
%                          17          1        0       0;    % Slow down
%                          18          2        20      0;    % Hover
%                          30          2        20      0];   % Hover & Descend

%                       time       Mode     X Cmd   Y Cmd
FlightPlan_Lateral = [    0          2        0       0;   % Liftoff
                          1          2        0       0;
                          5          2        10      0;
                          9          2        10      0;    % Begin translation @ 2 m/s
                         13          2        10      0;    % Slow down
                         17          2        10      0;    % Slow down
                         20          2        10      0;    % Hover
                         30          2        10      0;
                         30.1        2        10      0;   % Not Used - Here to allow for a bigger Table size
                         30.2        2        10      0];  % Not Used - Included to match "Port dimensions" in the Inport


saveFileName = 'Lateral_Flight_Schedule_10m.mat';
disp(['  *** Saving the Lateral Flight plan to the file "' saveFileName '" '])
save(saveFileName, "FlightPlan_Lateral")
%  ----------------------------------------------------------------------------




%%  Plotting
figure(5), clf
stairs(FlightPlan_Lateral(:,1), FlightPlan_Lateral(:,2), 'LineWidth',2)
   grid
       ylabel ('Control Mode)', 'FontSize',12)
       xlabel ('Time  (s)', 'FontSize',12)
       title('Flight Plan', 'FontSize',14)
clear gS
gS{1} = 'Lateral Mode 1 --> Lateral Velocity Control';
gS{2} = 'Lateral Mode 2 --> Position Hold (Hover)';
% gS{3} = 'Mode 3 --> Downrange Position';
% gS{4} = 'Mode 4 --> Downrange Velocity';
% gS{5} = 'Mode 5 --> Yaw Position';
% gS{6} = 'Mode 8 --> Land Now';
% gS{7} = 'Mode 9 --> Shut Down Center Engine';
% gS{8} = 'Mode 10 --> Cut All Power';

   bkColor = [1 1 0.96];
   txtColor = [0.1  0.1  0.85]; % Blue
   add_text(0.35, 0.75, gS, bkColor,txtColor)
