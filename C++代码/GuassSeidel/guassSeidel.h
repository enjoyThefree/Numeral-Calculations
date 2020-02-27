#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<armadillo>
#include<vector>
#include<iomanip>
#include"guassSeidel.h"
using namespace std;
using namespace arma;

const double err = 1e-6;
mat A;
vec X, b, X_temp;

void GreateA_mat(int &n) {
	A.zeros(n, n);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double temp;
			cout << "请输入系数" << '\t' << "A" << "(" << i << "," << j << ")" << " =   ";
			cin >> temp;
			A(i, j) = temp;
		}
	}
	A.print("A:");*/
	ifstream readfileA("A.txt", ios::in);
	if (!readfileA.is_open())
		cout << "Open file failure !" << endl;
	while (!readfileA.eof()) {
		for (int i = 0; i < 3; i++) {
			double a0, a1, a2;
			readfileA >> a0 >> a1 >> a2;
			A(i, 0) = a0;
			A(i, 1) = a1;
			A(i, 2) = a2;
		}
	}
	readfileA.close();
}

void Fillb_mat(int &n) {
	//cout << "请填充矩阵 b" << endl;
	b.zeros(n);
	ifstream readfileb("b.txt", ios::in);
	if (!readfileb.is_open())
		cout << "Open file failure !" << endl;
	while (!readfileb.eof()) {
		for (int i = 0; i < 3; i++) {
			double temp;
			readfileb >> temp;
			b(i) = temp;
		}
	}
	readfileb.close();
	/*for (int i = 0; i < n; i++) {
		double temp;
		cout << "请输入   " << "b" << i  << " =   ";
		cin >> temp;
		b(i) = temp;
	}
	b.print("b:");*/
}

void InitX_mat(int &n) {
	//cout << "请输入X矩阵的初始值 " << endl;
	X.zeros(n);
	/*for (int i = 0; i < n; i++) {
		double temp;
		cout << "请输入初始值   "  << "x"  << i  << " =   ";
		cin >> temp;
		X(i) = temp;
	}
	X.print("X:");*/
	ifstream readfileX("x.txt", ios::in);
	if (!readfileX.is_open())
		cout << "Open file failure !" << endl;
	while (!readfileX.eof()) {
		for (int i = 0; i < 3; i++) {
			double x;
			readfileX >> x;
			X(i) = x;
		}
	}
}

void saveDate(int &n) {
	ofstream outfileX("X_result.txt",ios::app);    //从文件末尾开始写，防止丢失文件中原来就有的内容
	if (!outfileX.is_open())
		cout << "Open file failure !" << endl;

	for (int i = 0; i < n; i++) {
		outfileX << X(i) << '\t';
	}
	outfileX << endl;
	outfileX.close();
}

void Iteration(int &n) {
	saveDate(n);
	cout << setprecision(6) << X(0) << '\t' << X(1) << '\t' << X(2) << endl;

	X_temp = X;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			sum += A(i, j)*X(j);
		}
		X(i) = 1 / A(i, i) * (b(i) - sum);
	}
	/*cout << setprecision(6) << X(0) << '\t' << X(1) << '\t' << X(2)<< endl;*/
}

void solve(int &n) {
	do {
		Iteration(n);
	} while (fabs(X(0) - X_temp(0)) > err);
}

void GuassSeidel(int &n) {
	cout << setprecision(6) << "x1" << '\t' << "x2" << '\t' << "x3" << endl;
	GreateA_mat(n);
	Fillb_mat(n);
	InitX_mat(n);
	cout << endl;
	solve(n);
}