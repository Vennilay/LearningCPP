#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
//22
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string strSearch, strFile;
    string filename = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/task3.txt";

    cout << "Номер 22" << endl;

    cout << "Введите строку для записи в файл: ";
    cin >> strFile;

    // Записываем введённую строку в файл
    ofstream out(filename);
    out << strFile;
    out.close();

    cout << "Введите искомую подстроку: ";
    cin >> strSearch;

    // Читаем строку из файла
    ifstream in(filename);
    getline(in, strFile);
    in.close();

    // Проверяем наличие подстроки
    if (strFile.find(strSearch) != string::npos) {
        cout << "Эта подстрока есть в строке" << endl;
    }
    else {
        cout << "Этой подстроки нет в строке" << endl;
    }

    return 0;
}
