#include<iostream>
#include"Differential.h"
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double result = CDF(1);
	cout << "微分结果为：" << setprecision(8) << result << endl;
	//cout << exp(1) << endl;
	//cout << "Hello World !" << endl;
}