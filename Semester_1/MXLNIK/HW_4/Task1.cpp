#include <iostream>
#include <Windows.h>
using namespace std;

double rectangle_area(double width, double height)
{
    return width * height;
}

double triangle_area(double base, double height)
{
    return base * height / 2;
}

double circle_area(double radius)
{
    return 3.14 * radius * radius;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double rectangle_width, rectangle_height, triangle_base, triangle_height, circle_radius;

    cout << "Введите ширину прямоугольника: ";
    cin >> rectangle_width;
    cout << "Введите высоту прямоугольника: ";
    cin >> rectangle_height;
    if (rectangle_width <= 0 || rectangle_height <= 0)
    {
        cout << "Введены некорректные значения" << endl << endl;
    }
    else
    {
        cout << "Площадь прямоугольника: " << rectangle_area(rectangle_width, rectangle_height) << endl << endl;
    }

    cout << "Введите основание треугольника: ";
    cin >> triangle_base;
    cout << "Введите высоту треугольника: ";
    cin >> triangle_height;
    if (triangle_base <= 0 || triangle_height <= 0)
    {
        cout << "Введены некорректные значения" << endl << endl;
    }
    else
    {
        cout << "Площадь треугольника: " << triangle_area(triangle_base, triangle_height) << endl << endl;
    }

    cout << "Введите радиус круга: ";
    cin >> circle_radius;
    if (circle_radius <= 0)
    {
        cout << "Введены некорректные значения" << endl;
    }
    else
    {
        cout << "Площадь круга: " << circle_area(circle_radius) << endl;
    }

    return 0;
}
