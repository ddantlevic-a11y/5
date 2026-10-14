#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Допоміжна функція k(x)
double k(const double x) {
    if (abs(x) >= 1) {
        return (exp(x) + sin(x)) / (cos(x) * cos(x) + 1);
    } else {
        double sum = 0;
        double a = 1; // a_0 = 1
        sum += a;

        for (int i = 1; i <= 5; i++) {
            a *= x / i; // a_i = a_{i-1} * x / i
            sum += a;
        }

        return (1.0 / exp(x)) * sum;
    }
}
// Захист main() від повторного оголошення при імпoрті в тест
#ifndef THIRD_PARTY_UNIT_TEST
int main() {
    double zp, zk, dz;
    int n;

    cout << "zp = "; cin >> zp;
    cout << "zk = "; cin >> zk;
    cout << "n  = "; cin >> n;

    if (n <= 0) {
        cout << "n" << endl;
        return 1;
    }

    dz = (zk - zp) / n;
    double z = zp;

    cout << fixed;
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(15) << "z" 
         << " |" << setw(25) << "Result" << " |" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i <= n; i++) {
        double res = k(z * z + 1) - k(z * z - 1) + 2 * k(z);
        cout << "|" << setw(15) << setprecision(5) << z 
             << " |" << setw(25) << setprecision(5) << res << " |" << endl;
        z += dz;
    }

    cout << "---------------------------------------------" << endl;

    return 0;
}
#endif