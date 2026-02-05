#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    string number, result;

    cout << "Введите число n: ";
    cin >> n;
    n *= n;
    number = to_string(n);

    if (number.find('3') != number.npos)
    {
        result = "входит";
    }
    else
    {
        result = "не входит";
    }

    cout << "Число n^2 = " << n << ", цифра 3 " << result << " в запись числа" << endl;

    return 0;
}
