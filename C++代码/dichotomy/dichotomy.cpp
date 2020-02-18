// dichotomy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
double fun(double x);
int main()
{
	double L, U, e, result;
	cout << "请输入求根区域下限lower,L=";
	cin >> L;
	cout << "请输入求根区域上限upper,U=";
	cin >> U;
	cout << "请输入误差限error,e=";
	cin >> e;

	while (abs(U - L) > e) {
		double root = (U + L) / 2.0;
		//double y = fun(root);
		if (fun(root) == 0)
			break;
		if (fun(root) * fun(U) > 0)
			U = root;
		else
			L = root;
		result = root;
	}
	cout << "方程的根为" << result << endl;
}

double fun(double x) {
	double y = sin(x) + x + 1;
	return y;
}
