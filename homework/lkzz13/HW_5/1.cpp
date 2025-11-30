#include <iostream>
#include <map>
#include <string>

using namespace std;
int deshifr(string word) {
    map<char, int> values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0;

    for (int i = 0; i < word.length(); i++) {
        int current = values[word[i]];
        if (i + 1 < word.length() && current < values[word[i + 1]]) {
            result += values[word[i + 1]] - current;
            i++;
        } else {
            result += current;
        }
    }
    return result;
}

int main() {
    string word;
    cout << "Введите римское число: ";
    cin >> word;
    cout << word << " = " << deshifr(word) << endl;
    return 0;
}