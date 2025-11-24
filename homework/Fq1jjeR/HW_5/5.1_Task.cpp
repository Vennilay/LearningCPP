#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Чтение слов из файла
vector<string> readWords(const string& filename) {
    ifstream file(filename);
    vector<string> words;
    string word;

    while (file >> word) {
        words.push_back(word);
    }

    return words;
}

// Запись слов в файл
void writeWords(const string& filename, const vector<string>& words) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка создания файла!" << endl;
        return;
    }

    for (const auto& w : words) {
        file << w << endl;
    }
}

int main() {
    cout << "=== Задача 4 ===" << endl;
    string filename = R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_5\5.1_Task.txt)";

    // 1) Читаем слова
    vector<string> words = readWords(filename);

    // 2) Сортируем
    sort(words.begin(), words.end());

    // 3) Добавляем новое слово
    string newWord;
    cout << "Введите слово для добавления: ";
    cin >> newWord;

    // Вставка с сохранением сортировки
    auto pos = lower_bound(words.begin(), words.end(), newWord);
    words.insert(pos, newWord);

    // 4) Записываем обратно в файл
    writeWords(filename, words);
    return 0;
}
