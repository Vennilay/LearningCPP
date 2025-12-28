#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double S = 0, p = 0, n = 0, m = 0;

    cout << "S: ";
    cin >> S;

    cout << "p: ";
    cin >> p;

    cout << "n: ";
    cin >> n;

    if (S <= 0) {
        cout << "Сумма займа должна быть положительна";
        return 1;
    }
    else if (n <= 0) {
        cout << "срок займа должна быть положительным";
        return 1;
    }

    double r = p / 100.0;

    if (r == 0) {
        m = S / (n * 12);
    }
    else {
        m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    }

    cout << "m = " << m;

}

