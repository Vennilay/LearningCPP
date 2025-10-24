#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    float a, b, c, x1, x2;

    cout << "Первое число: ";
    cin >> a;
    cout << "Второе число: ";
    cin >> b;
    cout << "Третье число: ";
    cin >> c;


    float discriminant = (b * b) - (4 * a * c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Любой x";
            }
            else {
                cout << "Нет решений";
            }
        }
        else {
            x1 = -c / b;
            cout << "x = " << x1;
        }
    }
    else {
        if (discriminant < 0) {
            cout << "D < 0";
        }
        else if(discriminant == 0){

            x1 = x2 = -b / (2 * a);
            if (x1 == x2 == 0)
                cout << "x = 0";
            else
                cout << "x1 = " << x1 << "; " << "x2 = " << x2;

        }
        else {
            x1 = (-b - sqrt(discriminant)) / (2 * a);
            x2 = (-b + sqrt(discriminant)) / (2 * a);
            cout << "x1 = " << x1 << "; " << "x2 = " << x2;
        }
    }
}
