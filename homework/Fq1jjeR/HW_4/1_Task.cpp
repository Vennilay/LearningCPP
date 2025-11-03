#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;


double rectangleArea(double width, double heightRectangle) { return width * heightRectangle; }
double triangleArea(double base, double heightTriangle) { return (base * heightTriangle) / 2; }
double circleArea(double radius, double PI) { return PI * (radius * radius) ; }


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    cout << "Прямоугольник" << endl;
    double width, heightRectangle;

    cout << "Введите ширину: "; cin >> width;
    cout << "Введите высоту: "; cin >> heightRectangle;
    cout << "Площадь: " << fixed << setprecision(2) << rectangleArea(width, heightRectangle) << endl;


    cout << "Треугольник" << endl;
    double base, heightTriangle;

    cout << "Введите основание: "; cin >> base;
    cout << "Введите высоту: "; cin >> heightTriangle;
    cout << "Площадь: " << fixed << setprecision(2) << triangleArea(base, heightTriangle) << endl;


    cout << "Круг" << endl;
    const double PI = 3.141592653589793;
    double radius = 5;

    cout << "Введите радиус: "; cin >> radius;
    cout << "Площадь: " << fixed << setprecision(2) << circleArea(radius, PI) << endl;

    return 0;
}