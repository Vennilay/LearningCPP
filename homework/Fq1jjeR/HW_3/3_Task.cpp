#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream shows_file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_3\3_Task.txt)");
    string show, line;

    if (!shows_file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (getline(shows_file, show)) {
        line += show;
    }
    if (line.length() > 30) {
        cout << "Ошибка: строка содержит более 30 символов!" << endl;
        return 1;
    }
    sort(line.begin(), line.end());
    cout << line;

    shows_file.close();

    return 0;
}