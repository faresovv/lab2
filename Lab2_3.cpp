#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
double eps = 0.0001;
 
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
 
void obr_matr(double a[2][2])
{
    double det, aa;
    det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    aa = a[0][0];
    a[0][0] = a[1][1]/det;
    a[1][1] = aa/det;
    aa = a[0][1];
    a[0][1] = -a[0][1]/det;
    a[1][0] = -a[1][0]/det;
}
 
void newton(double x, double y)
{
    int i = 1;
    double a[2][2], dx, dy, b[2], norm;
    do
    {
        a[0][0] = f1x(x, y);
        a[0][1] = f1y(x, y);
        a[1][0] = f2x(x, y);
        a[1][1] = f2y(x, y);
        obr_matr(a);
        dx = -a[0][0]*f1(x, y) + -a[0][1]*f2(x, y);
        dy = -a[1][0]*f1(x, y) + -a[1][1]*f2(x, y);
        x = x + dx;
        y = y + dy;
        b[0] = f1(x, y);
        b[1] = f2(x, y);
        norm = sqrt(b[0]*b[0]+b[1]*b[1]);
        i++;
    }
    while (norm >= eps);
	cout << x << " " << y << endl;
	cout << f1(x,y) << " " << f2(x , y) << endl;
}

int main()
{
	cout << setprecision(6) << fixed;
    double x = 1, y = 1;
    newton(x, y);
}
