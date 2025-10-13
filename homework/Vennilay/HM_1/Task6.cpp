#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double h = 0;
    double R = 0;
    double r = 0;
c
    cout << "Введите высоту конуса:" << endl;
    cin >> h;

    cout << "Введите радиус нижнего (большего) основания:" << endl;
    cin >> R;

    cout << "Введите радиус верхнего (меньшего) основания:" << endl;
    cin >> r;

    double l = sqrt(h * h + (R - r) * (R - r));

    double V = (1.0/3.0) * M_PI * h * (R * R + (R * r) + r * r);

    double S = M_PI * (R * R + (R + r) * l + r * r);

    cout << "Объём конуса: " << V << endl;
    cout << "Площадь поверхности: " << S << endl;
    return 0;
}
