#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float n;
    int max_num;

    cout << "Введите n: ";
    cin >> n;
    if (n <= 0)
    {
        n = 1;
    }
    n = ceil(n);
    max_num = n + 10;
    for (int i = n; i < max_num; i++)
    {
        cout << i << " ";
    }
    return 0;
}
