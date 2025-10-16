#include <iostream>
#include <cmath>

int main() {
    double S = 0, n = 0, p = 0;

    std::cout << "Введите сумму вклада S, срок вклада n (в годах) и годовой процент p через пробел: ";
    std::cin >> S >> n >> p;

    double r = p / 100.0;
    double num1 = S * r * std::pow(1 + r, n);
    double num2 = 12.0 * (std::pow(1 + r, n) - 1.0);

    if (num2 == 0.0) {
        std::cout << "Ошибка: знаменатель равен нулю" << std::endl;
        return 0; //test
    }

    double m = num1 / num2;
    std::cout << "Ежемесячный платеж: " << m << std::endl;

    return 0;
}
