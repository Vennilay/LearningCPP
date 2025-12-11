#include <iostream>
#include <string>

int charToDigit(const char digit) {
    switch (digit) {
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

int romanToInt(const std::string& rawRoman) {
    int total = 0;
    const int length = rawRoman.length();

    for (int i = 0; i < length; i++) {
        const int currentValue = charToDigit(rawRoman[i]);

        if (i + 1 < length && currentValue < charToDigit(rawRoman[i + 1])) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
    }
    return total;
}

std::string intToRoman(int number) {
    if (number <= 0) return "";

    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string resultRoman;
    for (int i = 0; i < 13; i++) {
        while (number >= values[i]) {
            resultRoman += numerals[i];
            number -= values[i];
        }
    }
    return resultRoman;
}

int main() {
    std::string userInput;
    std::cout << "Введите римское число: ";
    std::cin >> userInput;

    const int inputLength = userInput.length();

    for (int i = 0; i < inputLength; i++) {
        if (charToDigit(userInput[i]) == 0) {
            std::cout << "Ошибка: посторонние символы!" << std::endl;
            return 1;
        }
    }

    const int parsedValue = romanToInt(userInput);
    const std::string validationStr = intToRoman(parsedValue);

    if (validationStr == userInput) {
        std::cout << userInput << ": " << parsedValue << std::endl;
    } else {
        std::cout << "Ошибка записи" << std::endl;
    }

    return 0;
}
