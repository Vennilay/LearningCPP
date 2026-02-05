#include <iostream>
#include <windows.h>
using namespace std;

void pseudorandom(int m, int i, int c, int n)
{
    int s = 0;
    for (int j = 0; j < n; j++)
    {
        cout << s << " ";
        s = (m * s + i) % c;
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;

    cout << "Сколько чисел нужно сгенерировать: ";
    cin >> n;
    cout << "Вариант 1: ";
    pseudorandom(37, 3, 64, n);
    cout << "Вариант 2: ";
    pseudorandom(25173, 13849, 65537, n);

    return 0;
}
