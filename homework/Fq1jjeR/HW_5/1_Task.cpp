#include <iostream>

using namespace std;

int getValue(char c) {
    switch (c) {
        case 'I': return 1;   case 'V': return 5;
        case 'X': return 10;  case 'L': return 50;
        case 'C': return 100; case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanToDecimal(string s) {
    int result = 0;

    for (size_t i = 0; i < s.length(); i++) {
        int current = getValue(s[i]);
        if (i + 1 < s.length() && current < getValue(s[i + 1]))
            result = result - current;
        else
            result = result + current;
    }
    return result;
}

string decimalToRoman(int num) {
    if (num <= 0) return "";

    int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result;
    for (int i = 0; i < 13; i++) {
        while (num >= vals[i]) {
            result += strs[i];
            num -= vals[i];
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Введите римское число: ";
    cin >> s;

    for (size_t i = 0; i < s.length(); i++) {
        if (getValue(s[i]) == 0) {
            cout << "Ошибка: посторонние символы!" << endl;
            return 1;
        }
    }

    int number = romanToDecimal(s);

    string validValue = decimalToRoman(number);

    if (validValue == s)
        cout << s << " = " << number << endl;
    else
        cout << "Ошибка: нарушение правил записи" << endl;


    return 0;
}