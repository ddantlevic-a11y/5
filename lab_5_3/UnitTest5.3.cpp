#include <iostream>
#include <cmath>
#include <cassert>
#define THIRD_PARTY_UNIT_TEST
#include "5.3.cpp"
using namespace std;
int main() {
    const double eps = 1e-5;
    // Тест 1: x = 1.0, |x| >= 1 => (e^x + sin x) / (cos^2 x + 1)
    double x1 = 1.0;
    double expected1 = (exp(x1) + sin(x1)) / (cos(x1) * cos(x1) + 1);
    assert(abs(k(x1) - expected1) < eps);
    cout << "Test 1 passed: k(1.0) == (e^1 + sin 1) / (cos^2 1 + 1)" << endl;
    // Тест 2: x = 2.0, |x| >= 1
    double x2 = 2.0;
    double expected2 = (exp(x2) + sin(x2)) / (cos(x2) * cos(x2) + 1);
    assert(abs(k(x2) - expected2) < eps);
    cout << "Test 2 passed: k(2.0) == (e^2 + sin 2) / (cos^2 2 + 1)" << endl;
    // Тест 3: x = -1.0, межа гілки |x| >= 1 з від'ємним x
    double x3 = -1.0;
    double expected3 = (exp(x3) + sin(x3)) / (cos(x3) * cos(x3) + 1);
    assert(abs(k(x3) - expected3) < eps);
    cout << "Test 3 passed: k(-1.0) == (e^-1 + sin(-1)) / (cos^2(-1) + 1)" << endl;
    // Тест 4: x = 0.5, |x| < 1 => (1/e^x) * (1 + x + x^2/2! + ... + x^5/5!)
    double x4 = 0.5;
    double sum4 = 1.0 + 0.5 + pow(0.5, 2) / 2.0 + pow(0.5, 3) / 6.0
                + pow(0.5, 4) / 24.0 + pow(0.5, 5) / 120.0;
    double expected4 = (1.0 / exp(0.5)) * sum4;
    assert(abs(k(x4) - expected4) < eps);
    cout << "Test 4 passed: k(0.5) == e^-0.5 * (1 + x + x^2/2! + ... + x^5/5!)" << endl;
    // Тест 5: x = 0 => sum = 1, e^0 = 1 => 1.0
    assert(abs(k(0.0) - 1.0) < eps);
    cout << "Test 5 passed: k(0.0) == 1.0" << endl;
    // Тест 6: x = -0.5, |x| < 1 з від'ємним x
    double sum6 = 1.0 - 0.5 + pow(-0.5, 2) / 2.0 + pow(-0.5, 3) / 6.0
                + pow(-0.5, 4) / 24.0 + pow(-0.5, 5) / 120.0;
    double expected6 = (1.0 / exp(-0.5)) * sum6;
    assert(abs(k(-0.5) - expected6) < eps);
    cout << "Test 6 passed: k(-0.5) == e^0.5 * (1 - 0.5 + 0.5^2/2! - ...)" << endl;
    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}