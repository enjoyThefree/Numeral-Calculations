#include<iostream>
#include"integral.h"
#include<iomanip>
using namespace std;

const double eps = 1e-8;

int main()
{
	double resultT = T(fun2,  1, 2);
	cout << "���ι�ʽ������" << "\t" << setprecision(8) << resultT << endl;

	double resultS = S(fun2, 1, 2);
	cout << "����ɭ��ʽ������" << "\t" << setprecision(8) << resultS << endl;

	double resultTn = Tn(fun2, 1, 2, 100);
	cout << "�������ι�ʽ������" << "\t" << setprecision(8) << resultTn << endl;

	double resultT2n = T2n(fun2, 1, 2, eps);
	cout << "�䲽�����ι�ʽ������" << "\t" << setprecision(8) << resultT2n << endl;

	cout << endl;
	double resultSn = Sn(fun2, 1, 2);
	cout << "��������ɭ��ʽ������" << "\t" << setprecision(8) << resultSn << endl;
}