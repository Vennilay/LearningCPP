#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int a, b, c;
    cout << "Введите стоимость основания спиннера: ";
    cin >> a;
    cout << "Введите стоимость одной лопасти: ";
    cin >> b;
    cout << "Введите максимальную стоимость всего спиннера: ";
    cin >> c;

    if (a <= c)
    {
        cout << "Максимальное число лопастей спиннера: " << (c - a) / b << endl;
    }
    else
    {
        cout << "Введены недопустимые значения" << endl;
    }

	return 0;
}
