function y = Derivative()
syms x;
y = diff(sin(x)+x+1);
end