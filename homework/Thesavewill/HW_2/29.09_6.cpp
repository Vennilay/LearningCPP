#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float calc, m, S, r, p = 0.0;
	int n;
	cout << "Введите размер ссуды: "; cin >> S;
	cout << "Введите кол-во лет для выплаты: "; cin >> n;
	cout << "Введите месячную выплату: "; cin >> m;
    if (S > 0 and n > 0 and m > 0) {
        for (p = -100; p <= 100; p+=1.0) {
            r = p / 100.0;
            calc = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
            if (floor(m) == floor(calc)) {
                cout << "Процент под который выдана ссуда: " << p << "%" << endl;
                cout << "Срок в месяцах для выплаты ссуды: " << n*12 << " месяцев";
                break;
            }
        }
    }
    else {
        cout << "Размер ссуды, кол-во лет для выплаты и месячная выплата должны быть больше нуля";
    }
	return 0;
}