#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::string filename, newDelimiter;
    std::cout << "Имя файла: ";
    std::cin >> filename;

    std::ifstream in(filename);
    if (!in) {
        std::cout << "Ошибка открытия файла.\n";
        return 1;
    }

    std::map<char, int> freq;
    std::string text, line;
    while (std::getline(in, line)) text += line + '\n';
    in.close();

    for (char c : text) freq[c]++;
    char minChar = '\0';
    int minCount = INT_MAX;
    for (auto p : freq) {
        if (p.second < minCount) {
            minChar = p.first;
            minCount = p.second;
        }
    }
    std::cout << "Наименее часто встречающийся символ: '" << minChar << "' встречается " << minCount << " раз.\n";

    std::cout << "Введите новый разделитель (символ): ";
    std::cin >> newDelimiter;

    for (char& c : text) {
        if (c == ' ') c = newDelimiter[0];
    }

    std::ofstream out("converted_" + filename);
    out << text;
    out.close();
    std::cout << "Результат сохранён в файл: converted_" << filename << std::endl;
    return 0;
}
