#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float num_1, num_2;

    cout << "Введите первое число: ";
    cin >> num_1;
    cout << "Введите второе число: ";
    cin >> num_2;
    cout << "Сумма чисел: " << num_1 + num_2 << endl;
    cout << "Разность чисел: " << num_1 - num_2 << endl;
    cout << "Произведение чисел: " << num_1 * num_2 << endl;
    if (num_2 != 0)
    {
        cout << "Частное чисел: " << num_1 / num_2 << endl;
    }
    else
    {
        cout << "Нельзя найти частное (деление на ноль)" << endl;
    }
    return 0;
}
