// UnitTest_05_1.cpp
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

// Реалізація функції f для юніт-тесту
double f(const double a, const double b, const double c)
{
    return pow(sin(a * b * c), 2) / (a * a + b * b + c * c);
}

void test_f()
{
    double eps = 0.00001; // Точність порівняння чисел з плаваючою крапкою

    // Тест 1: якщо a = 0, sin(0) = 0 => f(0, 1, 1) = 0.0
    assert(abs(f(0, 1, 1) - 0.0) < eps);
    cout << "Test 1 passed!" << endl;

    // Тест 2: якщо a=1, b=1, c=1 => f(1, 1, 1) = sin^2(1)/3
    double expected2 = pow(sin(1.0), 2) / 3.0;
    assert(abs(f(1, 1, 1) - expected2) < eps);
    cout << "Test 2 passed!" << endl;

    // Тест 3: якщо b = 0, sin(0) = 0 => f(2, 0, 1) = 0.0
    assert(abs(f(2, 0, 1) - 0.0) < eps);
    cout << "Test 3 passed!" << endl;

    cout << "\nAll Unit Tests passed successfully!" << endl;
}

int main()
{
    cout << "Running Unit Tests for Lab_05_1..." << endl;
    test_f();
    return 0;
}