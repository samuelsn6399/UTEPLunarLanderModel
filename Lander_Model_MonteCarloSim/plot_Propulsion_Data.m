%  plot_Propulsion_Data.m   Plot the Flight Path

yLimits_Now = [315 350];  % rad/s
figure(130), clf
subplot(4,1,1), plot(out.Propulsion.Omega.Omega1, 'LineWidth',1.2), grid
   ylabel ('Omega1', 'FontSize',12)
   title('Fan Motor Speeds  (rad/s)', 'FontSize',14)
   ylim( yLimits_Now )
subplot(4,1,2), plot(out.Propulsion.Omega.Omega2, 'LineWidth',1.2), grid
    ylabel ('Omega2', 'FontSize',12)
    ylim( yLimits_Now )
subplot(4,1,3), plot(out.Propulsion.Omega.Omega3, 'LineWidth',1.2), grid
    ylabel ('Omega3', 'FontSize',12)
    ylim( yLimits_Now )

subplot(4,1,4), plot(out.Propulsion.Omega.Omega4, 'LineWidth',1.2), grid
    ylabel ('Omega4', 'FontSize',12)
    ylim( yLimits_Now )

   xlabel ('Time  (s)', 'FontSize',12)
   set(gcf, 'Name', ['Motor Speed Commands'])


figure(132), clf
subplot(3,1,1), plot(out.Propulsion.M_Fans.Time, out.Propulsion.M_Fans.Data(:,1),  'LineWidth',1.2), grid
     ylabel ('Mx  (N-m)', 'FontSize',12)
     title('Moments from Electric Fans', 'FontSize',14)
subplot(3,1,2), plot(out.Propulsion.M_Fans.Time, out.Propulsion.M_Fans.Data(:,2),  'LineWidth',1.2), grid
     ylabel ('My  (N-m)', 'FontSize',12)
subplot(3,1,3), plot(out.Propulsion.M_Fans.Time, out.Propulsion.M_Fans.Data(:,3),  'LineWidth',1.2), grid
     ylabel ('Mz  (N-m)', 'FontSize',12)
     xlabel ('Time  (s)', 'FontSize',12)
     set(gcf, 'Name', ['Moments from Fans'])

figure(134), clf
subplot(3,1,1), plot(out.Propulsion.M_prop.Time, out.Propulsion.M_prop.Data(:,1),  'LineWidth',1.2), grid
     ylabel ('Mx  (N-m)', 'FontSize',12)
     title('Moments from Propulsion System', 'FontSize',14)
subplot(3,1,2), plot(out.Propulsion.M_prop.Time, out.Propulsion.M_prop.Data(:,2),  'LineWidth',1.2), grid
     ylabel ('My  (N-m)', 'FontSize',12)
subplot(3,1,3), plot(out.Propulsion.M_prop.Time, out.Propulsion.M_prop.Data(:,3),  'LineWidth',1.2), grid
     ylabel ('Mz  (N-m)', 'FontSize',12)
     xlabel ('Time  (s)', 'FontSize',12)
     set(gcf, 'Name', ['Moments from Prop Sys'])

    
figure(142), clf
subplot(3,1,1), plot(out.Propulsion.F_Fans.Time, out.Propulsion.F_Fans.Data(:,1),  'LineWidth',1.2), grid
     ylabel ('Fx  (N)', 'FontSize',12) 
     title('Forces from Electric Fans', 'FontSize',14)
subplot(3,1,2), plot(out.Propulsion.F_Fans.Time, out.Propulsion.F_Fans.Data(:,2),  'LineWidth',1.2), grid
     ylabel ('Fy  (N)', 'FontSize',12)
subplot(3,1,3), plot(out.Propulsion.F_Fans.Time, out.Propulsion.F_Fans.Data(:,3),  'LineWidth',1.2), grid
     ylabel ('Fz  (N)', 'FontSize',12)
     xlabel ('Time  (s)', 'FontSize',12)
     set(gcf, 'Name', ['Forces from Fans'])

figure(144), clf
subplot(3,1,1), plot(out.Propulsion.F_CE.Time, out.Propulsion.F_CE.Data(:,1),  'LineWidth',1.2), grid
     ylabel ('Fx  (N)', 'FontSize',12) 
     title('Forces from the Center Engine', 'FontSize',14)
subplot(3,1,2), plot(out.Propulsion.F_CE.Time, out.Propulsion.F_CE.Data(:,2),  'LineWidth',1.2), grid
     ylabel ('Fy  (N)', 'FontSize',12)
subplot(3,1,3), plot(out.Propulsion.F_CE.Time, out.Propulsion.F_CE.Data(:,3),  'LineWidth',1.2), grid
     ylabel ('Fz  (N)', 'FontSize',12)
     xlabel ('Time  (s)', 'FontSize',12)
     set(gcf, 'Name', ['Forces from CE'])



 figure(146), clf
subplot(3,1,1), plot(out.Propulsion.F_prop.Time, out.Propulsion.F_prop.Data(:,1),  'LineWidth',1.2), grid
     ylabel ('Fx  (N)', 'FontSize',12)
     title('Forces from Propulsion System', 'FontSize',14)
subplot(3,1,2), plot(out.Propulsion.F_prop.Time, out.Propulsion.F_prop.Data(:,2),  'LineWidth',1.2), grid
     ylabel ('Fy  (N)', 'FontSize',12)
subplot(3,1,3), plot(out.Propulsion.F_prop.Time, out.Propulsion.F_prop.Data(:,3),  'LineWidth',1.2), grid
     ylabel ('Fz  (N)', 'FontSize',12)
     xlabel ('Time  (s)', 'FontSize',12)
     set(gcf, 'Name', ['Forces from Prop Sys'])
