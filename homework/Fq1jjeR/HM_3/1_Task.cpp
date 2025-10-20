#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    // Устанавливаем кодировку консоли на UTF-8 для правильного отображения
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream shows_file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HM_3\1_Task.txt)");

    // Проверяем, открылся ли файл
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