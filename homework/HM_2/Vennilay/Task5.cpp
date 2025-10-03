#include <iostream>
#include <cmath>

int main() {
    double S = 0, p = 0, n = 0;

    std::cout << "Введите S:\n";
    std::cin >> S;

    std::cout << "Введите p:\n";
    std::cin >> p;

    std::cout << "Введите n (в годах):\n";
    std::cin >> n;

    double r = p / 100.0;
    double m;

    if (r == 0.0) {
        m = S / (n * 12.0);
        std::cout << "Ежемесячный платеж (0% ставка): " << m << "\n";
    } else {
        double chislitel = S * r * std::pow(1 + r, n);
        double znamenatel = 12.0 * (std::pow(1 + r, n) - 1.0);

        m = chislitel / znamenatel;
        std::cout << "Ежемесячный платеж: " << m;
    }

    return 0;
}