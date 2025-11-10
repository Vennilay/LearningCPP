#include <iostream>
#include <string>

int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char valueToChar(int val) {
    return val < 10 ? '0' + val : 'A' + val - 10;
}

long long toDecimal(std::string num, int base) {
    long long result = 0;
    for (char c : num) {
        result = result * base + charToValue(c);
    }
    return result;
}

std::string fromDecimal(long long num, int base) {
    if (num == 0) return "0";

    std::string result = "";
    while (num > 0) {
        result = valueToChar(num % base) + result;
        num /= base;
    }
    return result;
}

int main() {
    std::string number;
    int oldBase, newBase;

    std::cout << "Число: ";
    std::cin >> number;
    std::cout << "Старое основание: ";
    std::cin >> oldBase;
    std::cout << "Новое основание: ";
    std::cin >> newBase;

    long long decimal = toDecimal(number, oldBase);
    std::string result = fromDecimal(decimal, newBase);

    std::cout << number << " (" << oldBase << ") = "
        << result << " (" << newBase << ")" << std::endl;

    return 0;
}
