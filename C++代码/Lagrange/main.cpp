#include<iostream>
#include<vector>
#include"Larange.h"
using namespace std;

int main()
{
	double x[] = { 0, 3, 5, 7, 9, 11, 12, 13, 14, 15 };
	double y[] = { 0, 1.2, 1.7, 2.0, 2.1, 2.0, 1.8, 1.2, 1.0, 1.6 };
	int  length = sizeof(x) / sizeof(x[0]);
	vector<double> arrX, arrY;
	for (int i = 0; i < length; i++) {
		arrX.push_back(x[i]);
		arrY.push_back(y[i]);
	}
	int length1 = arrX.size();
	double X;
	cout << "����������Ĳ�ֵ���Xֵ������X = " ;
	cin >> X;
	cout << endl;

	double result = Larange(arrX, arrY, length, X);

	cout << "lagrange����õ�X��Ӧ�ĺ���ֵΪ��y = " << result << endl;
	cout << "Hello World !" << endl;
}