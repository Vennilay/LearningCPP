#include <iostream>
#include <cmath>

int main() {
    double a = 0, x = 0, w = 0;

    std::cout << "Введите число a:\n";
    std::cin >> a;

    std::cout << "Введите число x:\n";
    std::cin >> x;

    if (std::abs(x) < 1) {
        if (x == 0) {
            std::cout << "ln|x| не определен при x = 0\n";
            return 0;
        }
        w = a * std::log(std::abs(x));
    } else {
        double t = a - x * x;
        if (t < 0) {
            std::cout << "Отрицательное выражение под корнем!\n";
            return 0;
        }
        w = std::sqrt(t);
    }

    std::cout << "Ответ: " << w << std::endl;
    return 0;
}
