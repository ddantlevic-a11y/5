#include <iostream>
#include <cmath>
#include <cassert>
#define THIRD_PARTY_UNIT_TEST
#include "5.4.cpp"
using namespace std;

const double EPS = 1e-12;

void check_all(int N, double expected)
{
    assert(fabs(S0(N)       - expected) < EPS);
    assert(fabs(S1(N, 1)    - expected) < EPS);
    assert(fabs(S2(N, N)    - expected) < EPS);
    assert(fabs(S3(N, 1, 0) - expected) < EPS);
    assert(fabs(S4(N, N, 0) - expected) < EPS);
}

int main()
{
    // Тест 1: N = 1 => 1/9
    check_all(1, 1. / 9);
    cout << "Test 1 passed: N = 1 => 1/9" << endl;

    // Тест 2: N = 2 => 1/9 + 1/25
    check_all(2, 1. / 9 + 1. / 25);
    cout << "Test 2 passed: N = 2 => 1/9 + 1/25" << endl;

    // Тест 3: N = 3 => 1/9 + 1/25 + 1/49
    check_all(3, 1. / 9 + 1. / 25 + 1. / 49);
    cout << "Test 3 passed: N = 3 => 1/9 + 1/25 + 1/49" << endl;

    // Тест 4: N = 10, усі рекурсивні способи збігаються з ітераційним
    {
        int N = 10;
        double ref = S0(N);
        assert(fabs(S1(N, 1)    - ref) < EPS);
        assert(fabs(S2(N, N)    - ref) < EPS);
        assert(fabs(S3(N, 1, 0) - ref) < EPS);
        assert(fabs(S4(N, N, 0) - ref) < EPS);
        cout << "Test 4 passed: N = 10, all five results match" << endl;
    }

    // Тест 5: N = 1000, збіг між способами (допускаємо похибку округлення)
    {
        int N = 1000;
        double ref = S0(N);
        assert(fabs(S1(N, 1)    - ref) < 1e-9);
        assert(fabs(S2(N, N)    - ref) < 1e-9);
        assert(fabs(S3(N, 1, 0) - ref) < 1e-9);
        assert(fabs(S4(N, N, 0) - ref) < 1e-9);
        cout << "Test 5 passed: N = 1000, all five results match" << endl;
    }

    // Тест 6: при великому N сума наближається до pi^2/8 - 1
    {
        int N = 1000;
        double limit = M_PI * M_PI / 8 - 1;
        assert(fabs(S0(N) - limit) < 1e-3);
        cout << "Test 6 passed: N = 1000 is close to pi^2/8 - 1" << endl;
    }

    // Тест 7: сума зростає разом із N
    assert(S0(5) < S0(6));
    assert(S1(5, 1) < S1(6, 1));
    cout << "Test 7 passed: sum grows with N" << endl;

    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}