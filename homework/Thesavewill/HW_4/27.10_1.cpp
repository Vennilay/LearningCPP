#define _USE_MATH_DEFINES
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
double pramoygolnik();
double treugolnik();
double krug();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int var; double result;
	cout << "Площадь какой фигуры вы хотите вычислить?\n1 - Прямоугольника\n2 - Треугольника\n3 - Круга\n";
	cout << "Введите вариант: "; cin >> var;

	if (var == 1) {
		result = pramoygolnik();
	}
	else if (var == 2) {
		result = treugolnik();
	}
	else {
		result = krug();
	}

	cout << "Площадь фигуры: " << result;
	return 0;
}

double pramoygolnik() {
	double l, h;
	cout << "Введите ширину и высоту фигуры...\n";
	cout << "Ширина: "; cin >> l;
	cout << "Высота: "; cin >> h;
	return l * h;
}

double treugolnik() {
	double l, h;
	cout << "Введите основание и высоту фигуры...\n";
	cout << "Основание: "; cin >> l;
	cout << "Высота: "; cin >> h;
	return (l * h) / 2;
}

double krug() {
	double r;
	cout << "Введите радиус фигуры...\n";
	cout << "Радиус: "; cin >> r;
	return M_PI * r * r;
}