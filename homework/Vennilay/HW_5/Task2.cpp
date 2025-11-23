#include <iostream>
#include <string>

int main() {
    std::string number;
    int oldBase, newBase;

    std::cout << "Число: ";
    std::cin >> number;
    std::cout << "Старая база: ";
    std::cin >> oldBase;
    std::cout << "Новая база: ";
    std::cin >> newBase;

    int decimal = 0;
    for (int i = 0; i < number.length(); i++) {
        const char c = number[i];
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else {
            digit = c - 'A' + 10;
        }

        decimal = decimal * oldBase + digit;
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
