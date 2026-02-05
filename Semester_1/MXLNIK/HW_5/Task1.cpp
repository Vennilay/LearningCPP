#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string number, check;
	int result = 0;

	cout << "Введите число в римской записи: ";
	cin >> number;
	vector<int> digits(number.length() + 1);

	for (int i = 0; i < number.length(); i++)
	{
		switch(number[i])
		{
			case 'I': digits[i] = 1; break;
			case 'V': digits[i] = 5; break;
			case 'X': digits[i] = 10; break;
			case 'L': digits[i] = 50; break;
			case 'C': digits[i] = 100; break;
			case 'D': digits[i] = 500; break;
			case 'M': digits[i] = 1000; break;
		}
	}

	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] >= digits[i + 1])
		{
			result += digits[i];
		}
		else
		{
			result -= digits[i];
		}
	}

	int default_digits[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string roman_digits[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int result_copy = result;
	for (int i = 0; i < 13; i++)
	{
		while (result_copy >= default_digits[i])
		{
			check += roman_digits[i];
			result_copy -= default_digits[i];
		}
	}

	if (check == number)
	{
		cout << "Обычная запись числа: " << result << endl;
	}
	else
	{
		cout << "Ошибка в записи римского числа" << endl;
	}

	return 0;
}
