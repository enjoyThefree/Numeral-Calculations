#include <iostream>
#include"function.h"
using namespace std;

int main()
{
	/* ţ�ٵ����� �󷽳̸� */
	//double x0, err, e, root;
	//cout << "�������ʼֵx0, x0 = "  ;
	//cin >> x0;
	//cout << "�����������e, e = ";
	//cin >> e;
	//err = 10;				    //����һ���ϴ������ʹ�����ѭ��
	//while (err > e) {
	//	int n = 1;                   //��������
	//	double x = x0;
	///*	double f = 2.0 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
	//	double df = 6 * pow(x, 2) - 8 * x + 3;*/
	//	double f = Original_equation(x);
	//	double df = Integral_equation(x);
	//	x = x0 - f / df;
	//	root = x;
	//	err = fabs(x0 - root);
	//	x0 = x;

	//	n++;
	//	if (n > 150) {
	//		cout << "��������̫�࣬������㷨�����Ƴ�����" << endl;
	//		break;
	//	}
	//}
	/*�ҽط�*/
	double x0, x1, error;
	double x ;
	double root;
	int n = 0;
	cout << "�������ʼֵx0, x0 = ";
	cin >> x0;
	cout << "�������ʼֵx1, x1 = ";
	cin >> x1;
	cout << "�����������error, error = ";
	cin >> error;
	while (fabs(x1 - x0) > error) {
		double s = equation2(x1, x0);
		root = x1 - equation1(x1) / s;
		x0 = x1;
		x1 = root;

		n++;
		if (n > 150) {
			cout << "��������̫�࣬������㷨�����Ƴ�����" << endl;
		    break;
		}
	}
	cout << "���̵ĸ�Ϊ��root = " << root << endl;
	//cout << "Hello World!" << endl;
}

