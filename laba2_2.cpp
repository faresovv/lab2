#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double F1(double x);

double a = 2;
double lambda = 1./F1(a);
double Eps = 0.0001;


/*

double F(double x){//функция
	return pow(x, x) + 9 * x - 20;
}
double F1(double x){//производная
	return pow(x, x)*(log(x)+1) + 9;
}

*/

double F(double x){//функция
	return x+log(1+x)-1.5;
}
double F1(double x){//производная
	return 1+1/(1+x);
}




double PHi(double x){//функция фи
	return x - lambda * F(x);
}



double NEWTON (double X, int &N){
  double Y,Y1,DX;
  N=0;
  do{
    Y  = F(X);
    if (Y==0.0) return (X);
    Y1 = F1(X);
    if (Y1==0.0) {
		puts("Производная обратилась в ноль \n");
		exit(1);
	}
    DX=Y/Y1;
	X=X-DX;
	N++;
  }
  while (abs(DX)>Eps);
  return (X);
}


double ITER(double X0, int& N){
	double X1 = PHi(X0);
	double X2 = PHi(X1);
	N += 2;
	while(abs(X2 - X1) > Eps || (X1 - X2) * (X1 - X2) >  1E-12){
		X0 = X1;
		X1 = X2;
		X2 = PHi(X1);
//		cout << (X1 - X2) * (X1 - X2) << " "<< abs((2 * X1 - X0 - X2)) * Eps <<"\n";
		N += 1;
	}
	return(X2);
}

int main(){
	cout << setprecision(20) << fixed;
	int n = 0;
	double res = NEWTON(a, n);
	cout <<"Newton: " << res << " " << n << "\n\n";
	int n2 = 0;
	double res2 = ITER(a, n2);
	cout <<"Iter: " << res2 << " " << n2;
	
}
