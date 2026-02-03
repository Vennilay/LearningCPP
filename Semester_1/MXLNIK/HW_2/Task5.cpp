#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float S, p, n, r;

    cout << "Введите сумму кредита: ";
    cin >> S;
    cout << "Введите процентную ставку: ";
    cin >> p;
    cout << "Введите на сколько лет берётся кредит: ";
    cin >> n;
    r = p / 100;
    if (r == 0)
    {
        cout << "Месячная выплата: " << S / (12 * n) << endl;
    }
    else
    {
        cout << "Месячная выплата: " << (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1)) << endl;
    }
    return 0;
}
