#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double S, m, n, r;

    cout << "Введите сумму кредита: ";
    cin >> S;
    cout << "Введите месячную выплату: ";
    cin >> m;
    cout << "Введите на сколько лет берётся кредит: ";
    cin >> n;
    for (double i = 10000; i > -10000; i--)
    {
        r = i / 100;
        if (round(m) >= round((S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1))))
        {
            cout << "Процентная ставка: " << i << endl;
            break;
        }
    }
    return 0;
}
