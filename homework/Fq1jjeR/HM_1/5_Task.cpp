#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char day, curtains, lamp;

    cout << "На улице день?(На выбор: + или - )" << endl;
    cin >> day;

    cout << "Шторы раздвинуты?(На выбор: + или - )" << endl;
    cin >> curtains;

    cout << "Лампа включена?(На выбор: + или - )" << endl;
    cin >> lamp;


    if (day == '+') {
        if (curtains == '+' || lamp == '+')
            cout << "В комнате светло";
        else
            cout << "В комнате темно";
    }
    else
        cout << "В комнате темно";

}
