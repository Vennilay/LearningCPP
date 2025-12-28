#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::string filename = "files/Vennilay/HW_3/task3.txt";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::string line;
    std::string result;
    int i = 0;

    std::getline(file, line);
    file.close();


    while ((result.length() < 30) && (i < line.length())) {
        if (((line[i] >= 65) && (line[i] <= 90)) // A-Z (заглавные латинские)
            || ((line[i] >= 97) && (line[i] <= 122)) // a-z (строчные латинские)
            || (line[i] < 0))  {  // Русские буквы
            result += line[i];
        }
        i++;
    }

    if ((result.length() == 30) && (i < line.length())) {
        for (unsigned int j = i; j < line.length(); j++) {
            if (!(((line[j] >= 65) && (line[j] <= 90)) ||
                  ((line[j] >= 97) && (line[j] <= 122)) ||
                  (line[j] < 0))) {
                std::cout << "Ошибка: после 30-й буквы обнаружен посторонний символ!" << std::endl;
                return 1;
            }
        }
    }

    if (result.empty()) {
        std::cout << "Ошибка: строка не содержит букв!" << std::endl;
        return 1;
    }

    std::cout << "Исходная строка (только буквы, макс. 30): " << result << std::endl;
    std::cout << "Количество букв: " << result.length() << std::endl;

    std::sort(result.begin(), result.end());

    std::cout << "Отсортированная строка: " << result << std::endl;

    return 0;
}
