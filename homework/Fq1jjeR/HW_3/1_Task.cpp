#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream shows_file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_3\1_Task.txt)");

    if (!shows_file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string show;
    while (getline(shows_file, show)) {
        cout << show << endl;
    }

    shows_file.close();
    return 0;
}