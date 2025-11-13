#include <iostream>
//#include <clocale>
#include <windows.h>
#include <string>
using namespace std;


int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string b;
    cout << "Введите имя: ";
    cin >> b;
    cout << "Привет, " << b<<endl;
    return 0;
}