%  plot_Velocities_Earth_and_Body.m       Plot the Velocities in the Earth and in the Body Frames

% figure(1), clf
% plot(r2d*out.Nav.Theta, 'LineWidth',1.2), grid
%   ylabel('Theta  (deg)', 'FontSize',12)
%   xlabel('Time  (s)', 'FontSize',12)
%   set(gcf, 'Name', 'Theta')

figure(68), clf
subplot(2,1,1), plot(out.Nav.VxB), grid
     hold on
        plot(out.Nav.VxE,  'Linestyle', '--', 'LineWidth', 1.5)
        hold off
        ylabel('Vx  (m/s)', 'FontSize',12)
        legend('V Body (w)', 'V Earth', 'FontSize', 12) 
        title('Velocities:  Body & Earth Frames', 'FontSize',14)
subplot(2,1,2), plot(out.Nav.VzB), grid
        hold on
        plot(out.Nav.VzE,  'Linestyle', '--', 'LineWidth', 1.5)
        hold off
  ylabel('Vz  (m/s)', 'FontSize',12)
  xlabel('Time  (s)', 'FontSize',12)
  set(gcf, 'Name', 'Vxz Earth & Body')
