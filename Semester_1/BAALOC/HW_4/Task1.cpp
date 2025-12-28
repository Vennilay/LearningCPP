#include <iostream>
#include <cmath>

double calculateTriangle(double h, double a) {
    return h * a * 0.5;
}

double calculateRectangle(double a, double b) {
    return a * b;
}

double calculateCircle(double r) {
    return M_PI * std::pow(r, 2);
}

int main() {
    double a = 0, b = 0, h = 0, r = 0;
    std::cout << "Введите число a, b, h, r через пробел: ";
    std::cin >> a >> b >> h >> r;

    if (a == 0 && b == 0 && h == 0 && r == 0) {
        std::cout << "Все числа должны быть больше нуля" << std::endl;
        return 1;
    }

    std::cout << calculateTriangle(h, a) << std::endl;
    std::cout << calculateRectangle(a, b) << std::endl;
    std::cout << calculateCircle(r) << std::endl;

    return 0;
}
