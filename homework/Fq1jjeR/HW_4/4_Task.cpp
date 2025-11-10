#include <iostream>

int main() {
    // Вариант 1
    const int m1 = 37;
    const int add1 = 3;
    const int c1 = 64;

    // Вариант 2
    const int m2 = 25173;
    const int add2 = 13849;
    const int c2 = 65537;

    int s = 0; // начальное значение s0

    std::cout << "=== Вариант 1 ===\n";
    s = 0;
    for (int i = 0; i < 20; ++i) { // можно увеличить длину последовательности
        s = (m1 * s + add1) % c1;
        std::cout << s << " ";
    }

    std::cout << "\n\n=== Вариант 2 ===\n";
    s = 0;
    for (int i = 0; i < 20; ++i) {
        s = (m2 * s + add2) % c2;
        std::cout << s << " ";
    }

    std::cout << std::endl;
    return 0;
}
