#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream file(R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_3\2_Task.txt)");
    char ch;
    bool count = true;

    if (file.is_open()) {

        while (file.get(ch)) {
            if (isdigit(ch)){
                cout << ch;
                count = true;
            }
            if ((isalpha(ch) || ch == ' ') && count){
                cout << " ";
                count = false;
            }
        }
        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }

    return 0;
}
