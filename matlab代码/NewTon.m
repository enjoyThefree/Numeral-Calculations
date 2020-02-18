clear;
clc;
% fun = 2* x^3 - 4* x^2 + 3*x - 6;
x0 = 0;
error = 1;
f = subs(myfunction,x0);
df = subs(diff(myfunction),x0);
while error > 0.0001
    f = double(subs(myfunction,x0));          %加上double是为了显示结果为小数
    df = double(subs(diff(myfunction),x0));
%     f = sin(x0)+ x0 + 1;
%     df = cos(x0) + 1;
    root = x0 - f/df;          %牛顿公式
    error = abs(x0 - root);    %更新误差
    x0 = root;                 %更新初始值
end
format long
root
