clc;
clear;
% x = -pi:pi;
% y = sin(x);
% x_ = -pi:.1:pi;
x = [ 0, 3, 5, 7, 9, 11, 12, 13, 14, 15 ];
y = [0,1.2,1.7,2.0,2.1,2.0,1.8,1.2,1.0,1.6 ];
x_ = 0:.1:15;
% p1 = pchip(x,y,x_); % �ֶ�����Hermite��ֵ
p1 = spline(x,y,x_); % �ֶ�����������ֵ
% plot(x,y,'ko',x_,p1,'r-',x_,p2,'b-')
plot(x,y,'ko',x_,p1,'b.')
legend('��ֵ�ڵ�','�ֶ�����������ֵ','location','southeast')
