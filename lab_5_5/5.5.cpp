// lab_5_5.cpp
// Данилевич Данило
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 7
#include <iostream>

using namespace std;

// 1. Двійкова система числення (base = 2)
int f1(int n, int level, int &depth) {
    if (level > depth)
        depth = level;

    cout << "  level = " << level << endl;

    if (n < 2)
        return n;
    else
        return f1(n / 2, level + 1, depth) * 10 + (n % 2);
}

// 2. Вісімкова система числення (base = 8)
int f2(int n, int level, int &depth) {
    if (level > depth)
        depth = level;

    cout << "  level = " << level << endl;

    if (n < 8)
        return n;
    else
        return f2(n / 8, level + 1, depth) * 10 + (n % 8);
}

// 3. Система числення з основою base (від 2 до 10)
int f3(int n, int base, int level, int &depth) {
    if (level > depth)
        depth = level;

    cout << "  level = " << level << endl;

    if (n < base)
        return n;
    else
        return f3(n / base, base, level + 1, depth) * 10 + (n % base);
}

#ifndef THIRD_PARTY_UNIT_TEST
int main() {
    int num;
    cout << "Введіть натуральне число: ";
    cin >> num;

    if (num <= 0) {
        cout << "Помилка: число має бути натуральним (> 0)!" << endl;
        return 1;
    }

    int baseN;
    cout << "Введіть основу системи числення N (від 2 до 10): ";
    cin >> baseN;

    if (baseN < 2 || baseN > 10) {
        cout << "Помилка: основа має бути від 2 до 10!" << endl;
        return 1;
    }

    // 1. Двійкова система
    int dtwo = 0;
    cout << "\n--- Двійкова система числення (base 2) ---" << endl;
    int two = f1(num, 1, dtwo);
    cout << "Результат у двійковій: " << two << endl;
    cout << "depth = " << dtwo << endl;

    // 2. Вісімкова система
    int deight = 0;
    cout << "\n--- Вісімкова система числення (base 8) ---" << endl;
    int eight = f2(num, 1, deight);
    cout << "Результат у вісімковій: " << eight << endl;
    cout << "depth = " << deight << endl;

    // 3. Система числення з основою N
    int dBase = 0;
    cout << "\n--- Система числення з основою " << baseN << " ---" << endl;
    int baseRes = f3(num, baseN, 1, dBase);
    cout << "Результат у системі з основою " << baseN << ": " << baseRes << endl;
    cout << "depth = " << dBase << endl;

    return 0;
}
#endif
