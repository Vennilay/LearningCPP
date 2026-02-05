#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string number;
    vector<char> digits;

    cout << "Введите число: ";
    cin >> number;

    for (int i = 0; i < number.length(); i++)
    {
        if (count(digits.begin(), digits.end(), number[i]) == 0)
        {
            digits.push_back(number[i]);
        }
    }

    cout << "Различных цифр в записи числа: " << digits.size() << endl;

    return 0;
}
