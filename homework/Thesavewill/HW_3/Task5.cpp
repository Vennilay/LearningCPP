#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N, i, j;
    cout << "Введите число N: "; cin >> N;
    string primes(N + 1, 1);
    primes[1] = 0;
    i = 2;
    while (i < N) {
        if (primes[i] != 0) {
            j = i * 2;
            while (j <= N) {
                primes[j] = 0;
                j = j + i;
            }
            i++;
        }
        else {
            i++;
        }
    }

    for (i = 2; i <= N; i++) {
        if (primes[i] != 0) {
            cout << i << " ";
        }
    }
    return 0;
}