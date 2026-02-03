#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float r, R, h;

    cout << "Вычислить объём и полную поверхность усечённого конуса" << endl;
    cout << "Введите радиус меньшего основания: ";
    cin >> r;
    cout << "Введите радиус большего основания: ";
    cin >> R;
    cout << "Введите высоту: ";
    cin >> h;

    if (R > r and h > 0)
    {
        cout << "Объём = " << 3.14 / 3 * h * (R * R + R * r + r * r) << endl;
        cout << "Полная поверхность = " << 3.14 * (R * R + (R + r) * sqrt(h * h + pow((R - r), 2)) + r * r) << endl;
    }
    else
    {
        cout << "Такой усечённый конус не может существовать" << endl;
    }
    return 0;
}
