#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    bool allowed = true;
    cout << "Введите строку для сортировки: ";
    cin >> text;
    for (int i = 0; i < text.length(); i++)
    {
        if (not (((text[i] > 64) && (text[i] <= 90)) || ((text[i] > 96) && (text[i] <= 122)) || (text[i] < 0)))
        {
            allowed = false;
            break;
        }
    }

    if (allowed)
    {
        text = text.substr(0, 30);
        sort(begin(text), end(text));
        cout << text << endl;
    }
    else
    {
        cout << "В строке есть запрещённые символы" << endl;
    }
    return 0;
}
