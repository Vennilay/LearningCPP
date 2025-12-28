#include <iostream>
#include <string>
using namespace std;

int main() {
    string number;
    int oldBase, newBase;

    cout << "Число: ";
    cin >> number;
    cout << "Старое основание: ";
    cin >> oldBase;
    cout << "Новое основание: ";
    cin >> newBase;

    if (oldBase < 2 || oldBase > 36 || newBase < 2 || newBase > 36) {
        cout << "Ошибка: основания должны быть от 2 до 36" << endl;
        return 1;
    }

    int newnumber = 0;
    for (int i = 0; i < number.length(); i++) {
        const char c = number[i];
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            digit = c - 'a' + 10;
        } else {
            cout << "Ошибка: недопустимый символ '" << c << "'" << endl;
            return 1;
        }

        if (digit >= oldBase) {
            cout << "Ошибка: цифра '" << number << "' недопустима в системе с основанием " << oldBase << endl;
            return 1;
        }
        newnumber = newnumber * oldBase + digit;
    }

    string result;
    if (newnumber == 0) {
        result = "0";
    } else {
        while (newnumber > 0) {
            const int remainder = newnumber % newBase;
            char digitChar;

            if (remainder < 10) {
                digitChar = '0' + remainder;
            } else {
                digitChar = 'A' + remainder - 10;
            }

            result.insert(0, 1, digitChar);
            newnumber /= newBase;
        }
    }

    cout << "Результат: " << result << endl;
    return 0;
}