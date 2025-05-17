%  plot_Wind_Speed.m  

figure(50), clf
plot(out.windSpeed), grid
   ylabel('Wind Speed  (m/s)', 'FontSize', 12)
   xlabel('Time  (s)', 'FontSize', 12)
   title('Wind Speed', 'FontSize',14)
   clear gS
        gS{1} = ['Base Wind Speed = ' num2str(windSpeed_knots) ' knots   ('  num2str(windSpeed,3) ...
                       ' m/s  or  '  num2str(windSpeed*mps2mph,3) ' mph)' ] ; 
        gS{2} = ['Wind Direction:   ' num2str(wind_angle) ' deg'];
        if wind_Gust_On == 1
            gS{3} = ['Wind Gust is ON'];
            gS{4} = ['     Gust Factor = ' num2str(gustFactor) ];
            gS{5} = ['     Gust Starts at ' num2str(tGust_Start)  ' sec' ];
            gS{6} = ['     Gust Duration = ' num2str(gustDuration)  ' sec' ];
            gS{7} = ['     Gust Ends at ' num2str(tGust_End)  ' sec' ];
        else
            gS{3} = ['NO Wind Gust'];
        end
            
       bkColor = [1 1 0.96];
       % txtColor = [0.1  0.1  0.85];  %   Blue
       txtColor = [0.1  0.1  0.1]; %
       % add_text(0.05, 0.85, gS, bkColor,txtColor)
       add_text(0.05, 0.80, gS)
set(gcf, 'Name', 'Wind Speed')

