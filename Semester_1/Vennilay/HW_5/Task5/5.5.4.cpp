#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream fin("../txtfiles/5.5.4.txt");
    if (!fin.is_open()) {
        std::cerr << "Ошибка: Файл не найден!" << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::string temp;

    while (fin >> temp) {
        words.push_back(temp);
    }

    std::cout << "Введите слово для добавления: ";
    std::cin >> temp;
    words.push_back(temp);

    std::sort(words.begin(), words.end());

    std::ofstream fout("../txtfiles/5.5.4_sorted.txt");
    for (const std::string& w : words) {
        fout << w << '\n';
    }

    std::cout << "Слово добавлено";

    return 0;
}
