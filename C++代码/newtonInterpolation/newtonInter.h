#pragma once
#include<iostream>
#include<armadillo>
using namespace std;
using namespace arma;

double newtonInter(mat &x_mat,mat &a,int &n,double &X) {
	double result = 0.0;
	//����һ�ײ�ֵ���ڶ��ף�...������a[i,j]�����в��������ڱ仯��������
	for (int j = 1; j < n; j++) {
		for (int i = j; i < n; i++) {
			a(i, j) = (a(i, j - 1) - a(i - 1, j - 1)) / (x_mat(i) - x_mat(i - j));
			//cout << i << "\t" << j << "\t" << a(i, j) << endl;   //������ֵ
		}
	}
	//����(x-x0)(x-x1)...(x-xn-1)
	mat x_Multiplication;
	x_Multiplication.ones(n, 1);   //����һ��n*1��ȫ1����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			x_Multiplication(i) *= (X - x_mat[j]);
		}
		//���
		result += a(i, i) * x_Multiplication(i);
	}
	return result;
}