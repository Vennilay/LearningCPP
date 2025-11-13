#include <cmath>
#include <windows.h>
#include <iostream>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float b, x, y, z;

    cout << "Введите b: "; cin >> b;
    cout << "Введите x: "; cin >> x;
    cout << "Введите y: "; cin >> y;
    
    if (b - y > 0 && b - x >= 0) {
        z = log(b - y) * sqrt(b - x);
        cout << z;
    }
    else
        cout << "Нет решений";

    return 0;
}