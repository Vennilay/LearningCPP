#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;
//4
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string filename = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/words.txt";
    vector<string> words;
    string word;

    // Чтение слов из файла
    ifstream infile(filename);
    while (infile >> word) {
        words.push_back(word);
    }
    infile.close();

    // Основной цикл добавления слов
    while (true) {
        cout << "Введите слово для добавления (или 'exit' для выхода):";
        string newWord;
        cin >> newWord;

        if (newWord == "exit") break; // выход из цикла

        words.push_back(newWord);
        sort(words.begin(), words.end()); // сортировка после добавления

        // Запись обратно в файл
        ofstream outfile(filename);
        for (size_t i = 0; i < words.size(); i++) {
            outfile << words[i] << "\n";
        }
        outfile.close();

        // Вывод текущего списка
        cout << "Текущий список слов:\n";
        for (size_t i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << "\n\n";
    }

    cout << "Программа завершена.\n";
    return 0;
}
