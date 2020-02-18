%¼òµ¥µü´ú
function x = simple_iter(fun,x0,n)
x = zeros(n+1,1);
x(1) = x0;
for k=1:n
    x(k+1) = fun(x(k))
end
end

