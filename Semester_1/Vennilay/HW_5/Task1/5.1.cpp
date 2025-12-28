#include <iostream>
#include <string>

int getValue(const char c) {
    switch (c) {
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

int decode(const std::string& line) {
    int res = 0;
    const int len = line.length();

    for (int i = 0; i < len; i++) {
        const int current = getValue(line[i]);

        if (i + 1 < len && current < getValue(line[i + 1])) {
            res -= current;
        } else {
            res += current;
        }
    }
    return res;
}

std::string encode(int num) {
    if (num <= 0) return "";

    const int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for (int i = 0; i < 13; i++) {
        while (num >= vals[i]) {
            res += syms[i];
            num -= vals[i];
        }
    }
    return res;
}

int main() {
    std::string roman;
    std::cout << "Введите римское число: ";
    std::cin >> roman;

    const int len = roman.length();

    for (int i = 0; i < len; i++) {
        if (getValue(roman[i]) == 0) {
            std::cout << "Ошибка: посторонние символы!" << std::endl;
            return 1;
        }
    }

    const int number = decode(roman);
    const std::string check = encode(number);

    if (check == roman) {
        std::cout << roman << " = " << number << std::endl;
    } else {
        std::cout << "Ошибка: нарушение правил записи" << std::endl;
    }

    return 0;
}
