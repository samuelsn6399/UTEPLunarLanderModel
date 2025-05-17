%% Build the monte carlo vectors for the number of iterations (iter)
% Intialize variables
% iter = 1000;
MonteCarloSim_In = zeros(iter, length(param), 3); % (iteration, parameter, xyz component)
% Build Vectors depending on distribution type
for a = 1:length(param)
    if param(a).Distribution == 'G'
        MonteCarloSim_In(:, a, 1:length(param(a).NomVal)) = randn(iter, length(param(a).NomVal)).*param(a).StandDev + param(a).NomVal;

    elseif param(a).Distribution == 'U'
        MonteCarloSim_In(:, a, 1:length(param(a).NomVal)) = (2*rand(iter, length(param(a).NomVal)) - 1).*param(a).StandDev + param(a).NomVal;

    else
        disp('ERROR: Not a valid distribution type')
        quit

    end
end

%% Plot Distributions
% Get an idea of how standard deviation effects the distribution of unknown
% parameters

% CE Translation in x distribution
Bins = 30;
figure(1)
histogram(MonteCarloSim_In(:,1,1)*100, Bins)
title 'CE Translation in x-axis distribution'
xlabel 'Offset [cm]'
ylabel 'Number of Iterations'

% CE Theta distribution
Bins = 10;
figure(2)
histogram(MonteCarloSim_In(:,2,3), Bins)
title 'CE Theta distribution'
xlabel 'Theta [deg]'
ylabel 'Number of Iterations'

% wind velocity distribution
Bins = 15;
figure(3)
histogram(MonteCarloSim_In(:,3,1), Bins)
title 'wind velocity distribution'
xlabel 'Wind Velocity [Knotts]'
ylabel 'Number of Iterations'

% wind direction distribution
Bins = 15;
figure(4)
histogram(MonteCarloSim_In(:,4,1), Bins)
title 'wind direction distribution'
xlabel 'Wind direction (from +x-axis in x-y plane) [deg]'
ylabel 'Number of Iterations'

% wind gust coefficient distribution
Bins = 15;
figure(5)
histogram(MonteCarloSim_In(:,5,1), Bins)
title 'Gust Coefficient distribution'
xlabel 'Gust Coeffictient [Unitless]'
ylabel 'Number of Iterations'

% wind gust duration distribution
Bins = 15;
figure(6)
histogram(MonteCarloSim_In(:,6,1), Bins)
title 'wind gust duration distribution'
xlabel 'duration [s]'
ylabel 'Number of Iterations'

% wind gust begin distribution
Bins = 15;
figure(7)
histogram(MonteCarloSim_In(:,7,1), Bins)
title 'wind gust start time distribution'
xlabel 'start time [s]'
ylabel 'Number of Iterations'

% Aero Moment Coeff
Bins = 15;
figure(8)
histogram(MonteCarloSim_In(:,8,1), Bins)
title 'Aero Pitch Moment Coeff Offset'
xlabel 'Pitch Moment Coeff Offset [Unitless]'
ylabel 'Number of Iterations'

% Moment Inertia about y-axis distribution
Bins = 15;
figure(9)
histogram(MonteCarloSim_In(:,9,2), Bins)
title 'Moment Inertia about y-axis distribution'
xlabel 'Moment of Intertia about y-axis [kg*m^2]'
ylabel 'Number of Iterations'

% Center Engine ISP
Bins = 15;
figure(10)
histogram(MonteCarloSim_In(:,10,1), Bins)
title 'Center Engine ISP distribution'
xlabel 'ISP [s]'
ylabel 'Number of Iterations'

% Center Engine Thrust
Bins = 15;
figure(11)
histogram(MonteCarloSim_In(:,11,1), Bins)
title 'Center Engine Thrust'
xlabel 'Thrust [N]'
ylabel 'Number of Iterations'

