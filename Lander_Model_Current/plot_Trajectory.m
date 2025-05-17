%  plot_Trajectory.m   Plot the Flight Path

figure(120), clf
subplot(4,1,1), plot(out.Nav.x, 'LineWidth',1.2), grid
   ylabel ('X  (m)', 'FontSize',12)
   title('Mission Trajectory', 'FontSize',14)
subplot(4,1,2), plot(-1*out.Nav.z), grid
   ylabel ('h  (m)', 'FontSize',12)
subplot(4,1,3), plot(out.Nav.VxE), grid
   ylabel ('VxE  (m/s)', 'FontSize',12)

subplot(4,1,4), plot(r2d*out.Nav.Theta), grid
   ylabel ('Theta  (deg)', 'FontSize',12)
   xlabel ('Time  (s)', 'FontSize',12)
   set(gcf, 'Name', 'X, h, Vx, Theta')


figure(122), clf
plot(out.Nav.x.Data, -1*out.Nav.z.Data, 'LineWidth',1.2), grid
   ylabel ('Altitude (m)', 'FontSize',12)
   xlabel ('Downrange Position (m)', 'FontSize',12)
   title('Mission Trajectory', 'FontSize',14)
   set(gcf, 'Name', 'Profile  (h vs Downrange)')


err_xPosition = out.Controls.xCmd.Data - out.Nav.x.Data;  % m     Position Error
% figure(126), clf
% plot(out.Controls.xCmd.Time, err_xPosition), grid
%    ylabel ('X Error  (m)', 'FontSize',12)
%    xlabel ('Time  (s)', 'FontSize',12)
%     title('X Position Error', 'FontSize',14)
%    set(gcf, 'Name', 'X Error')
% 
% 
% 
% figure(127), clf
% plot(out.Controls.xCmd, 'LineStyle', '--', 'LineWidth', 1.5), grid
%    hold on
%         plot(out.Nav.x)
%         hold off
%    ylabel ('X Position  (m)', 'FontSize', 12)
%    xlabel ('Time  (s)', 'FontSize',12)
%    title('X Command & Position', 'FontSize', 14)
%    legend('X Command', 'X Position', 'FontSize',12)
%        set(gcf, 'Name', 'X Cmd and Position')


figure(129), clf
subplot(4, 1, [1:3]), plot(out.Controls.xCmd, 'LineStyle', '--', 'LineWidth', 1.5), grid
     hold on
          plot(out.Nav.x)
          hold off
     ylabel ('X Position  (m)', 'FontSize', 12 )
       title('X Command & Position', 'FontSize', 14)
      legend('X Command', 'X Position', 'FontSize',12)
        hold on
        subplot(4, 1, 4),  plot(out.Controls.xCmd.Time, err_xPosition), grid
        hold off
   ylabel ('Error  (m)', 'FontSize', 12 )
   xlabel ('Time  (s)', 'FontSize',12)
 
  
       set(gcf, 'Name', 'X Cmd and Position')
