#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double x, a, w = 0;

    cout << "x: ";
    cin >> x;

    cout << "a: ";
    cin >> a;

    if (fabs(x) < 1) {
        if (x == 0) {
            cout << "логарифм не определен при x = 0";
            return 0;
        }
        w = a * log(fabs(x));
    }

    else if (fabs(x) >= 1) {
        if ((a - (x * x) < 0)) {
            cout << "Отрицательное выражение под корнем!";
            return 0;
        }
        w = sqrt(a - (x * x));
    }
    cout << "w = " << w;

}
