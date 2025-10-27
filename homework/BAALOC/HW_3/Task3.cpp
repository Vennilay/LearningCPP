#include <iostream>
#include <string>

bool isLatinLetter(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void bubbleSort(std::string& str) {
    size_t n = str.length();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                std::swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    std::string line;
    std::cout << "Введите строку: ";
    std::getline(std::cin, line);

    std::string s;
    size_t i = 0;

    while (s.length() < 30 && i < line.length()) {
        if (isLatinLetter(line[i])) {
            s += line[i];
        } else {
            std::cout << "Файл содержит посторонние символы!" << std::endl;
            return 1;
        }
        i++;
    }

    bubbleSort(s);

    std::cout << s << std::endl;
    return 0;
}
