#include <iostream>
#include <windows.h>
using namespace std;
//28
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    int a = 0;

    cout << "Введите строку цифр:";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            a += str[i] - '0';
        } else {
            cout << "Строка содержит нецифровой символ: " << str[i] << endl;
            return 1;
        }
    }

    cout << "Сумма цифр: " << a << endl;
    return 0;
}