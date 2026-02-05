#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

int permutations(vector<int> a)
{
    int result = 0;
    do
    {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == (i + 1))
            {
                count++;
            }
        }
        if (count != 0)
        {
            result++;
        }
    } while (next_permutation(a.begin(), a.end()));

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    vector<int> a;

    cout << "Введите количество шариков: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        a.emplace_back(i);
    }

    cout << "Количество ситуаций, когда хотя бы один номер вынимания шарика равен его порядковому номеру: " << permutations(a) << endl;

    return 0;
}
