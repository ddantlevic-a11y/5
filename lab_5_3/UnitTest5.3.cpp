#include <iostream>
#include <cmath>
#include <cassert>
#define THIRD_PARTY_UNIT_TEST
// Підключаємо файл із реалізацією лабораторії
#include "5.3.cpp"
using namespace std;
int main() {
    // Тест 1: перевірка k(x) з 5.3.cpp при |x| >= 1
    double x1 = 1.0;
    double expected1 = (exp(x1) + sin(x1)) / (cos(x1) * cos(x1) + 1);
    assert(abs(k(x1) - expected1) < 1e-5);
    // Тест 2: перевірка k(x) з 5.3.cpp при |x| < 1
    double x2 = 0.5;
    double sum2 = 1.0 + 0.5 + pow(0.5, 2)/2.0 + pow(0.5, 3)/6.0 + pow(0.5, 4)/24.0 + pow(0.5, 5)/120.0;
    double expected2 = (1.0 / exp(0.5)) * sum2;
    assert(abs(k(x2) - expected2) < 1e-5);
    cout << "-------------------------" << endl;
    cout << "UnitTest5.3 PASSED!" << endl;
    cout << "-------------------------" << endl;
    return 0;
}