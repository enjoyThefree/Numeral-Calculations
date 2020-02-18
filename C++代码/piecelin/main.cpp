#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

bool piecelin(double X[], double Y[], vector<double> &x, vector<double> &v);

int main()
{
	double x[] = { -1, -0.75, -0.5, -0.25, 0, 0.25, 0.5, 0.75, 1 };
	double y[] = { 0.0385, 0.0664, 0.1379, 0.39, 1, 0.39, 0.1379, 0.0664, 0.0385 };
	vector<double> u;
	for (double i = -1; i <= 1; i = i + 0.01) {
		u.push_back(i);
	}
	vector<double> v;
	/*piecelin(x, y, u,v);*/
	int  n = sizeof(x) / sizeof(x[0]);
	int k = u.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < k; j++) {
			if (x[i] <= u[j] && u[j] < x[i + 1]) {
				double s = u[j] - x[i];
				double delta = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
				v.push_back(y[i] + s * delta);
			}

			if (u[j] > x[i + 1])
				break;
		}
	}

	int size = v.size();

	std::ofstream output;
	output.open("piecelin.txt");
	for (unsigned i = 0; i < size; i++) {
		output << u[i] << '\t' << v[i] << std::endl;
	}
	output.close();
	cout << "Hello World !" << endl;
}

bool piecelin(double x[], double y[], vector<double> &u, vector<double> &v) {
	int  n = sizeof(x) / sizeof(x[0]);
	int k = u.size();
	for (int i = 0; i < n -1; i++) {
		for (int j = 0; j < k; j++) {
			if (x[i]<=u[j]&&u[j]<x[i+1]) {
				double s = u[j] - x[i];
				double delta = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
				v.push_back(y[i] + s * delta);
			}

			if (u[j] > x[i + 1]) 
				break;
		}
	}
	return true;
}