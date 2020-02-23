#pragma once
#include<iostream>
#include<math.h>
#include<armadillo>
#include<iomanip>
#include<vector>
using namespace std;
using namespace arma;

mat Romberg;                            //用于存放T、S、 C、R
mat Coefficient;                        //存放 计算系数
// 记录坐标值
vector<double> x_vec;
vector<double> y_vec;

// 积分函数
double fun(double x) {
	double y = log(1 + pow(x, 2)) / (1 + pow(x, 2));
	return y;
}

//存储对应坐标
void GreatXY(double a, double b, int n) {
	x_vec.clear();
	y_vec.clear();
	double h = (b - a) / n;
	for (int k = 0; k <= n; k++) {
		double x = a + h * k;
		double y = fun(x);
		x_vec.push_back(x);
		y_vec.push_back(y);
	}
}
/*变步梯形积分
   a:积分下限
   b:积分上限
   n:节点数
   s_mat:存放Tn、Sn、Cn、Rn的矩阵
   f: 积分函数*/
double getTn(double a, double b, int n)
{
	GreatXY(a, b, n);
	double h = (b - a) / n;
	double Tn = h / 2.0 * (fun(a) + fun(b));
	for (int k = 1; k < n; k++) {
		double x = a + k * h;
		Tn += h * fun(x);
	}
	return Tn;
}

void FillMatrix(double &a, double &b) {
	//填充Tn
	for (int k = 0; k <= 4; k++) { //先计算k =0,1,2,3,4的情况，即将S1、S2计算出来，在|S1-S2|不符合误差情况时在更新矩阵。
		Romberg(k, 0) = getTn(a, b, pow(2, k));
	}

	//填充Sn(i=1)、Cn(i=2)、Rn(i=3)       //编程思想的行列，从零开始
	for (int i = 1; i <= 3; i++) {       //列
		for (int j = i; j <= 4; j++) {    //行
			Romberg(j, i) = Romberg(j, i - 1)*Coefficient(i - 1, 0) - Romberg(j - 1, i - 1)*Coefficient(i - 1, 1);
		}
	}
}

double getSn(double a, double b,double eps){
	FillMatrix(a, b);
	//判断误差
	if (fabs(Romberg(4, 3) - Romberg(3, 3)) < eps) {
		return Romberg(4, 3);
	}
	else 
	{
		for (int k = 5;; k++) {
			Romberg(k, 0) = getTn(a, b, pow(2, k));     //T
			Romberg(k, 1) = 4 / 3.0 *Romberg(k, 0) - 1 / 3.0*Romberg(k - 1, 0);           //S
			Romberg(k, 2) = 16 / 15.0*Romberg(k, 1) - 1 / 15.0*Romberg(k - 1, 1);      //C
			Romberg(k, 3) = 64 / 63.0 *Romberg(k, 2) - 1 / 63.0*Romberg(k - 1, 2);     //R
			//再次比较
			if (fabs(Romberg(k, 3) - Romberg(k-1, 3)) < eps) {
				return Romberg(k, 3);
				break;
			}

			if (k >= 50) {
				cout << "循环次数太多，请更换程序算法";
				return -1;
				break;
			}
		}

	}
}