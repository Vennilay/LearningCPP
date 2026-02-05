#include <iostream>
#include <windows.h>
using namespace std;

int sum_of_digits(int number)
{
    int result = 0, i = number;
    while (i > 0)
    {
        result += i % 10;
        i /= 10;
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m;

    cout << "Введите число m < 27: ";
    cin >> m;
    cout << "Все трёхзначные числа, сумма цифр которых равна " << m << ":" << endl;

    for (int i = 100; i < 1000; i++)
    {
        if (sum_of_digits(i) == m)
        {
            cout << i << endl;
        }
    }

    return 0;
}
