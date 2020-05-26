

#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
double f1(double x, double y) {
	return x*x+pow((y-1),2)-1;
}
double f2(double x, double y) {
	return x*x*x+y*y*y-2;
}
double f1x(double x, double y) {
	return 2*x;
}
double f1y(double x, double y) {
	return 2*y-2;
}
double f2x(double x, double y) {
	return 3*x*x;
}
double f2y(double x, double y) {
	return 3*y*y;
}
double d(double x, double y) {
	return f1x(x, y) * f2y(x, y) - f1y(x, y) * f2x(x, y);
}
double dy(double x, double y) {
	return f1x(x, y) * f2(x, y) - f1(x, y) * f2x(x, y);
}
double dx(double x, double y) {
	return f1(x, y) * f2y(x, y) - f1y(x, y) * f2(x, y);
}

int main()
{
	double x1, y1, x2, y2, e, k = 0;
	e = 0.0001;
	x1 = 1;
	x2 = 1;
	y1 = 1;
	y2 = 1;
	while (abs(f1(x1, y1) - f2(x1, y1)) > e) {
		x1 = x2 - dx(x2, y2) / d(x2, y2);
		y1 = y2 - dy(x2, y2) / d(x2, y2);
		y2=y1;
		x2 = x1;
	}

	cout << x2 << endl << y2 << endl;
	cout << f1(x2, y2) << endl << f2(x2, y2);





}
