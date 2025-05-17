%  Load_Aero_Data.m    Load the input data for the Aero Disturbance Model

%%  Driving Inputs to the Sim
windSpeed_knots = 8;  %  knots
wind_Gust_On = 1;      %  If = 1 then a Wind Gust is added to the base wind
Cd = 1.2;  %      Drag Coeff
Psi_Angle_deg = 5;  % deg      Yaw Angle Psi  (about the Z axis)       Cm is a function of Psi
rho_air = 1.2;  % kg/m^3   Density of the air at 20 deg C.
wind_angle = 0*pi/180;  % rad,    Mean Wind Direction (in Body coords).  Zero degrees means
                                             %        the wind is blowing in the +X direction thus pushing the Lander
                                             %        downrange.  Rotating 90 deg CCW about the Z axis the wind blows 
                                             %        in the +Y direction.
                     %  The wind exists in the XY plane (horizontal to the ground).  The angle is measured 
                     %   CCW about the downward facing +Z axis.
Lref_scaleFactor = 1.0;  %  scale the ref area and ref length by this factor

        windSpeed = windSpeed_knots*knots2m_per_s;   % m/s      Mean Wind Speed at the reference height

 if Aero_Forces_On
        disp('     Aero Forces & Moments are ON')
        disp(['       Wind Speed = ' num2str(windSpeed_knots) ' knots      ('  num2str(windSpeed,3) ...
                       ' m/s  or  '  num2str(windSpeed*mps2mph,3) ' mph)' ])  
    else
        disp('     Aero Forces & Moments are OFF')
            Wind_Speed_data = [      0          0 ;
                                                       30         0 ]; % m/s     No Wind
 end

 disp(' '),  disp(' ')

    
%  The Cm (Pitch Moment) aero coeff is from the Mighty Eagle aero database.  The Cm coeff
%      was extracted from the ME DB with the script "run_Extract_Cm.m" in
%       C:\Users\mhann\OneDrive\Documents\MightyEagle\Aero\Forces_and_Moments\Matlab
%  Note that on ME the vertical axis was the X axis while for the Miner 320 the Z axis is the vertical axis.
Cm_Coeff_FileName = 'Cm_Coeff_MightyEagle.mat';
disp([' Loading the Cm coeff from the Mighty Eagle Aero DB --> ' Cm_Coeff_FileName] )
load(Cm_Coeff_FileName)
Cm_Lookup = [Phi'  Cm];   %       Pitch Moment table that the simulation will look up
        % figure(30), clf
        % plot(Phi, Cm), grid
        %    ylabel('Cm  (Pitch Moment)', 'FontSize', 12)
        %    xlabel('Yaw angle Psi  (deg)', 'FontSize', 12)
        %    title('Pitching Moment Cm vs. Yaw Angle', 'FontSize', 14)


%  What Reference Area and Length should be used for the Miner 320 Lander?
%       Assume that the dimensions  of the Garolite Deck (Mighty Eagle used the Lower Deck) will
%        be used.  The Garolite deck is 2 ft by 2 ft.  Therefore the refernce lenth is 2 ft and the reference
%        area is 4 ft^2.  
 
 %   Lref is the Reference Length.  It is the length of a side of the Garolite deck.  Lref = 24 in = 2 ft
 %  Sref is the Reference Area.  Sref = Lref^2
Lref_ft = 2*Lref_scaleFactor; % ft     Reference Length
   Lref = Lref_ft*0.3048; % meters
   disp([' Lref: ' num2str(Lref,3) ' m   (' num2str(Lref_ft,3) ' ft)'])

 Sref_ft2 = Lref_ft^2  ; %  ft^2      Reference Area
   Sref = Sref_ft2*0.3048^2; % m^2
   disp([' Sref: ' num2str(Sref,3) ' m^2   (' num2str(Sref_ft2,3) ' ft^2)'])


wind_unitVec = [ cos(wind_angle);   sin(wind_angle) ;  0 ];  %     Unit Vector in NED Coords

disp(['  Wind Direction: '  num2str(wind_angle*r2d,3) ' deg,  Wind  Unit Vector = '  ...
                                                   mat2str(wind_unitVec, 3)])
disp([' rho = ' num2str(rho_air) ' kg/m^3   (Air Density)' ])

t_last_Wind_Entry = 30; % sec     Time of the last Wind input - a time well after landing
if Aero_Forces_On == 1  &&  wind_Gust_On == 1   
      disp('    A Wind Gust will be added to the base wind ')
      % build_windProfile_with_Gust
      gustFactor = 1.4;  %  Wind Gust Factor
      tGust_Start = 5;  % sec    Time that the Wind Gust starts
      gustDuration = 10;  % sec    Duration of the Wind Gust
      tGust_End = tGust_Start + gustDuration; % sec    Time that the Wind Gust ends
      tGustPeak = tGust_Start + (tGust_End - tGust_Start) / 2; %  sec   Peak Wind Speed
        disp([ '      Wind Gust Factor = ' num2str(gustFactor)  '    Gust Duration =  '  ...
                             num2str(gustDuration) ' sec   Gust Peaks at ' num2str(tGustPeak) ' sec' ])

elseif Aero_Forces_On == 1  &&  wind_Gust_On == 0
    disp('    Only a base wind will disturb the vehicle - No Wind Gust')
      gustFactor = 1.0;  %  Wind Gust Factor
      tGust_Start = 9;  % sec    Time that the Wind Gust starts
      gustDuration = 9;  % sec    Duration of the Wind Gust
      tGust_End = tGust_Start + gustDuration; % sec    Time that the Wind Gust ends

   %                                                sec                              m/s
    % Wind_Speed_data = [              0                         windSpeed;
    %                                         t_last_Wind_Entry      windSpeed ];
end

%  %%  Plot the Wind Speed
%             figure(191), clf
%             plot(Wind_Speed_data(:,1), Wind_Speed_data(:,2))
%               xlabel('Time  (sec)',  'FontSize', 12),  grid
%               ylabel('Wind Velocity  (m/s)', 'FontSize', 12)
%               title('Wind Speed', 'FontSize', 14)
%             clear gS
%                   if wind_Gust_On == 1
%                       gS{1} = ['Gust Factor = ' num2str(gustFactor) ];
%                       gS{2} = ['Base Wind Speed = ' num2str(windSpeed,3) ' m/s'  ...
%                                                     '  ( ' num2str(windSpeed_knots) ' knots)'];
%                       gS{3} = ['Gust Duration =  ' num2str(gustDuration) ' sec' ];
%                       gS{4} = ['Gust Peaks at ' num2str(gustPeak) ' sec' ];
%                       gS{5} = ['Wind Gust Starts at t = ' num2str( tWindTemp(tGustStartIx) ) ' sec' ];
%                   else
%                       gS{1} = 'Base Wind Only  (No Wind Gust)';
%                       gS{2} =  ['Base Wind Speed = ' num2str(windSpeed,3) ' m/s'  ...
%                                                     '  ( ' num2str(windSpeed_knots) ' knots)'];
%                   end
%                   add_text(.5, .85, gS)
%                   set(gcf, 'Name', 'Wind Speed')
% 
%              clear  tWindTemp Wind_Temp tPulse tGustStart  tGustStartIx  postStartIndexes  pulseFactor
% 
% clear t_last_Wind_Entry
disp(' ')
