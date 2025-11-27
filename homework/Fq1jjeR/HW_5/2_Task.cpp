#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char valToChar(int v) {
    return (v < 10) ? ('0' + v) : ('A' + (v - 10));
}

// Перевод из любой СС -> 10
int toDecimal(const string& s, int base) {
    bool negative = false;
    int start = 0;

    if (s[0] == '-') {
        negative = true;
        start = 1;
    }

    int result = 0;
    for (int i = start; i < s.size(); i++) {
        int v = charToVal(s[i]);
        if (v < 0 || v >= base) {
            cout << "Ошибка: недопустимый символ '" << s[i] << "' для основания " << base << endl;
            exit(1);
        }
        result = result * base + v;
    }

    return negative ? -result : result;
}

// Перевод из 10 -> любая СС
string fromDecimal(int num, int base) {
    if (num == 0) return "0";

    bool negative = (num < 0);
    num = abs(num);

    string result;
    while (num > 0) {
        result += valToChar(num % base);
        num /= base;
    }
    reverse(result.begin(), result.end());

    return negative ? "-" + result : result;
}

int main() {
    string number;
    int oldBase, newBase;

    cout << "=== Конвертер систем счисления ===" << endl;
    cout << "Введите число: ";
    cin >> number;
    cout << "Введите старое основание (2-36): ";
    cin >> oldBase;
    cout << "Введите новое основание (2-36): ";
    cin >> newBase;

    if (oldBase < 2 || oldBase > 36 || newBase < 2 || newBase > 36) {
        cout << "Ошибка: основания должны быть в диапазоне 2–36." << endl;
        return 1;
    }

    int decimalValue = toDecimal(number, oldBase);
    string converted = fromDecimal(decimalValue, newBase);

    cout << "Результат преобразования: " << converted << endl;
    return 0;
}
