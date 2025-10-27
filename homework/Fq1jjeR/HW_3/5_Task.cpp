#include <fstream>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int N;
    cout << "Введите натуральное число:";
    cin >> N;

    vector <bool> primes(N + 1, true);

    for (int i = 2; i <= N; i++) {
        for (int j = i * 2; j <= N; j += i)
            primes[j] = false;
    }

    for (int i = 2; i <= N; i++) {
        if (primes[i])
            cout << i << " ";
    }
    return 0;
}
