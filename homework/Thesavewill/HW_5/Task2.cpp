#include <algorithm>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int charToVal(char i) {
    if (isdigit(i)) return i - '0';
    return toupper(i) - 'A' + 10;
}

char valToChar(int i) {
    if (i < 10) return '0' + i;
    return 'A' + i - 10;
}

bool isValidNumber(string num, int base) {
    for (char c : num) {
        int val = charToVal(c);
        if (val >= base) return false;
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string num, result;
    int base_old, base_new;

    cout << "Введите старое основание:";
    cin >> base_old;

    cout << "Введите число:";
    cin >> num;

    if (!isValidNumber(num, base_old)) {
        cout << "Ошибка: число некорректно для данной системы счисления." << endl;
        return 1;
    }

    cout << "Введите новое основание:";
    cin >> base_new;

    int decimal = 0;
    for (char c : num) {
        decimal = decimal * base_old + charToVal(c);
    }

    if (decimal == 0) {
        cout << "Результат:" << 0 << endl;
        return 0;
    }

    while (decimal > 0) {
        int r = decimal % base_new;
        result += valToChar(r);
        decimal /= base_new;
    }

    reverse(result.begin(), result.end());

    cout << "Результат:" << result << endl;

    return 0;
}
