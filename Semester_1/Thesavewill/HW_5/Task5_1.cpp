#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;
//4
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/words.txt";
    vector<string> words;
    string word;

    ifstream infile(filename);
    while (infile >> word) {
        words.push_back(word);
    }
    infile.close();

    while (true) {
        cout << "Введите слово для добавления (или 'exit' для выхода):";
        string newWord; cin >> newWord;

        if (newWord == "exit") break;

        words.push_back(newWord);
        sort(words.begin(), words.end());

        ofstream outfile(filename);
        for (size_t i = 0; i < words.size(); i++) {
            outfile << words[i] << endl;
        }
        outfile.close();

        cout << "Текущий список слов:\n";
        for (size_t i = 0; i < words.size(); i++) {
            cout << words[i] << " ";
        }
        cout << "\n\n";
    }

    cout << "Программа завершена.";
    return 0;
}
