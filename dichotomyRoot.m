function root = dichotomyRoot()
%���ַ�
clear;
clc;
% syms U L;    %�����������޶�Ϊ����
f=@(x) sin(x)+x+1;    %������ĺ���������ֱ���ڱ������޸ĺ������Ϊ��������
U=input('���������������upper,U=');    
L=input('���������������lower,L=');
e=input('���������,e=');
while U-L > e    %�趨һ��������򾫶ȣ�Ȼ������ж�
    root = (U+L)/2;    %���������������������ʱ�����ö��ַ����¹滮�������
    if f(root)==0    
        break;    %rǡ��Ϊ�������ֱ������ѭ��
    end
    if f(root)*f(U)> 0    %�������ڶ����жϸ����ڵ�����
        U = root;
    else
        L = root;
    end
end
root    %ֱ������������ֵ

 
end

