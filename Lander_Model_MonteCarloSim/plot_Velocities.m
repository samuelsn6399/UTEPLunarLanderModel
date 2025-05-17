%  plot_Velocities.m       Plot the velocity in the Earth and in the Body frames

figure(75), clf
subplot(2,1,1), plot(out.Nav.VxE, 'LineWidth',1.2), grid
      hold on
      plot(out.Nav.Vx, 'LineWidth',1.2)
      hold off
      ylabel ('Vx', 'FontSize',12)
      legend('Earth Frame', 'Body Frame')

subplot(2,1,2), plot(out.Nav.VzE, 'LineWidth',1.2), grid
hold on
      plot(out.Nav.Vz, 'LineWidth',1.2)
      hold off
      ylabel ('Vz', 'FontSize',12)
      legend('Earth Frame', 'Body Frame')
 xlabel ('Time  (s)', 'FontSize',12)
 title('Velocities in the Bodey & Earth Frames', 'FontSize',14)
