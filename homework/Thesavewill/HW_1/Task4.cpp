#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    float a; float b; float c; float x1; float x2; float D;
    cout << "Решение уравнения вида ax^2 + bx + c = 0" << endl;
    cout << "Введите число a: "; cin >> a;
    cout << "Введите число b: "; cin >> b;
    cout << "Введите число c: "; cin >> c;
    D = (pow(b, 2)) - (4 * a * c);
    if (a == 0 and b!=0) {
        x1 = -c / b;
        cout << "Ответ: x = " << x1;
    }
    else if (a == 0 and b == 0 and c != 0) {
        cout << "Ответ: уравнение не имеет решений";
    }
    else if (a == 0 and b == 0 and c == 0) {
        cout << "Ответ: уравнение имеет бесконечное количесво решений";
    }
    else if (D == 0) {
        x1 = (-b) / (2 * a);
        cout << "Ответ: x = " << x1;
    }
    else if (D > 0) {
        x1 = ((-b) + sqrt(D)) / (2 * a);
        x2 = ((-b) - sqrt(D)) / (2 * a);
        cout << "Ответ: " << endl << "x1 = " << x1 << "\nx2 = " << x2;
    }
    else if (D < 0) {
        cout << "Ответ: уравнение не имеет решений";
    }
    return 0;
}