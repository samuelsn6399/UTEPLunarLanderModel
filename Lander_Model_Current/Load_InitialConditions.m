% Load_InitialConditions.m   Load the needed ICs to integrators in the model.

x0 = 0; % m   Initial Altitude
y0 = 0;
z0 = -0.3; % m   Lander CG is this distance above ground

dx0 = 0;  % m/s   Intial "x" Velocity
dy0 = 0; 
dz0 = 0; 

theta0 = 0; % rad     Initial Pitch Angle
q0 = 0;     % rad/s   Initial Pitch Rate


% vInt0 = 0; % m/s  Initial Velocity
% 
% IC_CntrlIntegrator = g*massInitial; % N  Inital Thrust Command
