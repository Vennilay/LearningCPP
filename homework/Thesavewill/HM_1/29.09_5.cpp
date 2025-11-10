#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double m, S, p, r;
	int n;
	cout << "Введите размер займа: "; cin >> S;
	cout << "Введите кол-во лет для выплаты: "; cin >> n;
	cout << "Введите процент займа: "; cin >> p;
	if (p!=0) {
			r = p / 100.0;
			m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
			cout << "Месячная выплата: " << m << endl;
			cout << "Срок займа в месяцах: " << n * 12;
	}
	else {
		cout << "Месячная выплата: " << S / (n*12) << " рублей";
	}
	return 0;
}