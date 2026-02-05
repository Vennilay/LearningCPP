#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long n, m, sum_n, sum_m, result;
    cout << "Введите N: ";
    cin >> n;
    cout << "Введите M: ";
    cin >> m;

    if (n <= 75000 && m <= 75000 && n > 0 && m > 0)
    {
        sum_n = n * (n + 1) / 2;
        sum_m = m * (m + 1) / 2;
        result = sum_n * sum_m;
        cout << "Количество прямоугольников, которые можно вырезать: " << result << endl;
    }
    else
    {
        cout << "Введены недопустимые значения" << endl;
    }

    return 0;
}
