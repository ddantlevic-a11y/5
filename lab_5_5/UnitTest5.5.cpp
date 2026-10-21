#include <iostream>
#include <cassert>

#define THIRD_PARTY_UNIT_TEST
#include "5.5.cpp"

using namespace std;

int main() {
    int depth = 0;

    // Тест 1: Двійкова система f1 (число 10 -> 1010, глибина 4)
    depth = 0;
    assert(f1(10, 1, depth) == 1010);
    assert(depth == 4);
    cout << "Test 1 passed: f1(10) == 1010, depth = 4" << endl;

    // Тест 2: Граничний випадок (число 1 -> 1, глибина 1)
    depth = 0;
    assert(f1(1, 1, depth) == 1);
    assert(depth == 1);
    cout << "Test 2 passed: f1(1) == 1, depth = 1" << endl;

    // Тест 3: Вісімкова система f2 (число 10 -> 12, глибина 2)
    depth = 0;
    assert(f2(10, 1, depth) == 12);
    assert(depth == 2);
    cout << "Test 3 passed: f2(10) == 12, depth = 2" << endl;

    // Тест 4: Вісімкова система f2 (число 64 -> 100, глибина 3)
    depth = 0;
    assert(f2(64, 1, depth) == 100);
    assert(depth == 3);
    cout << "Test 4 passed: f2(64) == 100, depth = 3" << endl;

    // Тест 5: f3 з основою 2 збігається з f1
    {
        int d1 = 0, d2 = 0;
        assert(f3(42, 2, 1, d1) == f1(42, 1, d2));
        assert(d1 == d2);
        cout << "Test 5 passed: f3(42, 2) matches f1(42)" << endl;
    }

    // Тест 6: f3 з основою 8 збігається з f2
    {
        int d1 = 0, d2 = 0;
        assert(f3(125, 8, 1, d1) == f2(125, 1, d2));
        assert(d1 == d2);
        cout << "Test 6 passed: f3(125, 8) matches f2(125)" << endl;
    }

    // Тест 7: f3 з основою 3 (число 13 -> 111, глибина 3)
    depth = 0;
    assert(f3(13, 3, 1, depth) == 111);
    assert(depth == 3);
    cout << "Test 7 passed: f3(13, 3) == 111, depth = 3" << endl;

    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}
