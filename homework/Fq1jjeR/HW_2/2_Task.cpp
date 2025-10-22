#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double x, y, b, z;

    cout << "x: ";
    cin >> x;

    cout << "y: ";
    cin >> y;

    cout << "b: ";
    cin >> b;

    if (b - x < 0) {
        cout << "Подкоренное выражение должно быть неотрицательным";
        return 0;
    }
    else if (b - y <= 0) {
        cout << "Аргумент логарифма должен быть положительным";
        return 0;
    }

    z = log(b - y) * sqrt(b - x);
    cout << "z = " << z;
}
