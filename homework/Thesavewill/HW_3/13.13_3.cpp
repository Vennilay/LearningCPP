#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k = 0;
    string line, str;
    ifstream fin("text.txt");

    if (!fin.is_open()) {
        cout << "Ошибка открытия файла";
        return 1;
    }

    while (getline(fin, line)) {
        k++;
        if (line.size() <= 30) {
            for (char c1 = 'А'; c1 <= 'z'; c1++) {
                for (char c : line) {
                    if ((c >= -32 and c <= -1) or (c >= -64 and c <= -33) or (c >= 64 and c <= 90) or (c >= 96 and c <= 122)) {
                        if (c == c1) {
                            cout << c;
                        }
                    }
                    else {
                        cout << "Файл содержит сторонние символы";
                        return 1;
                    }
                }
            }
        }
        else {
            cout << "Строка не должна быть длинней 30 символов";
            return 1;
        }
    }
    return 0;
}
