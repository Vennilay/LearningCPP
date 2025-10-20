#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream shows_file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HM_3\3_Task.txt)");
    string show, line;

    if (!shows_file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (getline(shows_file, show)) {
        line += show;
    }

    sort(line.begin(), line.end());
    cout << line;

    shows_file.close();

    return 0;
}