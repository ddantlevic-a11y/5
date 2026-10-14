#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
#define main lab_main
#include "5.1.cpp"
#undef main
int main() {
    double a = 1.0;
    double b = 1.0;
    double c = 1.0;
    double expected = pow(sin(1.0), 2) / 3.0;    
    double actual = f(a, b, c);
    assert(abs(actual - expected) < 1e-5);
    cout << "-------------------------" << endl;
    cout << "UnitTest5.1 PASSED!" << endl;
    cout << "-------------------------" << endl;
    return 0;
}