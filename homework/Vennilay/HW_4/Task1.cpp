#define USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double RectangleSquare(const double width, const double rectangle_height) {
    return width * rectangle_height;
}

double TriangleSquare(const double triangle_base, const double triangle_height) {
    return 0.5 * triangle_base * triangle_height;
}

double CircleSquare(const double circle_radius) {
    return M_PI * pow(circle_radius, 2);
}

int main() {
    double width = 0, rectangle_height = 0, triangle_base = 0, triangle_height = 0, circle_radius = 0;
    std::cout << "Введите ширину и высоту прямоугольника: " << std::endl;
    std::cin >> width >> rectangle_height;

    std::cout << "Введите основание и высоту треугольника: " << std::endl;
    std::cin >> triangle_base >> triangle_height;

    std::cout << "Введите радиус окружности: " << std::endl;
    std::cin >> circle_radius;

    std::cout << "Площадь прямоугольника: " << RectangleSquare(width, rectangle_height) << std::endl;
    std::cout << "Площадь треугольника: " << TriangleSquare(triangle_base, triangle_height) << std::endl;
    std::cout << "Площадь круга: " << CircleSquare(circle_radius) << std::endl;

    return 0;
}