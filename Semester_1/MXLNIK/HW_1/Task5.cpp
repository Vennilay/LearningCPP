#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string outside, curtains, lamp;

    cout << "Светло ли на улице? (да/нет): ";
    cin >> outside;
    cout << "Раздвинуты ли шторы? (да/нет): ";
    cin >> curtains;
    cout << "Включена ли лампа? (да/нет): ";
    cin >> lamp;


    if ((outside == "да" and curtains == "да") or lamp == "да")
    {
        cout << "В комнате светло" << endl;
    }
    else
    {
        cout << "В комнате темно" << endl;
    }
    return 0;
}
