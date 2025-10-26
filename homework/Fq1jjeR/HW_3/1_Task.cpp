#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_3\1_Task.txt)");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}