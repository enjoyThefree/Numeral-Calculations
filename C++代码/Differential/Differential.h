#pragma once
//#include<iostream>


const double eps = 1e-8;
double fun(double x) {
	double y = exp(x);
	return y;
}

//±ä²½³¤
//Central difference quotient = CDF
double CDF(double x) {
	double h = 0.4;
	double y1 = (fun(x + h) - fun(x - h)) / (2 * h);
	double y2 ,temp;
	do {
		h /= 2;
		y2 = (fun(x + h) - fun(x - h)) / (2 * h);
		temp = y1;
		y1 = y2;
	} while (fabs(temp - y2) > eps);

	return y2;
}