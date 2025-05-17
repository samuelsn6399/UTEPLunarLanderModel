%  plot_Controller_Outputs.m  Plot Outputs of the FCS (Flight Control System)

 
figure(210), clf
subplot(3,1,1), plot(out.Controls.fire_Cmd, 'LineWidth',1.2), grid
   ylabel ('CE Fire Cmd', 'FontSize',12)
   title('Controller Outputs', 'FontSize',14)
subplot(3,1,2), plot(out.Controls.xCmd, 'LineWidth',1.2), grid
   ylabel ('xCmd  (m)', 'FontSize',12)
subplot(3,1,3), plot(out.Controls.yCmd, 'LineWidth',1.2), grid
   ylabel ('yCmd  (m)', 'FontSize',12)
   xlabel ('Time  (s)', 'FontSize',12)
   set(gcf, 'Name', 'Controller Out')


figure(220), clf
subplot(4,1,1), plot(out.Controls.OmegaCmds.M1, 'LineWidth',1.0), grid
   ylabel ('Motor 1', 'FontSize',12)
   title('Motor Speed Commands  (rad/s)', 'FontSize',14)
subplot(4,1,2), plot(out.Controls.OmegaCmds.M2, 'LineWidth',1.0), grid
   ylabel ('Motor 2', 'FontSize',12)
subplot(4,1,3), plot(out.Controls.OmegaCmds.M3, 'LineWidth',1.0), grid
   ylabel ('Motor 3', 'FontSize',12)
subplot(4,1,4), plot(out.Controls.OmegaCmds.M4, 'LineWidth',1.0), grid
   ylabel ('Motor 4', 'FontSize',12)
   xlabel ('Time  (s)', 'FontSize',12)
   set(gcf, 'Name', 'Motor Speed Commands')
