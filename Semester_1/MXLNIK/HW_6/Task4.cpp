#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, seat, s1, s2, s3, s4, s5, s6, current_in_a_row = 0, max_in_a_row = 0;
    vector<bool> available_seats(55, false);
    cout << "Введите количество свободных мест в вагоне: ";
    cin >> n;
    cout << "Введите номера свободных мест: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> seat;
        available_seats[seat] = true;
    }

    for (int i = 0; i < 9; i++)
    {
        s1 = i * 4 + 1;
        s2 = i * 4 + 2;
        s3 = i * 4 + 3;
        s4 = i * 4 + 4;
        s5 = 53 - 2 * i;
        s6 = 54 - 2 * i;

        if (available_seats[s1] && available_seats[s2] && available_seats[s3] &&
            available_seats[s4] && available_seats[s5] && available_seats[s6])
        {
            current_in_a_row++;
        }
        else
        {
            current_in_a_row = 0;
        }

        if (current_in_a_row > max_in_a_row)
        {
            max_in_a_row = current_in_a_row;
        }
    }

    cout << "Максимальное число подряд идущих купе: " << max_in_a_row << endl;

    return 0;
}
