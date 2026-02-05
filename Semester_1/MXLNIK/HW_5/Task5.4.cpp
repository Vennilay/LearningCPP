#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string new_word, word;
    vector<string> words;
    ifstream in;
    ofstream out;

    cout << u8"Введите слово для добавления в файл: ";
    cin >> new_word;

    in.open("C:/Users/MXLNIK/Downloads/5.5.4_in.txt");
    out.open("C:/Users/MXLNIK/Downloads/5.5.4_out.txt");
    while (in >> word)
    {
        words.emplace_back(word);
    }
    words.emplace_back(new_word);
    sort(words.begin(), words.end());
    for (string word : words)
    {
        out << word << " ";
    }

    in.close();
    out.close();

    return 0;
}
