#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::ifstream file("2_Task.txt");
    char ch;
    bool count = true;

    if (file.is_open()) {

        while (file.get(ch)) {
            if (std::isdigit(ch)){
                std::cout << ch;
                count = true;
            }
            if ((isalpha(ch) || ch == ' ') && count){
                std::cout << " ";
                count = false;
            }
        }
        file.close();
    } else {
        std::cout << "Не удалось открыть файл" << std::endl;
    }

    return 0;
}
