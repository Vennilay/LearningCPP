#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string name;

    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "Привет, " << name;
}
