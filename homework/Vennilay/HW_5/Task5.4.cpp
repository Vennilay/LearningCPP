#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream fin("txtfiles/words.txt");
    if (!fin) {
        std::cerr << "Не удалось открыть файл words.txt для чтения\n";
        return 1;
    }

    std::vector<std::string> words;
    std::string w;
    while (fin >> w) {
        words.push_back(w);
    }
    fin.close();

    if (words.empty()) {
        std::cout << "Файл words.txt пуст или в нем нет слов.\n";
        return 0;
    }

    std::sort(words.begin(), words.end());

    std::cout << "Слова после сортировки:\n";
    for (const std::string &s : words) {
        std::cout << s << '\n';
    }

    std::cout << "\nВведите слово для добавления: ";
    std::string newWord;
    std::cin >> newWord;

    auto it = std::lower_bound(words.begin(), words.end(), newWord);
    words.insert(it, newWord);

    std::ofstream fout("txtfiles/words_sorted.txt");
    if (!fout) {
        std::cerr << "Не удалось открыть файл words_sorted.txt для записи\n";
        return 1;
    }

    for (const std::string &s : words) {
        fout << s << '\n';
    }
    fout.close();

    std::cout << "Обновленный отсортированный список слов сохранен в words_sorted.txt.\n";
    return 0;
}
