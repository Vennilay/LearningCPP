#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string IsDay, СurtainsOpen, LampOn;
    cout << "Какое сейчас время суток? (день/ночь) "; cin >> IsDay;
    cout << "Шторы открыты? (да/нет) "; cin >> СurtainsOpen; 
    cout << "Ламба включена? (да/нет) "; cin >> LampOn;

    if (IsDay == "день" and СurtainsOpen == "да" or LampOn == "да") {
        cout << "В комнате светло";
    }
    else {
        cout << "В комнате темно";
    }
}