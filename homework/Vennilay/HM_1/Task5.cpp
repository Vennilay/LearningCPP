#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool IsDay;
    bool IsCurtainsOpen;
    bool IsLampOn;

    cout << "На улице день? (Введите 1, если да. 0, если нет)" << endl;
    cin >> IsDay;

    cout << "Шторы открыты? (Введите 1, если да. 0, если нет)" << endl;
    cin >> IsCurtainsOpen;

    cout << "Лампа включена? (Введите 1, если да. 0, если нет)" << endl;
    cin >> IsLampOn;

    if (IsDay && IsCurtainsOpen || IsLampOn)
        cout << "Сейчас в комнате светло" << endl;
    else
        cout << "Сейчас в комнате темно" << endl;
    return 0;
}