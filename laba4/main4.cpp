#include <iostream>
#include <vector>
#include "approxim.h"
using namespace std;

int main()
{
	vector<double>x = { 0,1,2,3,4,5,6,7,8 };
	vector<double>y(x.size());
	const int N = 9;
	
	liner(x,y,N);
	
	const int m = 4;

	vector<int>I(m + 1);
	vector<double>POWERX(2 * m);
	vector<vector<double>>SUMX(m + 1,vector<double>(m+1));
	vector<double>PRAW(m + 1);
	POWERX_(m, POWERX, N, x);
	SUMX_(m, N, SUMX, POWERX,I);
	PRAW_(m, N, y,x, PRAW);
	vector<double>c = gauss(SUMX, PRAW, m + 1);
	double S2 = 0;
	double s = SIGMA(S2, N, y, m, x, c);

	cout << "x" << setw(10) << "f(x)" << setw(10) << "q(x)"<< setw(10) << "i" << endl;
	for (int i = 0; i < m+1; i++) {
		cout << x[i] << setw(10) << y[i] << setw(10) <<(PRAW[i]) << setw(10) << I[i] << endl;
	}
	for (int i =  m+1; i < N; i++) {
		cout << x[i] << setw(10) << y[i] << endl;
	}
}