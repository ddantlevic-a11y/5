#include <iostream>
#include <cmath>
#include <cassert>

// Вимикаємо main() у 5.2.cpp
#define THIRD_PARTY_UNIT_TEST

// Підключаємо файл із реалізацією з тієї ж папки
#include "5.2.cpp"

using namespace std;

int main() {
    double x = 0.5;
    double eps = 0.0001;
    int n = 0;
    double s = 0;

    // Виклик функції S із файлу 5.2.cpp
    S(x, eps, n, s);

    double expected = M_PI / 2.0 - atan(x);

    // Перевірка результату з точністю eps
    assert(abs(s - expected) < eps);

    cout << "-------------------------" << endl;
    cout << "UnitTest5.2 PASSED!" << endl;
    cout << "-------------------------" << endl;

    return 0;
}