#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string text;
    ifstream fin;
    fin.open("C:\\Users\\MXLNIK\\Downloads\\text1.txt");
    if (fin.is_open())
    {
        while (getline(fin, text))
        {
            cout << text << endl;
        }
    }
    else
    {
        cout << u8"Указанный файл отсутствует" << endl;
    }
    fin.close();
    return 0;
}
