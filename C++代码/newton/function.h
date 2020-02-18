#pragma once
double Original_equation(double &x) {
	double y = 2.0 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
	return y;
}

double Integral_equation(double &x) {
	double dy = 6 * pow(x, 2) - 8 * x + 3;
	return dy;
}

double equation1(double &x) {
	double y = pow(x, 3) - x - 1;
	return y;
}
double equation2(double &x1, double &x0) {
	double s = (equation1(x1) - equation1(x0)) / (x1 - x0);
	return s;
}