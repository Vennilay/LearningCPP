#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float w, x, a;
    cout << "Введите число x: "; cin >> x;
    cout << "Введите число a: "; cin >> a;
    if (abs(x) < 1) {
        if (x != 0) {
            w = a * log(abs(x));
            cout << "Ответ: " << w;
        }
        else {
            cout << "Значение x выходит за область определения натурального логарифма";
        }
    }
    else if (abs(x) >= 1) {
        if ((a - pow(x, 2)) >= 0) {
            w = sqrt(a - pow(x, 2));
            cout << "Ответ: " << w;
        }
        else {
            cout << "Значение x выходит за область определения квадратного корня";
        }
    }
    else {
        cout << "Значения x выходит за область определения функции";
    }
    return 0;
}

