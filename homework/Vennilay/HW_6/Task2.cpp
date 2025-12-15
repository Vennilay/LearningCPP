#include <iostream>

int main() {
    long long m;

    if (!(std::cin >> m)) {
        std::cout << "Ошибка ввода" << std::endl;
        return 1;
    }

    long long x = 0;
    long long y = 0;

    if (m % 4 == 0) {
        x = 0;
        y = m / 4;
    } else if (m % 4 == 1) {
        if (m < 9) {
            std::cout << "0 0" << std::endl;
            return 0;
        }
        x = 3;
        y = (m - 9) / 4;
    } else if (m % 4 == 2) {
        if (m < 6) {
            std::cout << "0 0" << std::endl;
            return 0;
        }
        x = 2;
        y = (m - 6) / 4;
    } else {
        x = 1;
        y = (m - 3) / 4;
    }

    std::cout << x << " " << y << std::endl;

    return 0;
}
