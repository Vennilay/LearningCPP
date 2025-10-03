#include <iostream>
#include <cmath>

int main() {
    double S = 0, m = 0, n = 0;

    std::cout << "Введите S (сумма кредита):\n";
    std::cin >> S;
    std::cout << "Введите m (ежемесячный платеж):\n";
    std::cin >> m;
    std::cout << "Введите n (срок в годах):\n";
    std::cin >> n;

    double zero_payment = S / (12.0 * n);

    double left, right;

    if (m < zero_payment) {
        left = -100.0;
        right = 0.0;
    } else {
        left = 0.0;
        right = 100.0;
    }

    double p = 0, new_m = 0;

    for (int i = 0; i < 300; i++) {
        p = (left + right) / 2.0;

        if (p == 0.0) {
            new_m = S / (12.0 * n);
        } else {
            double r = p / 100.0;
            double stepen = std::pow(1 + r, n);
            new_m = (S * r * stepen) / (12.0 * (stepen - 1.0));
        }

        if (std::abs(new_m - m) < 0.01) {
            break;
        }

        if (new_m < m) {
            left = p;
        } else {
            right = p;
        }
    }

    std::cout << "Процентная ставка: " << p << "%" << "\n";
    std::cout << "Платеж: " << new_m << std::endl;

    return 0;
}