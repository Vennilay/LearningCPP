#include <iostream>
#include <string>

int main() {
    std::string number;
    int oldBase, newBase;

    std::cout << "Число: ";
    std::cin >> number;
    std::cout << "Старая система исчисления: ";
    std::cin >> oldBase;
    std::cout << "Новая система исчисления: ";
    std::cin >> newBase;

    if (oldBase < 2 || oldBase > 36 || newBase < 2 || newBase > 36) {
        std::cout << "Ошибка: основание должно быть в диапазоне [2, 36]" << std::endl;
        return 1;
    }

    int decimal = 0;
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
            std::cout << "Ошибка: недопустимый символ '" << c << "'" << std::endl;
            return 1;
        }

        if (digit >= oldBase) {
            std::cout << "Ошибка: цифра '" << c << "' (значение " << digit
                      << ") недопустима для системы с основанием " << oldBase << std::endl;
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
        const int remainder = decimal % newBase;
        char digitChar;

        if (remainder < 10) {
            digitChar = static_cast<char>('0' + remainder);
        } else {
            digitChar = static_cast<char>('A' + remainder - 10);
        }

        result.insert(0, 1, digitChar);
        decimal /= newBase;
    }

    std::cout << "Результат: " << result << std::endl;
    
    return 0;
}
