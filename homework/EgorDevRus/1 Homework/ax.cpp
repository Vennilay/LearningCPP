#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	float b, c, res;

	cout << "уравнение bx + c = 0\n";

	cout << "введите b: ";
	cin >> b;

	cout << "введите c: ";
	cin >> c;

	

	if (c == 0 && b == 0) {
		cout << "Бесконечное множество корней";
	}
	else if (b == 0) {
		cout << "Нет решений";
	}
	else {
		res = (-c) / b;
		if (res == 0) {
			res = 0;//убирает -, если x == -0
		}
		cout << "x равен: " << res;

		
	}


	return 0;

}