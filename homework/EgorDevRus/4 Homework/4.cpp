#include <windows.h>
#include <iostream>
using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m1 = 37, i1 = 3, c1 = 64;
    int s = 0,n;
    int m2 = 25173; int i2 = 13849; int c2 = 65537;
    cout << "Вариант №1" << endl;
    cout << "Введите количество чисел" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        s = (m1 * s + i1) % c1;
        cout << i+1 << " число: " << s <<endl;
    }

    cout << endl;
    s = 0;
    cout << "Вариант №2" << endl;
    cout << "Введите количество чисел" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        s = (m2 * s + i2) % c2;
        cout << i+1 << " число: " << s <<endl;
    }

    return 0;
}
