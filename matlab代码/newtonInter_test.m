% clear,clc;
% X = [0 pi/6 pi/4 pi/3 pi/2];  
% Y = [0 0.5 0.7071 0.8660 1];  
% x = linspace(0,pi,50);  
% M = 1;  
% [y,R,A,C,L] = newtonInter(X, Y, x, M);  
% y1 = sin(x);  
% errorbar(x,y,R,'.g')  
% hold on  
% plot(X, Y, 'or', x, y, '.k', x, y1, '-b');  
% legend('误差','样本点','牛顿插值估算','sin(x)'); 

% clear,clc;
% % X = [0 pi/6 pi/4 pi/3 pi/2  ];  
% % Y = [0 0.5 0.7071 0.8660 1];  
% X = [];
% x = linspace(0,pi,100);  
% [y,A,C,L] = newtonInter(X, Y, x);  
% % y1 = sin(x);  
% y1 = 1 / (25*x.^2);
% hold on  
% plot(X, Y, 'or', x, y, '.k', x, y1, '-b');  
% legend('样本点','牛顿插值估算','sin(x)');

% clear,clc;
% X = [-1, -0.5, 0, 0.5, 1];
% Y = [0.0385, 0.1379, 1, 0.1379, 0.0385];
% x = linspace(-1,1,200);  
% [y,A,C,L] = newtonInter(X, Y, x);   
% y1 = 1 ./ (1 + 25 * x.^2);
% hold on  
% plot(X, Y, 'or', x, y, '.k',x,y1,'-b');  
% legend('样本点','牛顿插值估算','1/(1+25x^2)');

clear,clc;
X = [-1, -0.75, -0.5, -0.25, 0, 0.25, 0.5, 0.75, 1];
Y = [0.0385, 0.0664, 0.1379, 0.39, 1, 0.39, 0.1379, 0.0664, 0.0385];
x = linspace(-1,1,200);  
% [y,A,C,L] = newtonInter(X, Y, x);   
% y1 = 1 ./ (1 + 25 * x.^2);
% hold on  
% plot(X, Y, 'or', x, y, '.k',x,y1,'-b');  
% legend('样本点','牛顿插值估算','1/(1+25x^2)');

y3 = piecelin(X,Y,x);
plot(X, Y, 'or', x, y3, '.k');  
legend('样本点','分段线性插值估算');

A = load('piecelin.txt');
xx = A(:,1);
yy = A(:,2);
% 
plot(X,Y,'ko',xx,yy,'.k');

hold on
