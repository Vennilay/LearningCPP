#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double number1 = 0;
    double number2 = 0;

    cout << "Введите первое число: " << endl;
    cin >> number1;

    cout << "Введите второе число: " << endl;
    cin >> number2;

    cout << "Сумма чисел: " << number1 + number2 << endl;
    cout << "Разность чисел: " << number1 - number2 << endl;
    cout << "Произведение чисел: " << number1 * number2 << endl;

    if (number2 == 0)
        cout << "Деление на ноль запрещено!" << endl;
    else
        cout << "Частное от деления: " << number1 / number2 << endl;
    return 0;
}