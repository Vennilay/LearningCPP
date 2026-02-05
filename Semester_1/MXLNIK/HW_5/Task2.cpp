#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int to_decimal(string number, int from_system)
{
    vector<int> digits(number.length());
    int result = 0;

    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] >= '0' && number[i] <= '9')
        {
            digits[i] = number[i] - 48;
        }
        else
        {
            digits[i] = number[i] - 87;
        }
    }

    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] > from_system)
        {
            return -1;
        }
        result += digits[i] * pow(from_system, i);
    }

    return result;
}

string from_decimal(int number, int to_system)
{
    vector<int> digits;
    string result;

    if (number == 0)
    {
        return "0";
    }
    if (number == -1)
    {
        return "Введены недопустимые для этого основания цифры";
    }

    while (number != 0)
    {
        digits.emplace_back(number % to_system);
        number = number / to_system;
    }

    reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] >= 0 && digits[i] <= 9)
        {
            result += digits[i] + 48;
        }
        else
        {
            result += digits[i] + 87;
        }
    }

    return result;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string number;
    int from_system, to_system;

    cout << "Введите число для перевода: ";
    cin >> number;
    cout << "Введите основание этого числа: ";
    cin >> from_system;
    cout << "Введите основание для перевода: ";
    cin >> to_system;

    if ((from_system >= 2 && from_system <= 36) && to_system >= 2 && to_system <= 36)
    {
        cout << "Результат: " << from_decimal(to_decimal(number, from_system), to_system) << endl;
    }
    else
    {
        cout << "Введены некорректные основания" << endl;
    }

    return 0;
}
