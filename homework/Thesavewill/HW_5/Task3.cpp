#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string strSearch, strFile;
    string filename = "task1.txt";

    cout << "Номер 18" << endl;
    cout << "Введите искомую подстроку:";
    cin >> strSearch;

    ofstream out(filename);
    out << "dgasyhgf2yg476124tugvsdgoida1337645wtegnww5y4h";
    out.close();

    ifstream in(filename);
    getline(in, strFile);
    in.close();

    if (strFile.find(strSearch) != string::npos) {
        cout << "Эта подстрока есть в строке" << endl;
    } else {
        cout << "Этой подстроки нет в строке" << endl;
    }
    return 0;
}