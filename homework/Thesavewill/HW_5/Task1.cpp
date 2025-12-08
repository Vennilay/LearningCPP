#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int rimToInt(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

string intToRim(int num) {
    int vals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res;
    for (int i = 0; i < 13; i++) {
        while (num >= vals[i]) {
            res += syms[i];
            num -= vals[i];
        }
    }
    return res;
}

int rimToArabic(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        int curr = rimToInt(s[i]);
        if (curr == 0) return -1;

        int next = 0;
        if (i + 1 < s.length()) {
            next = rimToInt(s[i + 1]);
        }

        if (curr < next) {
            result -= curr;
        } else {
            result += curr;
        }
    }

    if (intToRim(result) != s) return -2;
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    for (int i = 0; i < 100; i++) {
        cout << "Введите римское число:";
        cin >> input;

        int rez = rimToArabic(input);
        if (rez == -1) {
            cout << "Ошибка: посторонние символы!" << endl;
        } else if (rez == -2) {
            cout << "Ошибка: нарушение правил записи" << endl;
        } else {
            cout << "В арабских числах:" << rez << endl;
        }
    }
}
