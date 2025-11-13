#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	double r, m, S,p;
	cout << "Введите сумму займа: "; cin >> S;
	cout << "Введите процент: "; cin >> p;
	cout << "Введите на сколько лет: "; cin >> n;


	if (n >= 1 && S > 0 && p!=(-1)) {

		r = p / 100.0;

		m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		cout << "Месячная выплата: " << m << endl;
		cout << "Срок займа в месяцах: " << 12 * n << endl;
	}
	else {
		cout << "Некорректные данные" << endl;
	}


	return 0;

}