#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float x, y, b, z = 0.0;
	cout << "Введите число x: "; cin >> x;
	cout << "Введите число y: "; cin >> y;
	cout << "Введите число b: "; cin >> b;

	if ((b - y) > 0 and (b - x) >= 0) {
		z = log(b - y) * sqrt(b - x);
		cout << "Значение функции f(z): " << z;
	}
	else {
		cout << "Аргументы функций выходят за область их определения";
	}
}