#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


int delenie(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minys(int a, int b) {
    while (a != b) {
        // Если a больше b, вычитаем b из a
        if (a > b) {
            a = a - b;
        }
            // Иначе (b больше a), вычитаем a из b
        else {
            b = b - a;
        }
    }
    // Когда a и b равны, они и являются НОД
    return a;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c;

    cout << "Введите первое число:";
    cin >> a;
    cout << "Введите второе число:";
    cin >> b;

    cout << "Введите способ нахождения(0 - делением, 1 - вычитанием):";
    cin >> c;

    if (c == 0)
        cout << "НОД: " << delenie(a, b);
    else
        cout << "НОД: " << minys(a, b);
}