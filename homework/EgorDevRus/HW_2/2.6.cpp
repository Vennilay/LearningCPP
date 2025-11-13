#include <cmath>
#include <iostream>
#include <windows.h>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int n;
	double r, m, S, p, m1, delta, min_delta,best_p;

	cout << "Введите сумму займа: "; cin >> S;
	cout << "Введите на сколько лет: "; cin >> n;
	cout << "Введите месячную выплату: "; cin >> m;

	best_p = 0;
	min_delta = 10000;

	
	if (n >= 1 && S > 0) {
		for (int p = 0; p <= 100; p++) {
			r = p / 100.0;
			m1 = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
			delta = abs(m1 - m);
			if (delta < min_delta) {
				min_delta = delta;
				best_p = p;


			}
		}
		cout <<"Процентная ставка: " << best_p << endl;
	}
	else {
		cout << "Некорректные данные" << endl;
	}




    return 0;
}
