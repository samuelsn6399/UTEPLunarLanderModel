%  Load_Aero_Data.m    Load the input data for the Aero Disturbance Model

%%  Driving Inputs to the Sim

%  The Cm (Pitch Moment) aero coeff is from the Mighty Eagle aero database.  The Cm coeff
%      was extracted from the ME DB with the script "run_Extract_Cm.m" in
%       C:\Users\mhann\OneDrive\Documents\MightyEagle\Aero\Forces_and_Moments\Matlab
%  Note that on ME the vertical axis was the X axis while for the Miner 320 the Z axis is the vertical axis.
Cm_Coeff_FileName = 'Cm_Coeff_MightyEagle.mat';
load(Cm_Coeff_FileName)
Cm_Lookup = [Phi'  (Cm + MonteCarloSim_In(idx,8,1))];   %       Pitch Moment table that the simulation will look up

windSpeed_knots = MonteCarloSim_In(idx, 3, 1);  % [knots] randomly generated normally distributed wind speed
Cd = 1.2;  %      Drag Coeff
Psi_Angle_deg = 5;  % deg      Yaw Angle Psi  (about the Z axis)       Cm is a function of Psi
rho_air = 1.2;  % kg/m^3   Density of the air at 20 deg C.
wind_angle_deg = MonteCarloSim_In(idx, 4, 1);  % [deg] randomly generate uniformally distributed Wind Direction (in Body coords).  Zero degrees means
%                                                   The wind exists in the XY plane (horizontal to the ground).  The angle is measured
%                                                   CCW about the downward facing +Z axis.
% build_windProfile_with_Gust
t_last_Wind_Entry = 30; % sec     Time of the last Wind input - a time well after landing
gustFactor = MonteCarloSim_In(idx, 5, 1);  %  Wind Gust Factor
tGust_Start = MonteCarloSim_In(idx, 7, 1);  % sec    Time that the Wind Gust starts
gustDuration = MonteCarloSim_In(idx, 6, 1);  % sec    Duration of the Wind Gust
tGust_End = tGust_Start + gustDuration; % sec    Time that the Wind Gust ends
Gust_tf(idx) = tGust_End; % [sec] store a list of final gust times
tGustPeak = tGust_Start + (tGust_End - tGust_Start) / 2; %  sec   Peak Wind Speed
Gust_Peak(idx) = tGustPeak; % store a list of peak gust times
%  What Reference Area and Length should be used for the Miner 320 Lander?
%       Assume that the dimensions  of the Garolite Deck (Mighty Eagle used the Lower Deck) will
%        be used.  The Garolite deck is 2 ft by 2 ft.  Therefore the refernce lenth is 2 ft and the reference
%        area is 4 ft^2.

%   Lref is the Reference Length.  It is the length of a side of the Garolite deck.  Lref = 24 in = 2 ft
%  Sref is the Reference Area.  Sref = Lref^2
Lref_scaleFactor = 1.0;  %  scale the ref area and ref length by this factor

Lref_ft = 2*Lref_scaleFactor; % ft     Reference Length

Sref_ft2 = Lref_ft^2  ; %  ft^2      Reference Area
Sref = Sref_ft2*0.3048^2; % m^2

%% Unit Conversions
windSpeed = windSpeed_knots*knots2m_per_s;   % m/s      Mean Wind Speed at the reference height
wind_angle = wind_angle_deg*pi/180;  % [rad]    Mean Wind Direction (in Body coords).  Zero degrees means
                                             %        the wind is blowing in the +X direction thus pushing the Lander
                                             %        downrange.  Rotating 90 deg CCW about the Z axis the wind blows 
                                             %        in the +Y direction.
Lref = Lref_ft*0.3048; % meters
Sref = Sref_ft2*0.3048^2; % m^2

wind_unitVec = [ cos(wind_angle);   sin(wind_angle) ;  0 ];  %     Unit Vector in NED Coords

