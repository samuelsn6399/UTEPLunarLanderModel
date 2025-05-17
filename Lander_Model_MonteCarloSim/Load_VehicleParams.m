%  Load_VehicleParams.m   Load Vehicle parameters inot the Matlab WS

g = 9.807;  % m/s^2     Acceleration from Earth gravity

%%  Unit Conversions
             % in2m = 0.0254; %    Units Conversion,  1 inch = 0.0254 meters
lbm2kg = 1/2.20462; %    Units Conversion,  1 lbm = 0.4536 kg
   kg2lbm = 1/lbm2kg;
lbf2N = 4.44822162; %     1 lbf = 4.44822162 N
N2lbf = 1/lbf2N;    %     Newtons to lbf
m2in = 39.37;       %     1 meter = 39.3700787 inches
kg2N = g;           %     Convert from kg to Newtons
    N2kg = 1/kg2N;  %       Convert from Newtons to kg
d2r = pi/180;       %     Convert degress to rad
    r2d = 1/d2r;    %       "     radians to degrees

nm2ftLbf = 0.224809*3.28084;  %  Convert N-m to ft-lbf (1 N-m = 0.7376 ft-lbf) 
knots2m_per_s = 0.514444;    %  1 knot = 0.514444 m/s
mps2mph = 2.237;   %  1 m/s = 2.237 mph
Npermsq2psi = 0.0209;        %    1 N/m^2 = 0.0209 psi
Npermsq2psf = 0.000145;   %    1 N/m^2 = 0.000145 psi


mWet = 47.6;          % kg   Lander mass including a full propellant load
mN2_Total = 5.36;     % kg   Total (usable + unusable) N2 Propellant mass at takeoff
mN2_usable = 3.16;    % kg   Usable Propellant mass at takeoff
mN2_unusable = mN2_Total - mN2_usable;  % kg  Unusable Propellant mass
mDry = mWet - mN2_Total;  % kg   Dry mass of the Lander
CG_offset = [0 0 0];  % m    Offset of the Center of Gravity (CG)

I =   [MonteCarloSim_In(idx, 9, 1)  0  0;
       0 MonteCarloSim_In(idx, 9, 2)  0;
       0  0  MonteCarloSim_In(idx,9,3)]; % [kg-m^2]   Lander Inertia matrix with gaussian distributed offsets

massInitial = mDry + mN2_usable + mN2_unusable; % kg   Mass at Liftoff


fanMaxThrust = 122.5; % N     Max thrust of a single Electric Fan

% b = 0.001215;  % N-s^2        Slope of the Thrust vs rotational Vel squared line
% b_nonLin = 0.001215;  % N-s^2        Slope of the Thrust vs rotational Vel squared line
               %                 "b" times Omega^2 gives the Thrust
% b_Linear = 0.7052; % N-s   Slope of Thrust vs Omega  (Omega is angular Velocity)
b_Linear = 0.6167; % N-s   Slope of Thrust vs Omega  (Omega is angular Velocity)
                   %         Linear fit of Thrust vs Omega

fan_thrust_Poly = [0.0009987  -0.04316  4.44]; % N-s/rad  Fan Thrust as f(Omega)
                             % See "calc_Thrust_Coeff.m" where the motor-Fan
                             % data is fit to a quadratic curve

%  Linear Relationships between Motor Speed and Thrust   See "calc_Thrust_Coeff.m"
%            Thrust = mThrust*Omega + bThrust
mThrust = 0.6167;  % N/(rad/s)   Slope of the Thrust vs Omega line
bThrust = -104.2;  % rad/s       Y intercept of the Thrust vs Omega line

%            Omega = mOmega*Thrust + bOmega
mOmega = 1/mThrust;         % N/(rad/s)   Slope of the Omega vs Thrust line
bOmega = -bThrust/mThrust;  % rad/s       Y intercept of the Omega vs Thrust line


