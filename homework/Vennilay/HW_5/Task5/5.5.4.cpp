#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    const std::string inputFilename = "../txtfiles/5.5.4.txt";
    const std::string outputFilename = "../txtfiles/5.5.4_sorted.txt";
    std::vector<std::string> words;
    std::string temp;

    std::ifstream fin(inputFilename);
    if (fin) {
        while (fin >> temp) {
            words.push_back(temp);
        }
        fin.close();
    }

    std::cout << "Введите слово для добавления: ";
    if (std::cin >> temp) {
        words.push_back(temp);
    }

    std::sort(words.begin(), words.end());

    std::ofstream fout(outputFilename);
    if (!fout) {
        std::cerr << "Ошибка при открытии файла для записи\n";
        return 1;
    }

    for (const auto& w : words) {
        fout << w << '\n';
    }

    std::cout << "Слово добавлено, список отсортирован и сохранен в " << outputFilename << "\n";
    return 0;
}