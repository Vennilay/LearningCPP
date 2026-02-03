#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float b, c, x;

    cout << "Решение уравнения вида bx + c = 0" << endl;
    cout << "Введите коэффициент b: ";
    cin >> b;
    cout << "Введите коэффициент c: ";
    cin >> c;
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
    return 0;
}
