#include <cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float R; float r; float V; float S; float l; float h;
    float PI = M_PI;
    cout << "Вычисление объёма и полной поверхности усечённого конуса" << endl;
    cout << "Введите радиус нижнего основания: "; cin >> R;
    cout << "Введите радиус верхнего основания: "; cin >> r;
    cout << "Введите высоту: "; cin >> h;
    l = sqrt(pow(R - r, 2) + pow(h, 2));

    if (R > 0 and r > 0 and h > 0 and R > r) {
        V = (1.0 / 3.0) * PI * h * (pow(R, 2) + (R * r) + pow(r, 2));
        S = PI * (pow(R, 2) + ((R + r) * l) + pow(r, 2));
        cout << "Объём усечённого конуса: " << V << endl;
        cout << "Полная поверхность усечённого конуса: " << S << endl;
    }
    else {
        cout << "Такого усечённого конуса не существует.";
    }
}