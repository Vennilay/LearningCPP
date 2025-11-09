#include <iostream>


void generate(int m, int i, int c, int n) {
    int s = 0;

    std::cout << "0) " << s << "\n";

    for (int step = 1; step < n; step++) {
        int previous = s;
        s = (m * previous + i) % c;

        std::cout << step << ") " << s << "\n";
        std::cout << "   Вычисление: (" << m << " * " << previous
                  << " + " << i << ") % " << c
                  << " = " << (m * previous + i)
                  << " % " << c << " = " << s << "\n";
    }
}

int main() {
    int n;
    std::cout << "Сколько чисел генерировать? ";
    std::cin >> n;

    std::cout << "\n════════════════════════════════════════\n";
    std::cout << "Вариант I (m=37, i=3, c=64)\n";
    std::cout << "════════════════════════════════════════\n";
    generate(37, 3, 64, n);

    std::cout << "\n════════════════════════════════════════\n";
    std::cout << "Вариант II (m=25173, i=13849, c=65537)\n";
    std::cout << "════════════════════════════════════════\n";
    generate(25173, 13849, 65537, n);

    return 0;
}
