%  modify_Simulink.m   Modify the Format of some Simulink Blocks

disp('--------------------')
clear colorDesired
BlockType_ToChange = 'Outport';  %  Inport   Outport
                  
blks = find_system(bdroot,'LookUnderMasks','all', 'FollowLinks','on', ...
                      'blockType',BlockType_ToChange)  % The whole model

disp(['  Modifying ' num2str( length(blks) ) ' Blocks' ])
    %colorDesired = '[0  1  1]'; % cyan
    %  colorDesired = '[0.96 0.73 1]'; % Electric Lavender
    %  colorDesired = '[0.77 0.38 0.06]'; % Alloy Orange
    colorDesired = '[1 0.62 0.4]'; % Copper
    %  colorDesired = '[0.34 0.63 0.83]'; % Carolina Blue
    %  colorDesired = '[1 0.5 0.75]'; % Pink
    
disp(['  ** Changing ' BlockType_ToChange ':  Color = ' colorDesired ])

for jj = 1 : length(blks)
   set_param(blks{jj},'FontSize','14', ...
                        'BackgroundColor',colorDesired)
end
