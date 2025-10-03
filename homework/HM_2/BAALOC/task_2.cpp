#include <iostream>

int main() {
    double x = 0, y = 0, b = 0;
    std::cout << "Введите чиcло x, y и b через пробел: ";
    std::cin >> x >> y >> b;

    if (b - y <= 0) {
        std::cout << "Ошибка: b - y должно быть положительным" << std::endl;
        return 0;
    }
    if (b - x < 0) {
        std::cout << "Ошибка: b - x должно быть неотрицательным" << std::endl;
        return 0;
    }

    double z = log(b - y) * sqrt(b - x);
    std::cout << "Ответ: z = " << z << std::endl;

    return 0;
}
