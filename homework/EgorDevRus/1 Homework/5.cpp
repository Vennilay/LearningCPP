#define _USE_MATH_DEFINES // чтобы добавить константу пи
#include <iostream>
#include <cmath>
#include <clocale> //необязательное подключение для setlocale
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float R, r, l, h,V,S;

	cout << "Нахождение V и S полной поверхности усечённого конуса\n";

	cout << "Введите радиус нижнего основания: "; cin >> R;
	cout << "Введите радиус верхнего основания: "; cin >> r;
	cout << "Введите высоту усечённого конуса: "; cin >> h;
	
	l = sqrt(pow(h, 2) + pow(R - r, 2));//вычисление длины образующей
	
	V = (1.0 / 3.0) * M_PI * h * (pow(R, 2) + R * r + pow(r, 2));
	
	S = M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2));
	
	cout << "V усечённого конуса: " << V <<endl;
	
	cout << "S полной поверхности усечённого конуса: " << S << endl;
	
	return 0;


}
