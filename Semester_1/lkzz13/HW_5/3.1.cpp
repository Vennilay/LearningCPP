#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("/Users/lkzz/CLionProjects/untitled/main.txt");

    if (inputFile.is_open()) {
        char c;
        cout << "Результат замены пробелов:";
        while (inputFile.get(c)) {
            if (c == ' ') {
                cout << '=';
            } else {
                cout << c;
            }
        }
        inputFile.close();
    } else {
        cout << "Ошибка открытия файла." << endl;
    }

    return 0;
}