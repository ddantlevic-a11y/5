#include <iostream>
#include <cmath>
#include <cassert>
#define THIRD_PARTY_UNIT_TEST
#include "5.2.cpp"
using namespace std;
int main() {
    double x = 0.5;
    double eps = 0.0001;
    int n = 0;
    double s = 0;
    S(x, eps, n, s);
    double expected = M_PI / 2.0 - atan(x);
    assert(abs(s - expected) < eps);
    cout << "-------------------------" << endl;
    cout << "UnitTest5.2 PASSED!" << endl;
    cout << "-------------------------" << endl;
    return 0;
}