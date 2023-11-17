#include <iostream>
#include <iomanip>
#include <vector>
#include "CompareNewtonMethod.h"
using namespace std;



int main() {
    setlocale(LC_ALL,"ru");
    vector<double> MParametr = { 0.0,0.01, 0.05, 0.1 };
    for (const double& M : MParametr) {
        cout << "MParametr = " << M << endl;
        compareNewtonMethod(M);
        cout << "--------------------------" << endl;
    }

    return 0;
}