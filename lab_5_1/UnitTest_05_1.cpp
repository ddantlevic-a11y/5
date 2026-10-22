#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
#define main lab_main
#include "5.1.cpp"
#undef main
int main() {
    const double eps = 1e-5;
    // Тест 1: a = 1, b = 1, c = 1 => sin(1)^2 / 3
    assert(abs(f(1, 1, 1) - pow(sin(1.0), 2) / 3.0) < eps);
    cout << "Test 1 passed: f(1, 1, 1) == sin(1)^2 / 3" << endl;
    // Тест 2: a = 2, b = 1, c = 1 => sin(2)^2 / 6
    assert(abs(f(2, 1, 1) - pow(sin(2.0), 2) / 6.0) < eps);
    cout << "Test 2 passed: f(2, 1, 1) == sin(2)^2 / 6" << endl;
    // Тест 3: a = 0, b = 1, c = 1 => sin(0)^2 / 2 = 0.0
    assert(abs(f(0, 1, 1) - 0.0) < eps);
    cout << "Test 3 passed: f(0, 1, 1) == 0.0" << endl;
    // Тест 4: a = 1, b = 2, c = 3 => sin(6)^2 / 14
    assert(abs(f(1, 2, 3) - pow(sin(6.0), 2) / 14.0) < eps);
    cout << "Test 4 passed: f(1, 2, 3) == sin(6)^2 / 14" << endl;
    // Тест 5: a = -1, b = 1, c = 1 => sin(-1)^2 / 3 = sin(1)^2 / 3
    assert(abs(f(-1, 1, 1) - pow(sin(1.0), 2) / 3.0) < eps);
    cout << "Test 5 passed: f(-1, 1, 1) == sin(1)^2 / 3" << endl;
    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}