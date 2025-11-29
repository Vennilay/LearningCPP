#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float b; float c;
    cout << "Решение уравнения вида bx + c = 0" << endl;
    cout << "Введите число b: ";
    cin >> b;
    cout << "Введите число c: ";
    cin >> c;
    float x;
    if (b != 0) {
        x = (-c) / b;
        if (x == -0) {
            x = 0;
        }
        cout << "Ответ: " << x;
    }
    else if (b == 0 and c != 0) {
        cout << "Уравнение не имеет решений";
    }
    else {
        cout << "Уравнение имеет бесконечное количество решений";
    }
    return 0;
}