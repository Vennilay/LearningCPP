#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number, i = 2, j;
    string result;
    cout << "Введите число, до которого будут находиться простые числа: ";
    cin >> number;
    vector<int> primes(number + 1);

    for (int i = 0; i <= number; i++)
    {
        primes[i] = i;
    }
    primes[1] = 0;

    while (i < number)
    {
        if (primes[i] != 0)
        {
            j = i * 2;
            while (j <= number)
            {
                primes[j] = 0;
                j += i;
            }
        }
        i += 1;
    }

    cout << "Простые числа: ";
    for (int i = 2; i <= number; i++)
    {
        if (primes[i] != 0)
        {
            cout << primes[i] << " ";
        }
    }
    return 0;
}
