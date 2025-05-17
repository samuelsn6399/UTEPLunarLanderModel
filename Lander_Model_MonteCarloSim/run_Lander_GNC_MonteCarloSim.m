% Monte Carlo Disturbance Simulation
% iterate_Lander_GNC_Sim.m
% Run the simulation for many iterations with random disturbances
                       

clear, close all
disp(' '), disp(' ')

%% User input
iter = 2000; % number of iterations or random disturbance cases
Model_Version = 14;  %  Which Version of the Cold Gas Lander Model
Aero_Forces_On = 1;   %    When = 1 the Aero Forces and Moments are applied
                                         %         Edit "Load_Aero_Data.m" to turn a wind gust On/Off
 T = 0.02;  % sec    Sample Time of the Digital Controller

 build_MCarlo_Parameters % load the monte carlo parameters
 build_MCarlo_Vectors % create the vectors for the monte carlo sim based on the inputs in build_MCarlo_Parameters

 if Model_Version == 1
     disp('  Running with Controller Variant 1 of the Cold Gas Lander Model')
     disp('     This controller has a Lateral Postion Mode and a Velocity Mode')
     LatCntrl_variant = 1;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_2';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_2';
     Load_Controller_Gains_1   %  PID Control Gains (Kp, Ki & Kd) for the Model Version 1

 elseif Model_Version == 2
     disp('  Running with Controller Variant 2 of the Cold Gas Lander Model')
     disp('       This controller has a Pitch Controller inside a Velocity Controller inside a Position Controller')
     disp('       This is a triple Cascade Control architecture')
     LatCntrl_variant = 2;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_22';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_2';
     Load_Controller_Gains_2   %  PID Control Gains (Kp, Ki & Kd) for the Model Version 2

 elseif Model_Version == 3
     disp('  Running with Controller Variant 3 of the Cold Gas Lander Model')
     disp('     This controller has a Pitch Controller inside of a Lateral Postion Controller')
     disp('       Velocity is Controlled indirectly by how the Position Command profile is built')
     LatCntrl_variant = 3;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_3_15_20.mat';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_3_15_20.mat';
     Load_Controller_Gains_3   %  PD Control Gains (Kp, Ki & Kd) for Model Version 3

 elseif Model_Version == 4
     disp('  Running with Controller Variant 4 of the Cold Gas Lander Model')
     disp('       This controller has a Pitch Controller inside a Velocity Controller inside a Position Controller')
     disp('       This is a triple Cascade Control architecture')
     disp('       This is the same architecture as version 2 but with Samuel''s Controllers')
     LatCntrl_variant = 4;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_4';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_2';
     Load_Controller_Gains_4   %  PID Control Gains (Kp, Ki & Kd) for Model Version 4

 elseif Model_Version == 13
     disp('  Running with Controller Variant 13 of the Cold Gas Lander Model  -->>  Discrete Controller')
     disp('     This DISCRETE controller has a Pitch Controller inside of a Lateral Postion Controller')
     disp('       Velocity is Controlled indirectly by how the Position Command profile is built')
     LatCntrl_variant = 13;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_2_3_12_20.mat';
     % LatFlightScheduleFile = 'Lateral_Flight_Schedule_3_15_20.mat';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_3_15_20.mat';
     Load_Controller_Gains_13   %  PD Control Gains (Kp, Ki & Kd) for Model Version 13

 elseif Model_Version == 14
     disp('  Running with Controller Variant 14 of the Cold Gas Lander Model - A Discretized Version of Model 4')
     disp('       This controller has a Pitch Controller inside a Velocity Controller inside a Position Controller')
     disp('       This is a triple Cascade Control architecture')
     disp('       This is the same architecture as version 2 but with Samuel''s Digital Controllers')
     LatCntrl_variant = 14;  %      Variant Subsystem
     modelName = 'ColdGas_GNC_Model';
     LatFlightScheduleFile = 'Lateral_Flight_Schedule_4';
     VertFlightScheduleFile = 'Vertical_Flight_Schedule_2';
     Load_Controller_Gains_14   %  PID Discrete Control Gains (Kp, Ki & Kd) for Model Version 14

 else
     error('**  Value of "Model_Version" is NOT VALID **')
 end


disp(['  Simulink Model Name:  ' modelName ])
% cntrlMode = 2;  %   Control Mode    Description
%                   -----------     ----------
%                        1          Vertical Velocity
%                        2          Vertical Position (altitude "h")
%                        3          Lateral Velocity
%                        4          Lateral Position
%                        8          Land Now  (Command zero lateral Vel and land fast)
%                        9          Shut Down Center Engine
%                       10          Shut Down Center Engine & Electric Fans
%

%  Load the Mission Plan.  To create or modify a Mission Plan edit the file
%          "Build_Flight_Plan.m" in the directory "Build_Mission_Plan"
disp(['   Loading the Vertical Flight Plan contained in the file "' VertFlightScheduleFile '"' ])
load(VertFlightScheduleFile)
    clear VertFlightScheduleFile 

%   Load the Lateral Flight Plan (Lateral Velocity and Lateral Position Control)

disp(['   Loading the Lateral Flight Plan contained in the file "' LatFlightScheduleFile '"' ])
      load(LatFlightScheduleFile)
      clear LatFlightScheduleFile


numFlightSegments = length(FlightPlan_Vertical) - 1; % Number of Flight Segments
                           %  Subtract 1 because the last segment is there
                           %    in case the sim runs longer than expected.


  
