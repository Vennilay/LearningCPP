#include <iostream>
#include <windows.h>
using namespace std;

int counter = 0;

void perestanovka(int Urn[], int m, int n)
{
    if (m == n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (Urn[i] == i + 1)
            {
                counter++;
                break;
            }
        }
        return;
    }

    for (int i = m; i < n; ++i)
    {
        if (i == m)
        {
            perestanovka(Urn, m + 1, n);
        }
        else
        {
            swap(Urn[i], Urn[m]);
            perestanovka(Urn, m + 1, n);
            swap(Urn[i], Urn[m]);
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 11;
    int Urn[n];

    for (int i = 0; i < n; i++)
        Urn[i] = i + 1;

    perestanovka(Urn, 0, n);

    cout << counter;
    return 0;
}
