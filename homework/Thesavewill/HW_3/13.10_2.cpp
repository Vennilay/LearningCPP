#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string line, str;
    ifstream fin("text.txt");

    if (!fin) {
        cout << "Не удалось открыть файл.";
    }
    else {
        while (getline(fin, line)) {
            for (char c : line) {
                if (c >= '0' and c <= '9') {
                    cout << c;
                }
            }
        }
    }
    return 0;
}