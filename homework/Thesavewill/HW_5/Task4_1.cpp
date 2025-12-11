#include <iostream>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP
using namespace std;
//8
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a;
    int n;
    cout << "Введите a:"; cin >> a;
    cout << "Введите n:"; cin >> n;

    double y = 0.0;
    double delitel = a;

    for (int i = 0; i <= n; ++i) {
        y += (i + 1) / delitel;

        delitel *= (a + i + 1);
    }

    cout << "Сумма y = " << y << endl;
    return 0;
}
