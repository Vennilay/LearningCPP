#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, b, f;
    cout << "Выберите способ (1 - делением, 2 - вычитанием): "; cin >> f;
    if (f == 1) {
        cout << "Выбран Алгоритм Евклида через деление\n";
        cout << "Введите первое число: "; cin >> a;
        cout << "Введите второе число: "; cin >> b;
            while (a != 0 and b != 0) {
                if (a > b) {
                    a = a % b;
                }
                else {
                    b = b % a;
                }
            }
            cout << a + b;
    }

    else if (f == 2) {
        cout << "Выбран Алгоритм Евклида через вычитание\n";
        cout << "Введите первое число: "; cin >> a;
        cout << "Введите второе число: "; cin >> b;
        if (a != 0 and b != 0) {
            while (a != b) {
                if (a > b) {
                    a = a - b;
                }
                else {
                    b = b - a;
                }
            }
            cout << a;
        }
        else {
            cout << "Первое и второе число не должны быть равно нулю!";
        }
    }
    return 0;
}