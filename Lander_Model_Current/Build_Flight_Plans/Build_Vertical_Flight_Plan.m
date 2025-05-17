%  Build_Vertical_Flight_Plan.m      Build a Vertical Flight Plan for a Mission.
      %  This is Only for vertical control (both altitude & altitude rate)
      %   For Lateral control (X Translation) see "Build_Lateral_Flight_Plan.m"

clear, close all, disp(' ')

%   Mode 1 --> Vertical Velocity Mode    Ascend/Descend at some velocity
%                 for Mode 1 the Cmd is m/s
%   Mode 2 --> Vertical Altitude Mode    Hold Altitude to some level
%                 for Mode 2 the Cmd is meters

%  Turn "Interpolation" OFF in the "From Workspace" Block


%  ----------------------------------------------------------------------------
%               Flight Plan 1:    Ascend  ->  Hover  -->  Land

%                          
%                          t        Mode      Cmd 
% FlightPlan_Vertical = [    0          1        1  ;   % Ascend at 1 m/s
%                            3          2        3  ;   % Hover at 3 m
%                            9          1       -1  ;   % Descend at 1 m/s
%                           20          1       -1  ];
% 
% 
% saveFileName = 'Vertical_Flight_Schedule_1.mat';
% disp(['  *** Saving the Flight plan to the file "' saveFileName '" '])
% save(saveFileName, "FlightPlan_Vertical")


%  ----------------------------------------------------------------------------
% Flight Plan 2:    Ascend  
%                   Hover
%                   Translate Laterally at 2 m/s
%                   Command X position to 20 meters downrange
%                   Hover
%                   Descend & Land   (Lateral Velocity & Position  are controlled by
%                                            a seperate Lateral controller)

%  Extra rows added to the bottom of the file because the Port dimensions of
%       the Inport to the FCS is hard-coded as [10 3].  With the unused
%       rows at the bottom you can have up to 10 rows without changing the
%       Port dimensions of the Inport.
% 

%                          t        Mode      Cmd  
FlightPlan_Vertical = [    0          1        1  ;   % Ascend at 1 m/s
                           3          1        1  ;
                           3.2        2        3  ;   % Hover and hold altitude at 3 m
                          13          1       -1  ;   % Descend at 1 m/s
                          30          1       -1  ;   % Descending @ 1 m/s till touchdown
                          30.1        1       -1  ;   % Never Used - Here to allow for a bigger Table size
                          30.2        1       -1  ;   % Never Used
                          30.3        1       -1  ;   % Never Used
                          30.4        1       -1  ;   % Never Used
                          30.5        1       -1  ];

saveFileName = 'Vertical_Flight_Schedule_10m.mat';
disp(['  *** Saving the Flight plan to the file "' saveFileName '" '])
save(saveFileName, "FlightPlan_Vertical")




%%  Plotting
figure(4), clf
stairs(FlightPlan_Vertical(:,1), FlightPlan_Vertical(:,2), 'LineWidth',2)
   grid
       ylabel ('Control Mode)', 'FontSize',12)
       xlabel ('Time  (s)', 'FontSize',12)
       title('Flight Plan', 'FontSize',14)
clear gS
gS{1} = 'Mode 1 --> Vertical Velocity';
gS{2} = 'Mode 2 --> Altitude Hold (Hover)';
% gS{3} = 'Mode 3 --> Downrange Position';
% gS{4} = 'Mode 4 --> Downrange Velocity';
% gS{5} = 'Mode 5 --> Yaw Position';
gS{3} = 'Mode 8 --> Land Now';
gS{4} = 'Mode 9 --> Shut Down Center Engine';
gS{5} = 'Mode 10 --> Cut All Power';

   bkColor = [1 1 0.96];
   txtColor = [0.1  0.1  0.85]; % Blue
   add_text(0.35, 0.75, gS, bkColor,txtColor)
