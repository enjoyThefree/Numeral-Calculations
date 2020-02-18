clc;
clear;
% x = -pi:pi;
% y = sin(x);
% x_ = -pi:.1:pi;
x = [ 0, 3, 5, 7, 9, 11, 12, 13, 14, 15 ];
y = [0,1.2,1.7,2.0,2.1,2.0,1.8,1.2,1.0,1.6 ];
x_ = 0:.1:15;
% p1 = pchip(x,y,x_); % 分段三次Hermite插值
p1 = spline(x,y,x_); % 分段三次样条插值
% plot(x,y,'ko',x_,p1,'r-',x_,p2,'b-')
plot(x,y,'ko',x_,p1,'b.')
legend('插值节点','分段三次样条插值','location','southeast')