maxStepSim = 0.01; % sec    Maximum Integration time step
tFinal = 30; % sec   Time the Simulation ends
hFinal = -0.00001; % m   Stop simulation when descending below this altitude (h)
hFinal = 0.28; % m    Initial Condition for IMU altitude is 0.3 meters

Ts_Control = 1/50; % sec   Controller Sample time  (50 Hz)

% Intialize data logging simulation output variables
pos_final = zeros(iter,1); % Vector of position values at touchdown
theta_final = zeros(iter,1); % Vector of theta values at touchdown
Gust_tf = zeros(iter,1); % Vector of end of wind gust
Gust_Peak = zeros(iter,1);
N2_used = zeros(iter,1); % Vector of N2 used during each sim
latVelEarth_final = zeros(iter, 1); % vector of lateral velocities at touchdown in Earth cordinate frame
vertVelEarth_final = zeros(iter, 1); % vector of vertical velocities at touchdown in Earth cordinate frame
latVelEarth_max = zeros(iter,1); % vector of maximal lateral velocities in Earth cordinate frame

open(modelName)

%% Begin Iterating The Lander Simulation Model
for idx = 1:iter
    Create_Bus_Objects   % Create all of the needed Bus Objects

    Load_VehicleParams   %  load the mass properties, the Propulsion data and
    %                             some unit conversions

    Load_Aero_Data  %  Aero Drag and Pitch Moment

    Load_InitialConditions

    LandNowFlag = false;  %   Flag that when "True" results in an Emergency Landing
    %   Lateral Velocities commanded to zero and a fast descent
    %      profile (vertical velocity profile) is commanded.


    %  Altitude Command Profile  (meters)
    velHyst = 0.20; % meters  The width of the Velocity hysteresis deadband
    % "velHyst" is hard coded into the Vertical Controller.  It is also
    %    used in "plot_Vertical_Vel_Switching.m"


    %   The Altitude Phase Plane is design in the script
    %       "run_AltitudePhasePlane_Design.m" which is in the directory
    %              "Altitude_PhasePlane"
    load('PhasePlaneData.mat')  % Load the Phase Plane Switching lines

    %  For all of the outputs to be stored in "out" check the box for "Single
    %    simulation output" under "Data Import/Export" which is under "Model
    %    Settings" which is under the "Modeling" tab.
    out = sim(modelName);

    %%  Sim Output Processing
    Q = squeeze(out.Cntrl_miscData); %  Access select internal Vertical Control params


    %  h = out.logsout.get("z");
    h = out.Nav.z;
    hDot = out.Nav.VzE;
    % hDot = out.logsout.get("Vz");

    % hCmd = out.logsout.get("h_Cmd");
    % hDotCmd = out.logsout.get("hDot_Cmd");
    hDotCmd = Q(4,:);  % m/s    Vertical Velocity Command

    % hErr = h.Values.Data - hCmd.Values.Data;
    % hErr = h.Data - hCmd.Values.Data;
    % hDotErr = hDot.Values.Data - hDotCmd.Values.Data;
    hDotErr = hDot.Data - hDotCmd;

    % m = out.logsout.get("m");

    % Keep a vector of monteCarloSim outputs at touchdown
    pos_final(idx,1) = out.Nav.x.Data(end); % [m]
    theta_final(idx,1) = out.Nav.Theta.Data(end)*r2d; % [deg]
    N2_used(idx,1) = out.Propulsion.mProp_Consumed.Data(end); % [kg]
    latVelEarth_final(idx,1) = out.Nav.VxE.Data(end); % [m/s]
    vertVelEarth_final(idx,1) = out.Nav.VzE.Data(end); % [m/s]
    latVelEarth_max(idx,1) = max(out.Nav.VxE.Data); % [m/s]

    MissionTrajectorySims(idx).time = out.Nav.x.Time; % [sec]
    MissionTrajectorySims(idx).x = out.Nav.x.Data; % [m]
    MissionTrajectorySims(idx).z = -out.Nav.z.Data; % [m] Down is negative, so invert for graphing

    % Display the current iteration being simulated (progress bar of sorts)
    disp(' ')
    disp('Iteration: '+string(idx)+'/'+iter)
end

%% Iterative Disturbance Simulation Data Post-Processing
theta_final_MAX = max(theta_final)
theta_final_MIN = min(theta_final)
pos_final_AVG = mean(pos_final)
Iteration = (1:iter)';
Flight_Profile = table(Iteration, pos_final, theta_final, N2_used, MonteCarloSim_In(:,1,:)*100, MonteCarloSim_In(:,2,:), MonteCarloSim_In(:,3,1), MonteCarloSim_In(:,4,1), MonteCarloSim_In(:,5,1), MonteCarloSim_In(:,6,1), MonteCarloSim_In(:,7,1), Gust_tf,...
                        MonteCarloSim_In(:,8,1), MonteCarloSim_In(:,9,:),...
                        'VariableNames', ["Iteration", "Final Position [m]", "Pitch Angle @ Touchdown [deg]", "Mass of N2 Used [kg]", "Center Engine Offset Translation (in x,y,z) [cm]", "Center Engine Offset Angle (from x,y,z axis) [deg]",...
                        "Steady Wind Velocity [Knotts]", "Wind Direction (from x-axis in x-y plane) [deg]", "Wind Gust Coefficient", "Wind Gust Duration [sec]", "Wind Gust Begin [sec]", "Wind Gust End [sec]",...
                        "Cm Offset Value", "MOI (in x,y,z) [kg*m^2]"])
writetable(Flight_Profile,'MonteCarloSimOut.txt')

plot_MonteCarloSim