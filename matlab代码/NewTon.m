clear;
clc;
% fun = 2* x^3 - 4* x^2 + 3*x - 6;
x0 = 0;
error = 1;
f = subs(myfunction,x0);
df = subs(diff(myfunction),x0);
while error > 0.0001
    f = double(subs(myfunction,x0));          %����double��Ϊ����ʾ���ΪС��
    df = double(subs(diff(myfunction),x0));
%     f = sin(x0)+ x0 + 1;
%     df = cos(x0) + 1;
    root = x0 - f/df;          %ţ�ٹ�ʽ
    error = abs(x0 - root);    %�������
    x0 = root;                 %���³�ʼֵ
end
format long
root
