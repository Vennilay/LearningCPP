#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string filename = R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_5\5.4_Task.txt)";

    // Чтение слов из файла
    ifstream inFile(filename);
    vector <string> words;
    string word;

    while (inFile >> word) {
        words.push_back(word);
    }

    // Сортировка
    sort(words.begin(), words.end());

    // Добавление нового слова
    string newWord;
    cout << "Введите слово для добавления: ";
    cin >> newWord;

    auto pos = lower_bound(words.begin(), words.end(), newWord);
    words.insert(pos, newWord);

    // Запись в файл
    ofstream outFile(filename);
    for (const auto& w : words) {
        outFile << w << endl;
    }

    return 0;
}