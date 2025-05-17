%  plot_LatVel_Sim_Data.m   Plot results from the Outer Loop Velocity Control Model

figure(80), clf
subplot(4,1,1), plot(out.r_V, 'LineWidth', 1.2, 'LineStyle',':'), grid
     ylabel('r  (m/s)')
         hold on
         plot(out.vx, 'LineWidth', 1.2)
         hold off
subplot(4,1,2), plot(out.e_V, 'LineWidth', 1.2), grid
     ylabel('e  (m/s)')
subplot(4,1,3), plot(out.u_V*r2d, 'LineWidth', 1.2), grid
     ylabel('u  (deg)')
subplot(4,1,4), plot(out.Theta_V*r2d, 'LineWidth', 1.2), grid
     ylabel('Theta  (deg)')


figure(85), clf
subplot(4,1,1), plot(out.Thrust_V, 'LineWidth', 1.2), grid
     ylabel('X Thrust  (N)')
subplot(4,1,2), plot(out.ax, 'LineWidth', 1.2), grid
     ylabel('ax  (m/s^2)')
subplot(4,1,3), plot(out.vx, 'LineWidth', 1.2), grid
     ylabel('vx  (m/s)')
subplot(4,1,4), plot(out.x, 'LineWidth', 1.2), grid
     ylabel('x  (m)')





