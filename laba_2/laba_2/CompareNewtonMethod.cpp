//
// Created by vadim on 04.11.2023.
//

#include "CompareNewtonMethod.h"
using namespace std;
void compareNewtonMethod(const double& MParametr) {
    const double eps = 1e-9;
    double d1 = 1, d2 = 1;
    vector<double> x;
    x.push_back(0.5);
    x.push_back(0.2);
    vector<double> xKplus1(x);
    int k = 1;
    int NIT = 100;
    int N = 2;
    int M = 3;
    vector<vector<double>> matrix(N, vector<double>(M));
    vector<double> ans(N);

    while ((d1 > eps || d2 > eps)) {
        if (k >= NIT) {
            cout << "IER=2" << endl;
            break;
        }
        if (MParametr == 0.0) {
            jakobianMethod1(matrix, x);
        }
        else {
            jakobianMethod2(matrix, x, MParametr);
        }
        matrix[0][2] = -function1(x[0], x[1]);
        matrix[1][2] = -function2(x[0], x[1]);
        getAnswerGauss(matrix, N, M, ans);
        xKplus1[0] += ans[0];
        xKplus1[1] += ans[1];

        d1 = getD1(x);
        d2 = getD2(x, xKplus1);
        cout << "Iteration:" << k << " d1: " << d1 << " d2: " << d2 << endl;
        k++;
        x = xKplus1;
    }

    cout << "Solution: x = " << setprecision(20) << x[0] << ", y = " << x[1] << endl << "Number of iterations: " << k << endl;
}