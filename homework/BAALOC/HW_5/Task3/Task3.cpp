#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "files/BAALOC/HW_5/Task3.txt";
    char separator;

    std::cout << "Введите символ для замены пробелов: ";
    std::cin >> separator;

    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Не удалось открыть файл.\n";
        return 1;
    }

    std::string text, word, maxWord;
    size_t maxLen = 0;

    while (std::getline(fin, text)) {
        size_t pos = 0;

        while (pos < text.size()) {
            word.clear();

            while (pos < text.size() && text[pos] != ' ') {
                word += text[pos++];
            }

            if (word.size() > maxLen) {
                maxLen = word.size();
                maxWord = word;
            }

            ++pos;
        }
    }
    fin.close();

    std::cout << "Слово максимальной длины: " << maxWord << std::endl;
    std::cout << "Длина: " << maxLen << std::endl;

    std::ifstream fin2(filename);
    if (!fin2.is_open()) {
        std::cout << "Не удалось открыть файл для второй обработки.\n";
        return 1;
    }

    while (std::getline(fin2, text)) {
        for (char& c : text) {
            if (c == ' ') {
                c = separator;
            }
        }
        std::cout << text << std::endl;
    }
    fin2.close();

    return 0;
}
