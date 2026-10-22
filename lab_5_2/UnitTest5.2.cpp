#include <iostream>
#include <cmath>
#include <cassert>
#define THIRD_PARTY_UNIT_TEST
#include "5.2.cpp"
using namespace std;
int main() {
    double eps, s;
    int n;
    // Тест 1: x = 0.5, eps = 1e-4 => pi/2 - atan(0.5)
    eps = 1e-4; n = 0; s = 0;
    S(0.5, eps, n, s);
    assert(abs(s - (M_PI / 2.0 - atan(0.5))) < eps);
    cout << "Test 1 passed: S(0.5, 1e-4) == pi/2 - atan(0.5), n = " << n << endl;
    // Тест 2: x = 0, ряд не виконує жодної ітерації => pi/2
    eps = 1e-4; n = 0; s = 0;
    S(0.0, eps, n, s);
    assert(abs(s - M_PI / 2.0) < eps);
    assert(n == 0);
    cout << "Test 2 passed: S(0, 1e-4) == pi/2, n = " << n << endl;
    // Тест 3: x = -0.5, eps = 1e-4 => pi/2 - atan(-0.5)
    eps = 1e-4; n = 0; s = 0;
    S(-0.5, eps, n, s);
    assert(abs(s - (M_PI / 2.0 - atan(-0.5))) < eps);
    cout << "Test 3 passed: S(-0.5, 1e-4) == pi/2 - atan(-0.5), n = " << n << endl;
    // Тест 4: x = 0.3, eps = 1e-6 (вища точність) => pi/2 - atan(0.3)
    eps = 1e-6; n = 0; s = 0;
    S(0.3, eps, n, s);
    assert(abs(s - (M_PI / 2.0 - atan(0.3))) < eps);
    cout << "Test 4 passed: S(0.3, 1e-6) == pi/2 - atan(0.3), n = " << n << endl;
    // Тест 5: менша eps потребує більше членів ряду
    int n_coarse, n_fine;
    eps = 1e-2; n = 0; s = 0;
    S(0.5, eps, n, s);
    n_coarse = n;
    eps = 1e-6; n = 0; s = 0;
    S(0.5, eps, n, s);
    n_fine = n;
    assert(n_fine > n_coarse);
    cout << "Test 5 passed: n(eps=1e-6) = " << n_fine
         << " > n(eps=1e-2) = " << n_coarse << endl;
    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}