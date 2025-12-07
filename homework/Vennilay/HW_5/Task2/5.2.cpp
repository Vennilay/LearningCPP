#include <iostream>
#include <string>

int main() {
    std::string number;
    int oldBase = 0, newBase = 0;
    const std::string ALPHABET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::cout << "Введите число, старое основание и новое основание: ";
    std::cin >> number >> oldBase >> newBase;

    if (oldBase < 2 || oldBase > 36 || newBase < 2 || newBase > 36) {
        std::cout << "Ошибка: основание должно быть [2, 36]" << std::endl;
        return 1;
    }

    long long decimal = 0;
    for (int i = 0; i < number.length(); i++) {
        const char c = number[i];
        int digit = -1;

        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'A' && c <= 'Z') digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10;

        if (digit == -1 || digit >= oldBase) {
            std::cout << "Ошибка в числе" << std::endl;
            return 1;
        }
        decimal = decimal * oldBase + digit;
    }

    if (decimal == 0) {
        std::cout << "Результат: 0" << std::endl;
        return 0;
    }

    std::string result;
    while (decimal > 0) {
        result = ALPHABET[decimal % newBase] + result;
        decimal /= newBase;
    }

    std::cout << "Результат: " << result << std::endl;
    return 0;
}
