//#include<iostream>
//#include<armadillo>
//#include<iomanip>
#include"romberg.h"
//using namespace std;
//using namespace arma;

int main()
{
	const double eps = 1e-6;
	int size = 50;
	Romberg.zeros(size, 4);
	Coefficient << 4 / 3.0 << 1 / 3.0 << endr
		<< 16 / 15.0 << 1 / 15.0 << endr
		<< 64 / 63.0 << 1 / 63.0 << endr;

	double a =1, b=2;
	cout << "�������������, a = ";
	cin >> a;
	cout  << "�������������, b = ";
	cin >> b;
	cout << endl;
	double result = getSn(a, b, eps);
	cout << "���ֽ��Ϊ��" << setprecision(8) << result << endl;
}

