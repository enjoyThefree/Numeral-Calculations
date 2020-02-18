#include <iostream>
#include"function.h"
using namespace std;

int main()
{
	/* 牛顿迭代法 求方程根 */
	//double x0, err, e, root;
	//cout << "请输入初始值x0, x0 = "  ;
	//cin >> x0;
	//cout << "请输入误差限e, e = ";
	//cin >> e;
	//err = 10;				    //定义一个较大的数，使其进入循环
	//while (err > e) {
	//	int n = 1;                   //迭代次数
	//	double x = x0;
	///*	double f = 2.0 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
	//	double df = 6 * pow(x, 2) - 8 * x + 3;*/
	//	double f = Original_equation(x);
	//	double df = Integral_equation(x);
	//	x = x0 - f / df;
	//	root = x;
	//	err = fabs(x0 - root);
	//	x0 = x;

	//	n++;
	//	if (n > 150) {
	//		cout << "迭代次数太多，请更换算法，已推出程序！" << endl;
	//		break;
	//	}
	//}
	/*弦截法*/
	double x0, x1, error;
	double x ;
	double root;
	int n = 0;
	cout << "请输入初始值x0, x0 = ";
	cin >> x0;
	cout << "请输入初始值x1, x1 = ";
	cin >> x1;
	cout << "请输入误差限error, error = ";
	cin >> error;
	while (fabs(x1 - x0) > error) {
		double s = equation2(x1, x0);
		root = x1 - equation1(x1) / s;
		x0 = x1;
		x1 = root;

		n++;
		if (n > 150) {
			cout << "迭代次数太多，请更换算法，已推出程序！" << endl;
		    break;
		}
	}
	cout << "方程的根为：root = " << root << endl;
	//cout << "Hello World!" << endl;
}

