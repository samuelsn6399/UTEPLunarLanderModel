function add_text(xText, yText, gS, ColorBackGround, ColorText)
%  add_text.m  Add the text in variable "gS" to the current plot

if nargin < 4  % Default BackGround Color
%     ColorBackGround = [0.98 0.97 0.7];  % [1  0.97  0.78]
    ColorBackGround = 'none';
end

if nargin < 5  % Default Text Color
    ColorText = [0 0 0];  
end

axis_now = axis;
xText = axis_now(1) + xText*(axis_now(2) - axis_now(1));
yText = axis_now(3) + yText*abs((axis_now(4) - axis_now(3)));
% disp([mat2str(axis_now) '  x = ' num2str(xText) '  y = ' num2str(yText) ])
text(xText,yText,gS,'FontSize',12,'FontWeight','normal', ...
              'BackGroundColor',ColorBackGround, 'Color',ColorText);
