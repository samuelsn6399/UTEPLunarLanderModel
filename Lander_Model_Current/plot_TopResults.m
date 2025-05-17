%  plot_TopResults.m     Plot(s) you want to generate last and therefore be 
%                               on the top of any other plots

% a_xz = out.Nav.Ae;
% v_xz = out.Nav.Vb;
% x_xz = out.Nav.Xe;

figure(10), clf
% subplot(4,1,1), plot(out.Control.fire_Cmd, 'LineWidth',1.2), grid
subplot(4,1,1), plot(out.Controls.fire_Cmd, 'LineWidth',1.2), grid
   ylim([-0.1  1.1])
   xlim([ 0 20])
   ylabel ('CE Fire Cmd', 'FontSize',12)
   title('CE Fire Command, Acceleration, Velocity & Position', 'FontSize',14)
subplot(4,1,2), plot(out.Nav.Aze.Time, -1*out.Nav.Aze.Data), grid
   ylabel ('ddh  (m/s^2)', 'FontSize',12)
subplot(4,1,3), plot(out.Nav.VzE.Time, -1*out.Nav.VzE.Data), grid
   ylabel ('dh  (m/s)', 'FontSize',12)
subplot(4,1,4), plot(out.Nav.z.Time, -1*out.Nav.z.Data), grid
   ylabel ('h  (m)', 'FontSize',12)
   xlabel ('Time  (s)', 'FontSize',12)
   set(gcf, 'Name', 'a, hDot, h')


figure(85), clf
plot(out.Controls.fire_Cmd, 'LineWidth',1.2), grid
   ylabel ('Center Engine Fire Cmd', 'FontSize',12)
   xlabel ('Time  (s)', 'FontSize',12)
   title('Center Engine Fire Command', 'FontSize',14)
   ylim([-0.02  1.02])

% figure(10), clf
% subplot(4,1,1), plot(out.Control.fire_Cmd, 'LineWidth',1.2), grid
% % subplot(4,1,1), plot(out.Control.fireCmd.Time,out.Control.fireCmd.Data, 'LineWidth',1.2), grid
%    ylabel ('CE Fire Cmd', 'FontSize',12)
%    title('CE Fire Command, Acceleration, Velocity & Position', 'FontSize',14)
% subplot(4,1,2), plot(a_xz.Time, -a_xz.Data(:,2)), grid
%    ylabel ('ddh  (m/s^2)', 'FontSize',12)
% subplot(4,1,3), plot(v_xz.Time, -v_xz.Data(:,2)), grid
%    ylabel ('dh  (m/s)', 'FontSize',12)
% subplot(4,1,4), plot(x_xz.Time, -x_xz.Data(:,2)), grid
%    ylabel ('h  (m)', 'FontSize',12)
%    xlabel ('Time  (s)', 'FontSize',12)
%    set(gcf, 'Name', 'a, hDot, h')


