#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    for (float i = -4; i <= 4; i += 0.5)
    {
        if ((i - 1) == 0)
        {
            cout << "x = " << i << ", y = " << "Функция не определена" << endl;
        }
        else
        {
            cout << "x = " << i << ", y = " << (i * i - 2 * i + 2) / (i - 1) << endl;
        }
    }
    return 0;
}
