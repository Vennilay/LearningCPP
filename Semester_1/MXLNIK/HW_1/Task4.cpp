#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float a, b, c, discr, x, x_2;

    cout << "Решение уравнения вида ax^2 + bx + c = 0" << endl;
    cout << "Введите коэффициент a: ";
    cin >> a;
    cout << "Введите коэффициент b: ";
    cin >> b;
    cout << "Введите коэффициент c: ";
    cin >> c;
    if (a == 0)
    {
        if (b == 0 and c == 0)
        {
            cout << "x может быть равен любому числу" << endl;
        }
        else if (b == 0 and c != 0)
        {
            cout << "Уравнение не имеет решений" << endl;
        }
        else
        {
            x = (0 - c) / b;
            cout << "x = " << x << endl;
        }
    }
    else if (b == 0)
    {
        if ((0 - c) / a < 0)
        {
            cout << "Уравнение не имеет решений" << endl;
        }
        else
        {
            x = sqrt((0 - c) / a);
            cout << "x1 = " << x << endl;
            cout << "x2 = " << 0 - x << endl;
        }
    }
    else
    {
        discr = pow(b, 2) - 4 * a * c;
        if (discr < 0)
        {
            cout << "Уравнение не имеет решений" << endl;
        }
        else if (discr == 0)
        {
            x = (0 - b) / (2 * a);
            cout << "x = " << x << endl;
        }
        else
        {
            x = (0 - b + sqrt(discr)) / (2 * a);
            x_2 = (0 - b - sqrt(discr)) / (2 * a);
            cout << "x1 = " << x << endl;
            cout << "x2 = " << x_2 << endl;
        }
    }
    return 0;
}
