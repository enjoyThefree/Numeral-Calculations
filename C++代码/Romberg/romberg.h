#pragma once
#include<iostream>
#include<math.h>
#include<armadillo>
#include<iomanip>
#include<vector>
using namespace std;
using namespace arma;

mat Romberg;                            //���ڴ��T��S�� C��R
mat Coefficient;                        //��� ����ϵ��
// ��¼����ֵ
vector<double> x_vec;
vector<double> y_vec;

// ���ֺ���
double fun(double x) {
	double y = log(1 + pow(x, 2)) / (1 + pow(x, 2));
	return y;
}

//�洢��Ӧ����
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
/*�䲽���λ���
   a:��������
   b:��������
   n:�ڵ���
   s_mat:���Tn��Sn��Cn��Rn�ľ���
   f: ���ֺ���*/
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
	//���Tn
	for (int k = 0; k <= 4; k++) { //�ȼ���k =0,1,2,3,4�����������S1��S2�����������|S1-S2|������������ʱ�ڸ��¾���
		Romberg(k, 0) = getTn(a, b, pow(2, k));
	}

	//���Sn(i=1)��Cn(i=2)��Rn(i=3)       //���˼������У����㿪ʼ
	for (int i = 1; i <= 3; i++) {       //��
		for (int j = i; j <= 4; j++) {    //��
			Romberg(j, i) = Romberg(j, i - 1)*Coefficient(i - 1, 0) - Romberg(j - 1, i - 1)*Coefficient(i - 1, 1);
		}
	}
}

double getSn(double a, double b,double eps){
	FillMatrix(a, b);
	//�ж����
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
			//�ٴαȽ�
			if (fabs(Romberg(k, 3) - Romberg(k-1, 3)) < eps) {
				return Romberg(k, 3);
				break;
			}

			if (k >= 50) {
				cout << "ѭ������̫�࣬����������㷨";
				return -1;
				break;
			}
		}

	}
}