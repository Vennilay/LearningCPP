#include<iostream>
#include<windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double x;

	cout << "Введите натуральное число: "; cin >> x;
	if (x > 0 && x == (int)x) {
		for (int i = 0; i < 10; i++) {
			cout << x+i << endl;
		}
	}
	else
		cout << "Вы ввели не натуральное число" << endl;


	return 0;
}