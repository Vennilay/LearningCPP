#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double RectangleSquare(const double width, const double height) {
    return width * height;
}

double TriangleSquare(const double base, const double height) {
    return 0.5 * base * height;
}

double CircleSquare(const double r) {
    return M_PI * r * r;
}

int main() {
    double width = 0, heightRect = 0, baseTri = 0, heightTri = 0, radius = 0;

    std::cout << "Введите ширину прямоугольника: ";
    std::cin >> width;

    std::cout << "Введите высоту прямоугольника: ";
    std::cin >> heightRect;

    if (width <= 0 || heightRect <= 0) {
        std::cout << "Ошибка: размеры прямоугольника должны быть положительными!\n";
        return 0;
    }

    std::cout << "Введите основание треугольника: ";
    std::cin >> baseTri;

    std::cout << "Введите высоту треугольника: ";
    std::cin >> heightTri;

    if (baseTri <= 0 || heightTri <= 0) {
        std::cout << "Ошибка: размеры треугольника должны быть положительными!\n";
        return 0;
    }

    std::cout << "Введите радиус круга: ";
    std::cin >> radius;

    if (radius <= 0) {
        std::cout << "Ошибка: радиус должен быть положительным!\n";
        return 0;
    }

    std::cout << "\nПлощадь прямоугольника: "  << RectangleSquare(width, heightRect) << std::endl;
    std::cout << "Площадь треугольника: " << TriangleSquare(baseTri, heightTri) << std::endl;
    std::cout << "Площадь круга: " << CircleSquare(radius) << std::endl;

    return 0;
}