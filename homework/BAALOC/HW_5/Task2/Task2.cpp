#include <iostream>
#include <string>
#include <algorithm>

int charToDigit(char c) {
    // исходя из значений ASCI таблицы
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return -1;
}

char digitToChar(int digit) {
    // исходя из значений ASCI таблицы
    if (digit < 10) {
        return static_cast<char>('0' + digit);
    }
    return static_cast<char>('A' + (digit - 10));
}

long long toDecimal(const std::string& number, int base) {
    long long result = 0;

    for (char c : number) {
        result = result * base + charToDigit(c);
    }

    return result;
}

std::string fromDecimal(long long decimal, int base) {
    if (decimal == 0) {
        return "0";
    }

    std::string result;

    while (decimal > 0) {
        result += digitToChar(static_cast<int>(decimal % base));
        decimal /= base;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string number;
    int oldBase, newBase;

    std::cout << "Введите число: ";
    std::cin >> number;

    std::cout << "Введите старое основание: ";
    std::cin >> oldBase;

    std::cout << "Введите новое основание: ";
    std::cin >> newBase;

    long long decimal = toDecimal(number, oldBase);
    std::string result = fromDecimal(decimal, newBase);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
