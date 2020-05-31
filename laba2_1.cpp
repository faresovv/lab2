#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double F(double x){
	return 3*x*x*x*x+4*x*x*x-12*x*x-5;
}

bool issqrt(double a, double b){
	if(F(a) < 0){
		if(F(b) > 0) return true;
	}
	else {
		if(F(b) < 0) return true;
	}
	return false;
}


int main(){
	cout << setprecision(11) << fixed;
	double a = -100, b = -99;
	for(; !issqrt(a, b); a++, b++){}
	cout << a << " " << b << endl;
	cout << F(a) << " " << F(b) << endl;
	double middle, epsilon = 0.00000001;
	int choice1 = 0;
	for(; abs(F(a)) > epsilon;){
		middle = (a + b) / 2;
		if(issqrt(a, middle)) b = middle;
	//	else if (issqrt(b, middle)) a = middle;
		else a = middle; 
		choice1++;
	}
	cout << a << " " << F(a) << " " << choice1 << "\n\n\n";
	
	/*********************************************************/
	a = -100;
	b = -99;
	for(; !issqrt(a, b); a++, b++){}
	cout << a << " " << b << endl;
	cout << F(a) << " " << F(b) << endl;
	int choice2 = 0;
	double c;
	do{
		c = a - (F(a) * (b - a) / (F(b) - F(a)));
		if(issqrt(b , c))	b = c;
		else	a = c;
		choice2++;
	}while(abs(F(c)) > epsilon);
	cout << c << " " << F(c) << " " << choice2 << "\n\n\n";
}



































