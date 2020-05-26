
#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
double funct1(double x) {
	return x+log(1+x)-1.5;
}
double funct2(double x) {
	return 1+1/(1+x);
}
int main()
{
	ofstream out;
	out.open("abc.txt");
	double a, b, e, x, xn,h;
	e = 0.0001;
	x = funct1(2);
	xn = x - funct1(x) / funct2(x);
	while (abs(xn - x) > e) {
		x = xn;
		xn = x - funct1(x) / funct2(x);
        h++;
	}
	for (int i = -20; i <=20; i +=1) {
		out << i << " " << funct1(i) << endl;
	}
        cout << xn << endl;
	cout << funct1(xn);

	/*import numpy as np
	import matplotlib.pyplot as plt

	data = np.loadtxt("abc.txt")
        fig=plt.figure();
	plt.plot(data[:, 0], data[:, 1])
	plt.show()
	*/
    
    
#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
double funct1(double x) {
	return x+log(1+x)-1.5;
}
double funct2(double x) {
	return 1+1/(1+x);
}
double funct3(double x) {
	return sqrt(x+log(1+x)-1.5));
}
int main()
{
	double x1, x2,e;
	e = 0.0001;
	x1 = 0;
	x2 = 2;
	while (abs(x1 - funct3(x1)) > e) {
		x1 = funct3(x1);
		//x1 = x2;
		cout << x1 << endl;
	}
	cout << x1<<" "<<funct3(x1);
}


