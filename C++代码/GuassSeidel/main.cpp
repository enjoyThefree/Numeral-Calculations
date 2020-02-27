#include<iostream>
#include<armadillo>
#include<vector>
#include<iomanip>
#include"guassSeidel.h"

int main()
{
	int n;
	cout << "请输入未知数个数n，n = ";
	cin >> n;
	cout << endl;

	GuassSeidel(n);
}