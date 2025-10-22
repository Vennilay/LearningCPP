#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    float a, b;

    cout << "Первое число: ";
    cin >> a;
    cout << "Второе число: ";
    cin >> b;

    cout << "Сумма: " << a + b << endl;
    cout << "Разность: " << a - b << endl;
    cout << "Умножение: " << a * b << endl;

    if (b != 0)
        cout << "Частное: " << a / b << endl;
    else
        cout << "Деление на ноль!";

}
