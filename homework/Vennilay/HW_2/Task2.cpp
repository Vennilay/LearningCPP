#include <iostream>
#include <cmath>

int main() {
    double x = 0, y = 0, b = 0;

    std::cout << "Введите x:\n";
    std::cin >> x;

    std::cout << "Введите y:\n";
    std::cin >> y;

    std::cout << "Введите b:\n";
    std::cin >> b;

    if (b - x < 0) {
        std::cout << "Подкоренное выражение должно быть неотрицательным (b - x >= 0)\n";
        return 0;
    }
    if (b - y <= 0) {
        std::cout << "Аргумент логарифма должен быть положительным (b - y > 0)\n";
        return 0;
    }

    std::cout << std::log(b - y) * std::sqrt(b - x) << std::endl;


    return 0;
}