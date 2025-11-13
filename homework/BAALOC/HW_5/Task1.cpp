#include <iostream>
#include <string>
#include <map>

int decodeRoman(const std::string& roman) {
    std::map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

    int result = 0;

    for (size_t i = 0; i < roman.length(); i++) {
        int current = values[roman[i]];

        if (i + 1 < roman.length()) {
            int next = values[roman[i + 1]];

            if (current < next) {
                result += next - current;
                i++;
            } else {
                result += current;
            }
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
    std::cout << roman << " = " << decodeRoman(roman) << std::endl;

    return 0;
}
