#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name;
    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "Привет, " << name << endl;
    return 0;
}
