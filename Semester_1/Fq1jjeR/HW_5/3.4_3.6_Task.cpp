#include <iostream>
#include <fstream>

using namespace std;

// Очищает слово от знаков препинания, оставляя только буквы и цифры
string cleanWord(string word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c))
            cleaned += c;
    }
    return cleaned;
}

string findLongestWord(ifstream& file) {
    file.clear();
    file.seekg(0);

    string longest;
    string word;

    while (file >> word) {
        string clean = cleanWord(word);

        if (!clean.empty() && clean.length() > longest.length())
            longest = clean;
    }

    return longest;
}

string findShortestWord(ifstream& file) {
    file.clear();
    file.seekg(0);

    string shortest;
    string word;
    bool first = true;

    while (file >> word) {
        string clean = cleanWord(word);

        if (!clean.empty()) {
            if (first || clean.length() < shortest.length()) {
                shortest = clean;
                first = false;
            }
        }
    }

    return shortest;
}

int main() {
    ifstream file("files/3_Task.txt");

    if (!file) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    string longest = findLongestWord(file);
    string shortest = findShortestWord(file);

    cout << "=== Задача 4 ===" << endl;
    cout << "Слово максимальной длины: " << longest << endl;
    cout << "Длина: " << longest.length() << endl;

    cout << "=== Задача 6 ===" << endl;
    cout << "Слово минимальной длины: " << shortest << endl;
    cout << "Длина: " << shortest.length() << endl;

    file.close();
    return 0;
}
