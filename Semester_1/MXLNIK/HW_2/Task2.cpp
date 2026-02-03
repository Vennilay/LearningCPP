#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float b, x, y;

    cout << "Введите b: ";
    cin >> b;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    if ((b - y) > 0 and (b - x) >= 0)
    {
        cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    }
    else
    {
        cout << "Функция не определена при данных значениях" << endl;
    }
    return 0;
}
