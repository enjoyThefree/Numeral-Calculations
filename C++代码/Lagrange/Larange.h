#pragma once
#include<vector>
using namespace std;

double Larange(vector<double> &arrX, vector<double> &arrY, int &length, double &X) {
	double yResult = 0;      //��������ʼ��
	vector<double> LResult;     //��ÿ���������洢����

	for (int i = 0; i < length; i++) {
		double Molecule = 1.0;            //�����۳˻�
		double Denominator = 1.0;		//��ĸ�۳˻�
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