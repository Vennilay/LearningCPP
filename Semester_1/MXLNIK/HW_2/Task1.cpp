#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float a, x;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите x: ";
    cin >> x;
    if (fabs(x) < 1 and fabs(x) > 0)
    {
        cout << "w = " << a * log(fabs(x)) << endl;
    }
    else if (fabs(x) >= 1 and (a - pow(x, 2)) >= 0)
    {
        cout << "w = " << sqrt(a - pow(x, 2)) << endl;
    }
    else
    {
        cout << "Функция не определена при данных значениях" << endl;
    }
    return 0;
}
