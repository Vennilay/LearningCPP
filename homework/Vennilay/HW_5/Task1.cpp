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

int decodeRoman(const std::string& roman) {
    int result = 0;
    const size_t length = roman.length();

    for (size_t i = 0; i < length; i++) {
        const int current = getValue(roman[i]);
        if (i + 1 < length && current < getValue(roman[i + 1])) {
            result = result - current;
        } else {
            result = result + current;
        }
    }
    return result;
}

std::string encodeRoman(int num) {
    if (num <= 0) return "";

    const int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for (int i = 0; i < 13; i++) {
        while (num >= vals[i]) {
            res += strs[i];
            num -= vals[i];
        }
    }
    return res;
}

int main() {
    std::string roman;
    std::cout << "Введите римское число: ";
    std::cin >> roman;

    for (size_t i = 0; i < roman.length(); i++) {
        if (getValue(roman[i]) == 0) {
            std::cout << "Ошибка: посторонние символы!" << std::endl;
            return 1;
        }
    }

    const int number = decodeRoman(roman);

    const std::string check = encodeRoman(number);

    if (check == roman) {
        std::cout << roman << " = " << number << std::endl;
    } else {
        std::cout << "Ошибка: нарушение правил записи" << std::endl;
    }

    return 0;
}
