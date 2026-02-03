#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    int num1, num2, result;
    cout << "Введите числа для нахождения НОД: ";
    getline(cin, input);
    stringstream ss(input);
    ss >> num1 >> num2;

    while (num1 != 0 and num2 != 0)
    {
        if (num1 > num2)
        {
            num1 = num1 % num2;
        }
        else
        {
            num2 = num2 % num1;
        }
    }

    result = num1 + num2;
    cout << "НОД: " << result << endl;
    return 0;
}
