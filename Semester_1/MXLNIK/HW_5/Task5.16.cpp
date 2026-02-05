#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
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
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int to_system;
    string number;
    ifstream in;
    ofstream out;

    cout << u8"Введите систему счисления, в которую надо перевести числа: ";
    cin >> to_system;

    in.open("C:/Users/MXLNIK/Downloads/5.5.16_in.txt");
    out.open("C:/Users/MXLNIK/Downloads/5.5.16_out.txt");

    while (in >> number)
    {
        out << from_decimal(to_decimal(number, 16), to_system) << " ";
    }

    in.close();
    out.close();

    return 0;
}
