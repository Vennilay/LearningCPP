#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string line, str;

    ifstream fin("text.txt");
    if (!fin) {
        cout << "Не удалось открыть файл";
        return 1;
    }
    getline(fin, line);
    while (fin){
        cout << line << endl;
        getline(fin, line);
    }
    fin.close();
    return 0;
}