#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string filename = "/Users/lkzz/CLionProjects/untitled/main.txt";

    vector<string> words;
    string word;

    ifstream inFile(filename);
    while (inFile >> word) {
        words.push_back(word);
    }
    inFile.close();

    sort(words.begin(), words.end());

    string newWord;
    cout << "Введите новое слово: ";
    cin >> newWord;

    auto it = lower_bound(words.begin(), words.end(), newWord);
    words.insert(it, newWord);

    ofstream outFile(filename);
    for (const auto& w : words) {
        outFile << w << endl;
    }
    outFile.close();
    return 0;
}