#include<iostream>
#include<armadillo>
#include"newtonInter.h"
using namespace std;
using namespace arma;
int main()
{
	double x[] = { 0, 2,3,5};
	double y[] = { 1,3,2,5 };
	int  n = sizeof(x) / sizeof(x[0]);
	mat a, x_mat;
	a.zeros(n, n);              //创建一个n*n的全零矩阵
	x_mat.zeros(n, 1);
	//第一列存放y(x)的值
	for (int i = 0; i < n; i++) {
		a(i, 0) = y[i];
		x_mat(i) = x[i];
	}

	double X;
	cout << "请输入要计算的值X, X = ";
	cin >> X;
	cout << endl;

	double result = newtonInter(x_mat, a, n, X);
	cout << "所求的函数值y为，y = " << result << endl;
}