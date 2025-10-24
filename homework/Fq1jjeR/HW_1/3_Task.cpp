#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    float b, c, x;

    cout << "Первое число: ";
    cin >> b;
    cout << "Второе число: ";
    cin >> c;

    if (b == 0) {
        if (c == 0) {
            cout << "Любой x";
        }
        else {
            cout << "Нет решений";
        }
    }
    else if(b > 0 and c == 0){
        cout << "x = 0";
    }
    else {
        x = -c / b;
        cout << "x = " << x;
    }
}
