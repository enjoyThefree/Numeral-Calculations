#pragma once
#include<vector>
using namespace std;

double Larange(vector<double> &arrX, vector<double> &arrY, int &length, double &X) {
	double yResult = 0;      //计算结果初始化
	vector<double> LResult;     //将每个基函数存储起来

	for (int i = 0; i < length; i++) {
		double Molecule = 1.0;            //分子累乘积
		double Denominator = 1.0;		//分母累乘积
		for (int j = 0; j < length; j++) {
			if (i == j)
				continue;			//  i!=j
			Molecule *= (X - arrX[j]);
			Denominator *= (arrX[i] - arrX[j]);
		}
		double L = Molecule / Denominator;
		LResult.push_back(L);
	}

	for (int i = 0; i < length; i++) {
		yResult += arrY[i] * LResult[i];
	}
	return yResult;
}