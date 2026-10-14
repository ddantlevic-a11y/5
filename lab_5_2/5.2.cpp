// Lab_05_2.cpp
// Данилевич Данило
// Лабораторна робота №5.2
// Обчислення суми ряду тейлора за допомогою ітераційних циклів та рекурентних співвідношень
// Ваірант 7
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Рекурентна формула для обчислення члена ряду
void A(const double x, const int n, double &a) {
    double R = -x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
    a *= R;
}

// Обчислення суми ряду Тейлора
void S(const double x, const double eps, int &n, double &s) {
    n = 0;
    double a = -x;
    s = M_PI / 2.0 + a;

    while (abs(a) >= eps) {
        n++;
        A(x, n, a);
        s += a;
    }
}

// Захист main() від повторного оголошення при підключенні в юніт-тест
#ifndef THIRD_PARTY_UNIT_TEST
int main() {
    double xp, xk, dx, eps;
    int n;

    cout << "xp  = "; cin >> xp;
    cout << "xk  = "; cin >> xk;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "---------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" 
         << " |" << setw(15) << "arcctg(x)" 
         << " |" << setw(15) << "S" 
         << " |" << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------------" << endl;

    double x = xp;
    while (x <= xk) {
        double s = 0;
        S(x, eps, n, s);

        double exact = M_PI / 2.0 - atan(x);

        cout << "|" << setw(10) << setprecision(2) << x 
             << " |" << setw(15) << setprecision(5) << exact 
             << " |" << setw(15) << setprecision(5) << s 
             << " |" << setw(8) << n << " |" << endl;

        x += dx;
    }

    cout << "---------------------------------------------------------" << endl;

    return 0;
}
#endif