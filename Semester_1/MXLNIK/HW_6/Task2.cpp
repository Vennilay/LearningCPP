#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, remains, result3 = 0, result4 = 0;
    cout << "Введите количество лопастей: ";
    cin >> m;

    for (int i = 0; i <= m; i += 4)
    {
        remains = m - i;
        if (remains % 3 == 0)
        {
            result3 = remains / 3;
            result4 = i / 4;
        }
    }

    cout << "Спиннеров с тремя лопастями: " << result3 << endl;
    cout << "Спиннеров с четырьмя лопастями: " << result4 << endl;

    return 0;
}
