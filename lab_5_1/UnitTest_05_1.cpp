#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// Перейменовуємо main з 5.1.cpp, щоб не було конфлікту точок входу
#define main lab_main

// Прямий імпорт файлу лабораторної
#include "5.1.cpp"

// Повертаємо назву main для юніт-тесту
#undef main

int main() {
    double a = 1.0;
    double b = 1.0;
    double c = 1.0;

    // Обчислюємо очікуване значення для f(1, 1, 1) = pow(sin(1), 2) / (1 + 1 + 1)
    double expected = pow(sin(1.0), 2) / 3.0;
    
    // Виклики функції f(a, b, c) з файлу 5.1.cpp
    double actual = f(a, b, c);

    assert(abs(actual - expected) < 1e-5);

    cout << "-------------------------" << endl;
    cout << "UnitTest5.1 PASSED!" << endl;
    cout << "-------------------------" << endl;

    return 0;
}