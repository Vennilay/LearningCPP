#include <iostream>

int main() {
    double amount = 0, payment = 0, n = 0;

    std::cout << "Введите S, m и n через пробел: ";
    std::cin >> amount >> payment >> n;

    double min_pay = amount / (12.0 * n);
    double left = 0, right = 0;

    if (payment < min_pay) {
        left = -100.0;
        right = 0.0;
    }
    else {
        left = 0.0;
        right = 100.0;
    }

    double rate = 0, calc_pay = 0;

    for (int i = 0; i < 100; i++) {
        rate = (left + right) / 2.0;

        if (rate == 0.0) {
            calc_pay = amount / (12.0 * n);
        }
        else {
            double r = rate / 100.0;
            double power = std::pow(1 + r, n);
            calc_pay = (amount * r * power) / (12.0 * (power - 1.0));
        }

        if (std::abs(calc_pay - payment) < 0.01) {
            break;
        }

        if (calc_pay < payment) {
            left = rate;
        }
        else {
            right = rate;
        }
    }

    std::cout << "Процентная ставка: " << rate << "%" << std::endl;
    std::cout << "Платеж: " << calc_pay << std::endl;

    return 0;
}
