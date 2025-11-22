#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// перевод символа -> значение
int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

// перевод значения -> символ
char valToChar(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}

// перевод из любой системы в 10-ю
int toDecimal(const string& s, int base) {
    int result = 0;

    for (char c : s) {
        int v = charToVal(c);
        if (v < 0 || v >= base) {
            cout << "Ошибка: некорректный символ!" << endl;
            exit(0);
        }
        result = result * base + v;
    }
    return result;
}

// перевод из 10-й в любую другую
string fromDecimal(int num, int base) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result += valToChar(num % base);
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {

    string number;
    int oldBase, newBase;

    cout << "Введите число: ";
    cin >> number;
    cout << "Введите старое основание: ";
    cin >> oldBase;
    cout << "Введите новое основание: ";
    cin >> newBase;

    int decimalValue = toDecimal(number, oldBase);
    string converted = fromDecimal(decimalValue, newBase);

    cout << "Результат: " << converted << endl;

    return 0;
}
