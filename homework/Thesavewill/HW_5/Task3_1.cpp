#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string strSearch;
    string filename = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/task3.txt";

    cout << "Номер 18" << endl;
    cout << "Введите искомую подстроку:";
    cin >> strSearch;

    ifstream in(filename);
    if (!in) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    string line;
    bool found = false;
    while (getline(in, line)) {
        if (line.find(strSearch) != string::npos) {
            found = true;
            break;
        }
    }
    in.close();

    if (found) {
        cout << "Эта подстрока есть в файле" << endl;
    } else {
        cout << "Этой подстроки нет в файле" << endl;
    }

    return 0;
}
