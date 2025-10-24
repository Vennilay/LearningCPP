#include <iostream>

int main() {
    double a = 0, x = 0;
    std::cout << "Введите число a и x через пробел: ";
    std::cin >> a >> x;

    if (x == 0) {
        std::cout << "Ошибка: x должно быть не равно 0" << std::endl;
        return 0;
    }

    if (a - pow(x, 2) < 0) {
        std::cout << "Ошибка: a - x^2 должно быть неотрицательным" << std::endl;
        return 0;
    }

    double w = std::abs(x) < 1 ? a * log(fabs(x)) : std::sqrt(a - pow(x, 2));
    std::cout << "Ответ: w = " << w << std::endl;

    return 0;
}
