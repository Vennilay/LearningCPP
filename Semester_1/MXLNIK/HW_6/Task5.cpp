#include <iostream>
#include <windows.h>
#include <map>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long n, k, length, quantity, seats_left, seats_right;
    cout << "Введите N: ";
    cin >> n;
    cout << "Введите K: ";
    cin >> k;

    map<long long, long long> segments;
    segments[n] = 1;
    while (k > 0)
    {
        length = segments.rbegin()->first;
        quantity = segments.rbegin()->second;
        segments.erase(length);
        seats_left = (length - 1) / 2;
        seats_right = length / 2;
        if (k <= quantity)
        {
            cout << "Места слева: " << seats_left << endl;
            cout << "Места справа: " << seats_right << endl;
            return 0;
        }
        k -= quantity;
        segments[seats_left] += quantity;
        segments[seats_right] += quantity;
    }

    return 0;
}
