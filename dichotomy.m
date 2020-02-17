%二分法
clear;
clc;
syms U L;    %将区间上下限定为变量
f=@(x) sin(x)+x+1;    %求给定的函数，可以直接在本行中修改后面代码为其他函数
U=input('输入求根区域上限upper,U=');    
L=input('输入求根区域下限lower,L=');
while U-L>0.000001    %设定一个求根区域精度，然后进行判断
    root=(U+L)/2;    %当根的区间大于所给精度时，利用二分法重新规划求根区间
    if f(root)==0    
        break;    %r恰好为所求根，直接跳出循环
    end
    if f(root)*f(U)<0    %用零点存在定理判断根所在的区域
        L=root;
    else
        U=root;
    end
end
root    %直接输出所求根的值

 