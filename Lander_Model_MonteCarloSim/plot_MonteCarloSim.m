%% Plot Monte Carlo Outputs


%% Plot the end states of the lander mission (touch down position and pitch)
% Setup Mission Requirements
x_req = 20; % [m] Downrange position requirement
x_err = 0; % [m] Downrange position error
x_HardConstraint = 2; % [m] plus-minus 2 meter error hard constraint for mission pass/fail
x_SoftConstraint = 1; % [m] plus-minus 1 meter error soft constraint for mission pass/fail
theta_touchdown_req = 0; % [deg] Required theta at touchdown
theta_HardConstraint = 10; % [deg] plus-minus 10 degree pitch error hard constraint for mission pass/fail
theta_SoftConstraint = 5; % [deg] plus-minus 5 degree pitch error soft constraint for mission pass/fail
IdealVertVel_Touchdown = 1; % [m/s]

figure(101), clf
scatter(x_err, theta_touchdown_req, [], "r", "*");
hold on
pos_error = pos_final - x_req; % [m] postion error relative to the desired 20 meter down range position at touchdown
scatter(pos_error, theta_final, [], "b", ".");
line(NaN, NaN, 'LineWidth', 2, 'Color', 'r'); % hard constraint rectangle legend entry
line(NaN, NaN, 'LineWidth', 2, 'color', [1 0.8 0]); % soft constraint rectangle legend entry
rectangle('Position',[-x_HardConstraint -theta_HardConstraint ...
                      2*x_HardConstraint 2*theta_HardConstraint], ...
                     'EdgeColor', 'r');
rectangle('Position', [-x_SoftConstraint -theta_SoftConstraint ...
                      2*x_SoftConstraint 2*theta_SoftConstraint], ...
                     'EdgeColor', [1 0.8 0]);
hold off
axis([-5 5 -15 15])
ylabel 'Pitch Angle at Touchdown [deg]'
xlabel 'Downrange Position Error at Touchdown [m]'
title 'Pitch and Downrange Position at Touchdown'
legend('Desired', 'Simulation', 'Hard Constraint', 'Soft Constraint', 'Location', 'best')

%% Plot Propellant Remaining Vs Run # at Touchdown
figure(102), clf
N2_remaining = mN2_usable - N2_used; % [kg] reamining mass of fuel: neg. # = Too Much Used (BAD); pos. # = Extra Fuel Available (GOOD)
line(0:iter, zeros(iter+1,1), 'Color', 'r', 'LineStyle', '-');
hold on
scatter(Iteration, N2_remaining, [], 'b', '.')
axis([0 iter -1.5 1])
xlabel 'Iteration [#]'
ylabel 'Remaining N2 Fuel [kg]'
legend('Fuel Cutoff', 'Simulation Results', 'Location', 'best')
title 'Remaining N2 Fuel'
hold off

%% Plot Lateral Touchdown Velocity Vs. Run #
figure(103), clf
line(0:iter, zeros(iter+1,1), 'Color', 'r', 'LineStyle', '-')
hold on
scatter(Iteration, latVelEarth_final, [], 'b', '.')
xlabel 'Iteration [#]'
ylabel 'Lateral Velocity [m/s]'
title 'Lateral Velocities at Touchdown (Earth Cord Frame)'
legend('Ideal Lateral Velocity', 'Simulation Results', 'Location', 'best')
hold off

%% Plot Vertical Touchdown Velocity Vs. Run #
figure(104), clf
line(0:iter, zeros(iter+1,1)+IdealVertVel_Touchdown, 'Color', 'r', 'LineStyle', '-')
hold on
scatter(Iteration, vertVelEarth_final, [], 'b', '.')
xlabel 'Iteration [#]'
ylabel 'Vertical Velocity [m/s]'
title 'Vertical Velocities at Touchdown (Earth Cord Frame)'
legend('Ideal Vertical Velocity', 'Simulation Results', 'Location', 'best')
hold off

%% Plot Mission Trajectories for All Runs (z vs x Plane)
figure(105), clf
hold on
% plot all of the Monte Carl Sim Trajectories
for a = 1:iter
    plot(MissionTrajectorySims(a).x, MissionTrajectorySims(a).z, 'Color', [0.5 0.5 0.5])
end

% plot the nominal trajectories for reference
nomMission_HeadWind = load('nominalMissionTrajectory_HeadWind');
nomMission_TailWind = load('nominalMissionTrajectory_TailWind');
Traj_legend = plot(0,0, 'Color', [0.5 0.5 0.5]);
headWind_legend = plot(nomMission_HeadWind.x_data.Data, -nomMission_HeadWind.z_data.Data, 'Color', 'b', 'LineWidth', 2); % down is positive so flip z for graphing altitude
tailWind_legend = plot(nomMission_TailWind.x_data.Data, -nomMission_TailWind.z_data.Data, 'Color', 'r', 'LineWidth', 2); % down is positive so flip z for graphing altitude
title 'Monte Carlo Mission Trajectories (x-z plane)'
xlabel 'Downrange Position [m]'
ylabel 'Altitude [m]'
legend([Traj_legend headWind_legend tailWind_legend], {'Monte Carlo Sims', 'Nominal Trajectory w/ Headwind', 'Nominal Trajectory w/ Tailwind'}, 'Location', 'best')
hold off

%% Plot Mission Trajectories for All Runs (x vs time)
% plot all of the Monte Carl Sim Trajectories
figure(106), clf
hold on
for a = 1:iter
    plot(MissionTrajectorySims(a).time, MissionTrajectorySims(a).x, 'Color', [0.5 0.5 0.5])
end

% plot the nominal trajectories for reference
nomMission_HeadWind = load('nominalMissionTrajectory_HeadWind');
nomMission_TailWind = load('nominalMissionTrajectory_TailWind');
Traj_legend = plot(0,0, 'Color', [0.5 0.5 0.5]);
headWind_legend = plot(nomMission_HeadWind.x_data.Time, nomMission_HeadWind.x_data.Data, 'Color', 'b', 'LineWidth', 2); % down is positive so flip z for graphing altitude
tailWind_legend = plot(nomMission_TailWind.x_data.Time, nomMission_TailWind.x_data.Data, 'Color', 'r', 'LineWidth', 2); % down is positive so flip z for graphing altitude
title 'Monte Carlo Mission Trajectories (x-position)'
ylabel 'Downrange Position [m]'
xlabel 'Time [s]'
legend([Traj_legend headWind_legend tailWind_legend], {'Monte Carlo Sims', 'Nominal Trajectory w/ Headwind', 'Nominal Trajectory w/ Tailwind'}, 'Location', 'best')
hold off


%% Plot Maximum x-velocity For All Runs (Earth Cord)
