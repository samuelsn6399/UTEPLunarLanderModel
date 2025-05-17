%  Create_Bus_Objects.m    Create all needed Bus Objects
%
%       Bus Objects are required for nonvirtual buses
%       Only nonvirtual buses can contain variable-size signal elements
%       Nonvirtual buses require that all elements have the same sample time

    %  Need "BusElements" because the Bus crosses a Model Reference boundary

% %  Bus for Velocity in the Earth Frame
% clear elems
% elems = Simulink.BusElement();
% elems(1).Name = 'Vx';
% elems(2).Name = 'Vy';
% elems(3).Name = 'Vz';
% vbBus = Simulink.Bus();
% vbBus.Elements = elems;

    % %  Bus for Position in the Earth Frame
    % clear elems
    % elems = Simulink.BusElement();
    % elems(1).Name = 'x';
    % elems(2).Name = 'y';
    % elems(3).Name = 'z';
    % xeBus = Simulink.Bus();
    % xeBus.Elements = elems;


%  Bus for the Speed Command (Omega) to Each Motor
clear elems
elems = Simulink.BusElement();
elems(1).Name = 'M1';
elems(2).Name = 'M2';
elems(3).Name = 'M3';
elems(4).Name = 'M4';
MotorCmd_Bus = Simulink.Bus();
MotorCmd_Bus.Elements = elems;


%  Bus Object for the "States" Bus
  clear elems
    elems = Simulink.BusElement();
    elems(1).Name = 'Theta';
    elems(2).Name = 'q';
    elems(3).Name = 'dq';
    elems(4).Name = 'x';
    elems(5).Name = 'y';
    elems(6).Name = 'z';
    elems(7).Name = 'VxB';
    elems(8).Name = 'VyB';
    elems(9).Name = 'VzB';
    elems(10).Name = 'Axb';
    elems(11).Name = 'Ayb';
    elems(12).Name = 'Azb';
    elems(13).Name = 'Axe';
    elems(14).Name = 'Aye';
    elems(15).Name = 'Aze';
    elems(16).Name = 'VxE';
    elems(17).Name = 'VyE';
    elems(18).Name = 'VzE';
    States = Simulink.Bus();
    States.Elements = elems;

% %  Bus Object for the "Controller" Bus
%   clear elems
%       elems = Simulink.BusElement();
%       elems(1).Name = 'fire_Cmd';
%       elems(2).Name = 'LatMode';
%       elems(3).Name = 'xCmd';
%       elems(4).Name = 'yCmd';
%       elems(5).Name = 'NestedBus';
%           elems(5).DataType = 'Bus:  MotorCmd_Bus';
%       Controller = Simulink.Bus();
%       Controller.Elements = elems;











% ----------------------------------------------------------------------
% %  Need a BusElement because you are crossing a "Model Reference" boundary
%     ctrl = Simulink.Bus
%     elems = Simulink.BusElement
%     elems(1).Name = 'fire_Cmd'
%     elems(2).Name = 'Theta_Command'
%     ctrl.Elements = elems

% % % %  Control Data Bus Object     Removed May 5, 2024
% % %     elems = Simulink.BusElement();
% % %     elems(1).Name = 'fire_Cmd';
% % %     elems(2).Name = 'Theta_Cmd';
% % %     ctrl = Simulink.Bus();    
% % %     ctrl.Elements = elems;



% %  Bus Object for the "States" Bus
%     elems = Simulink.BusElement();
%     elems(1).Name = 'Theta';
%     elems(2).Name = 'q';
%     elems(3).Name = 'dq';
%     elems(4).Name = 'X';
%     elems(5).Name = 'V';
%     elems(6).Name = 'Ab';
%     elems(7).Name = 'Ae';
%     States = Simulink.Bus();
%     States.Elements = elems;

% %  Bus Object for the "States" Bus
%     elems = Simulink.BusElement();
%     elems(1).Name = 'Theta';
%     elems(2).Name = 'q';
%     elems(3).Name = 'dq';
%     elems(4,5,6).Name = 'X';
%     elems(7,8,9).Name = 'V';
%     elems(10,11,12).Name = 'Ab';
%     elems(13,14,15).Name = 'Ae';
%     States = Simulink.Bus();
%     States.Elements = elems;
