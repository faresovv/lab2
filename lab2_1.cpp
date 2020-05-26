#include <iostream>
#include <cmath>
using namespace std;
double funct(double x) {
	return 3*x*x*x*x+4*x*x*x-12*x*x-5;
}
int main()
{
	double a, b;
	a = -1;
	b = 0;
	double c;
        //c=(a*funct(b)-b*funct(a))/(funct(b)-funct(a));
	c = (a + b) / 2;
        int h=0;
        while (funct(a)*funct(b)>0){
        a++;
        b++;
        }
        double e = 0.001;
	while (abs(funct(c)) > e) {
                h++;
		if (funct(c) * funct(a) < 0) {
			b = c;
		}
		if (funct(c) * funct(a) > 0) {
			a = c;
		}
                c = (a + b) / 2;
                //c=(a*funct(b)-b*funct(a))/(funct(b)-funct(a));
	}
	cout << "koren="<<c<<endl;
	cout<<"itera="<<h<<endl;
	cout << funct(c);
	
}






