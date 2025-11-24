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

bool isValidRoman(const std::string& roman) {
    if (roman.empty()) return false;

    for (const char c : roman) {
        if (getValue(c) == 0) return false;
    }

    int repeatCount = 1;
    for (size_t i = 1; i < roman.size(); i++) {
        if (roman[i] == roman[i - 1]) {
            repeatCount++;
            if (roman[i] == 'V' || roman[i] == 'L' || roman[i] == 'D') return false;
            if (repeatCount > 3) return false;
        } else {
            repeatCount = 1;
        }
    }

    for (size_t i = 0; i + 1 < roman.size(); i++) {
        int current = getValue(roman[i]);
        int next = getValue(roman[i + 1]);
        if (current < next) {
            if (!((roman[i] == 'I' && (roman[i + 1] == 'V' || roman[i + 1] == 'X')) ||
                (roman[i] == 'X' && (roman[i + 1] == 'L' || roman[i + 1] == 'C')) ||
                (roman[i] == 'C' && (roman[i + 1] == 'D' || roman[i + 1] == 'M')))) {
                return false;
            }
        }
    }

    return true;
}

int decodeRoman(const std::string& roman) {
    int result = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        int current = getValue(roman[i]);
        if (i + 1 < roman.size() && current < getValue(roman[i + 1])) {
            result -= current;
        } else {
            result += current;
        }
    }
    return result;
}

int main() {
    std::string roman;
    std::cout << "Введите римское число: ";
    std::cin >> roman;

    if (!isValidRoman(roman)) {
        std::cout << "Ошибка: некорректное римское число!" << std::endl;
        return 1;
    }

    std::cout << roman << " = " << decodeRoman(roman) << std::endl;

    return 0;
}
