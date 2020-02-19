#pragma once
#include<iostream>
using namespace std;
double fun1(double x) {
	double y = 1 / x;
	return y;
}
double fun2(double x) {
	double y = log(3 + pow(x,2)) / (1 + pow(x, 2));
	return y;
}


//梯形公式
double T(double(*f)(double), double a, double b) {
	double result = 0.0;
	result = 0.5 * (b - a) * (f(a) + f(b));
	return result;
}

//辛普森公式
double S(double(*f)(double), double a, double b) {
	double result = 0.0;
	result = 1 / 6.0 * (b - a) * ( f(a) + f(b) + 4 * f( (a + b) / 2.0) );
	return result;
}

//复化梯形公式
double Tn(double(*f)(double), double a, double b, int n) {
	double result = 0.0;
	double h = (b - a) / n;
	result = h / 2.0 * (f(a) + f(b));
	for (int k = 1; k < n; k++) {
		double x = a + k * h;
		result += h * f(x);
	}
	return result;
}

//变步长梯形积分
double T2n(double(*f)(double), double a, double b, double error) {
	int n = 1;   
	double h = (b - a) / n;
	double Tn = (f(a) + f(b)) * h / 2.0;  //计算 n=1 时的积分，粗略值
	double T2n;     //步长变为一半后的积分值
	bool key = false;
	do {    //至少循环一次
		double Hn = 0.0;
		for (int k = 0; k < n; k++) {
			double x = a + (k + 0.5) * h;
			Hn += h * f(x);
		}
		T2n = (Tn + Hn) / 2.0;
		//判断误差
		if (fabs(Tn - T2n) < error) {
			key = true;
		}
		else {
			Tn = T2n;
			n *= 2;
			h /= 2;
		}

	} while (!key);
	return T2n;
}

//复化辛普森公式
double Sn(double(*f)(double), double a, double b) {
	int n;
	cout << "正在使用复化辛普森公式，请输入分段个数n, 要求为偶数。 n =";
	cin >> n;
	/*cout << endl;*/
	while (n % 2) {
		cout << "输入n要求为偶数，请重新输入, n = ";
		cin >> n;
		cout << endl;
	}
	double result = 0.0;
	double h = (b - a) / n;
	result = h / 3.0 * (f(a) + f(b));
	for (int k = 1; k < n; k++) {
		double x = a + k * h;
		if (k % 2 == 0) {
			result += h / 3.0 * 2 * f(x);
		}
		else {
			result += h / 3.0 * 4 * f(x);
		}
	}
	return result;
}