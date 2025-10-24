#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double numberB = 0;
    double numberC = 0;

    cout << "Введите число b: " << endl;
    cin >> numberB;
    cout << "Введите число c: " << endl;
    cin >> numberC;

    if (numberB == 0 && numberC == 0) {
        cout << "Бесконечно много решений!" << endl;
    }
    else if (numberB == 0) {
        cout << "Решений нет!" << endl;
    }
    else if (numberC == 0) {
        cout << "X равен: 0" << endl;
    }
    else {
        cout << "X равен: " << -numberC / numberB << endl;
    }
}