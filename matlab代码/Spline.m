clc;
clear;
% x = [1,2,4,5,6,8,9,11,13,15];
% y = [1,4,3,5.5,8,7,5,6,5.5,7];
% plot(x,y,'ko');

x = [ 0, 3, 5, 7, 9, 11, 12, 13, 14, 15 ];
y = [0,1.2,1.7,2.0,2.1,2.0,1.8,1.2,1.0,1.6 ];
% 
A = load('Spline.txt');
xx = A(:,1);
yy = A(:,2);
% 
plot(x,y,'ko',xx,yy,'g-');

hold on
