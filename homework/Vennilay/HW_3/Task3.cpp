#include <iostream>
#include <string>
#include <algorithm>


void bubbleSort(std::string& str) {
    int n = str.length();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::string line;
    std::string s = "";
    int i = 0;

    std::cout << "Введите строку (буквы латиницы или кириллицы): ";
    getline(std::cin, line);

    while ((s.length() < 30) && (i < line.length()))
    {
        if (((line[i] > 64) && (line[i] <= 90)) ||
            ((line[i] > 96) && (line[i] <= 122)) ||
            (line[i] < 0))
        {
            s = s + line[i];
        }
        i++;
    }

    if ((s.length() == 30) && (i < line.length())) {
        bool hasInvalidChars = false;

        for (int j = i; j < line.length(); j++) {
            if (!(((line[j] > 64) && (line[j] <= 90)) ||
                  ((line[j] > 96) && (line[j] <= 122)) ||
                  (line[j] < 0)))
            {
                hasInvalidChars = true;
                break;
            }
        }

        if (hasInvalidChars) {
            std::cout << "Ошибка: после 30-й буквы обнаружен посторонний символ!" << std::endl;
            return 1;
        }
    }

    if (s.empty()) {
        std::cout << "Ошибка: строка не содержит букв!" << std::endl;
        return 1;
    }

    std::cout << "\nИсходная строка (только буквы): " << s << std::endl;
    std::cout << "Количество букв: " << s.length() << std::endl;

    std::sort(s.begin(), s.end());

    std::cout << "Отсортированная строка: " << s << std::endl;

    return 0;
}
