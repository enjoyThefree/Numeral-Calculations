#include<iostream>
#include<armadillo>
#include<vector>
#include<iomanip>
#include"guassSeidel.h"

int main()
{
	int n;
	cout << "������δ֪������n��n = ";
	cin >> n;
	cout << endl;

	GuassSeidel(n);
}