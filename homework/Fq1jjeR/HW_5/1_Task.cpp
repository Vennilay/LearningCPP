#include <iostream>
#include <string>
using namespace std;

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; // сигнал ошибки
    }
}

bool isValidRoman(const string& s) {
    int repeatCount = 1;

    for (int i = 0; i < s.length(); i++) {
        int curr = value(s[i]);
        if (curr == -1) return false;

        //  проверка повторений
        if (i > 0 && s[i] == s[i - 1]) {
            repeatCount++;
            if (s[i] == 'V' || s[i] == 'L' || s[i] == 'D')
                return false;
            if (repeatCount > 3)
                return false;
        } else {
            repeatCount = 1;
        }

        //  проверка вычитаний
        if (i + 1 < s.length()) {
            int next = value(s[i + 1]);

            if (curr < next) {

                // допустимые пары
                bool ok =
                        (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                        (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                        (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'));

                if (!ok) return false;

                //  нельзя вычитать дважды подряд
                if (i > 0 && value(s[i - 1]) < curr)
                    return false;

                //  после вычитания нельзя ставить цифры того же или большего разряда
                if (i + 2 < s.length()) {
                    int after = value(s[i + 2]);
                    if (after >= curr)
                        return false;
                }
            }
        }
    }
    return true;
}


int main() {
    string s;
    cout << "Введите римское число: ";
    cin >> s;

    if (!isValidRoman(s)) {
        cout << "Ошибка: некорректное римское число!" << endl;
        return 0;
    }

    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        int curr = value(s[i]);

        int next = 0;
        if (i + 1 < s.length())
            next = value(s[i + 1]);


        if (curr < next)
            result -= curr;
        else
            result += curr;
    }

    cout << "Декодированное число: " << result;
    return 0;
}
