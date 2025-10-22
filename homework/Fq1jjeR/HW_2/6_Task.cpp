#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double S = 0, m = 0, n = 0, p;
    double left, right;
    double new_m;

    cout << "S: ";
    cin >> S;

    cout << "m: ";
    cin >> m;

    cout << "n: ";
    cin >> n;

    double _zeroPay = S / (12.0 * n);

    if (S <= 0 or n <= 0) {
        cout << "Ошибка входных данных";
        return 1;
    }

    if (m < _zeroPay) {
        left = -100.0;
        right = 0.0;
    }
    else {
        left = 0.0;
        right = 100.0;
    }

    for (int i = 0; i < 100; i++)
    {
        p = (left + right) / 2.0;

        if (p == 0)
            new_m = S / (12 * n);

        else {
            double r = p / 100.0;
            double _pow = pow(1 + r, n);
            new_m = (S * r * _pow) / (12.0 * (_pow - 1.0));
        }

        if (abs(new_m - m) < 0.01) {
            break;
        }

        if (new_m < m) {
            left = p;
        }
        else {
            right = p;
        }

    }

    cout << "Процентная ставка: " << p << "%" << endl;
}