nFans = 4;            %       Number of Fans
rFans = [ 0.6605    -0.6605    -0.1146;
          0.6605     0.6605    -0.1146;
         -0.6605     0.6605    -0.1146;
         -0.6605    -0.6605    -0.1146]; % meters   Vectors from the CG to the Fans

uvFans = [ -0.1830    0.1830    -0.9659;    % Unit Vector for the direction of the Force
           -0.1830   -0.1830    -0.9659;    %    that each fan fan applies to the vehicle.
            0.1830   -0.1830    -0.9659;
            0.1830    0.1830    -0.9659 ]; 

fanCantAngle_deg = 15; % degrees     Fan Orientation from Vertical
   fanCantAngle = fanCantAngle_deg*d2r; % radians
fan_tDelay = 0.020; % sec    Delay time between command and first valve movement.

% Build_Fan_Unit_Vectors  %  Create unit vectors for the Thrust of each Fan --> "uvFans"

g_Offset = 5/6;         %      Electric Fans offset this much of the lander mass

   Fan_num = 2500;               %      Numerator of the motor-fan Transfer Function
   Fan_den = [1  70.7  2500];    %      Denominator of the motor-fan Transfer Function
   fan_TF = tf(Fan_num, Fan_den); %      motor-fan Transfer Function
   

% Determine needed Initial Conditions
Cant_cosine_Loss = cos(fanCantAngle); %     Loss of vertical thrust due to the Cant angle of the Fans
Ic.FanThrust = (massInitial/nFans) * g_Offset * kg2N / Cant_cosine_Loss; % N
      %  At t = 0 the fans need to be at the proper thrust.


CE_ISP = MonteCarloSim_In(idx, 10, 1);     % sec   Center Engine Specific Impulse of N2
CE_Thrust = MonteCarloSim_In(idx, 11, 1); % N Thrust of the Center Engine
CE_tDelay = 0.030; % sec    Delay time between command and first valve movement.
CE_tau = 0.100;    % sec    Time Constant of the Cold Gas Lander Center Engine
CE_TF = tf(1, [(CE_tau/2.2)  1]); %    Transfer funtion of a system with a given Time Constant tau
                                 %       We know that the Rise Ttime is approximately = 2.2*tau
                                 %             figure(19), clf, step(CE_TF), grid



    %   ***  Disturbance from Center Engine (CE) misalignment
CE_Location = [MonteCarloSim_In(idx, 1, 1),...
               MonteCarloSim_In(idx, 1, 2),...
               MonteCarloSim_In(idx, 1, 3)];
CE_Direction = [-sind(MonteCarloSim_In(idx, 2, 3)),...
                                0,...
                -cosd(MonteCarloSim_In(idx, 2, 3))];

RCS_Thrust = 22.2;  % N      Thrust of the each Reaction Control System (RCS) thruster
RCS_r = 0.3082;     % m      Moment Arm to the RCS Thrusters
RCS_ISP = 30;       % sec    RCS Engine Specific Impulse of N2
RCS_tDelay = 0.025; % sec    Delay time between command and first valve movement.


Thrust_Fan_at_Liftoff = mWet*g_Offset*Cant_cosine_Loss*g / nFans; % N  Thrust from 1 Fan

max_Axial_Thrust = CE_Thrust + (fanMaxThrust*Cant_cosine_Loss*nFans); % N  Max Thrust in +X direction
% thrust2Weight_Liftoff = max_Axial_Thrust*N2kg / massInitial; %  Dimensionless ratio
thrust2Weight_Liftoff = (CE_Thrust + Thrust_Fan_at_Liftoff*nFans) / (mWet*g); %  Dimensionless ratio

% % LoopClosed = 1; % Use to open the Loop for Control Design Purposes
% 
% 
t_Liftoff_Achieved = 1;  % sec   Time when the vehicle is assumed off 
                           %           the ground and ascending.
                           
tau_AlgLoop = 0.01; % sec    Time Constant used to Break an Algebraic Loop