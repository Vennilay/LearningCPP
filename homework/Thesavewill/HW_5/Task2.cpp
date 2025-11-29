#include <algorithm>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// Преобразование символа в число (0-35)
int charToVal(char i) {
    if (isdigit(i)) return i - '0';
    return toupper(i) - 'A' + 10;
}

// Преобразование числа (0-35) в символ
char valToChar(int i) {
    if (i < 10) return '0' + i;
    return 'A' + (i - 10);
}
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string num, result;
    int base_old, base_new;

    cout << "Введите число: ";
    cin >> num;

    cout << "Введите старое основание: ";
    cin >> base_old;

    cout << "Введите новое основание: ";
    cin >> base_new;

    // 1) Переводим из старой системы → в десятичное
    int decimal = 0;
    for (char c : num) {
        decimal = decimal * base_old + charToVal(c);
    }

    // 2) Переводим из десятичного → в новую систему
    if (decimal == 0) {
        cout << 0;
        return 0;
    }

    while (decimal > 0) {
        int r = decimal % base_new;
        result += valToChar(r);
        decimal /= base_new;
    }

    reverse(result.begin(), result.end());

    cout << "Результат: " << result << endl;

    return 0;
}
