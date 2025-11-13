#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "a * x^2 + b * x + c=0\n";

    float a, b, c, D, x1, x2;

    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    cout << "Введите c: ";
    cin >> c;

// WELCOME TO GIT
    
    D = pow(b, 2) - 4 * a * c;
    if (a == 0) {
        if (b == 0 && c == 0) {
            cout << "Бесконечное множество корней";
        }
        else if (b == 0) {
            cout << "Нет решений уравнения";
        }
        else {
            x1 = x2 = (-c) / b;

            if (x1 == 0) x1 = 0;//убирает -, если x == -0
            cout << "Один корень: " << x1;

        }

    }

    else if (D >= 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);

        cout << "Первый корень: " << x1 << "\n";
        cout << "Второй корень: " << x2 << "\n";
        if (x1 == x2) {
            cout << "Корень чётной кратности";
        }
    }
    else {
        cout << "Нет решений";
    }

    return 0;

}
